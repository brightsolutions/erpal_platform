<?php

/**
 * @file
 * Contains default pages for ERPAL Commerce UI module.
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function erpal_commerce_ui_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'order_view_template';
  $page->task = 'page';
  $page->admin_title = 'Order view template';
  $page->admin_description = '';
  $page->path = 'admin/commerce/orders/%commerce_order';
  $page->access = array(
    'plugins' => array(),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    'commerce_order' => array(
      'id' => 1,
      'identifier' => 'Commerce Order: ID',
      'name' => 'entity_id:commerce_order',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_order_view_template_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'order_view_template';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Quote type',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:commerce_order',
          'settings' => array(
            'type' => array(
              'quote' => 'quote',
            ),
          ),
          'context' => 'argument_entity_id:commerce_order_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => array(
        'panel_tab_id_pattern' => 'region',
      ),
    ),
    'middle' => array(
      'style' => 'tabs',
    ),
  );
  $display->cache = array();
  $display->title = 'Quote %commerce_order:order-number';
  $display->uuid = '991f0569-aa46-470e-a8d5-3e18b03cd620';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ba618a2b-8bb9-450b-9bc1-c701d6e84977';
  $pane->panel = 'middle';
  $pane->type = 'entity_view';
  $pane->subtype = 'commerce_order';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'quote_pdf',
    'context' => 'argument_entity_id:commerce_order_1',
    'override_title' => 1,
    'override_title_text' => 'Quote',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ba618a2b-8bb9-450b-9bc1-c701d6e84977';
  $display->content['new-ba618a2b-8bb9-450b-9bc1-c701d6e84977'] = $pane;
  $display->panels['middle'][0] = 'new-ba618a2b-8bb9-450b-9bc1-c701d6e84977';
  $pane = new stdClass();
  $pane->pid = 'new-0fd95f23-0708-4a67-89c7-eb3322539432';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'commerce_order:field_customer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'view_mode' => 'full',
      'links' => 1,
    ),
    'context' => 'argument_entity_id:commerce_order_1',
    'override_title' => 1,
    'override_title_text' => 'Customer',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '0fd95f23-0708-4a67-89c7-eb3322539432';
  $display->content['new-0fd95f23-0708-4a67-89c7-eb3322539432'] = $pane;
  $display->panels['middle'][1] = 'new-0fd95f23-0708-4a67-89c7-eb3322539432';
  $pane = new stdClass();
  $pane->pid = 'new-b46b90d4-1a78-4865-bc12-40fcb7b956a7';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'commerce_order:field_sales_process';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'view_mode' => 'full',
      'links' => 1,
    ),
    'context' => 'argument_entity_id:commerce_order_1',
    'override_title' => 1,
    'override_title_text' => 'Sales Process',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'b46b90d4-1a78-4865-bc12-40fcb7b956a7';
  $display->content['new-b46b90d4-1a78-4865-bc12-40fcb7b956a7'] = $pane;
  $display->panels['middle'][2] = 'new-b46b90d4-1a78-4865-bc12-40fcb7b956a7';
  $pane = new stdClass();
  $pane->pid = 'new-3835f972-0b8d-46de-a23c-59e6a73584dd';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_quote-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:commerce_order_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '3835f972-0b8d-46de-a23c-59e6a73584dd';
  $display->content['new-3835f972-0b8d-46de-a23c-59e6a73584dd'] = $pane;
  $display->panels['middle'][3] = 'new-3835f972-0b8d-46de-a23c-59e6a73584dd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ba618a2b-8bb9-450b-9bc1-c701d6e84977';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_order_view_template_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'order_view_template';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Order type',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:commerce_order',
          'settings' => array(
            'type' => array(
              'commerce_order' => 'commerce_order',
            ),
          ),
          'context' => 'argument_entity_id:commerce_order_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'middle' => array(
        'panel_tab_id_pattern' => 'region',
      ),
    ),
    'middle' => array(
      'style' => 'tabs',
    ),
  );
  $display->cache = array();
  $display->title = 'Order %commerce_order:order-number';
  $display->uuid = '582569a3-8dcc-4f8a-814f-48a0997efea4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2b8bd0ea-4dff-4967-b5de-9b81ed4cea3f';
  $pane->panel = 'middle';
  $pane->type = 'entity_view';
  $pane->subtype = 'commerce_order';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'order_pdf',
    'context' => 'argument_entity_id:commerce_order_1',
    'override_title' => 1,
    'override_title_text' => 'Order',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2b8bd0ea-4dff-4967-b5de-9b81ed4cea3f';
  $display->content['new-2b8bd0ea-4dff-4967-b5de-9b81ed4cea3f'] = $pane;
  $display->panels['middle'][0] = 'new-2b8bd0ea-4dff-4967-b5de-9b81ed4cea3f';
  $pane = new stdClass();
  $pane->pid = 'new-325e8ee2-7691-445d-a9ff-c7a740b7ae52';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'commerce_order:field_customer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'view_mode' => 'full',
      'links' => 1,
    ),
    'context' => 'argument_entity_id:commerce_order_1',
    'override_title' => 1,
    'override_title_text' => 'Customer',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '325e8ee2-7691-445d-a9ff-c7a740b7ae52';
  $display->content['new-325e8ee2-7691-445d-a9ff-c7a740b7ae52'] = $pane;
  $display->panels['middle'][1] = 'new-325e8ee2-7691-445d-a9ff-c7a740b7ae52';
  $pane = new stdClass();
  $pane->pid = 'new-17ca080d-c238-4583-8092-42cf80d75ec0';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_order-panel_pane_4';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:commerce_order_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '17ca080d-c238-4583-8092-42cf80d75ec0';
  $display->content['new-17ca080d-c238-4583-8092-42cf80d75ec0'] = $pane;
  $display->panels['middle'][2] = 'new-17ca080d-c238-4583-8092-42cf80d75ec0';
  $pane = new stdClass();
  $pane->pid = 'new-b80eec7f-5c4f-4ab3-965a-999ba81e1fb6';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_order-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:commerce_order_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'b80eec7f-5c4f-4ab3-965a-999ba81e1fb6';
  $display->content['new-b80eec7f-5c4f-4ab3-965a-999ba81e1fb6'] = $pane;
  $display->panels['middle'][3] = 'new-b80eec7f-5c4f-4ab3-965a-999ba81e1fb6';
  $pane = new stdClass();
  $pane->pid = 'new-43357c17-2da1-41c5-9ae7-44011ee3ea1f';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_order-panel_pane_5';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:commerce_order_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '43357c17-2da1-41c5-9ae7-44011ee3ea1f';
  $display->content['new-43357c17-2da1-41c5-9ae7-44011ee3ea1f'] = $pane;
  $display->panels['middle'][4] = 'new-43357c17-2da1-41c5-9ae7-44011ee3ea1f';
  $pane = new stdClass();
  $pane->pid = 'new-f1c5541f-27f7-48bc-8478-f11140602cc5';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_invoice_line_items-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:commerce_order_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'f1c5541f-27f7-48bc-8478-f11140602cc5';
  $display->content['new-f1c5541f-27f7-48bc-8478-f11140602cc5'] = $pane;
  $display->panels['middle'][5] = 'new-f1c5541f-27f7-48bc-8478-f11140602cc5';
  $pane = new stdClass();
  $pane->pid = 'new-c2180bcc-a852-45be-bc10-ab8877b6ff67';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_project-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:commerce_order_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'c2180bcc-a852-45be-bc10-ab8877b6ff67';
  $display->content['new-c2180bcc-a852-45be-bc10-ab8877b6ff67'] = $pane;
  $display->panels['middle'][6] = 'new-c2180bcc-a852-45be-bc10-ab8877b6ff67';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_order_view_template_panel_context_3';
  $handler->task = 'page';
  $handler->subtask = 'order_view_template';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Invoice type',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:commerce_order',
          'settings' => array(
            'type' => array(
              'invoice' => 'invoice',
            ),
          ),
          'context' => 'argument_entity_id:commerce_order_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'middle' => array(
        'panel_tab_id_pattern' => 'region',
      ),
      'default' => NULL,
    ),
    'middle' => array(
      'style' => 'tabs',
    ),
  );
  $display->cache = array();
  $display->title = 'Invoice %commerce_order:order-number';
  $display->uuid = '98229ac5-b855-4aa6-b21e-151e2292e341';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-cbb8e8a1-3c65-462b-aed1-016f447d58a6';
  $pane->panel = 'middle';
  $pane->type = 'entity_view';
  $pane->subtype = 'commerce_order';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'pdf',
    'context' => 'argument_entity_id:commerce_order_1',
    'override_title' => 1,
    'override_title_text' => 'Invoice',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'cbb8e8a1-3c65-462b-aed1-016f447d58a6';
  $display->content['new-cbb8e8a1-3c65-462b-aed1-016f447d58a6'] = $pane;
  $display->panels['middle'][0] = 'new-cbb8e8a1-3c65-462b-aed1-016f447d58a6';
  $pane = new stdClass();
  $pane->pid = 'new-158c4cc6-001f-4610-8041-b19f2b49886e';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'commerce_order:field_customer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'view_mode' => 'full',
      'links' => 1,
    ),
    'context' => 'argument_entity_id:commerce_order_1',
    'override_title' => 1,
    'override_title_text' => 'Customer',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '158c4cc6-001f-4610-8041-b19f2b49886e';
  $display->content['new-158c4cc6-001f-4610-8041-b19f2b49886e'] = $pane;
  $display->panels['middle'][1] = 'new-158c4cc6-001f-4610-8041-b19f2b49886e';
  $pane = new stdClass();
  $pane->pid = 'new-ee40d253-2b54-4ff9-9dca-094651a6b56c';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_order-panel_pane_6';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:commerce_order_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'ee40d253-2b54-4ff9-9dca-094651a6b56c';
  $display->content['new-ee40d253-2b54-4ff9-9dca-094651a6b56c'] = $pane;
  $display->panels['middle'][2] = 'new-ee40d253-2b54-4ff9-9dca-094651a6b56c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-cbb8e8a1-3c65-462b-aed1-016f447d58a6';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;

  $pages['order_view_template'] = $page;

  return $pages;
}

/**
 * Implements hook_default_page_manager_pages_alter().
 */
function erpal_commerce_ui_default_page_manager_pages_alter(&$pages) {
  if (isset($pages['activity_template'])) {
    $pane = new stdClass();
    $pane->pid = 'new-40773955-7efe-4a99-a045-57c3bd5f005f';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'erpal_quote-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:crm_core_activity_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '40773955-7efe-4a99-a045-57c3bd5f005f';

    $pages['activity_template']->default_handlers['page_activity_template_panel_context']
    ->conf['display']->content['new-40773955-7efe-4a99-a045-57c3bd5f005f'] = $pane;
    $pages['activity_template']->default_handlers['page_activity_template_panel_context']
    ->conf['display']->panels['middle'][4] = 'new-40773955-7efe-4a99-a045-57c3bd5f005f';

    $pane = new stdClass();
    $pane->pid = 'new-1d3bf16c-b641-4f9e-bd5f-221a280f5063';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'erpal_order-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:crm_core_activity_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '1d3bf16c-b641-4f9e-bd5f-221a280f5063';

    $pages['activity_template']->default_handlers['page_activity_template_panel_context']
    ->conf['display']->content['new-1d3bf16c-b641-4f9e-bd5f-221a280f5063'] = $pane;
    $pages['activity_template']->default_handlers['page_activity_template_panel_context']
    ->conf['display']->panels['middle'][5] = 'new-1d3bf16c-b641-4f9e-bd5f-221a280f5063';
  }

  if (isset($pages['contact_view_template'])) {
    $pane = new stdClass();
    $pane->pid = 'new-88f8a7f6-6a91-4986-815a-4840fccaee01';
    $pane->panel = 'middle';
    $pane->type = 'panels_mini';
    $pane->subtype = 'erpal_contact_view_merged_tab';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:crm_core_contact_1',
      ),
      'override_title' => 1,
      'override_title_text' => 'Quotes, Orders, Invoices',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '88f8a7f6-6a91-4986-815a-4840fccaee01';
    $pages['contact_view_template']->default_handlers['page_contact_view_template_panel_context']
    ->conf['display']->content['new-88f8a7f6-6a91-4986-815a-4840fccaee01'] = $pane;
    $pages['contact_view_template']->default_handlers['page_contact_view_template_panel_context']
    ->conf['display']->panels['middle'][3] = 'new-88f8a7f6-6a91-4986-815a-4840fccaee01';
  }
}
