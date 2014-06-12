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

}
