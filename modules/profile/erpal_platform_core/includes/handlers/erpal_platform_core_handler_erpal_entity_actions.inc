<?php

/**
 * @file
 * Definition of erpal_platform_core_handler_erpal_entity_actions.
 */

/**
 * A handler to provide a field that is provide entity action links.
 *
 * @ingroup views_field_handlers
 */
class erpal_platform_core_handler_erpal_entity_actions extends views_handler_field_entity {

  function render($values) {
    $entity = $this->get_value($values);
    if ($entity) {

      // Take entity uri.
      $uri = entity_uri($this->entity_type, $entity);
      $actions = array();

      // Generate edit link.
      if (!empty($uri['path']) && entity_access('edit', $this->entity_type, $entity)) {
        $actions[] = array(
          'title' => t('Edit'),
          'href' => $uri['path'] . '/edit',
          'attributes' => array('class' => array('edit')),
        );
      }

      // Generate view link.
      if (!empty($uri['path']) && entity_access('view', $this->entity_type, $entity)) {
        $actions[] = array(
          'title' => t('View'),
          'href' => $uri['path'],
          'attributes' => array('class' => array('view')),
        );
      }

      // Generate delete link.
      if (!empty($uri['path']) && entity_access('delete', $this->entity_type, $entity)) {
        $actions[] = array(
          'title' => t('Delete'),
          'href' => $uri['path'] . '/delete',
          'attributes' => array('class' => array('delete')),
        );
      }

      // Prepare render array.
      $data = array(
        '#theme' => 'links__ctools_dropbutton',
        '#links' => $actions,
      );

      return array(
        '#theme' => 'erpal_entity_actions',
        '#actions' => $data,
      );
    }
  }
}
