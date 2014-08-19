<?php
/**
 * @file
 * erpal_crm_ui.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function erpal_crm_ui_path_breadcrumbs_settings_info() {
  $export = array();
  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'contact';
  $path_breadcrumb->name = 'Contact';
  $path_breadcrumb->path = 'crm-core/contact/%crm_core_contact';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Contacts',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'contacts',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'crm_core_contact' => array(
        'position' => 2,
        'argument' => 'entity_id:crm_core_contact',
        'settings' => array(
          'identifier' => 'CRM Core Contact: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -88;
  $export['contact'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'contact_edit';
  $path_breadcrumb->name = 'Contact edit';
  $path_breadcrumb->path = 'crm-core/contact/%crm_core_contact/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Contacts',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'contacts',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'crm_core_contact' => array(
        'position' => 2,
        'argument' => 'entity_id:crm_core_contact',
        'settings' => array(
          'identifier' => 'CRM Core Contact: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -87;
  $export['contact_edit'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'contact_add_bundle';
  $path_breadcrumb->name = 'Contact add bundle';
  $path_breadcrumb->path = 'crm-core/contact/add/%crm_core_contact:bundle';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Contacts',
      1 => 'Add a contact',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'contacts',
      1 => 'contacts/add',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'crm_core_contact:bundle' => array(
        'position' => 3,
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -86;
  $export['contact_add_bundle'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'contact_add_relation';
  $path_breadcrumb->name = 'Contact add relation';
  $path_breadcrumb->path = 'crm-core/contact/relationship-add/%relation/%index';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Contacts',
      1 => 'Add a relationship',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'contacts',
      1 => 'contacts/relationship-add',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'relation' => array(
        'position' => 3,
      ),
      'index' => array(
        'position' => 4,
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -85;
  $export['contact_add_relation'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'activity';
  $path_breadcrumb->name = 'Activity';
  $path_breadcrumb->path = 'crm-core/activity/%crm_core_activity';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Activities',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'activities',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'crm_core_activity' => array(
        'position' => 2,
        'argument' => 'entity_id:crm_core_activity',
        'settings' => array(
          'identifier' => 'CRM Activity: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -91;
  $export['activity'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'activity_edit';
  $path_breadcrumb->name = 'Activity edit';
  $path_breadcrumb->path = 'crm-core/activity/%crm_core_activity/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Activities',
      1 => '%crm_core_activity:title',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'activities',
      1 => 'activity/%crm_core_activity:activity-id',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'crm_core_activity' => array(
        'position' => 2,
        'argument' => 'entity_id:crm_core_activity',
        'settings' => array(
          'identifier' => 'CRM Activity: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -90;
  $export['activity_edit'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'activity_add_bundle';
  $path_breadcrumb->name = 'Activity add bundle';
  $path_breadcrumb->path = 'crm-core/activity/add/%crm_core_activity:bundle';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Activities',
      1 => 'Add an activity',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'activities',
      1 => 'activities/add',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'crm_core_activity:bundle' => array(
        'position' => 3,
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -89;
  $export['activity_add_bundle'] = $path_breadcrumb;

  return $export;
}
