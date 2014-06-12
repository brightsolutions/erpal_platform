<?php

/**
 * @file
 * Provides basic payment modality management functionality
 * in ERPAL payment modality.
 */

/**
 * Generates the payment modality type editing form.
 */
function erpal_payment_modality_type_form($form, &$form_state, $erpal_payment_modality_type, $op = 'edit') {

  if ($op == 'clone') {
    $erpal_payment_modality_type->label .= ' (cloned)';
    $erpal_payment_modality_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $erpal_payment_modality_type->label,
    '#description' => t('The human-readable name of this payment modality type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($erpal_payment_modality_type->type) ? $erpal_payment_modality_type->type : '',
    '#maxlength' => 32,
    '#disabled' => $erpal_payment_modality_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'erpal_payment_modality_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this payment_modality type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['description'] = array(
    '#type' => 'textarea',
    '#default_value' => isset($erpal_payment_modality_type->description) ? $erpal_payment_modality_type->description : '',
    '#description' => t('Description about the payment modality type.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save payment modality type'),
    '#weight' => 40,
  );

  if (!$erpal_payment_modality_type->isLocked() && $op != 'add') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete payment modality type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('erpal_payment_modality_type_form_submit_delete'),
    );
  }

  return $form;
}

/**
 * Submit handler for creating/editing erpal_payment_modality_type.
 */
function erpal_payment_modality_type_form_submit(&$form, &$form_state) {
  $erpal_payment_modality_type = entity_ui_form_submit_build_entity($form, $form_state);

  // Save and go back.
  $erpal_payment_modality_type->save();

  // Redirect user back to list of payment modality types.
  $form_state['redirect'] = 'admin/erpal/payment-modality-types';
}

/**
 * Submit handler for deletion button for erpal_payment_modality_type.
 */
function erpal_payment_modality_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/erpal/payment-modality-types/manage/' . $form_state['erpal_payment_modality_type']->type . '/delete';
}
