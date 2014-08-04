<?php

/**
 * Field handler to present a product's operations links.
 */
class erpal_commerce_product_handler_field_product_operations extends commerce_product_handler_field_product_operations {

  function render($values) {
    $product_id = $this->get_value($values, 'product_id');

    // Get the operations links.
    $links = menu_contextual_links('commerce-product', 'product', array($product_id));

    if (!empty($links)) {
      // Add the destination to the links if specified.
      if ($this->options['add_destination']) {
        foreach ($links as $id => &$link) {
          $link['query'] = drupal_get_destination();
        }
      }

      drupal_add_css(drupal_get_path('module', 'commerce_product') . '/theme/commerce_product.admin.css');
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}
