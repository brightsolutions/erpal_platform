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
      'group' => t('ERPAL Commerce'),
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

      // Generate label for invoice line item.
      $invoice_label = implode(' - ', array($order['order_number'], $line_item->line_item_label, $payment_modality->title));

      // Check if already exists invoice line item for this payment modality.
      $conditions = array(
        'line_item_label' => $invoice_label,
        'type' => 'invoice',
      );
      $invoice = commerce_line_item_load_multiple(array(), $conditions, TRUE);

      if (!empty($invoice)) {
        $invoice = reset($invoice);

        // If invoice line item already added to invoice nothing to do
        // here.
        if ($invoice->order_id != $order['order_id']) {
          return;
        }
      }
      else {
        $invoice = commerce_line_item_new('invoice');
      }

      // Provide logic for calculation.
      $total = commerce_line_items_total(array($line_item));
      $field_amount_type = field_get_items('erpal_payment_modality', $payment_modality, 'field_amount_type');
      $field_amount = field_get_items('erpal_payment_modality', $payment_modality, 'field_amount');
      if (!empty($field_amount_type) && !empty($field_amount)) {
        if ($field_amount_type[0]['value'] == 'percent') {
          $total['amount'] = ($field_amount[0]['value'] / 100) * $total['amount'];
        }
        else {
          $total['amount'] = $field_amount[0]['value'];
        }

        // Add all data to new invoice line item.
        $invoice->line_item_label = $invoice_label;
        $invoice->order_id = $order['order_id'];
        $langcode = field_language('commerce_line_item', $invoice, 'commerce_unit_price');
        $invoice->commerce_unit_price[$langcode][0] = $total;
        $langcode = field_language('commerce_line_item', $invoice, 'field_line_item_order');
        $invoice->field_line_item_order[$langcode][0]['target_id'] = $order['order_id'];
        commerce_line_item_rebase_unit_price($invoice);
        commerce_line_item_save($invoice);
        drupal_set_message(t('Invoice line item was created.'));
      }
    }
  }
}
