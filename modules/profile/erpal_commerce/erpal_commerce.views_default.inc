<?php

/**
 * @file
 * erpal_commerce.views_default.inc
 */


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
    $handler->display->display_options['defaults']['footer'] = FALSE;
    /* Footer: Global: Result summary */
    $handler->display->display_options['footer']['result']['id'] = 'result';
    $handler->display->display_options['footer']['result']['table'] = 'views';
    $handler->display->display_options['footer']['result']['field'] = 'result';
    $handler->display->display_options['footer']['result']['content'] = '@total rows';
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

    /* Display: dashboard */
    $handler = $view->new_display('block', 'dashboard', 'block_1');
    $handler->display->display_options['defaults']['title'] = FALSE;
    $handler->display->display_options['title'] = 'Invoices';
    $handler->display->display_options['defaults']['use_more'] = FALSE;
    $handler->display->display_options['defaults']['use_more_always'] = FALSE;
    $handler->display->display_options['defaults']['use_more_always'] = FALSE;
    $handler->display->display_options['use_more_always'] = TRUE;
    $handler->display->display_options['defaults']['use_more_text'] = FALSE;
    $handler->display->display_options['defaults']['pager'] = FALSE;
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['pager']['options']['items_per_page'] = '10';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'table';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['defaults']['footer'] = FALSE;
    /* Footer: Global: Text area */
    $handler->display->display_options['footer']['area']['id'] = 'area';
    $handler->display->display_options['footer']['area']['table'] = 'views';
    $handler->display->display_options['footer']['area']['field'] = 'area';
    $handler->display->display_options['footer']['area']['content'] = '<a href="invoices" class="link-global-view">Full view</a>';
    $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
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
    $handler->display->display_options['defaults']['filter_groups'] = FALSE;
    $handler->display->display_options['defaults']['filters'] = FALSE;
    /* Filter criterion: Commerce Order: Order type */
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['value'] = array(
      'invoice' => 'invoice',
    );

  }
}
