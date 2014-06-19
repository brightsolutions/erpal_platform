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
    'access' => array(),
    'active_trail_path' => '',
    'arguments' => array(
      2 => array(
        'argument_name' => 'crm_core_activity',
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
          'field_sales_process' => '[crm_core_activity:activity-id]',
          'field_customer' => '[crm_core_activity:field-activity-customer:contact-id]',
        ),
        'path_destination' => FALSE,
        'title' => 'Create quote',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'create_quote',
    'path_original' => 'crm-core/activity/%crm_core_activity',
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
        'argument_name' => 'crm_core_contact',
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
          'field_customer' => '[crm_core_contact:contact-id]',
        ),
        'path_destination' => FALSE,
        'title' => 'Add quote',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'create_quote_link',
    'path_original' => 'crm-core/contact/%crm_core_contact',
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
        'argument_name' => 'crm_core_contact',
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
        'path_pattern' => 'order/%',
        'path_query' => array(
          'field_customer' => '[crm_core_contact:contact-id]',
        ),
        'path_destination' => FALSE,
        'title' => 'Add order',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'create_order_link',
    'path_original' => 'crm-core/contact/%crm_core_contact',
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
        'argument_name' => 'crm_core_contact',
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
          'field_customer' => '[crm_core_contact:contact-id]',
        ),
        'path_destination' => FALSE,
        'title' => 'Add invoice',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'create_invoice_link',
    'path_original' => 'crm-core/contact/%crm_core_contact',
    'path_pattern' => 'crm-core/%/%',
    'path_query' => array(),
    'path_router' => 'crm-core/contact/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -97;
  $export['create_invoice_link'] = $cat_item;

  return $export;
}
