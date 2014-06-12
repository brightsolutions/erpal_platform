<?php

/**
 * @file
 * Entity support.
 */

/**
 * Implements hook_entity_property_info().
 */
function erpal_payment_modality_entity_property_info() {
  $info = array();

  // Add meta-data about erpal_payment_modality properties.
  $properties = &$info['erpal_payment_modality']['properties'];

  $properties['payment_modality_id'] = array(
    'label' => t('Payment modality ID'),
    'description' => t('The primary identifier for an payment_modality.'),
    'type' => 'integer',
    'schema field' => 'payment_modality_id',
  );
  $properties['type'] = array(
    'label' => t('Type'),
    'description' => t('The type (bundle) of the payment modality.'),
    'type' => 'token',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer site configuration',
    'options list' => 'erpal_payment_modality_type_get_names',
    'required' => TRUE,
    'schema field' => 'type',
  );
  $properties['title'] = array(
    'label' => t('Title'),
    'description' => t('Title of the payment modality.'),
    'type' => 'text',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer site configuration',
    'required' => TRUE,
    'schema field' => 'title',
  );
  $properties['uid'] = array(
    'label' => t('User ID'),
    'type' => 'integer',
    'description' => t("The unique ID of the user created payment modality."),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer site configuration',
    'schema field' => 'uid',
  );
  $properties['created'] = array(
    'label' => t('Date created'),
    'description' => t('The date the payment modality was created.'),
    'type' => 'date',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'dminister site configuration',
    'schema field' => 'created',
  );
  $properties['changed'] = array(
    'label' => t('Date updated'),
    'description' => t('The date the payment modality was last updated.'),
    'type' => 'date',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'Administer site configuration',
    'schema field' => 'changed',
  );

  if (module_exists('uuid')) {
    $properties['uuid'] = array(
      'label' => t('UUID'),
      'type' => 'text',
      'description' => t('The universally unique ID.'),
      'schema field' => 'uuid',
    );

    $properties['vuuid'] = array(
      'label' => t('Revision UUID'),
      'type' => 'text',
      'description' => t("The revision's universally unique ID."),
      'schema field' => 'vuuid',
    );
  }

  // Metadata of payment modality Type.
  $properties = &$info['erpal_payment_modality_type']['properties'];

  $properties['id'] = array(
    'label' => t('Payment modality Type ID'),
    'description' => t('Primary Key: Unique payment modality type ID.'),
    'type' => 'integer',
    'schema field' => 'id',
  );
  $properties['type'] = array(
    'label' => t('Type'),
    'description' => t('The machine-readable name of this type.'),
    'type' => 'token',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer site configuration',
    'required' => TRUE,
    'schema field' => 'type',
  );
  $properties['label'] = array(
    'label' => t('Label'),
    'description' => t('The human-readable name of this type.'),
    'type' => 'text',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer site configuration',
    'required' => TRUE,
    'schema field' => 'label',
  );
  $properties['description'] = array(
    'label' => t('Description'),
    'description' => t('A brief description of this type.'),
    'type' => 'text',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer site configuration',
    'schema field' => 'description',
  );

  return $info;
}
