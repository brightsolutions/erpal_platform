<?php
/**
 * @file
 * erpal_commerce_ui.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function erpal_commerce_ui_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'erpal_order';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_order';
  $view->human_name = 'ERPAL Order';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'ERPAL Orders';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any commerce_order entity of bundle commerce_order';
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
    'views_bulk_operations' => 'views_bulk_operations',
    'order_number' => 'order_number',
    'erpal_commerce_ui_order_link' => 'erpal_commerce_ui_order_link',
    'field_customer' => 'field_customer',
    'status' => 'status',
    'commerce_order_total' => 'commerce_order_total',
    'edit_order' => 'edit_order',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'erpal_commerce_ui_order_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_customer' => array(
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
    'commerce_order_total' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_order' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'Orders not found. Please, create new order.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Bulk operations: Commerce Order */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'commerce_order';
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
    'rules_component::rules_commerce_billy_set_to_canceled' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_commerce_billy_set_to_invoiced' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['alter']['path'] = 'admin/commerce/orders/[order_id]/order_pdf';
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'admin';
  /* Field: Commerce Order: Order PDF */
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['id'] = 'erpal_commerce_ui_order_link';
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['table'] = 'views_entity_commerce_order';
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['field'] = 'erpal_commerce_ui_order_link';
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
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Edit link */
  $handler->display->display_options['fields']['edit_order']['id'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['edit_order']['field'] = 'edit_order';
  /* Sort criterion: Commerce Order: Order ID */
  $handler->display->display_options['sorts']['order_id']['id'] = 'order_id';
  $handler->display->display_options['sorts']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['sorts']['order_id']['field'] = 'order_id';
  $handler->display->display_options['sorts']['order_id']['order'] = 'DESC';
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'commerce_order' => 'commerce_order',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'canceled' => 'canceled',
    'pending' => 'pending',
    'processing' => 'processing',
    'completed' => 'completed',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Order status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['status']['expose']['reduce'] = TRUE;
  /* Filter criterion: Commerce Order: Customer (field_customer) */
  $handler->display->display_options['filters']['field_customer_target_id']['id'] = 'field_customer_target_id';
  $handler->display->display_options['filters']['field_customer_target_id']['table'] = 'field_data_field_customer';
  $handler->display->display_options['filters']['field_customer_target_id']['field'] = 'field_customer_target_id';
  $handler->display->display_options['filters']['field_customer_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_customer_target_id']['expose']['operator_id'] = 'field_customer_target_id_op';
  $handler->display->display_options['filters']['field_customer_target_id']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['field_customer_target_id']['expose']['operator'] = 'field_customer_target_id_op';
  $handler->display->display_options['filters']['field_customer_target_id']['expose']['identifier'] = 'field_customer_target_id';
  $handler->display->display_options['filters']['field_customer_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  
  /* Display: Admin page */
  $handler = $view->new_display('page', 'Admin page', 'page');
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_customer_target_id']['id'] = 'field_customer_target_id';
  $handler->display->display_options['relationships']['field_customer_target_id']['table'] = 'field_data_field_customer';
  $handler->display->display_options['relationships']['field_customer_target_id']['field'] = 'field_customer_target_id';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'commerce_order' => 'commerce_order',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'canceled' => 'canceled',
    'pending' => 'pending',
    'processing' => 'processing',
    'completed' => 'completed',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Order status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['status']['expose']['reduce'] = TRUE;
  /* Filter criterion: CRM Core Contact: Household */
  $handler->display->display_options['filters']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['filters']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['filters']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['filters']['contact_name']['relationship'] = 'field_customer_target_id';
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
  $handler->display->display_options['path'] = 'admin/erpal/orders';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'ERPAL Orders';
  $handler->display->display_options['menu']['description'] = 'Manage ERPAL Orders.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  
  /* Display: User page */
  $handler = $view->new_display('page', 'User page', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'order_number' => 'order_number',
    'created' => 'created',
    'field_customer' => 'field_customer',
    'status' => 'status',
    'commerce_order_total' => 'commerce_order_total',
    'erpal_commerce_ui_order_link' => 'erpal_commerce_ui_order_link',
    'edit_order' => 'edit_order',
    'views_bulk_operations' => 'views_bulk_operations',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'order_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_customer' => array(
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
    'commerce_order_total' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'erpal_commerce_ui_order_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_order' => array(
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
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
  $handler->display->display_options['fields']['order_number']['label'] = 'Order';
  $handler->display->display_options['fields']['order_number']['alter']['path'] = 'order/[order_id]';
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'admin';
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'year';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
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
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Order PDF */
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['id'] = 'erpal_commerce_ui_order_link';
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['table'] = 'views_entity_commerce_order';
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['field'] = 'erpal_commerce_ui_order_link';
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['label'] = 'PDF';
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['text'] = 'PDF';
  /* Field: Commerce Order: Edit link */
  $handler->display->display_options['fields']['edit_order']['id'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['edit_order']['field'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['label'] = '';
  $handler->display->display_options['fields']['edit_order']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['edit_order']['alter']['path'] = 'order/[order_id]/edit';
  $handler->display->display_options['fields']['edit_order']['element_label_colon'] = FALSE;
  /* Field: Bulk operations: Commerce Order */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'commerce_order';
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
    'rules_component::rules_commerce_billy_set_to_canceled' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_commerce_billy_set_to_invoiced' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'commerce_order' => 'commerce_order',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'canceled' => 'canceled',
    'pending' => 'pending',
    'processing' => 'processing',
    'completed' => 'completed',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Order status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['status']['expose']['reduce'] = TRUE;
  /* Filter criterion: CRM Core Contact: Household */
  $handler->display->display_options['filters']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['filters']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['filters']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['filters']['contact_name']['relationship'] = 'field_customer_target_id';
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
  $handler->display->display_options['path'] = 'orders';
  
  /* Display: Activity by Order */
  $handler = $view->new_display('panel_pane', 'Activity by Order', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Sales process';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_quote_target_id']['id'] = 'field_quote_target_id';
  $handler->display->display_options['relationships']['field_quote_target_id']['table'] = 'field_data_field_quote';
  $handler->display->display_options['relationships']['field_quote_target_id']['field'] = 'field_quote_target_id';
  $handler->display->display_options['relationships']['field_quote_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Order: Sales process */
  $handler->display->display_options['fields']['field_sales_process']['id'] = 'field_sales_process';
  $handler->display->display_options['fields']['field_sales_process']['table'] = 'field_data_field_sales_process';
  $handler->display->display_options['fields']['field_sales_process']['field'] = 'field_sales_process';
  $handler->display->display_options['fields']['field_sales_process']['relationship'] = 'field_quote_target_id';
  $handler->display->display_options['fields']['field_sales_process']['label'] = '';
  $handler->display->display_options['fields']['field_sales_process']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sales_process']['empty'] = 'Activity not found. Please, create new Activity or add Activity to the quote.';
  $handler->display->display_options['fields']['field_sales_process']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_sales_process']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_sales_process']['settings'] = array(
    'view_mode' => 'full',
    'links' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Commerce Order: Order ID */
  $handler->display->display_options['arguments']['order_id']['id'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['order_id']['field'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['order_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['order_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['order_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['order_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['argument_input'] = array(
    'order_id' => array(
      'type' => 'context',
      'context' => 'entity:commerce_order.order-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Commerce Order: Order ID',
    ),
  );
  
  /* Display: Orders by Activity */
  $handler = $view->new_display('panel_pane', 'Orders by Activity', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Orders';
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
  $handler->display->display_options['empty']['area']['content'] = 'Orders not found. Please, create new order.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_quote_target_id']['id'] = 'field_quote_target_id';
  $handler->display->display_options['relationships']['field_quote_target_id']['table'] = 'field_data_field_quote';
  $handler->display->display_options['relationships']['field_quote_target_id']['field'] = 'field_quote_target_id';
  $handler->display->display_options['relationships']['field_quote_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_sales_process_target_id']['id'] = 'field_sales_process_target_id';
  $handler->display->display_options['relationships']['field_sales_process_target_id']['table'] = 'field_data_field_sales_process';
  $handler->display->display_options['relationships']['field_sales_process_target_id']['field'] = 'field_sales_process_target_id';
  $handler->display->display_options['relationships']['field_sales_process_target_id']['relationship'] = 'field_quote_target_id';
  $handler->display->display_options['relationships']['field_sales_process_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['alter']['path'] = 'order/[order_id]';
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'admin';
  /* Field: Commerce Order: Order PDF */
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['id'] = 'erpal_commerce_ui_order_link';
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['table'] = 'views_entity_commerce_order';
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['field'] = 'erpal_commerce_ui_order_link';
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
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Edit link */
  $handler->display->display_options['fields']['edit_order']['id'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['edit_order']['field'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['edit_order']['alter']['path'] = 'order/[order_id]/edit';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: CRM Core Activity: Activity ID */
  $handler->display->display_options['arguments']['activity_id']['id'] = 'activity_id';
  $handler->display->display_options['arguments']['activity_id']['table'] = 'crm_core_activity';
  $handler->display->display_options['arguments']['activity_id']['field'] = 'activity_id';
  $handler->display->display_options['arguments']['activity_id']['relationship'] = 'field_sales_process_target_id';
  $handler->display->display_options['arguments']['activity_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['activity_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['activity_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['activity_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['activity_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'commerce_order' => 'commerce_order',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  
  /* Display: Orders by Contact */
  $handler = $view->new_display('panel_pane', 'Orders by Contact', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Orders';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_customer_target_id']['id'] = 'field_customer_target_id';
  $handler->display->display_options['relationships']['field_customer_target_id']['table'] = 'field_data_field_customer';
  $handler->display->display_options['relationships']['field_customer_target_id']['field'] = 'field_customer_target_id';
  $handler->display->display_options['relationships']['field_customer_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['alter']['path'] = 'order/[order_id]';
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'admin';
  /* Field: Commerce Order: Order PDF */
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['id'] = 'erpal_commerce_ui_order_link';
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['table'] = 'views_entity_commerce_order';
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['field'] = 'erpal_commerce_ui_order_link';
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
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Edit link */
  $handler->display->display_options['fields']['edit_order']['id'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['edit_order']['field'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_order']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['edit_order']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['edit_order']['alter']['path'] = 'order/[order_id]/edit';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: CRM Core Contact: Contact ID */
  $handler->display->display_options['arguments']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['arguments']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['arguments']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['arguments']['contact_id']['relationship'] = 'field_customer_target_id';
  $handler->display->display_options['arguments']['contact_id']['default_action'] = 'not found';
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
    'commerce_order' => 'commerce_order',
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
  
  /* Display: Quote by Order */
  $handler = $view->new_display('panel_pane', 'Quote by Order', 'panel_pane_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Quote';
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
  $handler->display->display_options['empty']['area']['content'] = 'Quotes not found. Please, create new quote.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_quote_commerce_order']['id'] = 'reverse_field_quote_commerce_order';
  $handler->display->display_options['relationships']['reverse_field_quote_commerce_order']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['reverse_field_quote_commerce_order']['field'] = 'reverse_field_quote_commerce_order';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['alter']['path'] = 'order/[order_id]';
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'admin';
  /* Field: Commerce Order: Quote PDF */
  $handler->display->display_options['fields']['erpal_quote_ui_order_link']['id'] = 'erpal_quote_ui_order_link';
  $handler->display->display_options['fields']['erpal_quote_ui_order_link']['table'] = 'views_entity_commerce_order';
  $handler->display->display_options['fields']['erpal_quote_ui_order_link']['field'] = 'erpal_quote_ui_order_link';
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
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Edit link */
  $handler->display->display_options['fields']['edit_order']['id'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['edit_order']['field'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['edit_order']['alter']['path'] = 'order/[order_id]/edit';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Commerce Order: Order ID */
  $handler->display->display_options['arguments']['order_id']['id'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['order_id']['field'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['relationship'] = 'reverse_field_quote_commerce_order';
  $handler->display->display_options['arguments']['order_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['order_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['order_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['order_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['order_id']['summary_options']['items_per_page'] = '25';
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
  $handler->display->display_options['argument_input'] = array(
    'order_id' => array(
      'type' => 'context',
      'context' => 'entity:commerce_order.order-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Commerce Order: Order ID',
    ),
  );
  
  /* Display: Invoices by Order */
  $handler = $view->new_display('panel_pane', 'Invoices by Order', 'panel_pane_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Invoices';
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
  $handler->display->display_options['empty']['area']['content'] = 'Invoices not found. Please, create a new invoice.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'Invoice number';
  $handler->display->display_options['fields']['order_number']['alter']['path'] = 'order/[order_id]';
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'admin';
  /* Field: Commerce Order: Invoice PDF */
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['id'] = 'commerce_billy_pdf_invoice_link';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['table'] = 'views_entity_commerce_order';
  $handler->display->display_options['fields']['commerce_billy_pdf_invoice_link']['field'] = 'commerce_billy_pdf_invoice_link';
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
  /* Field: Commerce Order: Edit link */
  $handler->display->display_options['fields']['edit_order']['id'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['edit_order']['field'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['edit_order']['alter']['path'] = 'order/[order_id]/edit';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Commerce Order: Order (field_invoice_order) */
  $handler->display->display_options['arguments']['field_invoice_order_target_id']['id'] = 'field_invoice_order_target_id';
  $handler->display->display_options['arguments']['field_invoice_order_target_id']['table'] = 'field_data_field_invoice_order';
  $handler->display->display_options['arguments']['field_invoice_order_target_id']['field'] = 'field_invoice_order_target_id';
  $handler->display->display_options['arguments']['field_invoice_order_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_invoice_order_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_invoice_order_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_invoice_order_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_invoice_order_target_id']['summary_options']['items_per_page'] = '25';
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
    'field_invoice_order_target_id' => array(
      'type' => 'context',
      'context' => 'entity:commerce_order.order-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Commerce Order: Order (field_invoice_order)',
    ),
  );
  
  /* Display: Orders by Invoice */
  $handler = $view->new_display('panel_pane', 'Orders by Invoice', 'panel_pane_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Orders';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
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
  $handler->display->display_options['empty']['area']['content'] = 'Orders not found. Please, create new order.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_invoice_order_target_id']['id'] = 'field_invoice_order_target_id';
  $handler->display->display_options['relationships']['field_invoice_order_target_id']['table'] = 'field_data_field_invoice_order';
  $handler->display->display_options['relationships']['field_invoice_order_target_id']['field'] = 'field_invoice_order_target_id';
  $handler->display->display_options['relationships']['field_invoice_order_target_id']['label'] = 'Order';
  $handler->display->display_options['relationships']['field_invoice_order_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['relationship'] = 'field_invoice_order_target_id';
  $handler->display->display_options['fields']['order_number']['alter']['path'] = 'order/[order_id]';
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'admin';
  /* Field: Commerce Order: Order PDF */
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['id'] = 'erpal_commerce_ui_order_link';
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['table'] = 'views_entity_commerce_order';
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['field'] = 'erpal_commerce_ui_order_link';
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['relationship'] = 'field_invoice_order_target_id';
  /* Field: Commerce Order: Customer */
  $handler->display->display_options['fields']['field_customer']['id'] = 'field_customer';
  $handler->display->display_options['fields']['field_customer']['table'] = 'field_data_field_customer';
  $handler->display->display_options['fields']['field_customer']['field'] = 'field_customer';
  $handler->display->display_options['fields']['field_customer']['relationship'] = 'field_invoice_order_target_id';
  $handler->display->display_options['fields']['field_customer']['settings'] = array(
    'link' => 1,
  );
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'field_invoice_order_target_id';
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['relationship'] = 'field_invoice_order_target_id';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Edit link */
  $handler->display->display_options['fields']['edit_order']['id'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['edit_order']['field'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['relationship'] = 'field_invoice_order_target_id';
  $handler->display->display_options['fields']['edit_order']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['edit_order']['alter']['path'] = 'order/[order_id]/edit';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Commerce Order: Order ID */
  $handler->display->display_options['arguments']['order_id']['id'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['order_id']['field'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['order_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['order_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['order_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['order_id']['summary_options']['items_per_page'] = '25';
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
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'field_invoice_order_target_id';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'commerce_order' => 'commerce_order',
  );
  $handler->display->display_options['argument_input'] = array(
    'order_id' => array(
      'type' => 'context',
      'context' => 'entity:commerce_order.order-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Commerce Order: Order ID',
    ),
  );
  
  /* Display: dashboard */
  $handler = $view->new_display('block', 'dashboard', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Orders';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="orders" class="link-global-view">Full view</a>';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Orders not found. Please, create new order.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['alter']['path'] = 'admin/commerce/orders/[order_id]/order_pdf';
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'admin';
  /* Field: Commerce Order: Order PDF */
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['id'] = 'erpal_commerce_ui_order_link';
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['table'] = 'views_entity_commerce_order';
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['field'] = 'erpal_commerce_ui_order_link';
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Edit link */
  $handler->display->display_options['fields']['edit_order']['id'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['edit_order']['field'] = 'edit_order';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'commerce_order' => 'commerce_order',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  
  /* Display: Orders by Contact Teaser */
  $handler = $view->new_display('panel_pane', 'Orders by Contact Teaser', 'panel_pane_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Orders';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = 'qoi-teaser-list orders-teaser-list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_customer_target_id']['id'] = 'field_customer_target_id';
  $handler->display->display_options['relationships']['field_customer_target_id']['table'] = 'field_data_field_customer';
  $handler->display->display_options['relationships']['field_customer_target_id']['field'] = 'field_customer_target_id';
  $handler->display->display_options['relationships']['field_customer_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = '';
  $handler->display->display_options['fields']['order_number']['alter']['path'] = 'order/[order_id]';
  $handler->display->display_options['fields']['order_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'admin';
  /* Field: Commerce Order: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'year';
  $handler->display->display_options['fields']['changed']['format_date_sql'] = 0;
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = '';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  /* Field: Commerce Order: Order PDF */
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['id'] = 'erpal_commerce_ui_order_link';
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['table'] = 'views_entity_commerce_order';
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['field'] = 'erpal_commerce_ui_order_link';
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['label'] = '';
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['alter']['link_class'] = 'pdf-link';
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['erpal_commerce_ui_order_link']['text'] = 'PDF';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: CRM Core Contact: Contact ID */
  $handler->display->display_options['arguments']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['arguments']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['arguments']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['arguments']['contact_id']['relationship'] = 'field_customer_target_id';
  $handler->display->display_options['arguments']['contact_id']['default_action'] = 'not found';
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
    'commerce_order' => 'commerce_order',
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
  $translatables['erpal_order'] = array(
    t('Master'),
    t('ERPAL Orders'),
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
    t('Orders not found. Please, create new order.'),
    t('Commerce Order'),
    t('- Choose an operation -'),
    t('Order number'),
    t('Order PDF'),
    t('Customer'),
    t('Order status'),
    t('Order total'),
    t('Edit link'),
    t('Admin page'),
    t('@total rows'),
    t('CRM Core Contact entity referenced from field_customer'),
    t('User page'),
    t('Order'),
    t('Date'),
    t('Status'),
    t('Total'),
    t('PDF'),
    t('Edit'),
    t('Activity by Order'),
    t('Sales process'),
    t('Commerce Order entity referenced from field_quote'),
    t('Activity not found. Please, create new Activity or add Activity to the quote.'),
    t('All'),
    t('View panes'),
    t('Orders by Activity'),
    t('Orders'),
    t('CRM Core Activity entity referenced from field_sales_process'),
    t('Orders by Contact'),
    t('Quote by Order'),
    t('Quote'),
    t('Quotes not found. Please, create new quote.'),
    t('Commerce Order referencing Commerce Order from field_quote'),
    t('Quote PDF'),
    t('Invoices by Order'),
    t('Invoices'),
    t('Invoices not found. Please, create a new invoice.'),
    t('Invoice number'),
    t('Invoice PDF'),
    t('Invoice status'),
    t('Invoice total'),
    t('Orders by Invoice'),
    t('dashboard'),
    t('<a href="orders" class="link-global-view">Full view</a>'),
    t('Orders by Contact Teaser'),
  );

  $export['erpal_order'] = $view;


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
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create commerce_order entities of bundle invoice';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'line_item_title' => 'line_item_title',
    'commerce_total' => 'commerce_total',
    'order_number' => 'order_number',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'line_item_title' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_total' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
  /* Sort criterion: Commerce Line Item: Line item ID */
  $handler->display->display_options['sorts']['line_item_id']['id'] = 'line_item_id';
  $handler->display->display_options['sorts']['line_item_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['sorts']['line_item_id']['field'] = 'line_item_id';
  $handler->display->display_options['sorts']['line_item_id']['order'] = 'DESC';
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Line Item: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['label'] = '';
  $handler->display->display_options['fields']['order_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['order_id']['element_label_colon'] = FALSE;
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
  /* Field: Commerce Line item: Delivery date */
  $handler->display->display_options['fields']['field_line_item_delivery_date']['id'] = 'field_line_item_delivery_date';
  $handler->display->display_options['fields']['field_line_item_delivery_date']['table'] = 'field_data_field_line_item_delivery_date';
  $handler->display->display_options['fields']['field_line_item_delivery_date']['field'] = 'field_line_item_delivery_date';
  $handler->display->display_options['fields']['field_line_item_delivery_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_line_item_delivery_date']['group_column'] = 'target_id';
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['relationship'] = 'order_id';
  $handler->display->display_options['fields']['order_number']['label'] = '';
  $handler->display->display_options['fields']['order_number']['exclude'] = TRUE;
  $handler->display->display_options['fields']['order_number']['element_label_colon'] = FALSE;
  /* Field: Commerce Order: Invoice date */
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['id'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['relationship'] = 'order_id';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['label'] = 'Invoice';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['alter']['text'] = '[order_number]';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['alter']['path'] = 'admin/commerce/orders/[order_id]';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
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
  $handler->display->display_options['filters']['type_1']['expose']['label'] = 'Billed';
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
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'order_id' => 'order_id',
    'order_number' => 'order_number',
    'line_item_title' => 'line_item_title',
    'commerce_total' => 'commerce_total',
    'field_customer' => 'field_customer',
    'field_line_item_delivery_date' => 'field_line_item_delivery_date',
    'order_number_1' => 'order_number_1',
    'field_commerce_billy_i_date' => 'field_commerce_billy_i_date',
    'views_bulk_operations' => 'views_bulk_operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'order_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'line_item_title' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_total' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_customer' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_line_item_delivery_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_number_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_commerce_billy_i_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
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
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['relationship'] = 'field_line_item_order_target_id';
  $handler->display->display_options['fields']['order_number']['label'] = 'Order';
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'admin';
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
  /* Field: Commerce Order: Customer */
  $handler->display->display_options['fields']['field_customer']['id'] = 'field_customer';
  $handler->display->display_options['fields']['field_customer']['table'] = 'field_data_field_customer';
  $handler->display->display_options['fields']['field_customer']['field'] = 'field_customer';
  $handler->display->display_options['fields']['field_customer']['relationship'] = 'field_line_item_order_target_id';
  $handler->display->display_options['fields']['field_customer']['settings'] = array(
    'link' => 1,
  );
  /* Field: Commerce Line item: Delivery date */
  $handler->display->display_options['fields']['field_line_item_delivery_date']['id'] = 'field_line_item_delivery_date';
  $handler->display->display_options['fields']['field_line_item_delivery_date']['table'] = 'field_data_field_line_item_delivery_date';
  $handler->display->display_options['fields']['field_line_item_delivery_date']['field'] = 'field_line_item_delivery_date';
  $handler->display->display_options['fields']['field_line_item_delivery_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_line_item_delivery_date']['group_column'] = 'target_id';
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number_1']['id'] = 'order_number_1';
  $handler->display->display_options['fields']['order_number_1']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number_1']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number_1']['relationship'] = 'order_id';
  $handler->display->display_options['fields']['order_number_1']['label'] = '';
  $handler->display->display_options['fields']['order_number_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['order_number_1']['element_label_colon'] = FALSE;
  /* Field: Commerce Order: Invoice date */
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['id'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['relationship'] = 'order_id';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['label'] = 'Invoice';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['alter']['text'] = '[order_number_1]';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['alter']['path'] = 'admin/commerce/orders/[order_id]';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
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
  $handler->display->display_options['filters']['type_1']['expose']['label'] = 'Billed';
  $handler->display->display_options['filters']['type_1']['expose']['operator'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['type_1']['expose']['reduce'] = TRUE;
  /* Filter criterion: Commerce Line item: Delivery date (field_line_item_delivery_date) */
  $handler->display->display_options['filters']['field_line_item_delivery_date_value']['id'] = 'field_line_item_delivery_date_value';
  $handler->display->display_options['filters']['field_line_item_delivery_date_value']['table'] = 'field_data_field_line_item_delivery_date';
  $handler->display->display_options['filters']['field_line_item_delivery_date_value']['field'] = 'field_line_item_delivery_date_value';
  $handler->display->display_options['filters']['field_line_item_delivery_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_line_item_delivery_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_line_item_delivery_date_value']['expose']['operator_id'] = 'field_line_item_delivery_date_value_op';
  $handler->display->display_options['filters']['field_line_item_delivery_date_value']['expose']['label'] = 'Delivery date';
  $handler->display->display_options['filters']['field_line_item_delivery_date_value']['expose']['operator'] = 'field_line_item_delivery_date_value_op';
  $handler->display->display_options['filters']['field_line_item_delivery_date_value']['expose']['identifier'] = 'field_line_item_delivery_date_value';
  $handler->display->display_options['filters']['field_line_item_delivery_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_line_item_delivery_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['path'] = 'invoices/line_items';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Invoice';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 1;
  
  /* Display: Project Revenue */
  $handler = $view->new_display('panel_pane', 'Project Revenue', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Revenue';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
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
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Commerce Line Item: Order ID */
  $handler->display->display_options['relationships']['order_id']['id'] = 'order_id';
  $handler->display->display_options['relationships']['order_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['relationships']['order_id']['field'] = 'order_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_project_order_node']['id'] = 'reverse_field_project_order_node';
  $handler->display->display_options['relationships']['reverse_field_project_order_node']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['reverse_field_project_order_node']['field'] = 'reverse_field_project_order_node';
  $handler->display->display_options['relationships']['reverse_field_project_order_node']['relationship'] = 'order_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Line Item: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['label'] = '';
  $handler->display->display_options['fields']['order_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['order_id']['element_label_colon'] = FALSE;
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
  /* Field: Commerce Line item: Delivery date */
  $handler->display->display_options['fields']['field_line_item_delivery_date']['id'] = 'field_line_item_delivery_date';
  $handler->display->display_options['fields']['field_line_item_delivery_date']['table'] = 'field_data_field_line_item_delivery_date';
  $handler->display->display_options['fields']['field_line_item_delivery_date']['field'] = 'field_line_item_delivery_date';
  $handler->display->display_options['fields']['field_line_item_delivery_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_line_item_delivery_date']['group_column'] = 'target_id';
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['relationship'] = 'order_id';
  $handler->display->display_options['fields']['order_number']['label'] = '';
  $handler->display->display_options['fields']['order_number']['exclude'] = TRUE;
  $handler->display->display_options['fields']['order_number']['element_label_colon'] = FALSE;
  /* Field: Commerce Order: Invoice date */
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['id'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['table'] = 'field_data_field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['field'] = 'field_commerce_billy_i_date';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['relationship'] = 'order_id';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['label'] = 'Invoice';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['alter']['text'] = '[order_number]';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['alter']['path'] = 'admin/commerce/orders/[order_id]';
  $handler->display->display_options['fields']['field_commerce_billy_i_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
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
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_project_order_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
  $handler->display->display_options['filters']['type_1']['expose']['label'] = 'Billed';
  $handler->display->display_options['filters']['type_1']['expose']['operator'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['type_1']['expose']['reduce'] = TRUE;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  
  /* Display: View page */
  $handler = $view->new_display('block', 'View page', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_line_item_delivery_date' => 'field_line_item_delivery_date',
    'line_item_id' => 'line_item_id',
    'type' => 'type',
    'line_item_label' => 'line_item_label',
    'commerce_unit_price' => 'commerce_unit_price',
    'quantity' => 'quantity',
    'commerce_total' => 'commerce_total',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_line_item_delivery_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'line_item_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'line_item_label' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_unit_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'quantity' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_total' => array(
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
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No line items found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Line item: Delivery date */
  $handler->display->display_options['fields']['field_line_item_delivery_date']['id'] = 'field_line_item_delivery_date';
  $handler->display->display_options['fields']['field_line_item_delivery_date']['table'] = 'field_data_field_line_item_delivery_date';
  $handler->display->display_options['fields']['field_line_item_delivery_date']['field'] = 'field_line_item_delivery_date';
  $handler->display->display_options['fields']['field_line_item_delivery_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_line_item_delivery_date']['format_date_sql'] = 0;
  /* Field: Commerce Line Item: Line item ID */
  $handler->display->display_options['fields']['line_item_id']['id'] = 'line_item_id';
  $handler->display->display_options['fields']['line_item_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_id']['field'] = 'line_item_id';
  $handler->display->display_options['fields']['line_item_id']['exclude'] = TRUE;
  /* Field: Commerce Line Item: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  /* Field: Commerce Line Item: Label */
  $handler->display->display_options['fields']['line_item_label']['id'] = 'line_item_label';
  $handler->display->display_options['fields']['line_item_label']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_label']['field'] = 'line_item_label';
  /* Field: Commerce Line item: Unit price */
  $handler->display->display_options['fields']['commerce_unit_price']['id'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['table'] = 'field_data_commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['field'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_unit_price']['type'] = 'erpal_commerce_commerce_price_base_price';
  $handler->display->display_options['fields']['commerce_unit_price']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Line Item: Quantity */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['precision'] = '0';
  /* Field: Commerce Line item: Total */
  $handler->display->display_options['fields']['commerce_total']['id'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['table'] = 'field_data_commerce_total';
  $handler->display->display_options['fields']['commerce_total']['field'] = 'commerce_total';
  $handler->display->display_options['fields']['commerce_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_total']['type'] = 'erpal_commerce_commerce_price_base_price';
  $handler->display->display_options['fields']['commerce_total']['settings'] = array(
    'calculation' => FALSE,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Commerce Line Item: Line item ID */
  $handler->display->display_options['sorts']['line_item_id']['id'] = 'line_item_id';
  $handler->display->display_options['sorts']['line_item_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['sorts']['line_item_id']['field'] = 'line_item_id';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Commerce Line Item: Line item ID */
  $handler->display->display_options['arguments']['line_item_id']['id'] = 'line_item_id';
  $handler->display->display_options['arguments']['line_item_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['arguments']['line_item_id']['field'] = 'line_item_id';
  $handler->display->display_options['arguments']['line_item_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['line_item_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['line_item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['line_item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['line_item_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['line_item_id']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  
  /* Display: Dashboard */
  $handler = $view->new_display('block', 'Dashboard', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Revenue';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="invoices/line_items" class="link-global-view">Full view</a>';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['order_number']['label'] = 'Invoice number';
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'admin';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    t('@total rows'),
    t('Delivery date'),
    t('Invoice'),
    t('[order_number]'),
    t('Billed'),
    t('View panes'),
    t('Revenue page'),
    t('Commerce Order entity referenced from field_line_item_order'),
    t('CRM Core Contact entity referenced from field_customer'),
    t('Customer'),
    t('[order_number_1]'),
    t('Project Revenue'),
    t('Content referencing Commerce Order from field_project_order'),
    t('View page'),
    t('No line items found.'),
    t('Line item ID'),
    t('.'),
    t(','),
    t('Type'),
    t('Label'),
    t('Unit price'),
    t('Quantity'),
    t('Dashboard'),
    t('<a href="invoices/line_items" class="link-global-view">Full view</a>'),
    t('Invoice number'),
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
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any commerce_product entity';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
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
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
  /* No results behavior: Commerce Product: Empty text */
  $handler->display->display_options['empty']['empty_text']['id'] = 'empty_text';
  $handler->display->display_options['empty']['empty_text']['table'] = 'commerce_product';
  $handler->display->display_options['empty']['empty_text']['field'] = 'empty_text';
  $handler->display->display_options['empty']['empty_text']['empty'] = TRUE;
  $handler->display->display_options['empty']['empty_text']['add_path'] = 'product/add/product?destination=products';
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
  $handler->display->display_options['fields']['title']['alter']['path'] = 'product/[product_id]/edit';
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
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
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
    t('@total rows'),
    t('SKU'),
    t('Title'),
    t('Type'),
    t('Price'),
    t('Status'),
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
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
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
  /* Field: CRM Core Activity: Customer */
  $handler->display->display_options['fields']['field_activity_customer']['id'] = 'field_activity_customer';
  $handler->display->display_options['fields']['field_activity_customer']['table'] = 'field_data_field_activity_customer';
  $handler->display->display_options['fields']['field_activity_customer']['field'] = 'field_activity_customer';
  $handler->display->display_options['fields']['field_activity_customer']['settings'] = array(
    'link' => 0,
  );
  /* Field: CRM Core Activity: Notes */
  $handler->display->display_options['fields']['field_activity_notes']['id'] = 'field_activity_notes';
  $handler->display->display_options['fields']['field_activity_notes']['table'] = 'field_data_field_activity_notes';
  $handler->display->display_options['fields']['field_activity_notes']['field'] = 'field_activity_notes';
  $handler->display->display_options['fields']['field_activity_notes']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_activity_notes']['settings'] = array(
    'trim_length' => '400',
  );
  /* Field: CRM Core Activity: Status */
  $handler->display->display_options['fields']['field_activity_status']['id'] = 'field_activity_status';
  $handler->display->display_options['fields']['field_activity_status']['table'] = 'field_data_field_activity_status';
  $handler->display->display_options['fields']['field_activity_status']['field'] = 'field_activity_status';
  /* Sort criterion: CRM Core Activity: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'crm_core_activity';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
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
    t('@total rows'),
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
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: CRM Core Contact: Contact ID */
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
  /* Sort criterion: CRM Core Contact: Created date */
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
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: CRM Core Contact: Contact Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_contact';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['attach'] = array(
    0 => 'crm_core_activity:field_activity_participants:meeting',
    1 => 'crm_core_activity:field_activity_participants:phone_call',
    2 => 'crm_core_activity:field_activity_participants:email',
    3 => 'crm_core_activity:field_activity_participants:sales_process',
    4 => 'crm_core_activity:field_activity_customer:sales_process',
    5 => 'crm_core_activity:field_activity_main_contact:sales_process',
    6 => 'commerce_order:field_customer:commerce_order',
    7 => 'commerce_order:field_customer:invoice',
    8 => 'commerce_order:field_customer:quote',
    9 => 'commerce_order:field_vendor:commerce_order',
    10 => 'commerce_order:field_vendor:invoice',
    11 => 'commerce_order:field_vendor:quote',
  );
  
  /* Display: Reference dialog Search 2 */
  $handler = $view->new_display('references_dialog', 'Reference dialog Search 2', 'references_dialog_2');
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: CRM Core Contact: Contact Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_contact';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'individual' => 'individual',
  );
  $handler->display->display_options['attach'] = array(
    0 => 'crm_core_contact::individual',
  );
  
  /* Display: Reference dialog Search 3 */
  $handler = $view->new_display('references_dialog', 'Reference dialog Search 3', 'references_dialog_3');
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: CRM Core Contact: Contact Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_contact';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organization' => 'organization',
  );
  $handler->display->display_options['attach'] = array(
    0 => 'crm_core_contact::organization',
  );
  
  /* Display: Reference dialog Search 4 */
  $handler = $view->new_display('references_dialog', 'Reference dialog Search 4', 'references_dialog_4');
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: CRM Core Contact: Contact Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_contact';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'household' => 'household',
  );
  $handler->display->display_options['attach'] = array(
    0 => 'crm_core_contact::household',
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
    t('@total rows'),
    t('Type'),
    t('Reference dialog Search 2'),
    t('Reference dialog Search 3'),
    t('Reference dialog Search 4'),
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
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
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
    'order_number' => 'order_number',
    'field_customer' => 'field_customer',
    'status' => 'status',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'order_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_customer' => array(
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
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
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
    t('@total rows'),
    t('Order number'),
    t('Customer'),
    t('Order status'),
  );

  $export['erpal_quote_search'] = $view;

  $view = new view();
  $view->name = 'erpal_order_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_order';
  $view->human_name = 'ERPAL Order Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  /* Sort criterion: Commerce Order: Order ID */
  $handler->display->display_options['sorts']['order_id']['id'] = 'order_id';
  $handler->display->display_options['sorts']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['sorts']['order_id']['field'] = 'order_id';
  $handler->display->display_options['sorts']['order_id']['order'] = 'DESC';
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
    'order_number' => 'order_number',
    'field_customer' => 'field_customer',
    'status' => 'status',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'order_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_customer' => array(
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
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
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
    'commerce_order' => 'commerce_order',
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
    0 => 'commerce_order:field_invoice_order:invoice',
  );
  $translatables['erpal_order_search'] = array(
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
    t('@total rows'),
    t('Order number'),
    t('Customer'),
    t('Order status'),
  );

  $export['erpal_order_search'] = $view;

  return $export;
}
