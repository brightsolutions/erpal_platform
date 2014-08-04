<?php
/**
 * @file
 * erpal_commerce_ui.breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function erpal_commerce_ui_path_breadcrumbs_settings_info() {
  $export = array();
  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'quote';
  $path_breadcrumb->name = 'Quote';
  $path_breadcrumb->path = 'admin/commerce/orders/%commerce_order';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Quotes',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'quotes',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'commerce_order' => array(
        'position' => 3,
        'argument' => 'entity_id:commerce_order',
        'settings' => array(
          'identifier' => 'Commerce Order: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:commerce_order',
          'settings' => array(
            'type' => array(
              'quote' => 'quote',
            ),
          ),
          'context' => 'commerce_order',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['quote'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'order';
  $path_breadcrumb->name = 'Order';
  $path_breadcrumb->path = 'admin/commerce/orders/%commerce_order';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Orders',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'orders',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'commerce_order' => array(
        'position' => 3,
        'argument' => 'entity_id:commerce_order',
        'settings' => array(
          'identifier' => 'Commerce Order: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:commerce_order',
          'settings' => array(
            'type' => array(
              'commerce_order' => 'commerce_order',
            ),
          ),
          'context' => 'commerce_order',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['order'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'invoice';
  $path_breadcrumb->name = 'Invoice';
  $path_breadcrumb->path = 'admin/commerce/orders/%commerce_order';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Invoices',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'invoices',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'commerce_order' => array(
        'position' => 3,
        'argument' => 'entity_id:commerce_order',
        'settings' => array(
          'identifier' => 'Commerce Order: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:commerce_order',
          'settings' => array(
            'type' => array(
              'invoice' => 'invoice',
            ),
          ),
          'context' => 'commerce_order',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['invoice'] = $path_breadcrumb;

  return $export;
}
