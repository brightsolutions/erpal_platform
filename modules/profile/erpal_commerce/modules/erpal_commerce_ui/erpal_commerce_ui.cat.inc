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

  return $export;
}
