<?php

/**
 * @file
 * Defines the payment modality inline entity form controller.
 */

class ErpalPaymentModalityInlineEntityFormController extends EntityInlineEntityFormController {

  /**
   * Returns the entity form to be shown through the IEF widget.
   *
   * When adding data to $form_state it should be noted that there can be
   * several IEF widgets on one master form, each with several form rows,
   * leading to possible key collisions if the keys are not prefixed with
   * $entity_form['#parents'].
   *
   * @param array $entity_form
   *   The entity form.
   * @param array $form_state
   *   The form state of the parent form.
   */
  public function entityForm($entity_form, &$form_state) {
    $entity = $entity_form['#entity'];
    module_load_include('inc', 'erpal_payment_modality', 'erpal_payment_modality.pages');
    $entity_form += erpal_payment_modality_form($entity_form, $form_state, $entity);

    return $entity_form;
  }

  /**
   * Handles the submission of an entity form.
   *
   * Prepares the entity stored in $entity_form['#entity'] for saving by copying
   * the values from the form to matching properties and, if the entity is
   * fieldable, invoking Field API submit.
   *
   * @param array $entity_form
   *   The entity form.
   * @param array $form_state
   *   The form state of the parent form.
   */
  public function entityFormSubmit(&$entity_form, &$form_state) {
    parent::entityFormSubmit($entity_form, $form_state);
    $entity = $entity_form['#entity'];
    $entity_values = drupal_array_get_nested_value($form_state['values'], $entity_form['#parents']);

    $entity->title = $entity_values['title'];
    $entity->uid = $entity_values['uid'];
    erpal_payment_modality_title($entity);

    if (!empty($payment_modality->created)) {
      $payment_modality->created = REQUEST_TIME;
    }
  }

}
