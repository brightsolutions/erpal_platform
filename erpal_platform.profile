<?php
/**
 * @file
 * Enables modules and site configuration for a erpal platform site installation.
 */

/**
 * Implements hook_install_tasks_alter().
 */
function erpal_platform_install_tasks_alter(&$tasks, $install_state) {
  $tasks['install_select_profile']['display'] = FALSE;

  _erpal_platform_set_theme('erpal_maintenance');
}


/**
 * Forces to set the erpal_maintenance theme during the installation
 */
function _erpal_platform_set_theme($target_theme) {
  if ($GLOBALS['theme'] != $target_theme) {
    unset($GLOBALS['theme']);
    drupal_static_reset();
    $GLOBALS['conf']['maintenance_theme'] = $target_theme;
    _drupal_maintenance_theme();
  }
}

/**
 * Add additional install tasks
 */
function erpal_platform_install_tasks(){
  $tasks = array();

  drupal_get_messages('status', TRUE); //remove all messages we don't need them

  $tasks['erpal_platform_vendor_form'] = array(
    'display_name' => st('Vendor information'),
    'display' => TRUE,
    'type' => 'form',
  );

  return $tasks;
}

/**
 * Installation task "Vendor information"
 */
function erpal_platform_vendor_form($form, &$form_state){
  drupal_set_title(st('Vendor information'));
  module_load_include('inc', 'locale', 'locale');
  $countries = country_get_list();
  $privacy = array(
    '' => st('- None -'),
    1 => 'privacy',
    2 => 'public',
  );

  $form = array();
  $form['vendor'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#title' => st('Vendor Information'),
  );
  $form['vendor']['organization'] = array(
    '#type' => 'textfield',
    '#title' => st('Organization:'),
    '#maxlength' => 255,
    '#required' => TRUE,
  );
  $form['vendor']['vendor_phone'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#title' => st('Phone'),
  );
  $form['vendor']['vendor_phone']['phone'] = array(
    '#title' => st('Phone:'),
    '#type' => 'textfield',
    '#maxlength' => 255,
  );
  $form['vendor']['vendor_phone']['privacy'] = array(
    '#title' => st('Data privacy:'),
    '#type' => 'select',
    '#options' => $privacy,
  );
  $form['vendor']['vendor_email'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#title' => st('Email'),
  );
  $form['vendor']['vendor_email']['email'] = array(
    '#title' => st('Email:'),
    '#type' => 'textfield',
    '#maxlength' => 255,
  );
  $form['vendor']['vendor_email']['privacy'] = array(
    '#title' => st('Data privacy:'),
    '#type' => 'select',
    '#options' => $privacy,
  );
  $form['vendor']['vendor_address'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#title' => st('Vendor Address'),
  );
  $form['vendor']['vendor_address']['fullname'] = array(
    '#title' => st('Full name:'),
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#required' => TRUE,
  );
  $form['vendor']['vendor_address']['country'] = array(
    '#title' => st('Country:'),
    '#type' => 'select',
    '#options' => $countries,
    '#default_value' => array('DE'),
    '#required' => TRUE,
  );
  $form['vendor']['vendor_address']['street'] = array(
    '#title' => st('Street:'),
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#required' => TRUE,
  );
  $form['vendor']['vendor_address']['city'] = array(
    '#title' => st('City:'),
    '#type' => 'textfield',
    '#maxlength' => 80,
    '#required' => TRUE,
  );
  $form['vendor']['vendor_address']['postal_code'] = array(
    '#title' => st('Postal Code:'),
    '#type' => 'textfield',
    '#maxlength' => 10,
  );
  $form['submit'] = array(
    '#value' => st('Save and continue'),
    '#type' => 'submit',
  );
  return $form;
}

/**
 * Validate handler for "Vendor information" form.
 */
function erpal_platform_vendor_form_validate($form, $form_state){
  $values = $form_state['values'];

  if (!valid_email_address($values['vendor']['vendor_email']['email'])) {
    form_set_error('email', st('The Email-address is not valid!'));
  }
}

/**
 * Submit handler for "Vendor information" form.
 */
function erpal_platform_vendor_form_submit($form, $form_state){
  module_load_include('inc', 'entity', 'includes/entity.controller');
  global $user;
  $vendor = $form_state['values']['vendor'];
  $vendor_address = $vendor['vendor_address'];
  $entity_type = "crm_core_contact";

  $entity = crm_core_contact_create(array('type' => 'organization'));

  // Create phone field collection.
  $phone = entity_create('field_collection_item', array('field_name' => 'field_contact_phone_bundle'));
  $phone->setHostEntity($entity_type, $entity);
  $phone = entity_metadata_wrapper('field_collection_item', $phone);
  $phone->field_contact_phone->set($vendor['vendor_phone']['phone']);
  $phone->field_contact_data_privacy->set($vendor['vendor_phone']['privacy']);
  $phone->save(TRUE);

  // Create email field collection.
  $email = entity_create('field_collection_item', array('field_name' => 'field_contact_email_bundle'));
  $email->setHostEntity($entity_type, $entity);
  $email = entity_metadata_wrapper('field_collection_item', $email);
  $email->field_contact_email->set($vendor['vendor_email']['email']);
  $email->field_contact_data_privacy->set($vendor['vendor_email']['privacy']);
  $email->save(TRUE);

  // Create customer profile.
  $profile = commerce_customer_profile_new('billing');
  $profile->uid = $user->uid;
  $profile->commerce_customer_address[LANGUAGE_NONE][0]['country'] = $vendor_address['country'];
  $profile->commerce_customer_address[LANGUAGE_NONE][0]['name_line'] = $vendor_address['fullname'];
  $profile->commerce_customer_address[LANGUAGE_NONE][0]['first_name'] = $vendor_address['fullname'];
  $profile->commerce_customer_address[LANGUAGE_NONE][0]['locality'] = $vendor_address['city'];
  $wrapper->commerce_customer_address[LANGUAGE_NONE][0]['thoroughfare'] = $vendor_address['street'];
  $profile->commerce_customer_address[LANGUAGE_NONE][0]['postal_code'] = $vendor_address['postal_code'];
  commerce_customer_profile_save($profile);

  $entity->contact_name[LANGUAGE_NONE][0]['family'] = $vendor['organization'];
  $entity->contact_name[LANGUAGE_NONE][0]['safe']['family'] = $vendor['organization'];
  $entity->field_customer_profiles[LANGUAGE_NONE][0]['target_id'] = $profile->profile_id;

  crm_core_contact_save($entity);
}
