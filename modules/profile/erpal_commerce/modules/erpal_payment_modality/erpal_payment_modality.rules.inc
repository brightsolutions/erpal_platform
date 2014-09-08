<?php

/**
 * @file
 * Rules integration for ERPAL Commerce.
 */

/**
 * Implements hook_rules_action_info().
 */
function erpal_payment_modality_rules_action_info() {
  return array(
    'erpal_payment_modality_create_invoice_line_item_delivery' => array(
      'label' => t('Auto creating invoice line item from delivery payment.'),
      'parameter' => array(
        'erpal_payment_modality' => array('type' => 'erpal_payment_modality', 'label' => t('Payment Modality')),
      ),
      'group' => t('ERPAL Payment Modality'),
    ),
    'erpal_payment_modality_auto_create' => array(
      'label' => t('Auto creating payment modality on line item creation.'),
      'parameter' => array(
        'commerce_line_item' => array('type' => 'commerce_line_item', 'label' => t('Line Item')),
      ),
      'group' => t('ERPAL Payment Modality'),
    ),
  );
}

/**
 * Auto creating invoice line item from delivery payment.
 *
 * Used as Rules action callback.
 *
 * @see erpal_payment_modality_rules_action_info()
 */
function erpal_payment_modality_create_invoice_line_item_delivery($payment_modality) {
  $line_item_id = db_select('field_data_field_payment_modality', 'pm')
    ->fields('pm' , array('entity_id'))
    ->condition('pm.field_payment_modality_target_id', $payment_modality->payment_modality_id)
    ->execute()
    ->fetchAssoc();

  if (!$line_item_id) {
    return;
  }

  $line_item = commerce_line_item_load($line_item_id['entity_id']);

  // Check if line item referenced to commerce_order bundle.
  $order = db_select('commerce_order')
    ->fields('commerce_order')
    ->condition('order_id', $line_item->order_id)
    ->condition('type', 'commerce_order')
    ->execute()
    ->fetchAssoc();

  if ($order) {
    $field_due_with = field_get_items('erpal_payment_modality', $payment_modality, 'field_due_with');

    // Create invoice only if payment_modality have Due with delivery.
    if ($field_due_with && $field_due_with[0]['value'] == 'delivery') {

      erpal_payment_modality_create_line_item($payment_modality, $line_item, $order, TRUE);
    }
  }
}

/**
 * Auto creating payment modality on line item creation.
 *
 * Used as Rules action callback.
 *
 * @see erpal_payment_modality_rules_action_info()
 */
function erpal_payment_modality_auto_create($line_item) {
  $commerce_product = field_get_items('commerce_line_item', $line_item, 'commerce_product');
  if (!empty($commerce_product[0]['product_id'])) {

    $field_line_item_unit = field_get_items('commerce_line_item', $line_item, 'field_line_item_unit');
    $field_payment_modality = field_get_items('commerce_line_item', $line_item, 'field_payment_modality');
    $commerce_total = field_get_items('commerce_line_item', $line_item, 'commerce_total');
    $commerce_unit_price = field_get_items('commerce_line_item', $line_item, 'commerce_unit_price');
    $percentage = 0;

    // Check for unit item.
    if (!empty($field_line_item_unit[0]['value']) && $field_line_item_unit[0]['value'] == 'item') {
      
      if (!empty($field_payment_modality)) {
        foreach ($field_payment_modality as $payment_modality_id) {
          $payment_modality = erpal_payment_modality_load($payment_modality_id['target_id']);
          $field_amount = field_get_items('erpal_payment_modality', $payment_modality, 'field_amount');
          $field_amount_type = field_get_items('erpal_payment_modality', $payment_modality, 'field_amount_type');
          $field_due_with = field_get_items('erpal_payment_modality', $payment_modality, 'field_due_with');
          if (!empty($field_amount_type[0]['value']) && $field_amount_type[0]['value'] == 'percent') {
            $percentage = $percentage + $field_amount[0]['value'];
          }
          else {
            $amount = commerce_currency_decimal_to_amount($field_amount[0]['value'], $commerce_total[0]['currency_code']);
            $percentage = $percentage  + ($amount / $commerce_total[0]['amount']) * 100;
          }
        }
      }
      $new = 100 - $percentage;
      if ($new > 0) {
        $new_amount = $new;
        $new_amount_type = 'percent';
      }
    }

    // Check for unit time.
    $time = erpal_core_units_time();
    if (!empty($field_line_item_unit[0]['value']) && in_array($field_line_item_unit[0]['value'], $time)) {
      $new = TRUE;
      if (!empty($field_payment_modality)) {
        foreach ($field_payment_modality as $payment_modality_id) {
          $payment_modality = erpal_payment_modality_load($payment_modality_id['target_id']);
          $field_amount = field_get_items('erpal_payment_modality', $payment_modality, 'field_amount');
          $field_amount_type = field_get_items('erpal_payment_modality', $payment_modality, 'field_amount_type');
          $field_due_with = field_get_items('erpal_payment_modality', $payment_modality, 'field_due_with');
          if (!empty($field_due_with[0]['value']) && $field_due_with[0]['value'] == 'delivery') {
            $new = FALSE;
          }
        }
      }
      if ($new) {
        $new_amount = commerce_currency_amount_to_decimal($commerce_unit_price[0]['amount'], $commerce_unit_price[0]['currency_code']);
        $new_amount_type = 'total';
      }
    }

    // Create Payment Modality if needed.
    if (!empty($new_amount) && !empty($new_amount_type)) {

      $payment_modality = entity_get_controller('erpal_payment_modality')->create(array('type' => 'payment_modality'));

      $lang = field_language('erpal_payment_modality', $payment_modality, 'field_amount');
      $payment_modality->field_amount[$lang][0] = array(
        'value' => $new_amount,
      );

      $lang = field_language('erpal_payment_modality', $payment_modality, 'field_amount_type');
      $payment_modality->field_amount_type[$lang][0] = array(
        'value' => $new_amount_type,
      );

      $lang = field_language('erpal_payment_modality', $payment_modality, 'field_due_with');
      $payment_modality->field_due_with[$lang][0] = array(
        'value' => 'delivery',
      );

      erpal_payment_modality_save($payment_modality);

      // Add new Payment modality to line item.
      $lang = field_language('commerce_line_item', $line_item, 'field_payment_modality');
      $line_item->field_payment_modality[$lang][] = array('target_id' => $payment_modality->payment_modality_id);
    }

  }
}
