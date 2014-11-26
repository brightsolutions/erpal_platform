<?php
/**
 * @file
 * erpal_commerce_ui.cat.inc
 */

/**
 * Implements hook_cat_items_settings_info().
 */
function erpal_commerce_ui_cat_items_settings_info() {
  $export = array();
  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'create_quote';
  $cat_item->name = 'Create quote';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = '';
  $cat_item->path = 'crm-core/activity/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:crm_core_activity',
          'settings' => array(
            'type' => array(
              'meeting' => 'meeting',
              'phone_call' => 'phone_call',
              'email' => 'email',
            ),
          ),
          'context' => 'crm-core-activity',
          'not' => FALSE,
        ),
      ),
    ),
    'active_trail_path' => '',
    'arguments' => array(
      2 => array(
        'argument_name' => 'crm-core-activity',
        'argument_type' => 'path',
        'position' => 2,
        'argument' => 'entity_id:crm_core_activity',
        'settings' => array(
          'identifier' => 'CRM Activity: ID',
        ),
      ),
    ),
    'name' => 'Create quote',
    'path' => 'crm-core/activity/%',
    'category' => '',
    'cat_actions' => array(
      0 => array(
        'path' => 'quote/add',
        'path_router' => 'quote/add',
        'path_original' => 'quote/add',
        'path_pattern' => 'quote/%',
        'path_query' => array(
          'activity_id' => '[crm-core-activity:activity-id]',
        ),
        'path_destination' => FALSE,
        'title' => 'Create a quote',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'create_quote',
    'path_original' => 'crm-core/activity/%crm-core-activity',
    'path_pattern' => 'crm-core/%/%',
    'path_query' => array(),
    'path_router' => 'crm-core/activity/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['create_quote'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'create_quote_sales_process';
  $cat_item->name = 'Create quote';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = '';
  $cat_item->path = 'crm-core/activity/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:crm_core_activity',
          'settings' => array(
            'type' => array(
              'sales_process' => 'sales_process',
            ),
          ),
          'context' => 'crm-core-activity',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => '',
    'arguments' => array(
      2 => array(
        'argument_name' => 'crm-core-activity',
        'argument_type' => 'path',
        'position' => 2,
        'argument' => 'entity_id:crm_core_activity',
        'settings' => array(
          'identifier' => 'CRM Activity: ID',
        ),
      ),
    ),
    'name' => 'Create quote',
    'path' => 'crm-core/activity/%',
    'category' => '',
    'cat_actions' => array(
      0 => array(
        'path' => 'quote/add',
        'path_router' => 'quote/add',
        'path_original' => 'quote/add',
        'path_pattern' => 'quote/%',
        'path_query' => array(
          'field_sales_process' => '[crm-core-activity:activity-id]',
          'field_customer' => '[crm-core-activity:field-activity-customer:contact-id]',
        ),
        'path_destination' => FALSE,
        'title' => 'Create a quote',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'create_quote_sales_process',
    'path_original' => 'crm-core/activity/%crm-core-activity',
    'path_pattern' => 'crm-core/%/%',
    'path_query' => array(),
    'path_router' => 'crm-core/activity/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['create_quote_sales_process'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'create_quote_link';
  $cat_item->name = 'Create quote';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = '';
  $cat_item->path = 'crm-core/contact/%';
  $cat_item->data = array(
    'access' => array(),
    'active_trail_path' => '',
    'arguments' => array(
      2 => array(
        'argument_name' => 'crm-core-contact',
        'argument_type' => 'path',
        'position' => 2,
        'argument' => 'entity_id:crm_core_contact',
        'settings' => array(
          'identifier' => 'CRM Core Contact: ID',
        ),
      ),
    ),
    'name' => 'Create quote',
    'path' => 'crm-core/contact/%',
    'category' => '',
    'cat_actions' => array(
      0 => array(
        'path' => 'quote/add',
        'path_router' => 'quote/add',
        'path_original' => 'quote/add',
        'path_pattern' => 'quote/%',
        'path_query' => array(
          'field_customer' => '[crm-core-contact:contact-id]',
        ),
        'path_destination' => FALSE,
        'title' => 'Add a quote',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'create_quote_link',
    'path_original' => 'crm-core/contact/%crm-core-contact',
    'path_pattern' => 'crm-core/%/%',
    'path_query' => array(),
    'path_router' => 'crm-core/contact/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -99;
  $export['create_quote_link'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'create_order_link';
  $cat_item->name = 'Create order';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = '';
  $cat_item->path = 'crm-core/contact/%';
  $cat_item->data = array(
    'access' => array(),
    'active_trail_path' => '',
    'arguments' => array(
      2 => array(
        'argument_name' => 'crm-core-contact',
        'argument_type' => 'path',
        'position' => 2,
        'argument' => 'entity_id:crm_core_contact',
        'settings' => array(
          'identifier' => 'CRM Core Contact: ID',
        ),
      ),
    ),
    'name' => 'Create order',
    'path' => 'crm-core/contact/%',
    'category' => '',
    'cat_actions' => array(
      0 => array(
        'path' => 'order/add',
        'path_router' => 'order/add',
        'path_original' => 'order/add',
        'path_pattern' => 'admin/commerce/orders/%',
        'path_query' => array(
          'field_customer' => '[crm-core-contact:contact-id]',
        ),
        'path_destination' => FALSE,
        'title' => 'Add an order',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'create_order_link',
    'path_original' => 'crm-core/contact/%crm-core-contact',
    'path_pattern' => 'crm-core/%/%',
    'path_query' => array(),
    'path_router' => 'crm-core/contact/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -98;
  $export['create_order_link'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'create_invoice_link';
  $cat_item->name = 'Create invoice';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = '';
  $cat_item->path = 'crm-core/contact/%';
  $cat_item->data = array(
    'access' => array(),
    'active_trail_path' => '',
    'arguments' => array(
      2 => array(
        'argument_name' => 'crm-core-contact',
        'argument_type' => 'path',
        'position' => 2,
        'argument' => 'entity_id:crm_core_contact',
        'settings' => array(
          'identifier' => 'CRM Core Contact: ID',
        ),
      ),
    ),
    'name' => 'Create invoice',
    'path' => 'crm-core/contact/%',
    'category' => '',
    'cat_actions' => array(
      0 => array(
        'path' => 'invoice/add',
        'path_router' => 'invoice/add',
        'path_original' => 'invoice/add',
        'path_pattern' => 'invoice/%',
        'path_query' => array(
          'field_customer' => '[crm-core-contact:contact-id]',
        ),
        'path_destination' => FALSE,
        'title' => 'Add an invoice',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'create_invoice_link',
    'path_original' => 'crm-core/contact/%crm-core-contact',
    'path_pattern' => 'crm-core/%/%',
    'path_query' => array(),
    'path_router' => 'crm-core/contact/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -97;
  $export['create_invoice_link'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'add_product';
  $cat_item->name = 'Add product';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = '';
  $cat_item->path = 'products';
  $cat_item->data = array(
    'access' => array(),
    'active_trail_path' => '',
    'arguments' => array(),
    'name' => 'Add product',
    'path' => 'products',
    'category' => '',
    'cat_actions' => array(
      0 => array(
        'path' => 'product/add/product',
        'path_router' => 'product/add/product',
        'path_original' => 'product/add/product',
        'path_pattern' => 'product/%/%',
        'path_query' => array(),
        'path_destination' => TRUE,
        'title' => 'Add a product',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'add_product',
    'path_original' => 'products',
    'path_pattern' => 'products',
    'path_query' => array(),
    'path_router' => 'products',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['add_product'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'create_order';
  $cat_item->name = 'Create Order';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = '';
  $cat_item->path = 'orders';
  $cat_item->data = array(
    'access' => array(),
    'active_trail_path' => '',
    'arguments' => array(),
    'name' => 'Create Order',
    'path' => 'orders',
    'category' => '',
    'cat_actions' => array(
      0 => array(
        'path' => 'order/add',
        'path_router' => 'order/add',
        'path_original' => 'order/add',
        'path_pattern' => 'order/%',
        'path_query' => array(),
        'path_destination' => TRUE,
        'title' => 'Create an Order',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
      1 => array(
        'path' => 'admin/commerce/config/custom-order-number',
        'path_router' => 'admin/commerce/config/custom-order-number',
        'path_original' => 'admin/commerce/config/custom-order-number',
        'path_pattern' => 'admin/%/%/%',
        'path_query' => array(),
        'path_destination' => TRUE,
        'title' => 'Settings',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
      2 => array(
        'path' => 'admin/commerce/config/billy-order/pdf',
        'path_router' => 'admin/commerce/config/billy-order/pdf',
        'path_original' => 'admin/commerce/config/billy-order/pdf',
        'path_pattern' => 'admin/%/%/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'PDF Settings',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'create_order',
    'path_original' => 'orders',
    'path_pattern' => 'orders',
    'path_query' => array(),
    'path_router' => 'orders',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['create_order'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'create_order_sales';
  $cat_item->name = 'Create order';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = '';
  $cat_item->path = 'crm-core/activity/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:crm_core_activity',
          'settings' => array(
            'type' => array(
              'sales_process' => 'sales_process',
            ),
          ),
          'context' => 'crm-core-activity',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => '',
    'arguments' => array(
      2 => array(
        'argument_name' => 'crm-core-activity',
        'argument_type' => 'path',
        'position' => 2,
        'argument' => 'entity_id:crm_core_activity',
        'settings' => array(
          'identifier' => 'CRM Activity: ID',
        ),
      ),
    ),
    'name' => 'Create order',
    'path' => 'crm-core/activity/%',
    'category' => '',
    'cat_actions' => array(
      0 => array(
        'path' => 'order/add',
        'path_router' => 'order/add',
        'path_original' => 'order/add',
        'path_pattern' => 'order/%',
        'path_query' => array(
          'field_customer' => '[crm-core-activity:field-activity-customer:contact-id]',
        ),
        'path_destination' => FALSE,
        'title' => 'Create an order',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'create_order_sales',
    'path_original' => 'crm-core/activity/%crm-core-activity',
    'path_pattern' => 'crm-core/%/%',
    'path_query' => array(),
    'path_router' => 'crm-core/activity/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['create_order_sales'] = $cat_item;

  return $export;
}
