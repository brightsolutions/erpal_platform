<?php

/**
 * @file
 * Settings for Invoice.
 */

/**
* Implements hook_form_FORM_ID_alter().
*/
function erpal_commerce_ui_form_field_ui_widget_type_form_alter(&$form, &$form_state, $form_id) {
  $field = field_info_field($form['#field_name']);
  if ($field['type'] == 'commerce_line_item_reference') {
    $instance = field_info_instance($form['#entity_type'], $form['#field_name'], $form['#bundle']);
    $settings = $instance['widget']['settings'];

    $form['billable'] = array(
      '#type' => 'checkbox',
      '#title' => t('Billable line item'),
      '#default_value' => isset($settings['billable']) ? $settings['billable'] : 0,
      '#weight' => 10,
      '#description' => t('Defines if Line item can be billable.'),
    );
    $form['#submit'][] = 'erpal_commerce_ui_line_item_settings_submit';
  }
}

/**
 * Submit callback; updates the field settings.
 */
function erpal_commerce_ui_line_item_settings_submit(&$form, &$form_state) {
  $form_values = $form_state['values'];
  $bundle = $form['#bundle'];
  $entity_type = $form['#entity_type'];
  $field_name = $form['#field_name'];

  // Retrieve the stored instance settings to merge with the incoming values.
  $instance = field_read_instance($entity_type, $field_name, $bundle);
  $instance['widget']['settings']['billable'] = isset($form_values['billable']) ? $form_values['billable'] : 0;

  try {
    field_update_instance($instance);
  }
  catch (Exception $e) {
    drupal_set_message(t('There was a problem changing the widget for field %label.', array('%label' => $instance['label'])), 'error');
  }
}

/**
 * Hide useful fields if line item is billable.
 */
function erpal_commerce_ui_field_widget_form_alter(&$element, &$form_state, $context) {
  if ($context['field']['type'] == 'commerce_line_item_reference') {

    if (!empty($context['instance']['widget']['settings']['billable'])) {
      $language = $element['field_line_item_billable']['#language'];
      $element['field_line_item_billable'][$language]['#value'] = 1;
    }
    else {
      $hide_fields = array('field_line_item_order', 'field_line_item_delivery_date');
      foreach ($hide_fields as $field_name) {
        $element[$field_name]['#access'] = FALSE;
      }
    }
  }
}
