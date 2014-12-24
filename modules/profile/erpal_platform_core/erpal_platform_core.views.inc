<?php

/**
 * @file
 * Views integration for Erpal Platform core.
 */

/**
 * Implements hook_views_data_alter().
 */
function erpal_platform_core_views_data_alter(&$data) {
  foreach ($data as $key => $views_data) {
    if (!empty($views_data['table']['entity type'])) {
      $data['erpal_budget']['erpal_entity_actions'] = array(
        'title' => t('Actions'),
        'help' => t('Provide actions links to entity.'),
        'field' => array(
          'handler' => 'erpal_platform_core_handler_erpal_entity_actions',
        ),
      );
    }
  }

}
