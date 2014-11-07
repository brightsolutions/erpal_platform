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

  $site_properties['vendor'] = array(
    'label' => t('Site vendor'),
    'description' => t('CRM Contact entity of vendor'),
    'type' => 'crm_core_contact',
    'getter callback' => 'erpal_commerce_entity_get_properties',
    'computed' => TRUE,
  );

  $site_properties['vendor_address'] = array(
    'label' => t('Site vendor address'),
    'description' => t('Commerce profile address of site vendor'),
    'type' => 'commerce_customer_profile',
    'getter callback' => 'erpal_commerce_entity_get_properties',
    'computed' => TRUE,
  );
}
