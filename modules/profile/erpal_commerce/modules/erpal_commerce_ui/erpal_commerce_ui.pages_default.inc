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
  $pane->pid = 'new-7450548e-6297-4ae9-9ac0-1a2f39b9a00b';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'erpal_quote_merged_tab_orders_an';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:commerce_order_1',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'order-merged-tab',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '7450548e-6297-4ae9-9ac0-1a2f39b9a00b';
  $display->content['new-7450548e-6297-4ae9-9ac0-1a2f39b9a00b'] = $pane;
  $display->panels['middle'][2] = 'new-7450548e-6297-4ae9-9ac0-1a2f39b9a00b';
  $pane = new stdClass();
  $pane->pid = 'new-e17275fb-313d-48be-b3c8-d9e5c0abcf40';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'erpal_quote_merged_tab_sales_pro';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:commerce_order_1',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'order-merged-tab',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'e17275fb-313d-48be-b3c8-d9e5c0abcf40';
  $display->content['new-e17275fb-313d-48be-b3c8-d9e5c0abcf40'] = $pane;
  $display->panels['middle'][3] = 'new-e17275fb-313d-48be-b3c8-d9e5c0abcf40';
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
  $pane->pid = 'new-64593543-a915-4d84-adb6-a1375dd9ff17';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'erpal_order_merged_tab_quotes_an';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:commerce_order_1',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'order-merged-tab',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '64593543-a915-4d84-adb6-a1375dd9ff17';
  $display->content['new-64593543-a915-4d84-adb6-a1375dd9ff17'] = $pane;
  $display->panels['middle'][2] = 'new-64593543-a915-4d84-adb6-a1375dd9ff17';
  $pane = new stdClass();
  $pane->pid = 'new-1a970806-1637-42ae-bc52-d86d383c7220';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'erpal_order_merged_tab_sales_pro';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:commerce_order_1',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'order-merged-tab',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '1a970806-1637-42ae-bc52-d86d383c7220';
  $display->content['new-1a970806-1637-42ae-bc52-d86d383c7220'] = $pane;
  $display->panels['middle'][3] = 'new-1a970806-1637-42ae-bc52-d86d383c7220';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'f1c5541f-27f7-48bc-8478-f11140602cc5';
  $display->content['new-f1c5541f-27f7-48bc-8478-f11140602cc5'] = $pane;
  $display->panels['middle'][4] = 'new-f1c5541f-27f7-48bc-8478-f11140602cc5';
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
  $pane->pid = 'new-16999b14-9a66-475c-b6b9-d8f870a1c9f3';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'erpal_invoice_merged_tab_orders_';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:commerce_order_1',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'order-merged-tab',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '16999b14-9a66-475c-b6b9-d8f870a1c9f3';
  $display->content['new-16999b14-9a66-475c-b6b9-d8f870a1c9f3'] = $pane;
  $display->panels['middle'][2] = 'new-16999b14-9a66-475c-b6b9-d8f870a1c9f3';
  $pane = new stdClass();
  $pane->pid = 'new-e2607de5-df3e-4935-a33b-62dc88264c29';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'erpal_invoice_merged_tab_sales_p';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:commerce_order_1',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'order-merged-tab',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'e2607de5-df3e-4935-a33b-62dc88264c29';
  $display->content['new-e2607de5-df3e-4935-a33b-62dc88264c29'] = $pane;
  $display->panels['middle'][3] = 'new-e2607de5-df3e-4935-a33b-62dc88264c29';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-cbb8e8a1-3c65-462b-aed1-016f447d58a6';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['order_view_template'] = $page;

  return $pages;
}
