<?php

/**
 * @file
 * Extends EntityAPIControllerInterface with classes for payment modalities.
 */

/**
 * ERPAL payment modalities Entity Class.
 */
class ERPALPaymentModalityEntity extends Entity {
  /**
   * Defines the entity label if the 'entity_class_label' callback is used.
   */
  protected function defaultLabel() {
    return $this->title;
  }

  /**
   * Override this in order to implement a custom default URI.
   */
  protected function defaultUri() {
    return array(
      'path' => 'erpal/payment-modality/' . $this->identifier(),
      'options' => array(
        'absolute' => TRUE,
      ),
    );
  }
}

/**
 * Controller class for ERPAL Payment Modality.
 */
class ERPALPaymentModalityController extends EntityAPIController {
  /**
   * Implements EntityAPIControllerInterface.
   */
  public function create(array $values = array()) {
    $values += array(
      'title' => variable_get('erpal_payment_modality_title', '!due_with !amount!amount_type'),
      'created' => REQUEST_TIME,
      'changed' => REQUEST_TIME,
      'uid' => $GLOBALS['user']->uid,
    );

    return parent::create($values);
  }

  /**
   * Update payment modality object before saving revision.
   */
  protected function saveRevision($entity) {
    $entity->is_new_revision = TRUE;

    return parent::saveRevision($entity);
  }

  /**
   * Update payment modality object before saving revision.
   */
  public function save($entity) {
    erpal_payment_modality_title($entity);

    return parent::save($entity);
  }
}

/**
 * Provides a class for Payment Modalities.
 *
 * Use a separate class so we can specify some defaults modules may be alter.
 */
class ERPALPaymentModalityType extends Entity {
  public $type;
  public $label;
  public $weight = 0;

  /**
   * Creates a new payment modality type.
   *
   * @see entity_create()
   */
  public function __construct($values = array()) {
    parent::__construct($values, 'erpal_payment_modality_type');
  }

  /**
   * Check Payment Modality status.
   */
  public function isLocked() {
    return isset($this->status) && empty($this->is_new) && (($this->status & ENTITY_IN_CODE) || ($this->status & ENTITY_FIXED));
  }
}

/**
 * Controller class for ERPAL Payment Modality Type.
 */
class ERPALPaymentModalityTypeController extends EntityAPIControllerExportable {
  /**
   * Implements EntityAPIControllerInterface.
   */
  public function create(array $values = array()) {
    $values += array(
      'type' => '',
      'label' => '',
      'description' => '',
      'is_new' => TRUE,
    );

    return parent::create($values);
  }

  /**
   * Implements EntityAPIControllerInterface.
   *
   * @param array $ids
   *   List of IDs.
   * @param object $transaction
   *   Optionally a DatabaseTransaction object to use. Allows overrides to pass
   *   in their transaction object.
   */
  public function delete($ids, DatabaseTransaction $transaction = NULL) {
    // Delete all instances of the given type.
    $query = new EntityFieldQuery();
    $results = $query
      ->entityCondition('entity_type', 'erpal_payment_modality')
      ->entityCondition('bundle', $ids, 'IN')
      ->execute();

    if (!empty($results)) {
      $payment_modalities_to_remove = array_keys($results['erpal_payment_modality']);
      erpal_payment_modality_delete_multiple($payment_modalities_to_remove);
      watchdog('erpal_payment_modality', 'Delete !count payment modalities due to deletion of payment modality type.', array('!count' => count($payment_modalities_to_remove)), WATCHDOG_INFO);
    }

    // Finally delete the type itself.
    return parent::delete($ids, $transaction);
  }
}
