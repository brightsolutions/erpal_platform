<?php

/**
 * @file
 * Defines the inline entity form controller for ErpalCommerce Line Items.
 */

class ErpalCommerceLineItemInlineEntityFormController extends CommerceLineItemInlineEntityFormController {

  /**
   * Overrides EntityInlineEntityFormController::tableFields().
   */
  public function tableFields($bundles) {
    $fields = parent::tableFields($bundles);

    $fields['field_payment_modality'] = array(
      'type' => 'field',
      'label' => t('Payment modality'),
      'weight' => 5,
    );

    return $fields;
  }

  /**
   * Returns an array of default settings in the form of key => value.
   */
  public function defaultSettings() {
    $defaults = parent::defaultSettings();
    $defaults['allow_existing'] = TRUE;
    $defaults['match_operator'] = 'CONTAINS';

    return $defaults;
  }

  /**
   * Overrides EntityInlineEntityFormController::settingsForm().
   */
  public function settingsForm($field, $instance) {
    $form = parent::settingsForm($field, $instance);

    // Adding existing entities is not supported for line items.
    $form['allow_existing']['#access'] = TRUE;
    $form['match_operator']['#access'] = TRUE;

    return $form;
  }
}
