<?php

/**
 * @file
 * Settings for Erpal billable platform.
 */

/**
 * Admin settings form for order pdf.
 */
function erpal_commerce_ui_pdf_admin_form($form, &$form_state) {

  $settings = variable_get('erpal_order_pdf_text_settings', array());

  $form['erpal_order_pdf_settings'] = array(
    '#tree' => TRUE,
    '#type' => 'fieldset',
    '#title' => t('PDF Text settings'),
  );

  $form['erpal_order_pdf_settings']['order_header'] = array(
    '#type' => 'textarea',
    '#title' => t('Order header'),
    '#default_value' => isset($settings['order_header']) ? $settings['order_header'] : '',
    '#description' => t('This field will be ignored if vendor field filled.'),
  );
  $form['erpal_order_pdf_settings']['order_location'] = array(
    '#type' => 'textfield',
    '#title' => t('Location'),
    '#default_value' => isset($settings['order_location']) ? $settings['order_location'] : '',
    '#description' => t('This field will be ignored if vendor field filled.'),
  );
  $form['erpal_order_pdf_settings']['order_date_format'] = array(
    '#type' => 'textfield',
    '#title' => t('Date format'),
    '#default_value' => isset($settings['order_date_format']) ? $settings['order_date_format'] : 'Y-m-d',
  );
  $form['erpal_order_pdf_settings']['order_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Order text'),
    '#default_value' => isset($settings['order_text']) ? $settings['order_text'] : '',
  );
  $form['erpal_order_pdf_settings']['order_footer'] = array(
    '#type' => 'textarea',
    '#title' => t('Order footer'),
    '#default_value' => isset($settings['order_footer']) ? $settings['order_footer'] : '',
    '#description' => t('This field will be ignored if vendor field filled.'),
  );

  $form['erpal_order_pdf_logo'] = array(
    '#type' => 'textfield',
    '#title' => t('Logo'),
    '#default_value' => variable_get('erpal_order_pdf_logo', 'misc/druplicon.png'),
    '#required' => TRUE,
    '#description' => t('Path to invoice logo.'),
  );

  $css_files = variable_get('erpal_order_pdf_css_files');
  $default_value = "";
  foreach ($css_files as $file) {
    $default_value .= $file . "\n";
  }
  $form['erpal_order_pdf_css_files'] = array(
    '#type' => 'textarea',
    '#title' => t('Inline CSS files'),
    '#default_value' => $default_value,
    '#required' => TRUE,
    '#description' => t('One CSS file per line.'),
  );
  $form['tokens'] = array(
    '#type' => 'fieldset',
    '#title' => t('Replacement patterns'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => theme('token_tree', array('token_types' => array('commerce-order'))),
    '#weight' => 10,
  );
  $form = system_settings_form($form);
  // Use custom submit handler.
  $form['#submit'] = array('erpal_commerce_ui_pdf_admin_form_submit');
  return $form;
}

/**
 * Submit handler for settings form.
 */
function erpal_commerce_ui_pdf_admin_form_submit($form, $form_state) {
  $settings = array();
  foreach ($form_state['values']['erpal_order_pdf_settings'] as $key => $value) {
    $settings[$key] = $value;
  }
  variable_set('erpal_order_pdf_text_settings', $settings);

  $css_files = array();
  foreach (explode("\n", $form_state['values']['erpal_order_pdf_css_files']) as $file) {
    $file = trim($file);
    if (!empty($file)) {
      $css_files[] = $file;
    }
  }
  variable_set('erpal_order_pdf_css_files', $css_files);

  variable_set('erpal_order_pdf_logo', $form_state['values']['erpal_order_pdf_logo']);
  drupal_set_message(t('The configuration options have been saved.'));
}
