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

      if ($line_item_wrapper->type->value() == 'invoice') {
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
  $commerce_line_items = field_get_items('commerce_order', $replica, 'commerce_line_items');
  $language = field_language('commerce_order', $replica, 'commerce_line_items');
  unset($replica->order_number,
        $replica->revision_id,
        $replica->revision_uid,
        $replica->created,
        $replica->changed,
        $replica->hostname,
        $replica->commerce_line_items);
  // Replicate commerce lite items.
  if ($commerce_line_items) {
    foreach ($commerce_line_items as $value) {
      $line_item = clone commerce_line_item_load($value['line_item_id']);
      $type = $replica->type == 'quote' ? 'product' : 'invoice';
      $line_item_new = commerce_line_item_new($type);
      unset($line_item->line_item_id, $line_item->order_id);

      // Replicate payment modality for line items.
      $instance = field_info_instance('commerce_line_item', 'field_payment_modality', 'product');
      if ($instance && $replica->type != 'commerce_order') {
        $field_payment_modality = field_get_items('commerce_line_item', $line_item, 'field_payment_modality');
        $language = field_language('commerce_line_item', $line_item, 'field_payment_modality');
        unset($line_item->field_payment_modality);
        if ($field_payment_modality) {
          foreach ($field_payment_modality as $value) {
            $payment_modality = erpal_payment_modality_load($value['target_id']);
            unset($payment_modality->payment_modality_id,
                  $payment_modality->created,
                  $payment_modality->changed,
                  $payment_modality->revision_id,
                  $payment_modality->default_revision);
            $payment_modality->uid = $user->uid;
            erpal_payment_modality_save($payment_modality);
            $line_item->field_payment_modality[$language][] = array(
              'target_id' => $payment_modality->payment_modality_id,
            );
          }
        }
      }

      $line_item_new = $line_item;
      $line_item_new->type = $type;
      commerce_line_item_save($line_item_new);
      $replica->commerce_line_items[$language][] = array(
        'line_item_id' => $line_item_new->line_item_id,
      );
    }
  }

  if ($replica->type == 'commerce_order') {
    $replica->type = 'invoice';
    unset($replica->field_order_date,
          $replica->field_order_text,
          $replica->field_order);
    $wrapper = entity_metadata_wrapper('commerce_order', $replica);
    $wrapper->field_invoice_order->set($id);
  }

  if ($replica->type == 'quote') {
    $replica->type = 'commerce_order';
    unset($replica->field_sales_process,
          $replica->field_quote_text,
          $replica->field_valid_until);

    $wrapper = entity_metadata_wrapper('commerce_order', $replica);
    $wrapper->field_quote->set($id);
  }
}
