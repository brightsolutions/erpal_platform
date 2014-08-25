<?php

/**
 * @file
 * Adds fields to the payment modality entity type used by ERPAL Core.
 */

/**
 * Define the default fields for the ERPAL payment modality entity type.
 *
 * @return array
 *   Return default fields to be attached to newly created payment modality
 *   type.
 *
 * @see field_create_field()
 * @see field_create_instance()
 */
function erpal_payment_modality_add_default_fields() {
  $fields = array();
  $instances = array();

  // Exported field_base: 'field_amount'
  $fields[] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_amount',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_amount_type'
  $fields[] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_amount_type',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'total' => 'Total',
        'percent' => 'Percent',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_due_with'
  $fields[] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_due_with',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'order' => 'Order',
        'delivery' => 'Delivery',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_payment_modality'
  $fields[] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_payment_modality',
    'foreign keys' => array(
      'erpal_payment_modality' => array(
        'columns' => array(
          'target_id' => 'payment_modality_id',
        ),
        'table' => 'erpal_payment_modality',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'payment_modality' => 'payment_modality',
        ),
      ),
      'target_type' => 'erpal_payment_modality',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_instance:
  // 'erpal_payment_modality-payment_modality-field_amount'
  $instances[] = array(
    'bundle' => 'payment_modality',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'erpal_payment_modality',
    'field_name' => 'field_amount',
    'label' => 'Amount',
    'required' => 0,
    'settings' => array(
      'dfv' => array(
        'parent' => '',
        'status' => 0,
        'view' => '',
      ),
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => -4,
    ),
  );

  // Exported field_instance:
  // 'erpal_payment_modality-payment_modality-field_amount_type'
  $instances[] = array(
    'bundle' => 'payment_modality',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'erpal_payment_modality',
    'field_name' => 'field_amount_type',
    'label' => 'Amount type',
    'required' => 0,
    'settings' => array(
      'dfv' => array(
        'parent' => '',
        'status' => 0,
        'view' => '',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => -3,
    ),
  );

  // Exported field_instance:
  // 'erpal_payment_modality-payment_modality-field_due_with'
  $instances[] = array(
    'bundle' => 'payment_modality',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'erpal_payment_modality',
    'field_name' => 'field_due_with',
    'label' => 'Due with',
    'required' => 0,
    'settings' => array(
      'dfv' => array(
        'parent' => '',
        'status' => 0,
        'view' => '',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => -2,
    ),
  );

  // Exported field_instance:
  // 'commerce_line_item-product-field_payment_modality'
  $instances[] = array(
    'bundle' => 'product',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_payment_modality',
    'label' => 'Payment modality',
    'required' => 0,
    'settings' => array(
      'dfv' => array(
        'parent' => '',
        'status' => 0,
        'view' => '',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'inline_entity_form',
      'settings' => array(
        'fields' => array(),
        'type_settings' => array(
          'allow_existing' => 0,
          'delete_references' => 1,
          'label_plural' => 'payment modalities',
          'label_singular' => 'payment modality',
          'match_operator' => 'CONTAINS',
          'override_labels' => 0,
        ),
      ),
      'type' => 'inline_entity_form',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Amount');
  t('Amount type');
  t('Due with');

  return array(
    'fields' => $fields,
    'instances' => $instances,
  );
}
