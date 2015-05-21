<?php

/**
 * @file
 * Views handler for pdf link.
 */

/**
 * Simple entity generic views handler for a invoice PDF link.
 */
class erpal_payment_modality_full_label_handler extends views_handler_field_entity {

  /**
   * Render the field.
   *
   * @param array $values
   *   The values retrieved from the database.
   */
  public function render($values) {
    if ($entity = $this->get_value($values)) {
      return erpal_payment_modality_label($entity);
    }
  }

}
