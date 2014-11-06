<?php

/**
 * @file
 * Rules integration for ERPAL Commerce.
 */

/**
 * Implements hook_rules_action_info().
 */
function erpal_commerce_rules_action_info() {
  return array(
    'erpal_commerce_create_invoice_line_item' => array(
      'label' => t('Auto creating invoice line item an advance.'),
      'parameter' => array(
        'commerce_line_item' => array('type' => 'commerce_line_item', 'label' => t('Line item')),
      ),
      'group' => t('ERPAL Commerce'),
    ),
    'erpal_commerce_line_item_recalculate_prices' => array(
      'label' => t('Recalculate line item unit and total prices.'),
      'parameter' => array(
        'commerce_line_item' => array('type' => 'commerce_line_item', 'label' => t('Line Item')),
      ),
      'group' => t('ERPAL Commerce'),
    ),
    'erpal_commerce_change_quote_to_accepted' => array(
      'label' => t('Change Quote status to accepted'),
      'parameter' => array(
        'commerce_order' => array('type' => 'commerce_order', 'label' => t('Commerce Order')),
      ),
      'group' => t('ERPAL Commerce'),
    ),
  );
}

/**
 * Change Quote status to accepted.
 *
 * Used as Rules action callback.
 *
 * @see erpal_commerce_rules_action_info()
 */
function erpal_commerce_change_quote_to_accepted($commerce_order) {
  if ($commerce_order->type == 'commerce_order') {
    $field_quote = field_get_items('commerce_order', $commerce_order, 'field_quote');
    if (!empty($field_quote[0]['target_id'])) {
      $quotes = commerce_order_load_multiple(array($field_quote[0]['target_id']), array(), TRUE);
      $quote = reset($quotes);
      $quote->status = 'accepted';
      commerce_order_save($quote);
    }
  }
}

/**
 * Auto creating invoice line item an advance.
 *
 * Used as Rules action callback.
 *
 * @see erpal_commerce_rules_action_info()
 */
function erpal_commerce_create_invoice_line_item($line_item) {
  if ($line_item->order_id && module_exists('erpal_payment_modality')) {

    // Check if line item referenced to commerce_order bundle.
    $order = db_select('commerce_order')
      ->fields('commerce_order')
      ->condition('order_id', $line_item->order_id)
      ->condition('type', 'commerce_order')
      ->execute()
      ->fetchAssoc();
    if ($order) {

      // Load all payment modalities.
      $field_payment_modality = field_get_items('commerce_line_item', $line_item, 'field_payment_modality');
      if ($field_payment_modality) {
        foreach ($field_payment_modality as $payment_modality_id) {
          $payment_modality = erpal_payment_modality_load($payment_modality_id['target_id']);
          $field_due_with = field_get_items('erpal_payment_modality', $payment_modality, 'field_due_with');

          // Create invoice only if payment_modality have Due with an order.
          if ($field_due_with && $field_due_with[0]['value'] == 'order') {

            erpal_payment_modality_create_line_item($payment_modality, $line_item, $order);
          }
        }
      }
    }
  }
}

/**
 * Re-calculate new line item.
 *
 * Used as Rules action callback.
 *
 * @see erpal_commerce_rules_action_info()
 */
function erpal_commerce_line_item_recalculate_prices($line_item) {
  if (empty($line_item->line_item_id)) {
    erpal_commerce_line_item_refresh($line_item);
  }
}
