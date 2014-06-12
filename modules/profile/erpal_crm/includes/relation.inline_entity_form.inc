<?php

/**
 * @file
 * Defines the payment modality inline entity form controller.
 */

class RelationInlineEntityFormController extends EntityInlineEntityFormController {

  /**
   * Returns an array of fields used to represent an entity in the IEF table.
   *
   * The fields can be either Field API fields or properties defined through
   * hook_entity_property_info().
   *
   * Modules can alter the output of this method through
   * hook_inline_entity_form_table_fields_alter().
   *
   * @param array $bundles
   *   An array of allowed bundles for this widget.
   *
   * @return array
   *   An array of field information, keyed by field name. Allowed keys:
   *   - type: 'field' or 'property',
   *   - label: Human readable name of the field, shown to the user.
   *   - weight: The position of the field relative to other fields.
   *   Special keys for type 'field', all optional:
   *   - formatter: The formatter used to display the field, or "hidden".
   *   - settings: An array passed to the formatter.
   *   If empty, defaults are used.
   *   - delta: If provided, limits the field to just the specified delta.
   */
  public function tableFields($bundles) {
    $fields = parent::tableFields($bundles);
    $fields['endpoints'] = array(
      'type' => 'field',
      'label' => 'Relation',
      'formatter' => 'relation_endpoint',
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
    global $user;
    $entity = $entity_form['#entity'];
    $values['crm_core_contact'] = $form_state['crm_core_contact'];
    $reverse = TRUE;
    $type = $entity->relation_type;
    $form_state['op'] = 'edit';
    $form_state['build_info']['files']['form'] = drupal_get_path('module', 'crm_core_relationship_ui') . 'crm_core_relationship_ui.pages.inc';
    if (empty($entity->rid)) {
      $form_state['op'] = 'add';
      $types = relation_get_types(array($type));
      $current_type = array_pop($types);
      // Default empty Relation.
      $values = array(
        'relation_type' => $type,
        'uid' => $user->uid,
        'title' => '',
        'reverse' => $reverse,
        'directional' => $current_type->directional,
        'r_unique' => $current_type->r_unique,
        'source_bundles' => $current_type->source_bundles,
        'target_bundles' => $current_type->target_bundles,
        'label' => $current_type->directional && $reverse ? $current_type->reverse_label : $current_type->label,
        'min_arity' => 2,
        'max_arity' => 2,
      );
      $entity = crm_core_relation_create($values);

    }

    $form_state['crm_core_relationship'] = $entity;
    module_load_include('inc', 'crm_core_relationship_ui', 'crm_core_relationship_ui.pages');

    $entity_form += crm_core_relationship_form($entity_form, $form_state, $entity);
    $entity_form['#after_build'] = array();
    $entity_form['endpoints'] = array(
      '#type' => 'value',
      '#value' => TRUE,
      '#language' => LANGUAGE_NONE,
    );
    return $entity_form;
  }

  /**
   * Validates the entity form.
   *
   * @param array $entity_form
   *   The entity form.
   * @param array $form_state
   *   The form state of the parent form.
   */
  public function entityFormValidate($entity_form, &$form_state) {
    $form_state['values'] += drupal_array_get_nested_value($form_state['values'], $entity_form['#parents']);
    module_load_include('inc', 'crm_core_relationship_ui', 'crm_core_relationship_ui.pages');
    crm_core_relationship_ui_add_relationship_form_validate($entity_form, $form_state);
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
    $form_state['values'] += drupal_array_get_nested_value($form_state['values'], $entity_form['#parents']);
    module_load_include('inc', 'crm_core_relationship_ui', 'crm_core_relationship_ui.pages');
    $entity_form['#entity'] = $form_state['relation'];
    crm_core_relationship_ui_add_relationship_form_submit($entity_form, $form_state);
  }

  /**
   * Permanently saves the given entity.
   *
   * @param object $entity
   *   The entity to save.
   * @param array $context
   *   Available keys:
   *   - parent_entity_type: The type of the parent entity.
   *   - parent_entity: The parent entity.
   */
  public function save($entity, $context) {
    // Just rediclare.
  }
}
