<?php
/**
 * @file
 * erpal_layout.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function erpal_layout_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'ERPAL default',
    'no_blocks' => 1,
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
          'name' => 'theme',
          'settings' => array(
            'theme' => 'erpal_theme',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'erpalsitetemplate';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'righttabs' => NULL,
      'page-header-left' => NULL,
      'page-header-right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3854b10e-0fba-4f76-a395-539ed1ab4321';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6c6f0e47-777e-4c4c-968a-8193f9457c94';
  $pane->panel = 'bottom';
  $pane->type = 'powered_by';
  $pane->subtype = 'powered_by';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'types' => array(),
    'field_name' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '6c6f0e47-777e-4c4c-968a-8193f9457c94';
  $display->content['new-6c6f0e47-777e-4c4c-968a-8193f9457c94'] = $pane;
  $display->panels['bottom'][0] = 'new-6c6f0e47-777e-4c4c-968a-8193f9457c94';
  $pane = new stdClass();
  $pane->pid = 'new-bf44ebdd-7f82-4db8-8b33-eecd5e00c089';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'menu-erpal-menu';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'bf44ebdd-7f82-4db8-8b33-eecd5e00c089';
  $display->content['new-bf44ebdd-7f82-4db8-8b33-eecd5e00c089'] = $pane;
  $display->panels['left'][0] = 'new-bf44ebdd-7f82-4db8-8b33-eecd5e00c089';
  $pane = new stdClass();
  $pane->pid = 'new-096541d5-c302-4c35-b813-399a66ab501a';
  $pane->panel = 'page-header-left';
  $pane->type = 'page_logo';
  $pane->subtype = 'page_logo';
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
  $pane->uuid = '096541d5-c302-4c35-b813-399a66ab501a';
  $display->content['new-096541d5-c302-4c35-b813-399a66ab501a'] = $pane;
  $display->panels['page-header-left'][0] = 'new-096541d5-c302-4c35-b813-399a66ab501a';
  $pane = new stdClass();
  $pane->pid = 'new-b893103e-a6cb-483e-9235-f7f324edf680';
  $pane->panel = 'page-header-left';
  $pane->type = 'page_site_name';
  $pane->subtype = 'page_site_name';
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
  $pane->uuid = 'b893103e-a6cb-483e-9235-f7f324edf680';
  $display->content['new-b893103e-a6cb-483e-9235-f7f324edf680'] = $pane;
  $display->panels['page-header-left'][1] = 'new-b893103e-a6cb-483e-9235-f7f324edf680';
  $pane = new stdClass();
  $pane->pid = 'new-e6de1b56-d3b6-4ce5-9ff3-307e6110cb1b';
  $pane->panel = 'page-header-right';
  $pane->type = 'panels_mini';
  $pane->subtype = 'erpal_dropdown_user_menu';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e6de1b56-d3b6-4ce5-9ff3-307e6110cb1b';
  $display->content['new-e6de1b56-d3b6-4ce5-9ff3-307e6110cb1b'] = $pane;
  $display->panels['page-header-right'][0] = 'new-e6de1b56-d3b6-4ce5-9ff3-307e6110cb1b';
  $pane = new stdClass();
  $pane->pid = 'new-c76e38a0-5bbb-4e51-8b4c-bc0f39d4f7fb';
  $pane->panel = 'page-header-right';
  $pane->type = 'panels_mini';
  $pane->subtype = 'erpal_anonymous_user_panel';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 1,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'c76e38a0-5bbb-4e51-8b4c-bc0f39d4f7fb';
  $display->content['new-c76e38a0-5bbb-4e51-8b4c-bc0f39d4f7fb'] = $pane;
  $display->panels['page-header-right'][1] = 'new-c76e38a0-5bbb-4e51-8b4c-bc0f39d4f7fb';
  $pane = new stdClass();
  $pane->pid = 'new-eb400803-4724-4a8f-8d64-cca2eb9a3ccf';
  $pane->panel = 'right';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
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
  $pane->uuid = 'eb400803-4724-4a8f-8d64-cca2eb9a3ccf';
  $display->content['new-eb400803-4724-4a8f-8d64-cca2eb9a3ccf'] = $pane;
  $display->panels['right'][0] = 'new-eb400803-4724-4a8f-8d64-cca2eb9a3ccf';
  $pane = new stdClass();
  $pane->pid = 'new-8bb5efef-a892-4216-9c47-8d8290b4a63d';
  $pane->panel = 'right';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
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
  $pane->uuid = '8bb5efef-a892-4216-9c47-8d8290b4a63d';
  $display->content['new-8bb5efef-a892-4216-9c47-8d8290b4a63d'] = $pane;
  $display->panels['right'][1] = 'new-8bb5efef-a892-4216-9c47-8d8290b4a63d';
  $pane = new stdClass();
  $pane->pid = 'new-fc749562-787b-4fc7-9de0-52e4cd994c99';
  $pane->panel = 'right';
  $pane->type = 'page_messages';
  $pane->subtype = 'page_messages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'fc749562-787b-4fc7-9de0-52e4cd994c99';
  $display->content['new-fc749562-787b-4fc7-9de0-52e4cd994c99'] = $pane;
  $display->panels['right'][2] = 'new-fc749562-787b-4fc7-9de0-52e4cd994c99';
  $pane = new stdClass();
  $pane->pid = 'new-70ce4aba-f141-4439-b17f-101f99fd6eda';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'system-help';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '70ce4aba-f141-4439-b17f-101f99fd6eda';
  $display->content['new-70ce4aba-f141-4439-b17f-101f99fd6eda'] = $pane;
  $display->panels['right'][3] = 'new-70ce4aba-f141-4439-b17f-101f99fd6eda';
  $pane = new stdClass();
  $pane->pid = 'new-2afe3fab-96f2-401b-be3b-f06439833880';
  $pane->panel = 'right';
  $pane->type = 'page_actions';
  $pane->subtype = 'page_actions';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '2afe3fab-96f2-401b-be3b-f06439833880';
  $display->content['new-2afe3fab-96f2-401b-be3b-f06439833880'] = $pane;
  $display->panels['right'][4] = 'new-2afe3fab-96f2-401b-be3b-f06439833880';
  $pane = new stdClass();
  $pane->pid = 'new-2e487454-10c6-4d97-b0fc-6b783caeb1b4';
  $pane->panel = 'right';
  $pane->type = 'page_content';
  $pane->subtype = 'page_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_page_content_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '2e487454-10c6-4d97-b0fc-6b783caeb1b4';
  $display->content['new-2e487454-10c6-4d97-b0fc-6b783caeb1b4'] = $pane;
  $display->panels['right'][5] = 'new-2e487454-10c6-4d97-b0fc-6b783caeb1b4';
  $pane = new stdClass();
  $pane->pid = 'new-6c70aeca-92eb-4936-aeef-66eaae2774ac';
  $pane->panel = 'righttabs';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'both',
    'id' => 'tabs',
    'override_title' => 1,
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
  $pane->uuid = '6c70aeca-92eb-4936-aeef-66eaae2774ac';
  $display->content['new-6c70aeca-92eb-4936-aeef-66eaae2774ac'] = $pane;
  $display->panels['righttabs'][0] = 'new-6c70aeca-92eb-4936-aeef-66eaae2774ac';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;

  $export['site_template_panel_context'] = $handler;

  return $export;
}
