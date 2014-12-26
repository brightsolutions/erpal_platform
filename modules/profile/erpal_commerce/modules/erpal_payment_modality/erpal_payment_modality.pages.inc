
<?php

/**
 * @file
 * User page callbacks for the payment modality UI module.
 */

/**
 * Create new ERPAL payment modality entity and pass it to entity_ui_get_form().
 *
 * @param string $type
 *   payment_modality type.
 */
function erpal_payment_modality_entity_ui_get_form_wrapper($type) {
  $values = array('type' => $type);
  $payment_modality = entity_create('erpal_payment_modality', $values);
  return entity_ui_get_form('erpal_payment_modality', $payment_modality, 'add');
}

/**
 * Form builder for ERPAL payment modality forms.
 */
function erpal_payment_modality_form($form, &$form_state, $payment_modality) {
  // Ensure this include file is loaded when the form is rebuilt from the cache.
  $form_state['build_info']['files'][] = drupal_get_path('module', 'erpal_payment_modality') . '/erpal_payment_modality.pages.inc';

  $form['title_default'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto generate title'),
    '#default_value' => TRUE,
  );

  $form['title'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Title'),
    '#default_value' => $payment_modality->title,
    '#states' => array(
      'visible' => array(
        'input[name="title_default"]' => array('checked' => FALSE)
      )
    ),
    '#description' => t('In title field you can use such tokens: <br> !due_with - will be replaced with value from "Due with" field <br> !amount - will be replaced with value from "Amount" field <br> !amount_type - will be replaced with value from "Amount type" field (like a "%").'),
  );

  $form['uid'] = array(
    '#type' => 'value',
    '#value' => $payment_modality->uid,
  );

  field_attach_form('erpal_payment_modality', $payment_modality, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 40,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save payment modality'),
    '#submit' => $submit + array('erpal_payment_modality_form_submit'),
  );

  $query = drupal_get_query_parameters();
  // Show delete button if entity exists and user has appropriate permission.
  if (empty($query['render']) && isset($form_state['op']) && $form_state['op'] == 'edit' && entity_access('delete', 'erpal_payment_modality', $payment_modality)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('erpal_payment_modality_form_submit_delete'),
    );
  }

  // Set title.
  if (isset($form_state['op']) && $form_state['op'] == 'add') {
    $erpal_payment_modality_type = erpal_payment_modality_types($payment_modality->type);
    drupal_set_title(t('Add new payment modality @label', array('@label' => $erpal_payment_modality_type->label)));
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'erpal_payment_modality_form_validate';

  return $form;
}

/**
 * Validation callback for erpal_payment_modality_form.
 */
function erpal_payment_modality_form_validate($form, &$form_state) {
  $payment_modality = $form_state['erpal_payment_modality'];

  // Notify field widgets to validate their data.
  field_attach_form_validate('erpal_payment_modality', $payment_modality, $form, $form_state);
}

/**
 * Submit callback for erpal_payment_modality_form.
 */
function erpal_payment_modality_form_submit($form, &$form_state) {
  $payment_modality = $form_state['erpal_payment_modality'];

  $payment_modality->title = $form_state['values']['title'];
  $payment_modality->uid = $form_state['values']['uid'];

  if (!empty($payment_modality->created)) {
    $payment_modality->created = REQUEST_TIME;
  }

  // Notify field widgets.
  field_attach_submit('erpal_payment_modality', $payment_modality, $form, $form_state);

  erpal_payment_modality_save($payment_modality);

  // Show message to user.
  if ($form_state['op'] == 'add') {
    drupal_set_message(t('payment_modality %title created.', array('%title' => $payment_modality->title)));
  }
  elseif ($form_state['op'] == 'edit') {
    drupal_set_message(t('payment_modality %title edited.', array('%title' => $payment_modality->title)));
  }

  $form_state['redirect'] = 'erpal/payment-modality/' . $payment_modality->payment_modality_id;
}

/**
 * Submit handler for Delete button.
 *
 * Redirect to delete confirmation page.
 */
function erpal_payment_modality_form_submit_delete($form, &$form_state) {
  $destination = array();
  if (isset($_GET['destination'])) {
    $destination = drupal_get_destination();
    unset($_GET['destination']);
  }
  $payment_modality = $form_state['erpal_payment_modality'];
  $form_state['redirect'] = array(
    'erpal/payment-modality/' . $payment_modality->payment_modality_id . '/delete',
    array(
      'query' => $destination,
    ),
  );
}

/**
 * Delete payment modality form confirmation.
 */
function erpal_payment_modality_form_delete_confirm($form, &$form_state, $payment_modality) {
  $form_state['payment_modality'] = $payment_modality;
  // Always provide entity id in the same form key as in the entity edit form.
  $form['payment_modality_id'] = array(
    '#type' => 'value',
    '#value' => $payment_modality->payment_modality_id,
  );

  return confirm_form($form,
    t('Are you sure you want to delete payment modality %title?', array('%title' => $payment_modality->title)),
    'erpal/payment-modality/' . $payment_modality->payment_modality_id,
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Execute node deletion.
 */
function erpal_payment_modality_form_delete_confirm_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    $payment_modality = $form_state['payment_modality'];
    erpal_payment_modality_delete($payment_modality);

    watchdog('erpal_payment_modality', '@type: deleted %title.', array(
      '@type' => $payment_modality->type,
      '%title' => $payment_modality->title,
    ));
    drupal_set_message(t('@type %title has been deleted.', array(
      '@type' => erpal_payment_modality_type_get_name($payment_modality->type),
      '%title' => $payment_modality->title,
    )));
  }
  $destination = drupal_get_destination();
  $current_path = drupal_get_path_alias();
  if ($destination['destination'] == $current_path) {
    drupal_goto('erpal');
  }
  else {
    drupal_goto($destination);
  }
}

/**
 * Add payment modality page callback.
 *
 * @return string
 *   payment modality types list or empty text.
 */
function erpal_payment_modality_add_payment_modality() {

  global $user;
  $items = array();

  // Work around core issue where 'title' isn't set for MENU_LOCAL_ACTION,
  // see: http://drupal.org/node/891892
  $trail = menu_get_active_trail();
  drupal_set_title($trail[count($trail) - 1]['title']);

  foreach (erpal_payment_modality_types() as $info) {
    if (entity_access('create', 'erpal_payment_modality', $info->type, $user)) {
      $items[] = array(
        'title' => $info->label,
        'href' => 'erpal/payment-modality/add/' . $info->type,
        'localized_options' => array(),
        'description' => $info->description,
      );
    }
  }

  if (count($items) == 1) {
    drupal_goto($items[0]['href'], $items[0]);
  }

  return empty($items) ? t('It is not possible to create payment modality entities yet. Please create an payment modality type first.') : theme('erpal_core_ui_add_list', array('content' => $items));
}
