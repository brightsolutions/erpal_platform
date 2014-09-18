<?php

/**
 * @file
 * Defines the inline entity form controller for ErpalCommerce Line Items.
 */

class CommerceCustomerProfileInlineEntityFormController extends EntityInlineEntityFormController {

  /**
   * Overrides EntityInlineEntityFormController::tableFields().
   */
  public function tableFields($bundles) {
    $fields['commerce_customer_address'] = array(
      'type' => 'field',
      'label' => t('Address'),
      'weight' => 5,
    );

    return $fields;
  }

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
    $info = entity_get_info($this->entityType);
    $entity = $entity_form['#entity'];
    if (!empty($info['fieldable'])) {
      $langcode = entity_language($this->entityType, $entity);
      if (!empty($form_state['values'])) {
        unset($form_state['addressfield']);
      }
      field_attach_form($this->entityType, $entity, $entity_form, $form_state, $langcode);
    }

    return $entity_form;
  }
}
