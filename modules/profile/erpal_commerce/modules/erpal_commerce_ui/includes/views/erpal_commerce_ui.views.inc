<?php

/**
 * @file
 * Views integration for Commerce Billy PDF.
 */

/**
 * Implements hook_views_data_alter().
 */
function erpal_commerce_ui_views_data_alter(&$data) {
  $data['views_entity_commerce_order']['erpal_commerce_ui_order_link'] = array(
    'field' => array(
      'title' => t('Order PDF'),
      'handler' => 'erpal_commerce_ui_field_handler',
      'help' => t('Link to order PDF file.'),
    ),
  );
  $data['commerce_product']['operations']['field']['handler'] = 'erpal_commerce_product_handler_field_product_operations';

}
