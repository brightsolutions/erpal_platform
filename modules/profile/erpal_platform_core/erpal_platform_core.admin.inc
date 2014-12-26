<?php

/**
 * @file
 * Settings for ERPAL platform.
 */

/**
 * Admin settings form for Vendor.
 */
function erpal_platform_core_settings_form($form, &$form_state) {
  $settings = variable_get('erpal_platform_core_messages', array());
  $form['erpal_platform_core_messages'] = array(
    '#tree' => TRUE,
    '#type' => 'fieldset',
    '#title' => t('messages settings'),
  );

  $form['erpal_platform_core_messages']['global'] = array(
    '#title' => t('Enable All messages'),
    '#type' => 'checkbox',
    '#default_value' => isset($settings['global']) ? $settings['global'] : TRUE,
    '#description' => t('Enable or disable All messages which shows after entity creation.'),
  );

  $info = entity_get_info();
  $settings = array_filter($settings);
  foreach ($info as $entity_name => $data) {
    $form['erpal_platform_core_messages'][$entity_name] = array(
      '#title' => t('Enable messages for !entity', array('!entity' => $data['label'])),
      '#type' => 'checkbox',
      '#default_value' => isset($settings[$entity_name]) ? $settings[$entity_name] : TRUE,
      '#description' => t('Enable or disable messages which shows after !entity creation.', array('!entity' => $data['label'])),
    );

    if (!isset($settings[$entity_name])) {
      $form['erpal_platform_core_messages'][$entity_name]['#states'] = array(
        'checked' => array(
          ':input[name="erpal_platform_core_messages[global]"]' => array('checked' => TRUE),
        ),
      );
    }

  }

  return system_settings_form($form);
}
