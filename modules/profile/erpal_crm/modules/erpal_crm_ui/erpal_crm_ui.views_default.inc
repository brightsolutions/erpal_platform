<?php

/**
 * @file
 * Contains default views for the ERPAL CRM UI module.
 */

/**
 * Implements hook_views_default_views().
 */
function erpal_crm_ui_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'erpal_crm_contacts';
  $view->description = 'Displays complete contact list and contacts by activity.';
  $view->tag = 'erpal_crm';
  $view->base_table = 'crm_core_contact';
  $view->human_name = 'ERPAL CRM Contacts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Customer';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any crm_core_contact entity';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'contact_id' => 'contact_id',
    'field_contact_picture' => 'field_contact_picture',
    'contact_name' => 'contact_name',
    'type' => 'type',
    'field_contact_email_bundle' => 'field_contact_email_bundle',
    'field_contact_phone_bundle' => 'field_contact_phone_bundle',
    'field_contact_url_bundle' => 'field_contact_url_bundle',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'contact_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_contact_picture' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'contact_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_contact_email_bundle' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_contact_phone_bundle' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_contact_url_bundle' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Currently there are no participiants of activity.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_activity_customer_crm_core_activity']['id'] = 'reverse_field_activity_customer_crm_core_activity';
  $handler->display->display_options['relationships']['reverse_field_activity_customer_crm_core_activity']['table'] = 'crm_core_contact';
  $handler->display->display_options['relationships']['reverse_field_activity_customer_crm_core_activity']['field'] = 'reverse_field_activity_customer_crm_core_activity';
  $handler->display->display_options['relationships']['reverse_field_activity_customer_crm_core_activity']['label'] = 'CRM Activity Customer';
  $handler->display->display_options['relationships']['reverse_field_activity_customer_crm_core_activity']['required'] = TRUE;
  /* Field: CRM Core Contact: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['label'] = '';
  $handler->display->display_options['fields']['contact_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['contact_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contact_id']['link_to_contact'] = 0;
  /* Field: CRM Core Contact: Logo */
  $handler->display->display_options['fields']['field_contact_picture']['id'] = 'field_contact_picture';
  $handler->display->display_options['fields']['field_contact_picture']['table'] = 'field_data_field_contact_picture';
  $handler->display->display_options['fields']['field_contact_picture']['field'] = 'field_contact_picture';
  $handler->display->display_options['fields']['field_contact_picture']['label'] = 'Picture';
  $handler->display->display_options['fields']['field_contact_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_contact_picture']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: CRM Core Contact: Household */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['label'] = 'Name';
  $handler->display->display_options['fields']['contact_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['contact_name']['alter']['path'] = 'crm-core/contact/[contact_id]';
  $handler->display->display_options['fields']['contact_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['contact_name']['settings'] = array(
    'format' => 'default',
    'markup' => 0,
    'output' => 'default',
    'multiple' => 'default',
    'multiple_delimiter' => ', ',
    'multiple_and' => 'text',
    'multiple_delimiter_precedes_last' => 'never',
    'multiple_el_al_min' => '3',
    'multiple_el_al_first' => '1',
  );
  /* Field: CRM Core Contact: Contact Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'crm_core_contact';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['link_to_contact_type'] = 0;
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
  /* Field: CRM Core Contact: Email */
  $handler->display->display_options['fields']['field_contact_email_bundle']['id'] = 'field_contact_email_bundle';
  $handler->display->display_options['fields']['field_contact_email_bundle']['table'] = 'field_data_field_contact_email_bundle';
  $handler->display->display_options['fields']['field_contact_email_bundle']['field'] = 'field_contact_email_bundle';
  $handler->display->display_options['fields']['field_contact_email_bundle']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_contact_email_bundle']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_contact_email_bundle']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_contact_email_bundle']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_contact_email_bundle']['separator'] = '<br/>';
  /* Field: CRM Core Contact: Phone */
  $handler->display->display_options['fields']['field_contact_phone_bundle']['id'] = 'field_contact_phone_bundle';
  $handler->display->display_options['fields']['field_contact_phone_bundle']['table'] = 'field_data_field_contact_phone_bundle';
  $handler->display->display_options['fields']['field_contact_phone_bundle']['field'] = 'field_contact_phone_bundle';
  $handler->display->display_options['fields']['field_contact_phone_bundle']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_contact_phone_bundle']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_contact_phone_bundle']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_contact_phone_bundle']['separator'] = '<br/>';
  /* Field: CRM Core Contact: URL */
  $handler->display->display_options['fields']['field_contact_url_bundle']['id'] = 'field_contact_url_bundle';
  $handler->display->display_options['fields']['field_contact_url_bundle']['table'] = 'field_data_field_contact_url_bundle';
  $handler->display->display_options['fields']['field_contact_url_bundle']['field'] = 'field_contact_url_bundle';
  $handler->display->display_options['fields']['field_contact_url_bundle']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_contact_url_bundle']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_contact_url_bundle']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_contact_url_bundle']['separator'] = '<br/>';
  /* Sort criterion: CRM Core Contact: Contact ID */
  $handler->display->display_options['sorts']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['sorts']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['sorts']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['sorts']['contact_id']['order'] = 'DESC';
  /* Filter criterion: CRM Core Contact: Household */
  $handler->display->display_options['filters']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['filters']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['filters']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['filters']['contact_name']['group'] = 1;
  $handler->display->display_options['filters']['contact_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['contact_name']['expose']['operator_id'] = 'contact_name_op';
  $handler->display->display_options['filters']['contact_name']['expose']['label'] = 'Contact name';
  $handler->display->display_options['filters']['contact_name']['expose']['operator'] = 'contact_name_op';
  $handler->display->display_options['filters']['contact_name']['expose']['identifier'] = 'contact_name';
  $handler->display->display_options['filters']['contact_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: CRM Core Contact: Contact Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_contact';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Contact type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  
  /* Display: Contact list */
  $handler = $view->new_display('panel_pane', 'Contact list', 'panel_pane_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Currently there are no contacts in a system.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['inherit_panels_path'] = '1';
  
  /* Display: Main contact of activity */
  $handler = $view->new_display('panel_pane', 'Main contact of activity', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Main contact';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_activity_main_contact_crm_core_activity']['id'] = 'reverse_field_activity_main_contact_crm_core_activity';
  $handler->display->display_options['relationships']['reverse_field_activity_main_contact_crm_core_activity']['table'] = 'crm_core_contact';
  $handler->display->display_options['relationships']['reverse_field_activity_main_contact_crm_core_activity']['field'] = 'reverse_field_activity_main_contact_crm_core_activity';
  $handler->display->display_options['relationships']['reverse_field_activity_main_contact_crm_core_activity']['label'] = 'CRM Activity Main Contact';
  $handler->display->display_options['relationships']['reverse_field_activity_main_contact_crm_core_activity']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: CRM Core Activity: Activity ID */
  $handler->display->display_options['arguments']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['arguments']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['arguments']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['arguments']['activity_id']['relationship'] = 'reverse_field_activity_main_contact_crm_core_activity';
  $handler->display->display_options['arguments']['activity_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['activity_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['activity_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['activity_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['activity_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['argument_input'] = array(
    'activity_id' => array(
      'type' => 'context',
      'context' => 'entity:crm_core_activity.activity-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'CRM Core Activity: Activity ID',
    ),
  );
  
  /* Display: Customer of activity */
  $handler = $view->new_display('panel_pane', 'Customer of activity', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Customer';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Currently there are no customer in this activity.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_activity_customer_crm_core_activity']['id'] = 'reverse_field_activity_customer_crm_core_activity';
  $handler->display->display_options['relationships']['reverse_field_activity_customer_crm_core_activity']['table'] = 'crm_core_contact';
  $handler->display->display_options['relationships']['reverse_field_activity_customer_crm_core_activity']['field'] = 'reverse_field_activity_customer_crm_core_activity';
  $handler->display->display_options['relationships']['reverse_field_activity_customer_crm_core_activity']['label'] = 'CRM Activity Customer';
  $handler->display->display_options['relationships']['reverse_field_activity_customer_crm_core_activity']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: CRM Core Activity: Activity ID */
  $handler->display->display_options['arguments']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['arguments']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['arguments']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['arguments']['activity_id']['relationship'] = 'reverse_field_activity_customer_crm_core_activity';
  $handler->display->display_options['arguments']['activity_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['activity_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['activity_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['activity_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['activity_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['argument_input'] = array(
    'activity_id' => array(
      'type' => 'context',
      'context' => 'entity:crm_core_activity.activity-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'CRM Core Activity: Activity ID',
    ),
  );
  
  /* Display: Participiants of activity */
  $handler = $view->new_display('panel_pane', 'Participiants of activity', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Participiants';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_activity_participants_crm_core_activity']['id'] = 'reverse_field_activity_participants_crm_core_activity';
  $handler->display->display_options['relationships']['reverse_field_activity_participants_crm_core_activity']['table'] = 'crm_core_contact';
  $handler->display->display_options['relationships']['reverse_field_activity_participants_crm_core_activity']['field'] = 'reverse_field_activity_participants_crm_core_activity';
  $handler->display->display_options['relationships']['reverse_field_activity_participants_crm_core_activity']['label'] = 'CRM Activity Participants';
  $handler->display->display_options['relationships']['reverse_field_activity_participants_crm_core_activity']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: CRM Core Activity: Activity ID */
  $handler->display->display_options['arguments']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['arguments']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['arguments']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['arguments']['activity_id']['relationship'] = 'reverse_field_activity_participants_crm_core_activity';
  $handler->display->display_options['arguments']['activity_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['activity_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['activity_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['activity_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['activity_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'activity_id' => array(
      'type' => 'context',
      'context' => 'entity:crm_core_activity.activity-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'CRM Core Activity: Activity ID',
    ),
  );
  
  /* Display: dashboard */
  $handler = $view->new_display('block', 'dashboard', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Contacts';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="contacts" class="link-global-view">Full view</a>';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Currently there are no contacts.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: CRM Core Contact: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['label'] = '';
  $handler->display->display_options['fields']['contact_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['contact_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contact_id']['link_to_contact'] = 0;
  /* Field: CRM Core Contact: Logo */
  $handler->display->display_options['fields']['field_contact_picture']['id'] = 'field_contact_picture';
  $handler->display->display_options['fields']['field_contact_picture']['table'] = 'field_data_field_contact_picture';
  $handler->display->display_options['fields']['field_contact_picture']['field'] = 'field_contact_picture';
  $handler->display->display_options['fields']['field_contact_picture']['label'] = 'Picture';
  $handler->display->display_options['fields']['field_contact_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_contact_picture']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: CRM Core Contact: Household */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['label'] = 'Name';
  $handler->display->display_options['fields']['contact_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['contact_name']['alter']['path'] = 'crm-core/contact/[contact_id]';
  $handler->display->display_options['fields']['contact_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['contact_name']['settings'] = array(
    'format' => 'default',
    'markup' => 0,
    'output' => 'default',
    'multiple' => 'default',
    'multiple_delimiter' => ', ',
    'multiple_and' => 'text',
    'multiple_delimiter_precedes_last' => 'never',
    'multiple_el_al_min' => '3',
    'multiple_el_al_first' => '1',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $translatables['erpal_crm_contacts'] = array(
    t('Master'),
    t('Customer'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Currently there are no participiants of activity.'),
    t('CRM Activity Customer'),
    t('Picture'),
    t('Name'),
    t('Contact Type'),
    t('Email'),
    t('Phone'),
    t('URL'),
    t('Contact name'),
    t('Contact type'),
    t('Contact list'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('@total rows'),
    t('Currently there are no contacts in a system.'),
    t('View panes'),
    t('Main contact of activity'),
    t('Main contact'),
    t('CRM Activity Main Contact'),
    t('All'),
    t('Customer of activity'),
    t('Currently there are no customer in this activity.'),
    t('Participiants of activity'),
    t('Participiants'),
    t('CRM Activity Participants'),
    t('dashboard'),
    t('Contacts'),
    t('<a href="contacts" class="link-global-view">Full view</a>'),
    t('Currently there are no contacts.'),
  );

  $views['erpal_crm_contacts'] = $view;

  // ERPAL CRM Activities view.
  $view = new view();
  $view->name = 'erpal_crm_activities';
  $view->description = 'Displays a list of activities.';
  $view->tag = 'erpal_crm';
  $view->base_table = 'crm_core_activity';
  $view->human_name = 'ERPAL CRM Activities';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Activities';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'activity_id' => 'activity_id',
    'title' => 'title',
    'type' => 'type',
    'field_activity_event_date' => 'field_activity_event_date',
    'field_activity_customer' => 'field_activity_customer',
    'field_activity_participants' => 'field_activity_participants',
    'field_activity_sales_process' => 'field_activity_sales_process',
    'field_activity_next_contact_date' => 'field_activity_next_contact_date',
    'field_activity_status' => 'field_activity_status',
    'edit_crm_activity' => 'edit_crm_activity',
    'views_bulk_operations' => 'views_bulk_operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'activity_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity_event_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity_customer' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity_participants' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity_sales_process' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity_next_contact_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_crm_activity' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Currently there are no activities in a system.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_activity_customer_target_id']['id'] = 'field_activity_customer_target_id';
  $handler->display->display_options['relationships']['field_activity_customer_target_id']['table'] = 'field_data_field_activity_customer';
  $handler->display->display_options['relationships']['field_activity_customer_target_id']['field'] = 'field_activity_customer_target_id';
  /* Field: CRM Core Activity: Activity ID */
  $handler->display->display_options['fields']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['label'] = '';
  $handler->display->display_options['fields']['activity_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['activity_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['activity_id']['separator'] = '';
  /* Field: CRM Core Activity: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Activity title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'crm-core/activity/[activity_id]';
  /* Field: CRM Core Activity: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: CRM Core Activity: Date */
  $handler->display->display_options['fields']['field_activity_event_date']['id'] = 'field_activity_event_date';
  $handler->display->display_options['fields']['field_activity_event_date']['table'] = 'field_data_field_activity_event_date';
  $handler->display->display_options['fields']['field_activity_event_date']['field'] = 'field_activity_event_date';
  $handler->display->display_options['fields']['field_activity_event_date']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_activity_event_date']['settings'] = array(
    'view_mode' => 'default',
    'links' => 0,
  );
  /* Field: CRM Core Activity: Customer */
  $handler->display->display_options['fields']['field_activity_customer']['id'] = 'field_activity_customer';
  $handler->display->display_options['fields']['field_activity_customer']['table'] = 'field_data_field_activity_customer';
  $handler->display->display_options['fields']['field_activity_customer']['field'] = 'field_activity_customer';
  $handler->display->display_options['fields']['field_activity_customer']['settings'] = array(
    'link' => 1,
  );
  /* Field: CRM Core Activity: Participants */
  $handler->display->display_options['fields']['field_activity_participants']['id'] = 'field_activity_participants';
  $handler->display->display_options['fields']['field_activity_participants']['table'] = 'field_data_field_activity_participants';
  $handler->display->display_options['fields']['field_activity_participants']['field'] = 'field_activity_participants';
  $handler->display->display_options['fields']['field_activity_participants']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_activity_participants']['delta_offset'] = '0';
  /* Field: CRM Core Activity: Sales process */
  $handler->display->display_options['fields']['field_activity_sales_process']['id'] = 'field_activity_sales_process';
  $handler->display->display_options['fields']['field_activity_sales_process']['table'] = 'field_data_field_activity_sales_process';
  $handler->display->display_options['fields']['field_activity_sales_process']['field'] = 'field_activity_sales_process';
  $handler->display->display_options['fields']['field_activity_sales_process']['settings'] = array(
    'link' => 1,
  );
  /* Field: CRM Core Activity: Next contact date */
  $handler->display->display_options['fields']['field_activity_next_contact_date']['id'] = 'field_activity_next_contact_date';
  $handler->display->display_options['fields']['field_activity_next_contact_date']['table'] = 'field_data_field_activity_next_contact_date';
  $handler->display->display_options['fields']['field_activity_next_contact_date']['field'] = 'field_activity_next_contact_date';
  $handler->display->display_options['fields']['field_activity_next_contact_date']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_activity_next_contact_date']['settings'] = array(
    'view_mode' => 'default',
    'links' => 0,
  );
  /* Field: CRM Core Activity: Status */
  $handler->display->display_options['fields']['field_activity_status']['id'] = 'field_activity_status';
  $handler->display->display_options['fields']['field_activity_status']['table'] = 'field_data_field_activity_status';
  $handler->display->display_options['fields']['field_activity_status']['field'] = 'field_activity_status';
  /* Sort criterion: CRM Core Activity: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'crm_core_activity';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: CRM Core Activity: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: CRM Core Activity: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: CRM Core Activity: Customer (field_activity_customer) */
  $handler->display->display_options['filters']['field_activity_customer_target_id']['id'] = 'field_activity_customer_target_id';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['table'] = 'field_data_field_activity_customer';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['field'] = 'field_activity_customer_target_id';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_activity_customer_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_customer_target_id']['expose']['operator_id'] = 'field_activity_customer_target_id_op';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['expose']['operator'] = 'field_activity_customer_target_id_op';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['expose']['identifier'] = 'field_activity_customer_target_id';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: CRM Core Activity: Status (field_activity_status) */
  $handler->display->display_options['filters']['field_activity_status_value']['id'] = 'field_activity_status_value';
  $handler->display->display_options['filters']['field_activity_status_value']['table'] = 'field_data_field_activity_status';
  $handler->display->display_options['filters']['field_activity_status_value']['field'] = 'field_activity_status_value';
  $handler->display->display_options['filters']['field_activity_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_activity_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['operator_id'] = 'field_activity_status_value_op';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['operator'] = 'field_activity_status_value_op';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['identifier'] = 'field_activity_status_value';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  
  /* Display: Activity list */
  $handler = $view->new_display('panel_pane', 'Activity list', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_activity_customer_target_id']['id'] = 'field_activity_customer_target_id';
  $handler->display->display_options['relationships']['field_activity_customer_target_id']['table'] = 'field_data_field_activity_customer';
  $handler->display->display_options['relationships']['field_activity_customer_target_id']['field'] = 'field_activity_customer_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: CRM Core Activity: Activity ID */
  $handler->display->display_options['fields']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['label'] = '';
  $handler->display->display_options['fields']['activity_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['activity_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['activity_id']['separator'] = '';
  /* Field: CRM Core Activity: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Activity title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'crm-core/activity/[activity_id]';
  /* Field: CRM Core Activity: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: CRM Core Activity: Date */
  $handler->display->display_options['fields']['field_activity_event_date']['id'] = 'field_activity_event_date';
  $handler->display->display_options['fields']['field_activity_event_date']['table'] = 'field_data_field_activity_event_date';
  $handler->display->display_options['fields']['field_activity_event_date']['field'] = 'field_activity_event_date';
  $handler->display->display_options['fields']['field_activity_event_date']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_activity_event_date']['settings'] = array(
    'view_mode' => 'default',
    'links' => 0,
  );
  /* Field: CRM Core Activity: Customer */
  $handler->display->display_options['fields']['field_activity_customer']['id'] = 'field_activity_customer';
  $handler->display->display_options['fields']['field_activity_customer']['table'] = 'field_data_field_activity_customer';
  $handler->display->display_options['fields']['field_activity_customer']['field'] = 'field_activity_customer';
  $handler->display->display_options['fields']['field_activity_customer']['settings'] = array(
    'link' => 1,
  );
  /* Field: CRM Core Activity: Participants */
  $handler->display->display_options['fields']['field_activity_participants']['id'] = 'field_activity_participants';
  $handler->display->display_options['fields']['field_activity_participants']['table'] = 'field_data_field_activity_participants';
  $handler->display->display_options['fields']['field_activity_participants']['field'] = 'field_activity_participants';
  $handler->display->display_options['fields']['field_activity_participants']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_activity_participants']['delta_offset'] = '0';
  /* Field: CRM Core Activity: Sales process */
  $handler->display->display_options['fields']['field_activity_sales_process']['id'] = 'field_activity_sales_process';
  $handler->display->display_options['fields']['field_activity_sales_process']['table'] = 'field_data_field_activity_sales_process';
  $handler->display->display_options['fields']['field_activity_sales_process']['field'] = 'field_activity_sales_process';
  $handler->display->display_options['fields']['field_activity_sales_process']['settings'] = array(
    'link' => 1,
  );
  /* Field: CRM Core Activity: Next contact date */
  $handler->display->display_options['fields']['field_activity_next_contact_date']['id'] = 'field_activity_next_contact_date';
  $handler->display->display_options['fields']['field_activity_next_contact_date']['table'] = 'field_data_field_activity_next_contact_date';
  $handler->display->display_options['fields']['field_activity_next_contact_date']['field'] = 'field_activity_next_contact_date';
  $handler->display->display_options['fields']['field_activity_next_contact_date']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_activity_next_contact_date']['settings'] = array(
    'view_mode' => 'default',
    'links' => 0,
  );
  /* Field: CRM Core Activity: Status */
  $handler->display->display_options['fields']['field_activity_status']['id'] = 'field_activity_status';
  $handler->display->display_options['fields']['field_activity_status']['table'] = 'field_data_field_activity_status';
  $handler->display->display_options['fields']['field_activity_status']['field'] = 'field_activity_status';
  /* Field: CRM Core Activity: Edit link */
  $handler->display->display_options['fields']['edit_crm_activity']['id'] = 'edit_crm_activity';
  $handler->display->display_options['fields']['edit_crm_activity']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['edit_crm_activity']['field'] = 'edit_crm_activity';
  $handler->display->display_options['fields']['edit_crm_activity']['text'] = 'Edit';
  $handler->display->display_options['fields']['edit_crm_activity']['redirect'] = 0;
  /* Field: Bulk operations: CRM Core Activity */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: CRM Core Activity: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: CRM Core Activity: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: CRM Core Contact: Household */
  $handler->display->display_options['filters']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['filters']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['filters']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['filters']['contact_name']['relationship'] = 'field_activity_customer_target_id';
  $handler->display->display_options['filters']['contact_name']['operator'] = 'word';
  $handler->display->display_options['filters']['contact_name']['group'] = 1;
  $handler->display->display_options['filters']['contact_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['contact_name']['expose']['operator_id'] = 'contact_name_op';
  $handler->display->display_options['filters']['contact_name']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['contact_name']['expose']['operator'] = 'contact_name_op';
  $handler->display->display_options['filters']['contact_name']['expose']['identifier'] = 'contact_name';
  $handler->display->display_options['filters']['contact_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: CRM Core Activity: Status (field_activity_status) */
  $handler->display->display_options['filters']['field_activity_status_value']['id'] = 'field_activity_status_value';
  $handler->display->display_options['filters']['field_activity_status_value']['table'] = 'field_data_field_activity_status';
  $handler->display->display_options['filters']['field_activity_status_value']['field'] = 'field_activity_status_value';
  $handler->display->display_options['filters']['field_activity_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_activity_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['operator_id'] = 'field_activity_status_value_op';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['operator'] = 'field_activity_status_value_op';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['identifier'] = 'field_activity_status_value';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';
  
  /* Display: Activities by Contact */
  $handler = $view->new_display('panel_pane', 'Activities by Contact', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Activities';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['id'] = 'field_activity_participants_target_id';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['table'] = 'field_data_field_activity_participants';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['field'] = 'field_activity_participants_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: CRM Core Activity: Activity ID */
  $handler->display->display_options['fields']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['label'] = '';
  $handler->display->display_options['fields']['activity_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['activity_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['activity_id']['separator'] = '';
  /* Field: CRM Core Activity: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Activity title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'crm-core/activity/[activity_id]';
  /* Field: CRM Core Activity: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: CRM Core Activity: Date */
  $handler->display->display_options['fields']['field_activity_event_date']['id'] = 'field_activity_event_date';
  $handler->display->display_options['fields']['field_activity_event_date']['table'] = 'field_data_field_activity_event_date';
  $handler->display->display_options['fields']['field_activity_event_date']['field'] = 'field_activity_event_date';
  $handler->display->display_options['fields']['field_activity_event_date']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_activity_event_date']['settings'] = array(
    'view_mode' => 'default',
    'links' => 0,
  );
  /* Field: CRM Core Activity: Customer */
  $handler->display->display_options['fields']['field_activity_customer']['id'] = 'field_activity_customer';
  $handler->display->display_options['fields']['field_activity_customer']['table'] = 'field_data_field_activity_customer';
  $handler->display->display_options['fields']['field_activity_customer']['field'] = 'field_activity_customer';
  $handler->display->display_options['fields']['field_activity_customer']['settings'] = array(
    'link' => 1,
  );
  /* Field: CRM Core Activity: Participants */
  $handler->display->display_options['fields']['field_activity_participants']['id'] = 'field_activity_participants';
  $handler->display->display_options['fields']['field_activity_participants']['table'] = 'field_data_field_activity_participants';
  $handler->display->display_options['fields']['field_activity_participants']['field'] = 'field_activity_participants';
  $handler->display->display_options['fields']['field_activity_participants']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_activity_participants']['delta_offset'] = '0';
  /* Field: CRM Core Activity: Sales process */
  $handler->display->display_options['fields']['field_activity_sales_process']['id'] = 'field_activity_sales_process';
  $handler->display->display_options['fields']['field_activity_sales_process']['table'] = 'field_data_field_activity_sales_process';
  $handler->display->display_options['fields']['field_activity_sales_process']['field'] = 'field_activity_sales_process';
  $handler->display->display_options['fields']['field_activity_sales_process']['settings'] = array(
    'link' => 1,
  );
  /* Field: CRM Core Activity: Next contact date */
  $handler->display->display_options['fields']['field_activity_next_contact_date']['id'] = 'field_activity_next_contact_date';
  $handler->display->display_options['fields']['field_activity_next_contact_date']['table'] = 'field_data_field_activity_next_contact_date';
  $handler->display->display_options['fields']['field_activity_next_contact_date']['field'] = 'field_activity_next_contact_date';
  $handler->display->display_options['fields']['field_activity_next_contact_date']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_activity_next_contact_date']['settings'] = array(
    'view_mode' => 'default',
    'links' => 0,
  );
  /* Field: CRM Core Activity: Status */
  $handler->display->display_options['fields']['field_activity_status']['id'] = 'field_activity_status';
  $handler->display->display_options['fields']['field_activity_status']['table'] = 'field_data_field_activity_status';
  $handler->display->display_options['fields']['field_activity_status']['field'] = 'field_activity_status';
  /* Field: CRM Core Activity: Edit link */
  $handler->display->display_options['fields']['edit_crm_activity']['id'] = 'edit_crm_activity';
  $handler->display->display_options['fields']['edit_crm_activity']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['edit_crm_activity']['field'] = 'edit_crm_activity';
  $handler->display->display_options['fields']['edit_crm_activity']['text'] = 'Edit';
  $handler->display->display_options['fields']['edit_crm_activity']['redirect'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: CRM Core Activity: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: CRM Core Activity: Status (field_activity_status) */
  $handler->display->display_options['filters']['field_activity_status_value']['id'] = 'field_activity_status_value';
  $handler->display->display_options['filters']['field_activity_status_value']['table'] = 'field_data_field_activity_status';
  $handler->display->display_options['filters']['field_activity_status_value']['field'] = 'field_activity_status_value';
  $handler->display->display_options['filters']['field_activity_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_activity_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['operator_id'] = 'field_activity_status_value_op';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['operator'] = 'field_activity_status_value_op';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['identifier'] = 'field_activity_status_value';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: CRM Core Contact: Contact ID */
  $handler->display->display_options['filters']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['filters']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['filters']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['filters']['contact_id']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['filters']['contact_id']['value']['value'] = '!2';
  $handler->display->display_options['filters']['contact_id']['group'] = 2;
  $handler->display->display_options['filters']['contact_id']['expose']['operator_id'] = 'contact_id_op';
  $handler->display->display_options['filters']['contact_id']['expose']['label'] = 'Contact ID';
  $handler->display->display_options['filters']['contact_id']['expose']['operator'] = 'contact_id_op';
  $handler->display->display_options['filters']['contact_id']['expose']['identifier'] = 'contact_id';
  $handler->display->display_options['filters']['contact_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: CRM Core Activity: Customer (field_activity_customer) */
  $handler->display->display_options['filters']['field_activity_customer_target_id']['id'] = 'field_activity_customer_target_id';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['table'] = 'field_data_field_activity_customer';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['field'] = 'field_activity_customer_target_id';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['value']['value'] = '!2';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['group'] = 2;
  $handler->display->display_options['filters']['field_activity_customer_target_id']['expose']['operator_id'] = 'field_activity_customer_target_id_op';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['expose']['label'] = 'Customer (field_activity_customer)';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['expose']['operator'] = 'field_activity_customer_target_id_op';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['expose']['identifier'] = 'customer';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: CRM Core Activity: Main contact (field_activity_main_contact) */
  $handler->display->display_options['filters']['field_activity_main_contact_target_id']['id'] = 'field_activity_main_contact_target_id';
  $handler->display->display_options['filters']['field_activity_main_contact_target_id']['table'] = 'field_data_field_activity_main_contact';
  $handler->display->display_options['filters']['field_activity_main_contact_target_id']['field'] = 'field_activity_main_contact_target_id';
  $handler->display->display_options['filters']['field_activity_main_contact_target_id']['value']['value'] = '!2';
  $handler->display->display_options['filters']['field_activity_main_contact_target_id']['group'] = 2;
  $handler->display->display_options['filters']['field_activity_main_contact_target_id']['expose']['operator_id'] = 'field_activity_main_contact_target_id_op';
  $handler->display->display_options['filters']['field_activity_main_contact_target_id']['expose']['label'] = 'Main contact (field_activity_main_contact)';
  $handler->display->display_options['filters']['field_activity_main_contact_target_id']['expose']['operator'] = 'field_activity_main_contact_target_id_op';
  $handler->display->display_options['filters']['field_activity_main_contact_target_id']['expose']['identifier'] = 'main_contact';
  $handler->display->display_options['filters']['field_activity_main_contact_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['argument_input'] = array(
    'contact_id' => array(
      'type' => 'context',
      'context' => 'entity:crm_core_contact.contact-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'CRM Contact: Contact ID',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  
  /* Display: Activities by Contact Teaser */
  $handler = $view->new_display('panel_pane', 'Activities by Contact Teaser', 'panel_pane_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest activities';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'activity-teaser-list-x';
  $handler->display->display_options['style_options']['wrapper_class'] = 'activity-teaser-list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['id'] = 'field_activity_participants_target_id';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['table'] = 'field_data_field_activity_participants';
  $handler->display->display_options['relationships']['field_activity_participants_target_id']['field'] = 'field_activity_participants_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: CRM Core Activity: Activity ID */
  $handler->display->display_options['fields']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['label'] = '';
  $handler->display->display_options['fields']['activity_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['activity_id']['element_label_colon'] = FALSE;
  /* Field: CRM Core Activity: Date */
  $handler->display->display_options['fields']['field_activity_event_date']['id'] = 'field_activity_event_date';
  $handler->display->display_options['fields']['field_activity_event_date']['table'] = 'field_data_field_activity_event_date';
  $handler->display->display_options['fields']['field_activity_event_date']['field'] = 'field_activity_event_date';
  $handler->display->display_options['fields']['field_activity_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_activity_event_date']['alter']['text'] = '<time>[field_activity_event_date]</time>';
  $handler->display->display_options['fields']['field_activity_event_date']['alter']['preserve_tags'] = '<span> <time>';
  $handler->display->display_options['fields']['field_activity_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_activity_event_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_activity_event_date']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_activity_event_date']['settings'] = array(
    'view_mode' => 'default',
    'links' => 0,
  );
  /* Field: CRM Core Activity: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['alter']['text'] = '<span class="activity-type" data-type="[type]" title="[type]"></span>';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: CRM Core Activity: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'crm-core/activity/[activity_id]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: CRM Core Activity: Date (field_activity_event_date) */
  $handler->display->display_options['sorts']['field_activity_event_date_target_id']['id'] = 'field_activity_event_date_target_id';
  $handler->display->display_options['sorts']['field_activity_event_date_target_id']['table'] = 'field_data_field_activity_event_date';
  $handler->display->display_options['sorts']['field_activity_event_date_target_id']['field'] = 'field_activity_event_date_target_id';
  $handler->display->display_options['sorts']['field_activity_event_date_target_id']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: CRM Core Contact: Contact ID */
  $handler->display->display_options['filters']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['filters']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['filters']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['filters']['contact_id']['relationship'] = 'field_activity_participants_target_id';
  $handler->display->display_options['filters']['contact_id']['value']['value'] = '!2';
  $handler->display->display_options['filters']['contact_id']['group'] = 2;
  $handler->display->display_options['filters']['contact_id']['expose']['operator_id'] = 'contact_id_op';
  $handler->display->display_options['filters']['contact_id']['expose']['label'] = 'Contact ID';
  $handler->display->display_options['filters']['contact_id']['expose']['operator'] = 'contact_id_op';
  $handler->display->display_options['filters']['contact_id']['expose']['identifier'] = 'contact_id';
  $handler->display->display_options['filters']['contact_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: CRM Core Activity: Customer (field_activity_customer) */
  $handler->display->display_options['filters']['field_activity_customer_target_id']['id'] = 'field_activity_customer_target_id';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['table'] = 'field_data_field_activity_customer';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['field'] = 'field_activity_customer_target_id';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['value']['value'] = '!2';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['group'] = 2;
  $handler->display->display_options['filters']['field_activity_customer_target_id']['expose']['operator_id'] = 'field_activity_customer_target_id_op';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['expose']['label'] = 'Customer (field_activity_customer)';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['expose']['operator'] = 'field_activity_customer_target_id_op';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['expose']['identifier'] = 'customer';
  $handler->display->display_options['filters']['field_activity_customer_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: CRM Core Activity: Main contact (field_activity_main_contact) */
  $handler->display->display_options['filters']['field_activity_main_contact_target_id']['id'] = 'field_activity_main_contact_target_id';
  $handler->display->display_options['filters']['field_activity_main_contact_target_id']['table'] = 'field_data_field_activity_main_contact';
  $handler->display->display_options['filters']['field_activity_main_contact_target_id']['field'] = 'field_activity_main_contact_target_id';
  $handler->display->display_options['filters']['field_activity_main_contact_target_id']['value']['value'] = '!2';
  $handler->display->display_options['filters']['field_activity_main_contact_target_id']['group'] = 2;
  $handler->display->display_options['filters']['field_activity_main_contact_target_id']['expose']['operator_id'] = 'field_activity_main_contact_target_id_op';
  $handler->display->display_options['filters']['field_activity_main_contact_target_id']['expose']['label'] = 'Main contact (field_activity_main_contact)';
  $handler->display->display_options['filters']['field_activity_main_contact_target_id']['expose']['operator'] = 'field_activity_main_contact_target_id_op';
  $handler->display->display_options['filters']['field_activity_main_contact_target_id']['expose']['identifier'] = 'main_contact';
  $handler->display->display_options['filters']['field_activity_main_contact_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: CRM Core Activity Type: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_activity_type';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = '!=';
  $handler->display->display_options['filters']['type']['value'] = '"Sales process"';
  $handler->display->display_options['argument_input'] = array(
    'contact_id' => array(
      'type' => 'context',
      'context' => 'entity:crm_core_contact.contact-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'CRM Contact: Contact ID',
    ),
  );
  $handler->display->display_options['link_to_view'] = '0';
  $handler->display->display_options['inherit_panels_path'] = '1';
  
  /* Display: Activities by Sales Process */
  $handler = $view->new_display('panel_pane', 'Activities by Sales Process', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Communication';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_activity_sales_process_target_id']['id'] = 'field_activity_sales_process_target_id';
  $handler->display->display_options['relationships']['field_activity_sales_process_target_id']['table'] = 'field_data_field_activity_sales_process';
  $handler->display->display_options['relationships']['field_activity_sales_process_target_id']['field'] = 'field_activity_sales_process_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_activity_customer_target_id']['id'] = 'field_activity_customer_target_id';
  $handler->display->display_options['relationships']['field_activity_customer_target_id']['table'] = 'field_data_field_activity_customer';
  $handler->display->display_options['relationships']['field_activity_customer_target_id']['field'] = 'field_activity_customer_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: CRM Core Activity: Activity ID */
  $handler->display->display_options['fields']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['label'] = '';
  $handler->display->display_options['fields']['activity_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['activity_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['activity_id']['separator'] = '';
  /* Field: CRM Core Activity: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Activity title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'crm-core/activity/[activity_id]';
  /* Field: CRM Core Activity: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: CRM Core Activity: Date */
  $handler->display->display_options['fields']['field_activity_event_date']['id'] = 'field_activity_event_date';
  $handler->display->display_options['fields']['field_activity_event_date']['table'] = 'field_data_field_activity_event_date';
  $handler->display->display_options['fields']['field_activity_event_date']['field'] = 'field_activity_event_date';
  $handler->display->display_options['fields']['field_activity_event_date']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_activity_event_date']['settings'] = array(
    'view_mode' => 'default',
    'links' => 0,
  );
  /* Field: CRM Core Activity: Customer */
  $handler->display->display_options['fields']['field_activity_customer']['id'] = 'field_activity_customer';
  $handler->display->display_options['fields']['field_activity_customer']['table'] = 'field_data_field_activity_customer';
  $handler->display->display_options['fields']['field_activity_customer']['field'] = 'field_activity_customer';
  $handler->display->display_options['fields']['field_activity_customer']['settings'] = array(
    'link' => 1,
  );
  /* Field: CRM Core Activity: Participants */
  $handler->display->display_options['fields']['field_activity_participants']['id'] = 'field_activity_participants';
  $handler->display->display_options['fields']['field_activity_participants']['table'] = 'field_data_field_activity_participants';
  $handler->display->display_options['fields']['field_activity_participants']['field'] = 'field_activity_participants';
  $handler->display->display_options['fields']['field_activity_participants']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_activity_participants']['delta_offset'] = '0';
  /* Field: CRM Core Activity: Sales process */
  $handler->display->display_options['fields']['field_activity_sales_process']['id'] = 'field_activity_sales_process';
  $handler->display->display_options['fields']['field_activity_sales_process']['table'] = 'field_data_field_activity_sales_process';
  $handler->display->display_options['fields']['field_activity_sales_process']['field'] = 'field_activity_sales_process';
  $handler->display->display_options['fields']['field_activity_sales_process']['settings'] = array(
    'link' => 1,
  );
  /* Field: CRM Core Activity: Next contact date */
  $handler->display->display_options['fields']['field_activity_next_contact_date']['id'] = 'field_activity_next_contact_date';
  $handler->display->display_options['fields']['field_activity_next_contact_date']['table'] = 'field_data_field_activity_next_contact_date';
  $handler->display->display_options['fields']['field_activity_next_contact_date']['field'] = 'field_activity_next_contact_date';
  $handler->display->display_options['fields']['field_activity_next_contact_date']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_activity_next_contact_date']['settings'] = array(
    'view_mode' => 'default',
    'links' => 0,
  );
  /* Field: CRM Core Activity: Notes */
  $handler->display->display_options['fields']['field_activity_notes']['id'] = 'field_activity_notes';
  $handler->display->display_options['fields']['field_activity_notes']['table'] = 'field_data_field_activity_notes';
  $handler->display->display_options['fields']['field_activity_notes']['field'] = 'field_activity_notes';
  $handler->display->display_options['fields']['field_activity_notes']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_activity_notes']['settings'] = array(
    'trim_length' => '400',
  );
  /* Field: CRM Core Activity: Edit link */
  $handler->display->display_options['fields']['edit_crm_activity']['id'] = 'edit_crm_activity';
  $handler->display->display_options['fields']['edit_crm_activity']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['edit_crm_activity']['field'] = 'edit_crm_activity';
  $handler->display->display_options['fields']['edit_crm_activity']['text'] = 'Edit';
  $handler->display->display_options['fields']['edit_crm_activity']['redirect'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: CRM Core Activity: Activity ID */
  $handler->display->display_options['arguments']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['arguments']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['arguments']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['arguments']['activity_id']['relationship'] = 'field_activity_sales_process_target_id';
  $handler->display->display_options['arguments']['activity_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['activity_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['activity_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['activity_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['activity_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: CRM Core Activity: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: CRM Core Activity: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: CRM Core Contact: Household */
  $handler->display->display_options['filters']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['filters']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['filters']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['filters']['contact_name']['relationship'] = 'field_activity_customer_target_id';
  $handler->display->display_options['filters']['contact_name']['operator'] = 'word';
  $handler->display->display_options['filters']['contact_name']['group'] = 1;
  $handler->display->display_options['filters']['contact_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['contact_name']['expose']['operator_id'] = 'contact_name_op';
  $handler->display->display_options['filters']['contact_name']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['contact_name']['expose']['operator'] = 'contact_name_op';
  $handler->display->display_options['filters']['contact_name']['expose']['identifier'] = 'contact_name';
  $handler->display->display_options['filters']['contact_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: CRM Core Activity: Status (field_activity_status) */
  $handler->display->display_options['filters']['field_activity_status_value']['id'] = 'field_activity_status_value';
  $handler->display->display_options['filters']['field_activity_status_value']['table'] = 'field_data_field_activity_status';
  $handler->display->display_options['filters']['field_activity_status_value']['field'] = 'field_activity_status_value';
  $handler->display->display_options['filters']['field_activity_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_activity_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['operator_id'] = 'field_activity_status_value_op';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['operator'] = 'field_activity_status_value_op';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['identifier'] = 'field_activity_status_value';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['argument_input'] = array(
    'activity_id' => array(
      'type' => 'context',
      'context' => 'entity:crm_core_activity.activity-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'CRM Core Activity: Activity ID',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  
  /* Display: dashboard */
  $handler = $view->new_display('block', 'dashboard', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Activities';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="activities" class="link-global-view">Full view</a>';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Currently there are no activities.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: CRM Core Activity: Activity ID */
  $handler->display->display_options['fields']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['label'] = '';
  $handler->display->display_options['fields']['activity_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['activity_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['activity_id']['separator'] = '';
  /* Field: CRM Core Activity: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Activity title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'crm-core/activity/[activity_id]';
  /* Field: CRM Core Activity: Customer */
  $handler->display->display_options['fields']['field_activity_customer']['id'] = 'field_activity_customer';
  $handler->display->display_options['fields']['field_activity_customer']['table'] = 'field_data_field_activity_customer';
  $handler->display->display_options['fields']['field_activity_customer']['field'] = 'field_activity_customer';
  $handler->display->display_options['fields']['field_activity_customer']['settings'] = array(
    'link' => 1,
  );
  /* Field: CRM Core Activity: Status */
  $handler->display->display_options['fields']['field_activity_status']['id'] = 'field_activity_status';
  $handler->display->display_options['fields']['field_activity_status']['table'] = 'field_data_field_activity_status';
  $handler->display->display_options['fields']['field_activity_status']['field'] = 'field_activity_status';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $translatables['erpal_crm_activities'] = array(
    t('Master'),
    t('Activities'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Currently there are no activities in a system.'),
    t('CRM Core Contact entity referenced from field_activity_customer'),
    t('.'),
    t('Activity title'),
    t('Type'),
    t('Date'),
    t('Customer'),
    t('Participants'),
    t('Sales process'),
    t('Next contact date'),
    t('Status'),
    t('Title'),
    t('Activity list'),
    t('@total rows'),
    t('Edit link'),
    t('Edit'),
    t('CRM Core Activity'),
    t('- Choose an operation -'),
    t('View panes'),
    t('Activities by Contact'),
    t('CRM Core Contact entity referenced from field_activity_participants'),
    t('Contact ID'),
    t('Customer (field_activity_customer)'),
    t('Main contact (field_activity_main_contact)'),
    t('Activities by Contact Teaser'),
    t('Latest activities'),
    t(','),
    t('<time>[field_activity_event_date]</time>'),
    t('<span class="activity-type" data-type="[type]" title="[type]"></span>'),
    t('Activities by Sales Process'),
    t('Communication'),
    t('CRM Core Activity entity referenced from field_activity_sales_process'),
    t('Notes'),
    t('All'),
    t('dashboard'),
    t('<a href="activities" class="link-global-view">Full view</a>'),
    t('Currently there are no activities.'),
  );

  $views['erpal_crm_activities'] = $view;

  /* crm replationships */
  $view = new view();
  $view->name = 'erpal_crm_contact_relationships';
  $view->description = 'Displays contact relationships.';
  $view->tag = 'erpal_crm';
  $view->base_table = 'relation';
  $view->human_name = 'ERPAL CRM Relationships by contact';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Active Relationships';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view relation entities of any contact relationship';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'rid' => 'rid',
    'endpoints' => 'endpoints',
    'endpoints_1' => 'endpoints_1',
    'edit' => 'edit',
    'crm_core_relationship_status_1' => 'crm_core_relationship_status_1',
    'delete' => 'delete',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'rid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'endpoints' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'endpoints_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'crm_core_relationship_status_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No active relationships are stored in the system for this contact at this time.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Field: Relation: Rid */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'relation';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['exclude'] = TRUE;
  /* Field: Relation: endpoints */
  $handler->display->display_options['fields']['endpoints']['id'] = 'endpoints';
  $handler->display->display_options['fields']['endpoints']['table'] = 'field_data_endpoints';
  $handler->display->display_options['fields']['endpoints']['field'] = 'endpoints';
  $handler->display->display_options['fields']['endpoints']['label'] = '';
  $handler->display->display_options['fields']['endpoints']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['endpoints']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['endpoints']['click_sort_column'] = 'entity_type';
  $handler->display->display_options['fields']['endpoints']['type'] = 'contact_relationship_human';
  $handler->display->display_options['fields']['endpoints']['delta_offset'] = '0';
  /* Field: Relation: endpoints */
  $handler->display->display_options['fields']['endpoints_1']['id'] = 'endpoints_1';
  $handler->display->display_options['fields']['endpoints_1']['table'] = 'field_data_endpoints';
  $handler->display->display_options['fields']['endpoints_1']['field'] = 'endpoints';
  $handler->display->display_options['fields']['endpoints_1']['label'] = 'Contact ID';
  $handler->display->display_options['fields']['endpoints_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['endpoints_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['endpoints_1']['alter']['text'] = '[endpoints_1-entity_id]';
  $handler->display->display_options['fields']['endpoints_1']['click_sort_column'] = 'entity_type';
  $handler->display->display_options['fields']['endpoints_1']['type'] = 'relation_endpoint_full';
  $handler->display->display_options['fields']['endpoints_1']['delta_offset'] = '0';
  /* Field: Relation: Edit link */
  $handler->display->display_options['fields']['edit']['id'] = 'edit';
  $handler->display->display_options['fields']['edit']['table'] = 'relation';
  $handler->display->display_options['fields']['edit']['field'] = 'edit';
  $handler->display->display_options['fields']['edit']['exclude'] = TRUE;
  /* Field: Relation: Status */
  $handler->display->display_options['fields']['crm_core_relationship_status_1']['id'] = 'crm_core_relationship_status_1';
  $handler->display->display_options['fields']['crm_core_relationship_status_1']['table'] = 'field_data_crm_core_relationship_status';
  $handler->display->display_options['fields']['crm_core_relationship_status_1']['field'] = 'crm_core_relationship_status';
  $handler->display->display_options['fields']['crm_core_relationship_status_1']['label'] = 'Status (Link)';
  $handler->display->display_options['fields']['crm_core_relationship_status_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['crm_core_relationship_status_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['crm_core_relationship_status_1']['alter']['text'] = 'Mark as inactive';
  $handler->display->display_options['fields']['crm_core_relationship_status_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['crm_core_relationship_status_1']['alter']['path'] = 'crm-core/contact/[endpoints_1]/relationships/[rid]/inactive?destination=crm-core/contact/[endpoints_1]/relationships';
  $handler->display->display_options['fields']['crm_core_relationship_status_1']['type'] = 'list_key';
  /* Field: Relation: Delete link */
  $handler->display->display_options['fields']['delete']['id'] = 'delete';
  $handler->display->display_options['fields']['delete']['table'] = 'relation';
  $handler->display->display_options['fields']['delete']['field'] = 'delete';
  $handler->display->display_options['fields']['delete']['exclude'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit] [crm_core_relationship_status_1] [delete]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Relation: endpoints */
  $handler->display->display_options['fields']['endpoints_2']['id'] = 'endpoints_2';
  $handler->display->display_options['fields']['endpoints_2']['table'] = 'field_data_endpoints';
  $handler->display->display_options['fields']['endpoints_2']['field'] = 'endpoints';
  $handler->display->display_options['fields']['endpoints_2']['label'] = 'Current contact name';
  $handler->display->display_options['fields']['endpoints_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['endpoints_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['endpoints_2']['click_sort_column'] = 'entity_type';
  $handler->display->display_options['fields']['endpoints_2']['type'] = 'contact_relationship_current';
  $handler->display->display_options['fields']['endpoints_2']['delta_offset'] = '0';
  /* Sort criterion: Relation: Rid */
  $handler->display->display_options['sorts']['rid']['id'] = 'rid';
  $handler->display->display_options['sorts']['rid']['table'] = 'relation';
  $handler->display->display_options['sorts']['rid']['field'] = 'rid';
  $handler->display->display_options['sorts']['rid']['order'] = 'DESC';
  /* Contextual filter: Relation: endpoints (endpoints:entity_id) */
  $handler->display->display_options['arguments']['endpoints_entity_id']['id'] = 'endpoints_entity_id';
  $handler->display->display_options['arguments']['endpoints_entity_id']['table'] = 'field_data_endpoints';
  $handler->display->display_options['arguments']['endpoints_entity_id']['field'] = 'endpoints_entity_id';
  $handler->display->display_options['arguments']['endpoints_entity_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['endpoints_entity_id']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['endpoints_entity_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['endpoints_entity_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['endpoints_entity_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Relation: Status (crm_core_relationship_status) */
  $handler->display->display_options['filters']['crm_core_relationship_status_value']['id'] = 'crm_core_relationship_status_value';
  $handler->display->display_options['filters']['crm_core_relationship_status_value']['table'] = 'field_data_crm_core_relationship_status';
  $handler->display->display_options['filters']['crm_core_relationship_status_value']['field'] = 'crm_core_relationship_status_value';
  $handler->display->display_options['filters']['crm_core_relationship_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['crm_core_relationship_status_value']['expose']['operator_id'] = 'crm_core_relationship_status_value_op';
  $handler->display->display_options['filters']['crm_core_relationship_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['crm_core_relationship_status_value']['expose']['operator'] = 'crm_core_relationship_status_value_op';
  $handler->display->display_options['filters']['crm_core_relationship_status_value']['expose']['identifier'] = 'crm_core_relationship_status_value';
  $handler->display->display_options['filters']['crm_core_relationship_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  
  /* Display: Contact relationships */
  $handler = $view->new_display('panel_pane', 'Contact relationships', 'panel_pane_1');
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
  $handler->display->display_options['argument_input'] = array(
    'endpoints_entity_id' => array(
      'type' => 'panel',
      'context' => 'entity:crm_core_contact.name-contact-name',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Relation: endpoints (endpoints:entity_id)',
    ),
  );
  
  /* Display: Contact relationships Teaser */
  $handler = $view->new_display('panel_pane', 'Contact relationships Teaser', 'panel_pane_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'realtion-teaser-list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Relation: Rid */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'relation';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['exclude'] = TRUE;
  /* Field: Relation: endpoints */
  $handler->display->display_options['fields']['endpoints']['id'] = 'endpoints';
  $handler->display->display_options['fields']['endpoints']['table'] = 'field_data_endpoints';
  $handler->display->display_options['fields']['endpoints']['field'] = 'endpoints';
  $handler->display->display_options['fields']['endpoints']['label'] = '';
  $handler->display->display_options['fields']['endpoints']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['endpoints']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['endpoints']['click_sort_column'] = 'entity_type';
  $handler->display->display_options['fields']['endpoints']['type'] = 'contact_relationship_human';
  $handler->display->display_options['fields']['endpoints']['delta_offset'] = '0';
  /* Field: Relation: endpoints */
  $handler->display->display_options['fields']['endpoints_1']['id'] = 'endpoints_1';
  $handler->display->display_options['fields']['endpoints_1']['table'] = 'field_data_endpoints';
  $handler->display->display_options['fields']['endpoints_1']['field'] = 'endpoints';
  $handler->display->display_options['fields']['endpoints_1']['label'] = 'Contact ID';
  $handler->display->display_options['fields']['endpoints_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['endpoints_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['endpoints_1']['alter']['text'] = '[endpoints_1-entity_id]';
  $handler->display->display_options['fields']['endpoints_1']['click_sort_column'] = 'entity_type';
  $handler->display->display_options['fields']['endpoints_1']['type'] = 'relation_endpoint_full';
  $handler->display->display_options['fields']['endpoints_1']['delta_offset'] = '0';
  /* Field: Relation: Edit link */
  $handler->display->display_options['fields']['edit']['id'] = 'edit';
  $handler->display->display_options['fields']['edit']['table'] = 'relation';
  $handler->display->display_options['fields']['edit']['field'] = 'edit';
  $handler->display->display_options['fields']['edit']['exclude'] = TRUE;
  /* Field: Relation: Status */
  $handler->display->display_options['fields']['crm_core_relationship_status_1']['id'] = 'crm_core_relationship_status_1';
  $handler->display->display_options['fields']['crm_core_relationship_status_1']['table'] = 'field_data_crm_core_relationship_status';
  $handler->display->display_options['fields']['crm_core_relationship_status_1']['field'] = 'crm_core_relationship_status';
  $handler->display->display_options['fields']['crm_core_relationship_status_1']['label'] = 'Status (Link)';
  $handler->display->display_options['fields']['crm_core_relationship_status_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['crm_core_relationship_status_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['crm_core_relationship_status_1']['alter']['text'] = 'Mark as inactive';
  $handler->display->display_options['fields']['crm_core_relationship_status_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['crm_core_relationship_status_1']['alter']['path'] = 'crm-core/contact/[endpoints_1]/relationships/[rid]/inactive?destination=crm-core/contact/[endpoints_1]/relationships';
  $handler->display->display_options['fields']['crm_core_relationship_status_1']['type'] = 'list_key';
  /* Field: Relation: Delete link */
  $handler->display->display_options['fields']['delete']['id'] = 'delete';
  $handler->display->display_options['fields']['delete']['table'] = 'relation';
  $handler->display->display_options['fields']['delete']['field'] = 'delete';
  $handler->display->display_options['fields']['delete']['exclude'] = TRUE;
  /* Field: Relation: endpoints */
  $handler->display->display_options['fields']['endpoints_2']['id'] = 'endpoints_2';
  $handler->display->display_options['fields']['endpoints_2']['table'] = 'field_data_endpoints';
  $handler->display->display_options['fields']['endpoints_2']['field'] = 'endpoints';
  $handler->display->display_options['fields']['endpoints_2']['label'] = 'Current contact name';
  $handler->display->display_options['fields']['endpoints_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['endpoints_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['endpoints_2']['click_sort_column'] = 'entity_type';
  $handler->display->display_options['fields']['endpoints_2']['type'] = 'contact_relationship_current';
  $handler->display->display_options['fields']['endpoints_2']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Relation: Status (crm_core_relationship_status) */
  $handler->display->display_options['filters']['crm_core_relationship_status_value']['id'] = 'crm_core_relationship_status_value';
  $handler->display->display_options['filters']['crm_core_relationship_status_value']['table'] = 'field_data_crm_core_relationship_status';
  $handler->display->display_options['filters']['crm_core_relationship_status_value']['field'] = 'crm_core_relationship_status_value';
  $handler->display->display_options['filters']['crm_core_relationship_status_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['argument_input'] = array(
    'endpoints_entity_id' => array(
      'type' => 'panel',
      'context' => 'entity:crm_core_contact.name-contact-name',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Relation: endpoints (endpoints:entity_id)',
    ),
  );
  $handler->display->display_options['link_to_view'] = '0';
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['erpal_crm_contact_relationships'] = array(
    t('Master'),
    t('Active Relationships'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('No active relationships are stored in the system for this contact at this time.'),
    t('Rid'),
    t('.'),
    t(','),
    t('Contact ID'),
    t('[endpoints_1-entity_id]'),
    t('Edit link'),
    t('Status (Link)'),
    t('Mark as inactive'),
    t('Delete link'),
    t('[edit] [crm_core_relationship_status_1] [delete]'),
    t('Current contact name'),
    t('All'),
    t('Status'),
    t('Contact relationships'),
    t('@total rows'),
    t('View panes'),
    t('Contact relationships Teaser'),
  );

  $views['erpal_crm_contact_relationships'] = $view;

  return $views;
}

/**
 * Implements hook_views_default_views_alter().
 *
 * Here we drop default views that comes from CRM Core module,
 * but we don't need them.
 */
function erpal_crm_ui_views_default_views_alter(&$views) {
  unset($views['crm_core_contacts']);
  unset($views['crm_activities_by_contact']);
  unset($views['crm_relationships_by_contact']);
}
