<?php

/**
 * @file
 * Contains a page callbacks for ERPAL CRM UI module.
 */

/**
 * Callback of "Add activity" page.
 *
 * @return string
 *   Activity types list or empty text.
 */
function erpal_crm_ui_add_activity_page() {

  global $user;
  $items = array();

  // Work around core issue where 'title' isn't set for MENU_LOCAL_ACTION,
  // see: http://drupal.org/node/891892
  $trail = menu_get_active_trail();
  drupal_set_title($trail[count($trail) - 1]['title']);

  // Collect links to an activity create forms.
  foreach (crm_core_activity_types() as $info) {
    if (entity_access('create', 'crm_core_activity', $info->type, $user)) {
      $items[] = array(
        'title' => $info->label,
        'href' => 'crm-core/activity/add/' . $info->type,
        'localized_options' => array(),
        'description' => $info->description,
      );
    }
  }

  // If there are only one activity bundle - then we may redirect user to it
  // without showing an extra step.
  if (count($items) == 1) {
    drupal_goto($items[0]['href'], $items[0]);
  }

  // Show list of links to add an activities.
  return empty($items) ? t('It is not possible to create activities yet.
    Please add an activity type first.') : theme('crm_core_contact_ui_add_list', array('content' => $items));
}
