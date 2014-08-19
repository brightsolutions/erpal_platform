<?php
/**
 * @file
 * erpal_commerce_ui.path_breadcrumbs.inc
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

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'quote_add';
  $path_breadcrumb->name = 'Quote add';
  $path_breadcrumb->path = 'quote/add';
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
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -97;
  $export['quote_add'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'order_add';
  $path_breadcrumb->name = 'Order add';
  $path_breadcrumb->path = 'order/add';
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
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -96;
  $export['order_add'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'invoice_add';
  $path_breadcrumb->name = 'Invoice add';
  $path_breadcrumb->path = 'invoice/add';
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
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -95;
  $export['invoice_add'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'quote_edit';
  $path_breadcrumb->name = 'Quote edit';
  $path_breadcrumb->path = 'admin/commerce/orders/%commerce_order/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Quotes',
      1 => 'Quote %commerce_order:order-number',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'quotes',
      1 => 'quote/%commerce_order:order-id',
      2 => '<none>',
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
  $path_breadcrumb->weight = -94;
  $export['quote_edit'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'order_edit';
  $path_breadcrumb->name = 'Order edit';
  $path_breadcrumb->path = 'admin/commerce/orders/%commerce_order/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Orders',
      1 => 'Order %commerce_order:order-number',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'orders',
      1 => 'order/%commerce_order:order-id',
      2 => '<none>',
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
  $path_breadcrumb->weight = -93;
  $export['order_edit'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'invoice_edit';
  $path_breadcrumb->name = 'Invoice edit';
  $path_breadcrumb->path = 'admin/commerce/orders/%commerce_order/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Invoices',
      1 => 'Invoice %commerce_order:order-number',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'invoices',
      1 => 'invoice/%commerce_order:order-id',
      2 => '<none>',
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
  $path_breadcrumb->weight = -92;
  $export['invoice_edit'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'product';
  $path_breadcrumb->name = 'Product';
  $path_breadcrumb->path = 'admin/commerce/products/%commerce_product';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Products',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'products',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'commerce_product' => array(
        'position' => 3,
        'argument' => 'entity_id:commerce_product',
        'settings' => array(
          'identifier' => 'Commerce Product: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -84;
  $export['product'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'product_revisions';
  $path_breadcrumb->name = 'Product revisions';
  $path_breadcrumb->path = 'admin/commerce/products/%commerce_product/revisions';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Products',
      1 => '%commerce_product:title',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'products',
      1 => 'product/%commerce_product:product-id',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'commerce_product' => array(
        'position' => 3,
        'argument' => 'entity_id:commerce_product',
        'settings' => array(
          'identifier' => 'Commerce Product: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -83;
  $export['product_revisions'] = $path_breadcrumb;

  return $export;
}
