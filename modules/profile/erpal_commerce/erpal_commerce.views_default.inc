<?php

/**
 * @file
 * erpal_commerce.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function erpal_commerce_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'erpal_customer_profile';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_customer_profile';
  $view->human_name = 'ERPAL customer profile';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_customer_profiles_crm_core_contact']['id'] = 'reverse_field_customer_profiles_crm_core_contact';
  $handler->display->display_options['relationships']['reverse_field_customer_profiles_crm_core_contact']['table'] = 'commerce_customer_profile';
  $handler->display->display_options['relationships']['reverse_field_customer_profiles_crm_core_contact']['field'] = 'reverse_field_customer_profiles_crm_core_contact';
  /* Field: Commerce Customer Profile: Profile ID */
  $handler->display->display_options['fields']['profile_id']['id'] = 'profile_id';
  $handler->display->display_options['fields']['profile_id']['table'] = 'commerce_customer_profile';
  $handler->display->display_options['fields']['profile_id']['field'] = 'profile_id';
  $handler->display->display_options['fields']['profile_id']['label'] = '';
  $handler->display->display_options['fields']['profile_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['profile_id']['link_to_profile'] = 0;
  /* Field: Commerce Customer profile: Address - Full name */
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['id'] = 'commerce_customer_address_name_line';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['field'] = 'commerce_customer_address_name_line';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['label'] = '';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['element_label_colon'] = FALSE;
  /* Field: Commerce Customer profile: Address - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['id'] = 'commerce_customer_address_thoroughfare';
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['field'] = 'commerce_customer_address_thoroughfare';
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['label'] = '';
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['element_label_colon'] = FALSE;
  /* Field: Commerce Customer profile: Address - Premise (i.e. Apartment / Suite number) */
  $handler->display->display_options['fields']['commerce_customer_address_premise']['id'] = 'commerce_customer_address_premise';
  $handler->display->display_options['fields']['commerce_customer_address_premise']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_premise']['field'] = 'commerce_customer_address_premise';
  $handler->display->display_options['fields']['commerce_customer_address_premise']['label'] = '';
  $handler->display->display_options['fields']['commerce_customer_address_premise']['element_label_colon'] = FALSE;
  /* Field: Commerce Customer profile: Address - Locality (i.e. City) */
  $handler->display->display_options['fields']['commerce_customer_address_locality']['id'] = 'commerce_customer_address_locality';
  $handler->display->display_options['fields']['commerce_customer_address_locality']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_locality']['field'] = 'commerce_customer_address_locality';
  $handler->display->display_options['fields']['commerce_customer_address_locality']['label'] = '';
  $handler->display->display_options['fields']['commerce_customer_address_locality']['element_label_colon'] = FALSE;
  /* Field: Commerce Customer profile: Address - Country */
  $handler->display->display_options['fields']['commerce_customer_address_country']['id'] = 'commerce_customer_address_country';
  $handler->display->display_options['fields']['commerce_customer_address_country']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_country']['field'] = 'commerce_customer_address_country';
  $handler->display->display_options['fields']['commerce_customer_address_country']['label'] = '';
  $handler->display->display_options['fields']['commerce_customer_address_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_customer_address_country']['display_name'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[profile_id] -- [commerce_customer_address_name_line] -- [commerce_customer_address_thoroughfare] -- [commerce_customer_address_premise] -- [commerce_customer_address_locality] -- [commerce_customer_address_country]';
  /* Contextual filter: CRM Contact: Contact ID */
  $handler->display->display_options['arguments']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['arguments']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['arguments']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['arguments']['contact_id']['relationship'] = 'reverse_field_customer_profiles_crm_core_contact';
  $handler->display->display_options['arguments']['contact_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['contact_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['contact_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['contact_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['contact_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Commerce Customer Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_customer_profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'billing' => 'billing',
  );

  /* Display: Dependend Field Values */
  $handler = $view->new_display('dfv', 'Dependend Field Values', 'dfv_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'dfv_style';
  $handler->display->display_options['style_options']['title_field'] = 'nothing';
  $handler->display->display_options['style_options']['key_field'] = 'profile_id';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'dfv_fields';
  $handler->display->display_options['row_options']['separator'] = ' -- ';
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  $export['erpal_customer_profile'] = $view;

  $view = new view();
  $view->name = 'erpal_invoice_line_items';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_line_item';
  $view->human_name = 'ERPAL Invoice line items';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Create invoice';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'rendered_entity' => 'rendered_entity',
    'views_bulk_operations' => 'views_bulk_operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'rendered_entity' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'No Revenue ...';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Commerce Line Item: Order ID */
  $handler->display->display_options['relationships']['order_id']['id'] = 'order_id';
  $handler->display->display_options['relationships']['order_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['relationships']['order_id']['field'] = 'order_id';
  /* Field: Bulk operations: Commerce Line Item */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::erpal_invoice_create_invoice' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
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
    'action::erpal_commerce_create_invoice' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Commerce Line Item: Title */
  $handler->display->display_options['fields']['line_item_title']['id'] = 'line_item_title';
  $handler->display->display_options['fields']['line_item_title']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_title']['field'] = 'line_item_title';
  /* Field: Commerce Line item: Total */
  $handler->display->display_options['fields']['commerce_total']['id'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['table'] = 'field_data_commerce_total';
  $handler->display->display_options['fields']['commerce_total']['field'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['relationship'] = 'order_id';
  /* Contextual filter: Commerce Line item: Order (field_line_item_order) */
  $handler->display->display_options['arguments']['field_line_item_order_target_id']['id'] = 'field_line_item_order_target_id';
  $handler->display->display_options['arguments']['field_line_item_order_target_id']['table'] = 'field_data_field_line_item_order';
  $handler->display->display_options['arguments']['field_line_item_order_target_id']['field'] = 'field_line_item_order_target_id';
  $handler->display->display_options['arguments']['field_line_item_order_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_line_item_order_target_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_line_item_order_target_id']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_line_item_order_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_line_item_order_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_line_item_order_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Commerce Line Item: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_line_item';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'invoice' => 'invoice',
  );
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'order_id';
  $handler->display->display_options['filters']['type_1']['operator'] = 'not in';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'invoice' => 'invoice',
  );
  
  /* Display: Revenue */
  $handler = $view->new_display('panel_pane', 'Revenue', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Revenue';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Line Item: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['label'] = '';
  $handler->display->display_options['fields']['order_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['order_id']['element_label_colon'] = FALSE;
  /* Field: Bulk operations: Commerce Line Item */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::erpal_invoice_create_invoice' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_commerce_create_invoice' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
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
  /* Field: Commerce Line Item: Title */
  $handler->display->display_options['fields']['line_item_title']['id'] = 'line_item_title';
  $handler->display->display_options['fields']['line_item_title']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_title']['field'] = 'line_item_title';
  /* Field: Commerce Line item: Total */
  $handler->display->display_options['fields']['commerce_total']['id'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['table'] = 'field_data_commerce_total';
  $handler->display->display_options['fields']['commerce_total']['field'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Line Item: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Commerce Order: Invoice date */
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['id'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['relationship'] = 'order_id';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['label'] = 'Delivery date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['alter']['path'] = 'admin/commerce/orders/[order_id]';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Line Item: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_line_item';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'invoice' => 'invoice',
  );
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'order_id';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'commerce_order' => 'commerce_order',
    'invoice' => 'invoice',
  );
  $handler->display->display_options['filters']['type_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type_1']['expose']['operator_id'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['label'] = 'Delivered';
  $handler->display->display_options['filters']['type_1']['expose']['operator'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['type_1']['expose']['reduce'] = TRUE;
  $handler->display->display_options['argument_input'] = array(
    'field_line_item_order_target_id' => array(
      'type' => 'context',
      'context' => 'entity:commerce_order.order-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Commerce Line item: Order (field_line_item_order)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  
  /* Display: Revenue page */
  $handler = $view->new_display('page', 'Revenue page', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Revenue';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Commerce Line Item: Order ID */
  $handler->display->display_options['relationships']['order_id']['id'] = 'order_id';
  $handler->display->display_options['relationships']['order_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['relationships']['order_id']['field'] = 'order_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_line_item_order_target_id']['id'] = 'field_line_item_order_target_id';
  $handler->display->display_options['relationships']['field_line_item_order_target_id']['table'] = 'field_data_field_line_item_order';
  $handler->display->display_options['relationships']['field_line_item_order_target_id']['field'] = 'field_line_item_order_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_customer_target_id']['id'] = 'field_customer_target_id';
  $handler->display->display_options['relationships']['field_customer_target_id']['table'] = 'field_data_field_customer';
  $handler->display->display_options['relationships']['field_customer_target_id']['field'] = 'field_customer_target_id';
  $handler->display->display_options['relationships']['field_customer_target_id']['relationship'] = 'field_line_item_order_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Line Item: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['label'] = '';
  $handler->display->display_options['fields']['order_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['order_id']['element_label_colon'] = FALSE;
  /* Field: Bulk operations: Commerce Line Item */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::erpal_invoice_create_invoice' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_commerce_create_invoice' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
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
  /* Field: Commerce Line Item: Title */
  $handler->display->display_options['fields']['line_item_title']['id'] = 'line_item_title';
  $handler->display->display_options['fields']['line_item_title']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_title']['field'] = 'line_item_title';
  /* Field: Commerce Line item: Total */
  $handler->display->display_options['fields']['commerce_total']['id'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['table'] = 'field_data_commerce_total';
  $handler->display->display_options['fields']['commerce_total']['field'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['relationship'] = 'field_line_item_order_target_id';
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'admin';
  /* Field: Commerce Order: Customer */
  $handler->display->display_options['fields']['field_customer']['id'] = 'field_customer';
  $handler->display->display_options['fields']['field_customer']['table'] = 'field_data_field_customer';
  $handler->display->display_options['fields']['field_customer']['field'] = 'field_customer';
  $handler->display->display_options['fields']['field_customer']['relationship'] = 'field_line_item_order_target_id';
  $handler->display->display_options['fields']['field_customer']['settings'] = array(
    'link' => 1,
  );
  /* Field: Commerce Order: Invoice date */
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['id'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['relationship'] = 'order_id';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['label'] = 'Delivery date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['alter']['path'] = 'admin/commerce/orders/[order_id]';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Line Item: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_line_item';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'invoice' => 'invoice',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Commerce Order: Order number */
  $handler->display->display_options['filters']['order_number']['id'] = 'order_number';
  $handler->display->display_options['filters']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['order_number']['field'] = 'order_number';
  $handler->display->display_options['filters']['order_number']['relationship'] = 'field_line_item_order_target_id';
  $handler->display->display_options['filters']['order_number']['group'] = 1;
  $handler->display->display_options['filters']['order_number']['exposed'] = TRUE;
  $handler->display->display_options['filters']['order_number']['expose']['operator_id'] = 'order_number_op';
  $handler->display->display_options['filters']['order_number']['expose']['label'] = 'Order number';
  $handler->display->display_options['filters']['order_number']['expose']['operator'] = 'order_number_op';
  $handler->display->display_options['filters']['order_number']['expose']['identifier'] = 'order_number';
  $handler->display->display_options['filters']['order_number']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: CRM Core Contact: Household */
  $handler->display->display_options['filters']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['filters']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['filters']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['filters']['contact_name']['relationship'] = 'field_customer_target_id';
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
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'order_id';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'commerce_order' => 'commerce_order',
    'invoice' => 'invoice',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  $handler->display->display_options['filters']['type_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type_1']['expose']['operator_id'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['label'] = 'Delivered';
  $handler->display->display_options['filters']['type_1']['expose']['operator'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['type_1']['expose']['reduce'] = TRUE;
  /* Filter criterion: Commerce Order: Invoice date (field_commerce_billy_i_date) */
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['id'] = 'field_commerce_billy_i_date_value';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['field'] = 'field_commerce_billy_i_date_value';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['relationship'] = 'order_id';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['expose']['operator_id'] = 'field_commerce_billy_i_date_value_op';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['expose']['label'] = 'Delivery date';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['expose']['operator'] = 'field_commerce_billy_i_date_value_op';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['expose']['identifier'] = 'field_commerce_billy_i_date_value';
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_commerce_billy_i_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['path'] = 'invoices/line_items';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Invoice';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 1;
  $translatables['erpal_invoice_line_items'] = array(
    t('Master'),
    t('Create invoice'),
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
    t('No Revenue ...'),
    t('Order'),
    t('Commerce Line Item'),
    t('- Choose an operation -'),
    t('Title'),
    t('Total'),
    t('Order number'),
    t('All'),
    t('Revenue'),
    t('Created date'),
    t('Delivery date'),
    t('Delivered'),
    t('View panes'),
    t('Revenue page'),
    t('Commerce Order entity referenced from field_line_item_order'),
    t('CRM Core Contact entity referenced from field_customer'),
    t('Customer'),
  );

  $export['erpal_invoice_line_items'] = $view;

  $view = new view();
  $view->name = 'erpal_products';
  $view->description = 'Display a list of products.';
  $view->tag = 'commerce';
  $view->base_table = 'commerce_product';
  $view->human_name = 'ERPAL Products';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Products';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer commerce_product entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 50;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'sku' => 'sku',
    'title' => 'title',
    'type' => 'type',
    'commerce_price' => 'commerce_price',
    'status' => 'status',
    'operations' => 'operations',
  );
  $handler->display->display_options['style_options']['default'] = 'sku';
  $handler->display->display_options['style_options']['info'] = array(
    'sku' => array(
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
    'commerce_price' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* No results behavior: Commerce Product: Empty text */
  $handler->display->display_options['empty']['empty_text']['id'] = 'empty_text';
  $handler->display->display_options['empty']['empty_text']['table'] = 'commerce_product';
  $handler->display->display_options['empty']['empty_text']['field'] = 'empty_text';
  $handler->display->display_options['empty']['empty_text']['add_path'] = 'admin/commerce/products/add';
  /* Field: Commerce Product revision: Product ID */
  $handler->display->display_options['fields']['product_id']['id'] = 'product_id';
  $handler->display->display_options['fields']['product_id']['table'] = 'commerce_product_revision';
  $handler->display->display_options['fields']['product_id']['field'] = 'product_id';
  $handler->display->display_options['fields']['product_id']['label'] = '';
  $handler->display->display_options['fields']['product_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['product_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['product_id']['link_to_product'] = 0;
  /* Field: Commerce Product: SKU */
  $handler->display->display_options['fields']['sku']['id'] = 'sku';
  $handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['sku']['field'] = 'sku';
  $handler->display->display_options['fields']['sku']['link_to_product'] = 0;
  /* Field: Commerce Product: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'product/[product_id]';
  $handler->display->display_options['fields']['title']['link_to_product'] = 0;
  /* Field: Commerce Product: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['link_to_product'] = 0;
  /* Field: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  /* Field: Commerce Product: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['type'] = 'active-disabled';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Commerce Product: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['label'] = 'Operations';
  $handler->display->display_options['fields']['operations']['add_destination'] = 1;
  /* Sort criterion: Commerce Product: SKU */
  $handler->display->display_options['sorts']['sku']['id'] = 'sku';
  $handler->display->display_options['sorts']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['sorts']['sku']['field'] = 'sku';
  /* Filter criterion: Commerce Product: SKU */
  $handler->display->display_options['filters']['sku']['id'] = 'sku';
  $handler->display->display_options['filters']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['sku']['field'] = 'sku';
  $handler->display->display_options['filters']['sku']['operator'] = 'contains';
  $handler->display->display_options['filters']['sku']['exposed'] = TRUE;
  $handler->display->display_options['filters']['sku']['expose']['operator_id'] = 'sku_op';
  $handler->display->display_options['filters']['sku']['expose']['label'] = 'Filter by SKUs containing';
  $handler->display->display_options['filters']['sku']['expose']['operator'] = 'sku_op';
  $handler->display->display_options['filters']['sku']['expose']['identifier'] = 'sku';

  /* Display: Products */
  $handler = $view->new_display('page', 'Products', 'products_page');
  $handler->display->display_options['path'] = 'products';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Products';
  $handler->display->display_options['tab_options']['description'] = 'Manage products and product types in the store.';
  $handler->display->display_options['tab_options']['weight'] = '';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $translatables['erpal_products'] = array(
    t('Defaults'),
    t('Products'),
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
    t('SKU'),
    t('Title'),
    t('Type'),
    t('Price'),
    t('Status'),
    t('Operations'),
    t('Filter by SKUs containing'),
  );

  $export['erpal_products'] = $view;

  $view = new view();
  $view->name = 'erpal_activity_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'crm_core_activity';
  $view->human_name = 'ERPAL Activity Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: CRM Core Activity: Activity ID */
  $handler->display->display_options['fields']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['fields']['activity_id']['exclude'] = TRUE;
  /* Field: CRM Core Activity: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'crm_core_activity';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: CRM Activity: Customer */
  $handler->display->display_options['fields']['field_activity_customer']['id'] = 'field_activity_customer';
  $handler->display->display_options['fields']['field_activity_customer']['table'] = 'field_data_field_activity_customer';
  $handler->display->display_options['fields']['field_activity_customer']['field'] = 'field_activity_customer';
  $handler->display->display_options['fields']['field_activity_customer']['settings'] = array(
    'link' => 0,
  );
  /* Field: CRM Activity: Notes */
  $handler->display->display_options['fields']['field_activity_notes']['id'] = 'field_activity_notes';
  $handler->display->display_options['fields']['field_activity_notes']['table'] = 'field_data_field_activity_notes';
  $handler->display->display_options['fields']['field_activity_notes']['field'] = 'field_activity_notes';
  $handler->display->display_options['fields']['field_activity_notes']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_activity_notes']['settings'] = array(
    'trim_length' => '400',
  );
  /* Field: CRM Activity: Status */
  $handler->display->display_options['fields']['field_activity_status']['id'] = 'field_activity_status';
  $handler->display->display_options['fields']['field_activity_status']['table'] = 'field_data_field_activity_status';
  $handler->display->display_options['fields']['field_activity_status']['field'] = 'field_activity_status';
  /* Filter criterion: CRM Core Activity: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sales_process' => 'sales_process',
  );
  /* Filter criterion: CRM Core Activity: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'crm_core_activity';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Activity';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );

  /* Display: Reference dialog Search */
  $handler = $view->new_display('references_dialog', 'Reference dialog Search', 'references_dialog_1');
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['attach'] = array(
    0 => 'crm_core_activity:field_activity_sales_process:meeting',
    1 => 'crm_core_activity:field_activity_sales_process:phone_call',
    2 => 'crm_core_activity:field_activity_sales_process:email',
    3 => 'commerce_order:field_sales_process:quote',
  );
  $translatables['erpal_activity_search'] = array(
    t('Master'),
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
    t('Activity ID'),
    t('.'),
    t(','),
    t('Title'),
    t('Customer'),
    t('Notes'),
    t('Status'),
    t('Activity'),
    t('Reference dialog Search'),
  );

  $export['erpal_activity_search'] = $view;

  $view = new view();
  $view->name = 'erpal_contact_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'crm_core_contact';
  $view->human_name = 'ERPAL Contact Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: CRM Contact: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['contact_id']['link_to_contact'] = 0;
  /* Field: CRM Core Contact: Household */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['label'] = 'Contact';
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
  /* Field: CRM Core Contact: Address */
  $handler->display->display_options['fields']['field_customer_profiles']['id'] = 'field_customer_profiles';
  $handler->display->display_options['fields']['field_customer_profiles']['table'] = 'field_data_field_customer_profiles';
  $handler->display->display_options['fields']['field_customer_profiles']['field'] = 'field_customer_profiles';
  $handler->display->display_options['fields']['field_customer_profiles']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_customer_profiles']['delta_offset'] = '0';
  /* Field: CRM Core Contact: Email */
  $handler->display->display_options['fields']['field_contact_email_bundle']['id'] = 'field_contact_email_bundle';
  $handler->display->display_options['fields']['field_contact_email_bundle']['table'] = 'field_data_field_contact_email_bundle';
  $handler->display->display_options['fields']['field_contact_email_bundle']['field'] = 'field_contact_email_bundle';
  $handler->display->display_options['fields']['field_contact_email_bundle']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_contact_email_bundle']['delta_offset'] = '0';
  /* Field: CRM Core Contact: Phone */
  $handler->display->display_options['fields']['field_contact_phone_bundle']['id'] = 'field_contact_phone_bundle';
  $handler->display->display_options['fields']['field_contact_phone_bundle']['table'] = 'field_data_field_contact_phone_bundle';
  $handler->display->display_options['fields']['field_contact_phone_bundle']['field'] = 'field_contact_phone_bundle';
  $handler->display->display_options['fields']['field_contact_phone_bundle']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_contact_phone_bundle']['delta_offset'] = '0';
  /* Sort criterion: CRM Contact: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'crm_core_contact';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: CRM Core Contact: Household */
  $handler->display->display_options['filters']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['filters']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['filters']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['filters']['contact_name']['group'] = 1;
  $handler->display->display_options['filters']['contact_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['contact_name']['expose']['operator_id'] = 'contact_name_op';
  $handler->display->display_options['filters']['contact_name']['expose']['label'] = 'Contact';
  $handler->display->display_options['filters']['contact_name']['expose']['operator'] = 'contact_name_op';
  $handler->display->display_options['filters']['contact_name']['expose']['identifier'] = 'contact_name';
  $handler->display->display_options['filters']['contact_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );

  /* Display: Reference dialog Search */
  $handler = $view->new_display('references_dialog', 'Reference dialog Search', 'references_dialog_1');
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['attach'] = array(
    0 => 'commerce_order:field_vendor:commerce_order',
    1 => 'commerce_order:field_vendor:invoice',
    2 => 'commerce_order:field_vendor:quote',
    3 => 'commerce_order:field_customer:commerce_order',
    4 => 'commerce_order:field_customer:invoice',
    5 => 'commerce_order:field_customer:quote',
    6 => 'crm_core_activity:field_activity_participants:meeting',
    7 => 'crm_core_activity:field_activity_participants:phone_call',
    8 => 'crm_core_activity:field_activity_participants:email',
    9 => 'crm_core_activity:field_activity_participants:sales_process',
    10 => 'crm_core_activity:field_activity_customer:phone_call',
    11 => 'crm_core_activity:field_activity_customer:email',
    12 => 'crm_core_activity:field_activity_customer:sales_process',
    13 => 'crm_core_activity:field_activity_main_contact:sales_process',
  );
  $translatables['erpal_contact_search'] = array(
    t('Master'),
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
    t('Contact ID'),
    t('Contact'),
    t('Address'),
    t('Email'),
    t('Phone'),
    t('Reference dialog Search'),
  );

  $export['erpal_contact_search'] = $view;

  $view = new view();
  $view->name = 'erpal_quote_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_order';
  $view->human_name = 'ERPAL Quote Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'quote' => 'quote',
  );

  /* Display: Reference dialog Search */
  $handler = $view->new_display('references_dialog', 'Reference dialog Search', 'references_dialog_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'order_id' => 'order_id',
    'field_customer' => 'field_customer',
    'order_number' => 'order_number',
    'status' => 'status',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'order_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_customer' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['exclude'] = TRUE;
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  /* Field: Commerce Order: Customer */
  $handler->display->display_options['fields']['field_customer']['id'] = 'field_customer';
  $handler->display->display_options['fields']['field_customer']['table'] = 'field_data_field_customer';
  $handler->display->display_options['fields']['field_customer']['field'] = 'field_customer';
  $handler->display->display_options['fields']['field_customer']['settings'] = array(
    'link' => 0,
  );
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'quote' => 'quote',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Commerce Order: Order number */
  $handler->display->display_options['filters']['order_number']['id'] = 'order_number';
  $handler->display->display_options['filters']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['order_number']['field'] = 'order_number';
  $handler->display->display_options['filters']['order_number']['operator'] = 'contains';
  $handler->display->display_options['filters']['order_number']['group'] = 1;
  $handler->display->display_options['filters']['order_number']['exposed'] = TRUE;
  $handler->display->display_options['filters']['order_number']['expose']['operator_id'] = 'order_number_op';
  $handler->display->display_options['filters']['order_number']['expose']['label'] = 'Order number';
  $handler->display->display_options['filters']['order_number']['expose']['operator'] = 'order_number_op';
  $handler->display->display_options['filters']['order_number']['expose']['identifier'] = 'order_number';
  $handler->display->display_options['filters']['order_number']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['attach'] = array(
    0 => 'commerce_order:field_quote:commerce_order',
  );
  $translatables['erpal_quote_search'] = array(
    t('Master'),
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
    t('Order ID'),
    t('Reference dialog Search'),
    t('Order number'),
    t('Customer'),
    t('Order status'),
  );

  $export['erpal_quote_search'] = $view;
  return $export;
}

/**
 * Alter default views defined by other modules.
 *
 * This hook is called right before all default views are cached to the
 * database. It takes a keyed array of views by reference.
 *
 * Example usage to add a field to a view:
 * @code
 *   $handler =& $view->display['DISPLAY_ID']->handler;
 *   // Add the user name field to the view.
 *   $handler->display->display_options['fields']['name']['id'] = 'name';
 *   $handler->display->display_options['fields']['name']['table'] = 'users';
 *   $handler->display->display_options['fields']['name']['field'] = 'name';
 *   $handler->display->display_options['fields']['name']['label'] = 'Author';
 *   $handler->display->display_options['fields']['name']['link_to_user'] = 1;
 * @endcode
 */
function erpal_commerce_views_default_views_alter(&$views) {

  if (isset($views['commerce_line_item_table'])) {
    unset($views['commerce_line_item_table']->display['default']->display_options['filters']);
  }

  // Add new VBO to invoice view.
  if (isset($views['erpal_invoice_line_items'])) {
    $views['erpal_invoice_line_items']->display['default']->handler->display
    ->display_options['fields']['views_bulk_operations']['vbo_operations']['action::erpal_invoice_create_invoice']['selected'] = 0;

    $views['erpal_invoice_line_items']->display['default']->handler->display
    ->display_options['fields']['views_bulk_operations']['vbo_operations']['action::erpal_commerce_create_invoice'] = array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    );
  }

  if (isset($views['erpal_invoice'])) {
    $view = $views['erpal_invoice'];
    // Disable VBO action Delete item.
    $view->display['default']->handler->display
    ->display_options['fields']['views_bulk_operations']['vbo_operations']['action::views_bulk_operations_delete_item']['selected'] = 0;
    // Enable custom invoice deletion VBO.
    $view->display['default']->handler->display
    ->display_options['fields']['views_bulk_operations']['vbo_operations']['action::erpal_commerce_delete_invoice'] = array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    );

    // Disable set to invoiced.
    $view->display['default']->handler->display
    ->display_options['fields']['views_bulk_operations']['vbo_operations']['rules_component::rules_commerce_billy_set_to_invoiced']['selected'] = 0;
    $view->display['page_1']->handler->display
    ->display_options['fields']['views_bulk_operations']['vbo_operations']['rules_component::rules_commerce_billy_set_to_invoiced']['selected'] = 0;

    /* Display: Invoices by Contact */

    $handler = $view->new_display('panel_pane', 'Invoices by Contact', 'panel_pane_1');
    $handler->display->display_options['defaults']['title'] = FALSE;
    $handler->display->display_options['title'] = 'Invoices';
    $handler->display->display_options['defaults']['empty'] = FALSE;
    /* No results behavior: Global: Text area */
    $handler->display->display_options['empty']['area']['id'] = 'area';
    $handler->display->display_options['empty']['area']['table'] = 'views';
    $handler->display->display_options['empty']['area']['field'] = 'area';
    $handler->display->display_options['empty']['area']['empty'] = TRUE;
    $handler->display->display_options['empty']['area']['content'] = 'Invoices not found. Please, create new invoice. ';
    $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
    $handler->display->display_options['defaults']['relationships'] = FALSE;
    /* Relationship: Entity Reference: Referenced Entity */
    $handler->display->display_options['relationships']['field_customer_target_id']['id'] = 'field_customer_target_id';
    $handler->display->display_options['relationships']['field_customer_target_id']['table'] = 'field_data_field_customer';
    $handler->display->display_options['relationships']['field_customer_target_id']['field'] = 'field_customer_target_id';
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Commerce Order: Order number */
    $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
    $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
    $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
    $handler->display->display_options['fields']['order_number']['label'] = 'Invoice number';
    $handler->display->display_options['fields']['order_number']['alter']['path'] = 'admin/commerce/orders/[order_id]/pdf';
    $handler->display->display_options['fields']['order_number']['link_to_order'] = 'admin';
    /* Field: Commerce Order: Invoice PDF */
    $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['id'] = 'commerce_billy_pdf_invoice_link';
    $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['table'] = 'views_entity_commerce_order';
    $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['field'] = 'commerce_billy_pdf_invoice_link';
    $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['label'] = 'Download PDF';
    /* Field: Commerce Order: Customer */
    $handler->display->display_options['fields']['field_customer']['id'] = 'field_customer';
    $handler->display->display_options['fields']['field_customer']['table'] = 'field_data_field_customer';
    $handler->display->display_options['fields']['field_customer']['field'] = 'field_customer';
    $handler->display->display_options['fields']['field_customer']['settings'] = array(
      'link' => 1,
    );
    /* Field: Commerce Order: Order status */
    $handler->display->display_options['fields']['status']['id'] = 'status';
    $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
    $handler->display->display_options['fields']['status']['field'] = 'status';
    $handler->display->display_options['fields']['status']['label'] = 'Invoice status';
    /* Field: Commerce Order: Order total */
    $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
    $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
    $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
    $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Invoice total';
    $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
    $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
      'calculation' => FALSE,
    );
    /* Field: Commerce Order: Invoice date */
    $handler->display->display_options['fields']['field_commerce_billy_i_date']['id'] = 'field_commerce_billy_i_date';
    $handler->display->display_options['fields']['field_commerce_billy_i_date']['table'] = 'field_data_field_commerce_billy_i_date';
    $handler->display->display_options['fields']['field_commerce_billy_i_date']['field'] = 'field_commerce_billy_i_date';
    $handler->display->display_options['fields']['field_commerce_billy_i_date']['settings'] = array(
      'format_type' => 'short',
      'fromto' => 'both',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
    );
    /* Field: Commerce Order: Edit link */
    $handler->display->display_options['fields']['edit_order']['id'] = 'edit_order';
    $handler->display->display_options['fields']['edit_order']['table'] = 'commerce_order';
    $handler->display->display_options['fields']['edit_order']['field'] = 'edit_order';
    $handler->display->display_options['fields']['edit_order']['alter']['text'] = 'Edit';
    $handler->display->display_options['fields']['edit_order']['alter']['path'] = 'order/[order_id]/edit';
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    /* Contextual filter: CRM Contact: Contact ID */
    $handler->display->display_options['arguments']['contact_id']['id'] = 'contact_id';
    $handler->display->display_options['arguments']['contact_id']['table'] = 'crm_core_contact';
    $handler->display->display_options['arguments']['contact_id']['field'] = 'contact_id';
    $handler->display->display_options['arguments']['contact_id']['relationship'] = 'field_customer_target_id';
    $handler->display->display_options['arguments']['contact_id']['default_action'] = 'empty';
    $handler->display->display_options['arguments']['contact_id']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['contact_id']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['contact_id']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['contact_id']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['defaults']['filter_groups'] = FALSE;
    $handler->display->display_options['defaults']['filters'] = FALSE;
    /* Filter criterion: Commerce Order: Order type */
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['value'] = array(
      'invoice' => 'invoice',
    );
    $handler->display->display_options['filters']['type']['group'] = 1;
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

  }
}
