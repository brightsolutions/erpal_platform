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
 * Forces to set the erpal_maintenance theme during the installation.
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
 * Add additional install tasks.
 */
function erpal_platform_install_tasks() {
  $tasks = array();

  // Remove all messages we don't need them.
  drupal_get_messages('status', TRUE);

  if (!drupal_is_cli()) {
    $tasks['erpal_platform_vendor_form'] = array(
      'display_name' => st('Vendor information'),
      'display' => TRUE,
      'type' => 'form',
    );
  }

  return $tasks;
}

/**
 * Installation task "Vendor information".
 */
function erpal_platform_vendor_form($form, &$form_state) {
  drupal_set_title(st('Vendor information'));
  module_load_include('inc', 'locale', 'locale');
  $countries = country_get_list();
  // Get all currencies.
  $currencies = array();
  foreach (commerce_currencies() as $code => $currency) {
    $currencies[$code] = $currency['name'];
  }

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
  $form['vendor']['currency'] = array(
    '#title' => st('Default currency'),
    '#type' => 'select',
    '#description' => st('Select the default currency.'),
    '#options' => $currencies,
    '#default_value' => array('EUR'),
    '#required' => TRUE,
  );
  $form['vendor']['vat_rate'] = array(
    '#title' => st('Default VAT rate'),
    '#type' => 'textfield',
    '#description' => st('Enter the default VAT rate for your country. Format should be like: ".19" for a rate of 19%'),
    '#maxlength' => 255,
    '#required' => TRUE,
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
function erpal_platform_vendor_form_validate($form, $form_state) {
  $vendor = $form_state['values']['vendor'];

  if (!empty($vendor['vendor_email']['email']) && !valid_email_address($vendor['vendor_email']['email'])) {
    form_set_error('email', st('The Email-address is not valid!'));
  }

  if (!empty($vendor['vat_rate']) && $vendor['vat_rate'][0] != '.') {
    form_set_error('vat_rate', st('Incorrect format of VAT rate. Please look description.'));
  }
}

/**
 * Submit handler for "Vendor information" form.
 */
function erpal_platform_vendor_form_submit($form, $form_state) {
  module_load_include('inc', 'entity', 'includes/entity.controller');
  global $user;
  $vendor = $form_state['values']['vendor'];
  $vendor_address = $vendor['vendor_address'];
  $entity_type = 'crm_core_contact';
  $entity = crm_core_contact_create(array('type' => 'organization'));

  // Privacy public.
  $privacy = 2;

  // Create phone field collection.
  $phone = entity_create('field_collection_item', array('field_name' => 'field_contact_phone_bundle'));
  $phone->setHostEntity($entity_type, $entity);
  $phone = entity_metadata_wrapper('field_collection_item', $phone);
  $phone->field_contact_phone->set($vendor['vendor_phone']['phone']);
  $phone->field_contact_data_privacy->set($privacy);
  $phone->save(TRUE);

  // Create email field collection.
  $email = entity_create('field_collection_item', array('field_name' => 'field_contact_email_bundle'));
  $email->setHostEntity($entity_type, $entity);
  $email = entity_metadata_wrapper('field_collection_item', $email);
  $email->field_contact_email->set($vendor['vendor_email']['email']);
  $email->field_contact_data_privacy->set($privacy);
  $email->save(TRUE);

  // Create customer profile.
  $profile = commerce_customer_profile_new('billing');
  $profile->uid = $user->uid;

  // Take field language.
  $lang = field_language('commerce_customer_profile', $profile, 'commerce_customer_address');
  $profile->commerce_customer_address[$lang][0]['country'] = $vendor_address['country'];
  $profile->commerce_customer_address[$lang][0]['name_line'] = $vendor_address['fullname'];
  $profile->commerce_customer_address[$lang][0]['first_name'] = $vendor_address['fullname'];
  $profile->commerce_customer_address[$lang][0]['locality'] = $vendor_address['city'];
  $profile->commerce_customer_address[$lang][0]['thoroughfare'] = $vendor_address['street'];
  $profile->commerce_customer_address[$lang][0]['postal_code'] = $vendor_address['postal_code'];
  commerce_customer_profile_save($profile);

  // Take field language.
  $lang = field_language('crm_core_contact', $entity, 'contact_name');
  $entity->contact_name[$lang][0]['family'] = $vendor['organization'];
  $entity->contact_name[$lang][0]['safe']['family'] = $vendor['organization'];

  // Add customer profile to crm contact.
  $lang = field_language('crm_core_contact', $entity, 'field_customer_profiles');
  $entity->field_customer_profiles[$lang][0]['target_id'] = $profile->profile_id;

  crm_core_contact_save($entity);

  // Add first reference between user 1 and vendor (CRM Contact) that just has
  // been just created.
  $account = user_load(1);
  $field_contact = 'field_user_crm_contact';
  $field_language = field_language('user', $account, $field_contact);
  $account->{$field_contact}[$field_language][]['target_id'] = 1;
  user_save($account);

  // Set default vendor.
  $settings = array(
    'vendor_id' => $entity->contact_id,
    'customer_profile_id' => $profile->profile_id,
  );
  variable_set('erpal_vendor_settings', $settings);
  variable_set('erpal_currency_settings', $vendor['currency']);

  // Set default tax.
  $tax = array(
    'vat_rate' => $vendor['vat_rate'],
    'vat_rate_enable' => TRUE,
  );
  variable_set('erpal_vendor_settings', $settings);

  variable_set('commerce_default_currency', $vendor['currency']);
  variable_set('commerce_enabled_currencies', array($vendor['currency'] => $vendor['currency']));

}
