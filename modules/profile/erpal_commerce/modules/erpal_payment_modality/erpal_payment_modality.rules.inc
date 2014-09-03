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

      erpal_payment_modality_create_line_item($payment_modality, $line_item, $order, TRUE);
    }
  }
}
