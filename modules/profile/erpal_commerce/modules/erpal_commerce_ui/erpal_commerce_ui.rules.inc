<?php

/**
 * @file
 * ERPAL Commerce UI Rules code: actions, conditions and events.
 */

/**
 * Implements hook_rules_action_info().
 */
function erpal_commerce_ui_rules_action_info() {
  $actions = array(
    'erpal_commerce_ui_replicate_order' => array(
      'label' => t('Replicate a Commerce Order'),
      'group' => t('Replicate'),
      'parameter' => array(
        'commerce_order' => array(
          'type' => 'commerce_order',
          'label' => t('Order to replicate'),
        ),
      ),
      'provides' => array(
        'new_commerce_order' => array(
          'type' => 'integer',
          'label' => t('New order'),
        ),
      ),
    ),
  );

  return $actions;
}

/**
 * The action function for the 'erpal_commerce_ui_replicate_order'.
 */
function erpal_commerce_ui_replicate_order($commerce_order) {
  $new = replicate_entity('commerce_order', $commerce_order);
  if ($new) {
    $order = commerce_order_load($new);

    // Ensure the attached line items are associated with the order
    // if they do not have an order_id set yet.
    foreach (entity_metadata_wrapper('commerce_order', $order)->commerce_line_items as $line_item_wrapper) {
      if ($line_item_wrapper->order_id->value() != $order->order_id) {
        $line_item_wrapper->order_id = $order->order_id;
        $line_item_wrapper->save();
      }

      if ($line_item_wrapper->field_line_item_billable->value()) {
        $line_item_wrapper->order_id = $order->order_id;
        $line_item_wrapper->field_line_item_order->set($commerce_order->order_id);
        $line_item_wrapper->field_line_item_delivery_date->set(REQUEST_TIME);
        $line_item_wrapper->save();
      }
    }

    drupal_set_message(t('@bundle has been replicated!', array('@bundle' => $commerce_order->type)));
  }
  return array('new_commerce_order' => $new);
}

/**
 * Alter the replica of type commerce_order.
 *
 * Use this function to make specific changes to an entity of a given type.
 * Usefull to "clean" custom entities, ie reset their id to be able to save
 * the new copy for example.
 *
 * @param object $replica
 *   Reference to the fully loaded entity object being saved (the clone) that
 *   can be altered as needed.
 *
 * @see replicate_clone_entity()
 */
function erpal_commerce_ui_replicate_entity_commerce_order(&$replica) {
  global $user;
  $id = $replica->order_id;
  $replica->order_id = NULL;
  $replica->status = 'pending';
  $replica->uid = $user->uid;
  $replica_wrapper = entity_metadata_wrapper('commerce_order', $replica, array('bundle' => $replica->type));
  $commerce_line_items = field_get_items('commerce_order', $replica, 'commerce_line_items');
  unset($replica->order_number,
        $replica->revision_id,
        $replica->revision_uid,
        $replica->created,
        $replica->changed,
        $replica->hostname,
        $replica->commerce_line_items);
  // Replicate commerce lite items.
  if ($commerce_line_items) {
    $new_commerce_line_items = array();
    foreach ($commerce_line_items as $value) {
      $line_item = clone commerce_line_item_load($value['line_item_id']);
      unset($line_item->line_item_id, $line_item->order_id);
      $line_item_wrapper = entity_metadata_wrapper('commerce_line_item', $line_item, array('bundle' => $line_item->type));

      // Replicate payment modality for line items.
      if (isset($line_item_wrapper->field_payment_modality) && $replica->type != 'commerce_order') {
        $field_payment_modalities = $line_item_wrapper->field_payment_modality->value();
        unset($line_item->field_payment_modality);
        if ($field_payment_modalities) {

          $new_payment_modalities = array();
          foreach ($field_payment_modalities as $payment_modality) {
            unset($payment_modality->payment_modality_id,
                  $payment_modality->created,
                  $payment_modality->changed,
                  $payment_modality->revision_id,
                  $payment_modality->default_revision);
            $payment_modality->uid = $user->uid;
            erpal_payment_modality_save($payment_modality);
            $new_payment_modalities[] = $payment_modality;
          }

          $line_item_wrapper->field_payment_modality->set($new_payment_modalities);
        }
      }

      // If its copied from Order to Invoice.
      if ($replica->type == 'commerce_order') {
        $line_item_wrapper->field_line_item_billable->set(TRUE);
      }

      module_load_include('inc', 'commerce_tax', 'commerce_tax.rules');
      commerce_tax_remove_taxes($line_item_wrapper, TRUE, array());

      $line_item_wrapper->save();
      
      $new_commerce_line_items[] = $line_item;

    }
    $replica_wrapper->commerce_line_items->set($new_commerce_line_items);
  }

  if ($replica->type == 'commerce_order') {
    $replica->type = 'invoice';
    $replica_wrapper = entity_metadata_wrapper('commerce_order', $replica, array('bundle' => $replica->type));
    unset($replica->field_order_date,
          $replica->field_order_text,
          $replica->field_order);
    $replica_wrapper->field_invoice_order->set($id);
  }

  if ($replica->type == 'quote') {
    $replica->type = 'commerce_order';
    $replica_wrapper = entity_metadata_wrapper('commerce_order', $replica, array('bundle' => $replica->type));
    unset($replica->field_sales_process,
          $replica->field_quote_text,
          $replica->field_valid_until);

    $replica_wrapper->field_quote->set($id);
  }
}
