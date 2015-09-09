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
