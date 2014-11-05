<?php

/**
 * @file
 * Provides integration with Rules.
 */

/**
 * Implements hook_rules_event_info().
 */
function erpal_commerce_cart_rules_event_info() {
  return array(
    'erpal_commerce_cart_commerce_customer_insert' => array(
      'label' => t('Customer profile has been created during the checkout'),
      'group' => t('ERPAL Commerce Cart'),
      'variables' => array(
        'commerce_order' => array(
          'type' => 'commerce_order',
          'label' => t('Order from cart'),
        ),
        'commerce_customer_profile' => array(
          'type' => 'commerce_customer_profile',
          'label' => t('Created customer profile'),
        ),
      ),
    ),
  );
}
