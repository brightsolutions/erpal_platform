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
  $contacts = array('' => t('None'));
  $profiles = array('' => t('None'));

  // Get contacts list.
  $view = views_get_view('erpal_crm_contacts');
  $view->set_display('panel_pane_4');
  $view->pre_execute();
  $view->execute();

  if (isset($view->result)) {
    foreach ($view->result as $contact) {
      $contacts[$contact->contact_id] = $contact->field_contact_name[0]['raw']['family'];
    }
  }

  if (isset($form_state['triggering_element']) || !empty($settings['vendor_id'])) {

    // Get profiles list.
    $param = isset($form_state['values']) ? $form_state['values']['erpal_vendor_settings']['vendor_id'] : $settings['vendor_id'];
    $view = views_get_view('erpal_customer_profile');
    $view->set_display('dfv_1');
    $view->set_arguments(array($param));
    $view->pre_execute();
    $view->execute();

    if (isset($view->result)) {
      foreach ($view->result as $profile) {
        $str = array();
        foreach ($profile as $field) {
          $str[] = $field;
        }
        $profiles[$profile->profile_id] = implode(' - ', $str);
      }
    }
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
    '#type' => 'select',
    '#title' => t('Vendor'),
    '#default_value' => isset($settings['vendor_id']) ? $settings['vendor_id'] : '',
    '#options' => $contacts,
    '#ajax' => $ajax,
    '#required' => TRUE,
  );
  $form['erpal_vendor_settings']['customer_profile_id'] = array(
    '#type' => 'select',
    '#title' => t('Vendor address'),
    '#default_value' => isset($settings['customer_profile_id']) ? $settings['customer_profile_id'] : '',
    '#options' => $profiles,
  );

  $form = system_settings_form($form);
  // Use custom submit handler.
  $form['#submit'] = array('erpal_commerce_vendor_settings_form_submit');
  return $form;
}

/**
 * Submit handler for settings form.
 */
function erpal_commerce_vendor_settings_form_submit($form, $form_state) {
  $settings = array();
  foreach ($form_state['values']['erpal_vendor_settings'] as $key => $value) {
    $settings[$key] = $value;
  }
  variable_set('erpal_vendor_settings', $settings);

  drupal_set_message(t('The configuration options have been saved.'));
}

/**
 * Ajax callback function.
 */
function erpal_commerce_vendor_settings_form_field_callback($form, &$form_state) {
  return $form;
}
