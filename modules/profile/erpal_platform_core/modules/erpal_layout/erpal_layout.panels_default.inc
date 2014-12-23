<?php
/**
 * @file
 * erpal_layout.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function erpal_layout_default_panels_mini() {
  $export = array();

  /* dropdown user menu */
  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'erpal_dropdown_user_menu';
  $mini->category = '';
  $mini->admin_title = 'ERPAL dropdown user menu';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array(
    0 => array(
      'identifier' => 'User',
      'keyword' => 'user',
      'name' => 'user',
      'type' => 'current',
      'uid' => '',
      'id' => 1,
    ),
  );
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'erpaldropdownregion';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'trigger' => NULL,
      'dropdown' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'cd279c8f-4241-4ca1-b002-f94d7504d188';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a906d76c-53ce-49df-8727-a06c6b205463';
  $pane->panel = 'dropdown';
  $pane->type = 'user_menu_welcome';
  $pane->subtype = 'user_menu_welcome';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'greeting' => 'Hey',
    'context' => 'context_user_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a906d76c-53ce-49df-8727-a06c6b205463';
  $display->content['new-a906d76c-53ce-49df-8727-a06c6b205463'] = $pane;
  $display->panels['dropdown'][0] = 'new-a906d76c-53ce-49df-8727-a06c6b205463';
  $pane = new stdClass();
  $pane->pid = 'new-77fc4a8f-aab6-4801-9fa6-389446ead170';
  $pane->panel = 'dropdown';
  $pane->type = 'block';
  $pane->subtype = 'system-user-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '77fc4a8f-aab6-4801-9fa6-389446ead170';
  $display->content['new-77fc4a8f-aab6-4801-9fa6-389446ead170'] = $pane;
  $display->panels['dropdown'][1] = 'new-77fc4a8f-aab6-4801-9fa6-389446ead170';
  $pane = new stdClass();
  $pane->pid = 'new-263469a9-64e5-4e0a-87d1-d5f59d8801f1';
  $pane->panel = 'trigger';
  $pane->type = 'user_avatar';
  $pane->subtype = 'user_avatar';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'image_style' => 'usermenu_profileimage',
    'context' => 'context_user_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '263469a9-64e5-4e0a-87d1-d5f59d8801f1';
  $display->content['new-263469a9-64e5-4e0a-87d1-d5f59d8801f1'] = $pane;
  $display->panels['trigger'][0] = 'new-263469a9-64e5-4e0a-87d1-d5f59d8801f1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-77fc4a8f-aab6-4801-9fa6-389446ead170';
  $mini->display = $display;

  $export['erpal_dropdown_user_menu'] = $mini;


  /* contacts merged tab for invoice, order & quote */
  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'erpal_contact_view_merged_tab';
  $mini->category = 'Mini panels';
  $mini->admin_title = 'ERPAL contact view merged tab';
  $mini->admin_description = '';
  $mini->requiredcontexts = array(
    0 => array(
      'identifier' => 'CRM Core Contact',
      'keyword' => 'crm_core_contact',
      'name' => 'entity:crm_core_contact',
      'entity_id' => '',
      'id' => 1,
    ),
  );
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'naked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9bb1aabc-64a0-4072-bda0-da7b297f9120';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0eb1802a-9dce-47dd-b1f2-622c4d23f2ff';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_quote-panel_pane_3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'requiredcontext_entity:crm_core_contact_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0eb1802a-9dce-47dd-b1f2-622c4d23f2ff';
  $display->content['new-0eb1802a-9dce-47dd-b1f2-622c4d23f2ff'] = $pane;
  $display->panels['content'][0] = 'new-0eb1802a-9dce-47dd-b1f2-622c4d23f2ff';
  $pane = new stdClass();
  $pane->pid = 'new-857684ec-44fc-4bf5-b1dd-57f843ff13d3';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_order-panel_pane_3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'requiredcontext_entity:crm_core_contact_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '857684ec-44fc-4bf5-b1dd-57f843ff13d3';
  $display->content['new-857684ec-44fc-4bf5-b1dd-57f843ff13d3'] = $pane;
  $display->panels['content'][1] = 'new-857684ec-44fc-4bf5-b1dd-57f843ff13d3';
  $pane = new stdClass();
  $pane->pid = 'new-16593066-e539-4170-a9df-96278861a538';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_invoice-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'requiredcontext_entity:crm_core_contact_1',
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
  $pane->uuid = '16593066-e539-4170-a9df-96278861a538';
  $display->content['new-16593066-e539-4170-a9df-96278861a538'] = $pane;
  $display->panels['content'][2] = 'new-16593066-e539-4170-a9df-96278861a538';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-0eb1802a-9dce-47dd-b1f2-622c4d23f2ff';
  $mini->display = $display;

  $export['erpal_contact_view_merged_tab'] = $mini;


  /* enhanced contact main-tab */
  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'contact_view_main_tab_content';
  $mini->category = 'Mini panels';
  $mini->admin_title = 'ERPAL contact view main tab content';
  $mini->admin_description = '';
  $mini->requiredcontexts = array(
    0 => array(
      'identifier' => 'CRM Core Contact',
      'keyword' => 'crm_core_contact',
      'name' => 'entity:crm_core_contact',
      'entity_id' => '',
      'id' => 1,
    ),
  );
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Contact';
  $display->uuid = '4619cdc3-6122-4f78-aa67-cf40a463c9ee';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0036f131-1490-4757-8e9e-da550fafdcbe';
  $pane->panel = 'left';
  $pane->type = 'entity_view';
  $pane->subtype = 'crm_core_contact';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'requiredcontext_entity:crm_core_contact_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0036f131-1490-4757-8e9e-da550fafdcbe';
  $display->content['new-0036f131-1490-4757-8e9e-da550fafdcbe'] = $pane;
  $display->panels['left'][0] = 'new-0036f131-1490-4757-8e9e-da550fafdcbe';
  $pane = new stdClass();
  $pane->pid = 'new-f0049a02-8f6d-4ed4-bcdf-a2b61c84b19f';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_crm_activities-panel_pane_4';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f0049a02-8f6d-4ed4-bcdf-a2b61c84b19f';
  $display->content['new-f0049a02-8f6d-4ed4-bcdf-a2b61c84b19f'] = $pane;
  $display->panels['right'][0] = 'new-f0049a02-8f6d-4ed4-bcdf-a2b61c84b19f';
  $pane = new stdClass();
  $pane->pid = 'new-3fe3c76d-a88e-4fbf-a8f8-586ae192f6d6';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_crm_contact_relationships-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '3fe3c76d-a88e-4fbf-a8f8-586ae192f6d6';
  $display->content['new-3fe3c76d-a88e-4fbf-a8f8-586ae192f6d6'] = $pane;
  $display->panels['right'][1] = 'new-3fe3c76d-a88e-4fbf-a8f8-586ae192f6d6';
  $pane = new stdClass();
  $pane->pid = 'new-7104e2ef-d9a8-46ed-ba6f-efd2afea524f';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_quote-panel_pane_4';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'requiredcontext_entity:crm_core_contact_1',
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
  $pane->uuid = '7104e2ef-d9a8-46ed-ba6f-efd2afea524f';
  $display->content['new-7104e2ef-d9a8-46ed-ba6f-efd2afea524f'] = $pane;
  $display->panels['right'][2] = 'new-7104e2ef-d9a8-46ed-ba6f-efd2afea524f';
  $pane = new stdClass();
  $pane->pid = 'new-4e00aec1-b0c6-48d9-a54a-82b1e71fc703';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_order-panel_pane_7';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'requiredcontext_entity:crm_core_contact_1',
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
  $pane->uuid = '4e00aec1-b0c6-48d9-a54a-82b1e71fc703';
  $display->content['new-4e00aec1-b0c6-48d9-a54a-82b1e71fc703'] = $pane;
  $display->panels['right'][3] = 'new-4e00aec1-b0c6-48d9-a54a-82b1e71fc703';
  $pane = new stdClass();
  $pane->pid = 'new-8c72d095-dfa9-4d03-9db1-26d2e4e6dd2e';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_invoice-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'requiredcontext_entity:crm_core_contact_1',
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
  $pane->uuid = '8c72d095-dfa9-4d03-9db1-26d2e4e6dd2e';
  $display->content['new-8c72d095-dfa9-4d03-9db1-26d2e4e6dd2e'] = $pane;
  $display->panels['right'][4] = 'new-8c72d095-dfa9-4d03-9db1-26d2e4e6dd2e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;

  $export['contact_view_main_tab_content'] = $mini;


  /* anonymous user login (mini-) panel */
  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'erpal_anonymous_user_panel';
  $mini->category = '';
  $mini->admin_title = 'ERPAL anonymous user panel';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'erpaldropdownregion';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content' => NULL,
      'trigger' => NULL,
      'dropdown' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'c7a9cefb-6663-4c1a-b132-f8073c9b59d3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-dbfddf4e-a11e-43fa-8ac4-a4be293b6bc1';
  $pane->panel = 'dropdown';
  $pane->type = 'block';
  $pane->subtype = 'user-login';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'dbfddf4e-a11e-43fa-8ac4-a4be293b6bc1';
  $display->content['new-dbfddf4e-a11e-43fa-8ac4-a4be293b6bc1'] = $pane;
  $display->panels['dropdown'][0] = 'new-dbfddf4e-a11e-43fa-8ac4-a4be293b6bc1';
  $pane = new stdClass();
  $pane->pid = 'new-76d86e82-c2cf-4b5f-84cf-cf15b0052126';
  $pane->panel = 'trigger';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<a href="user" class="login">Login</a>',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '76d86e82-c2cf-4b5f-84cf-cf15b0052126';
  $display->content['new-76d86e82-c2cf-4b5f-84cf-cf15b0052126'] = $pane;
  $display->panels['trigger'][0] = 'new-76d86e82-c2cf-4b5f-84cf-cf15b0052126';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;

  $export['erpal_anonymous_user_panel'] = $mini;


  return $export;
}
