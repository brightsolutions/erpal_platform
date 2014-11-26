<?php
/**
 * @file
 * erpal_commerce_ui.cat.inc
 */

/**
 * Implements hook_cat_items_settings_info().
 */
function erpal_crm_ui_cat_items_settings_info() {
  $export = array();
  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'create_meeting';
  $cat_item->name = 'Create meeting';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = '';
  $cat_item->path = 'crm-core/activity/%';
  $cat_item->data = array(
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
    'name' => 'Create meeting',
    'path' => 'crm-core/activity/%',
    'category' => '',
    'cat_actions' => array(
      0 => array(
        'path' => 'crm-core/activity/add/meeting',
        'path_router' => 'crm-core/activity/add/meeting',
        'path_original' => 'crm-core/activity/add/meeting',
        'path_pattern' => 'crm-core/%/%/%',
        'path_query' => array(
          'field_activity_sales_process' => '[crm-core-activity:activity-id]',
          'field_activity_customer' => '[crm-core-activity:field-activity-customer:contact-id]',
        ),
        'path_destination' => FALSE,
        'title' => 'Create meeting',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'create_meeting',
    'path_original' => 'crm-core/activity/%crm-core-activity',
    'path_pattern' => 'crm-core/%/%',
    'path_query' => array(),
    'path_router' => 'crm-core/activity/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -97;
  $export['create_meeting'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'create_phone_call';
  $cat_item->name = 'Create phone call';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = '';
  $cat_item->path = 'crm-core/activity/%';
  $cat_item->data = array(
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
    'name' => 'Create phone call',
    'path' => 'crm-core/activity/%',
    'category' => '',
    'cat_actions' => array(
      0 => array(
        'path' => 'crm-core/activity/add/phone_call',
        'path_router' => 'crm-core/activity/add/phone_call',
        'path_original' => 'crm-core/activity/add/phone_call',
        'path_pattern' => 'crm-core/%/%/%',
        'path_query' => array(
          'field_activity_sales_process' => '[crm-core-activity:activity-id]',
          'field_activity_customer' => '[crm-core-activity:field-activity-customer:contact-id]',
        ),
        'path_destination' => FALSE,
        'title' => 'Create phone call',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'create_phone_call',
    'path_original' => 'crm-core/activity/%crm-core-activity',
    'path_pattern' => 'crm-core/%/%',
    'path_query' => array(),
    'path_router' => 'crm-core/activity/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -96;
  $export['create_phone_call'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'create_email';
  $cat_item->name = 'Create email';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = '';
  $cat_item->path = 'crm-core/activity/%';
  $cat_item->data = array(
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
    'name' => 'Create email',
    'path' => 'crm-core/activity/%',
    'category' => '',
    'cat_actions' => array(
      0 => array(
        'path' => 'crm-core/activity/add/email',
        'path_router' => 'crm-core/activity/add/email',
        'path_original' => 'crm-core/activity/add/email',
        'path_pattern' => 'crm-core/%/%/%',
        'path_query' => array(
          'field_activity_sales_process' => '[crm-core-activity:activity-id]',
          'field_activity_customer' => '[crm-core-activity:field-activity-customer:contact-id]',
        ),
        'path_destination' => FALSE,
        'title' => 'Create email',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'create_email',
    'path_original' => 'crm-core/activity/%crm-core-activity',
    'path_pattern' => 'crm-core/%/%',
    'path_query' => array(),
    'path_router' => 'crm-core/activity/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -95;
  $export['create_email'] = $cat_item;

  return $export;
}
