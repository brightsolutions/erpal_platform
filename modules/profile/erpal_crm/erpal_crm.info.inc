<?php

/**
 * @file
 * Contains Entity API hooks and callbacks.
 */

/**
 * Implements hook_entity_property_info_alter().
 */
function erpal_crm_entity_property_info_alter(&$info) {

  // Add possibility to modify some properties of CRM Contact.
  $contact_properties = &$info['crm_core_contact']['properties'];
  foreach ($contact_properties as $property_name => &$property_info) {
    if ($property_name == 'uid') {
      $property_info['setter callback'] = 'entity_property_verbatim_set';
    }
    elseif ($property_name == 'type') {
      $property_info['setter callback'] = 'entity_property_verbatim_set';
      $property_info['options list'] = 'erpal_crm_core_contact_type_options_list';
    }
  }
}
