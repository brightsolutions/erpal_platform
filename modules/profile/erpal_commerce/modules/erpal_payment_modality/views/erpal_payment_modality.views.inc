<?php

/**
 * @file
 * Views integration for Erpal payment modality entity.
 */

/**
 * Implements hook_views_data_alter().
 */
function erpal_payment_modality_views_data_alter(&$data) {
  $data['views_entity_erpal_payment_modality']['erpal_payment_modality_full_label'] = array(
    'field' => array(
      'title' => t('Full label'),
      'handler' => 'erpal_payment_modality_full_label_handler',
      'help' => t('Full label of erpal payment modality.'),
    ),
  );
}
