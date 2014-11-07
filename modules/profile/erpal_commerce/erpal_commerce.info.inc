<?php

/**
 * @file
 * Contains Entity API hooks and callbacks.
 */

/**
 * Implements hook_entity_property_info_alter().
 */
function erpal_commerce_entity_property_info_alter(&$info) {
  $site_properties = &$info['site']['properties'];
  $site_properties['global_vendor'] = array(
    'label' => t('Global site vendor'),
    'description' => t('Information about site vendor'),
    'getter callback' => 'erpal_commerce_entity_get_properties',
    'type' => 'struct',
    'property info' => array(
      'vendor' => array(
        'label' => t('Vendor'),
        'description' => t('CRM Contact entity of vendor'),
        'type' => 'crm_core_contact',
      ),
      'vendor_address' => array(
        'label' => t('Vendor address'),
        'description' => t('Commerce profile address of site vendor'),
        'type' => 'commerce_customer_profile',
      ),
    ),
    'computed' => TRUE,
  );
}

/**
 * Entity API property getter callback.
 */
function erpal_commerce_entity_get_properties($data, array $options, $name, $type, $info) {
  if (empty($data)) {
    return;
  }

  return '';
}
