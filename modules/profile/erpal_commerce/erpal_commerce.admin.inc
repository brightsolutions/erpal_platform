<?php

/**
 * @file
 * Settings for ERPAL Vendor.
 */

/**
 * Admin settings form for Vendor.
 */
function erpal_commerce_vendor_settings_form($form, &$form_state) {
  $settings = variable_get('erpal_vendor_settings', array());
  $profiles = array('' => t('None'));


  if (isset($form_state['triggering_element']) || !empty($settings['vendor_id'])) {

    // Get profiles list.
    $param = isset($form_state['values']) ? $form_state['values']['erpal_vendor_settings']['vendor_id'] : $settings['vendor_id'];
    $profiles = erpal_commerce_get_profiles($param);
  }

  // Get all currencies.
  $currencies = array();
  foreach (commerce_currencies() as $code => $currency) {
    $currencies[$code] = $currency['name'];
  }

  // Ajax settings array.
  $ajax = array(
    'callback' => 'erpal_commerce_vendor_settings_form_field_callback',
    'wrapper' => 'ajax-form-wrapper',
  );
  $form['#prefix'] = '<div id="ajax-form-wrapper">';
  $form['#suffix'] = '</div>';
  $form['erpal_vendor_settings'] = array(
    '#tree' => TRUE,
    '#type' => 'fieldset',
    '#title' => t('Vendor settings'),
  );
  $form['erpal_vendor_settings']['vendor_id'] = array(
    '#type' => 'entity_autocomplete',
    '#title' => t('Vendor'),
    '#default_value' => isset($settings['vendor_id']) ? $settings['vendor_id'] : '',
    '#entity_type' => 'crm_core_contact',
    '#ajax' => $ajax,
    '#required' => TRUE,
  );
  $form['erpal_vendor_settings']['customer_profile_id'] = array(
    '#type' => 'select',
    '#title' => t('Vendor address'),
    '#default_value' => isset($settings['customer_profile_id']) ? $settings['customer_profile_id'] : '',
    '#options' => $profiles,
  );

  // Settings for erpal currencies.
  $currency = variable_get('erpal_currency_settings', array());
  $form['erpal_currency_settings'] = array(
    '#type' => 'select',
    '#title' => t('Default currency'),
    '#default_value' => !empty($currency) ? $currency : '',
    '#options' => $currencies,
    '#required' => TRUE,
  );

  // Settings for erpal currencies.
  $tax = variable_get('erpal_tax_settings', array());
  $form['erpal_tax_settings'] = array(
    '#tree' => TRUE,
    '#type' => 'fieldset',
    '#title' => t('Tax settings'),
  );
  $form['erpal_tax_settings']['vat_rate_enable'] = array(
    '#title' => st('Enable Default VAT rate'),
    '#type' => 'checkbox',
    '#default_value' => isset($tax['vat_rate_enable']) ? $tax['vat_rate_enable'] : TRUE,
    '#description' => st('Enable or disable default VAT rate on site.'),
  );
  $form['erpal_tax_settings']['vat_rate'] = array(
    '#title' => st('Default VAT rate'),
    '#type' => 'textfield',
    '#default_value' => isset($tax['vat_rate']) ? $tax['vat_rate'] : '',
    '#description' => st('Enter the default VAT rate in percent for your country.'),
    '#maxlength' => 255,
    '#required' => TRUE,
    '#states' => array(
      'visible' => array(
        ':input[name="erpal_vendor_settings[vat_rate_enable]"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['erpal_tax_settings']['vat_rate_eu'] = array(
    '#markup' => t('If you want to use <a href="@module_url">Commerce European Union VAT</a> module you should change "Default country" field on <a href="@admin_url">admin page</a> to country for which you enabled Commerce EU VAT module.',
      array(
        '@module_url' => 'https://www.drupal.org/project/commerce_eu_vat',
        '@admin_url' => '/admin/config/regional/settings',
      )
    ),
  );
  $form = system_settings_form($form);
  // Use custom submit handler.
  $form['#submit'][] = 'erpal_commerce_vendor_settings_form_submit';
  return $form;
}

/**
 * Submit handler for settings form.
 */
function erpal_commerce_vendor_settings_form_submit($form, $form_state) {
// TODO: Only needed if entityreference_autcomplete module is used.
//  dpm($form_state['values'], 'values');
//  $vendor_ids = $form_state['values']['erpal_vendor_settings']['vendor_id']['entity_id'];
//  $profile_id = $form_state['values']['erpal_vendor_settings']['customer_profile_id'];
//  $settings = array(
//    'vendor_id' => $vendor_ids[0],
//    'customer_profile_id' => $profile_id,
//  );
//  variable_set('erpal_vendor_settings', $settings);
//
  variable_set('commerce_default_currency', $form_state['values']['erpal_currency_settings']);
  drupal_set_message(t('The configuration options have been saved.'));
}

/**
 * Ajax callback function.
 */
function erpal_commerce_vendor_settings_form_field_callback($form, &$form_state) {
  return $form;
}
