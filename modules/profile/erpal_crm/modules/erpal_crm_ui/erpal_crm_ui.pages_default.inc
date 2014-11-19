<?php

/**
 * @file
 * Contains default pages for ERPAL CRM UI moduke.
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function erpal_crm_ui_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'activity_list_page';
  $page->task = 'page';
  $page->admin_title = 'Activity list template';
  $page->admin_description = '';
  $page->path = 'crm-core/activity';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'view any crm_core_activity entity',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_activity_list_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'activity_list_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Activity list';
  $display->uuid = '94ceb77a-6ba2-4700-9adf-62dc2d982371';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-62aded31-cff3-42b3-ab3d-06cee46e4bff';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_crm_activities-panel_pane_1';
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
  $pane->uuid = '62aded31-cff3-42b3-ab3d-06cee46e4bff';
  $display->content['new-62aded31-cff3-42b3-ab3d-06cee46e4bff'] = $pane;
  $display->panels['middle'][0] = 'new-62aded31-cff3-42b3-ab3d-06cee46e4bff';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-62aded31-cff3-42b3-ab3d-06cee46e4bff';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['activity_list_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'activity_template';
  $page->task = 'page';
  $page->admin_title = 'Activity view template';
  $page->admin_description = '';
  $page->path = 'crm-core/activity/%crm_core_activity';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'view any crm_core_activity entity',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    'crm_core_activity' => array(
      'id' => 1,
      'identifier' => 'CRM Activity: ID',
      'name' => 'entity_id:crm_core_activity',
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
  $handler->name = 'page_activity_template_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'activity_template';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Default activity type',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => array(
        'panel_tab_id_pattern' => 'region',
      ),
      'middle' => array(
        'panel_tab_id_pattern' => 'region',
      ),
    ),
    'center' => array(
      'style' => 'tabs',
    ),
    'middle' => array(
      'style' => 'tabs',
    ),
  );
  $display->cache = array();
  $display->title = '%crm_core_activity:title';
  $display->uuid = 'd56137a1-45d2-4963-88bf-a870ea2c3fda';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d339fb59-74ee-417d-9ecf-db1098783c7e';
  $pane->panel = 'middle';
  $pane->type = 'entity_view';
  $pane->subtype = 'crm_core_activity';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'argument_entity_id:crm_core_activity_1',
    'override_title' => 1,
    'override_title_text' => 'Activity',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd339fb59-74ee-417d-9ecf-db1098783c7e';
  $display->content['new-d339fb59-74ee-417d-9ecf-db1098783c7e'] = $pane;
  $display->panels['middle'][0] = 'new-d339fb59-74ee-417d-9ecf-db1098783c7e';
  $pane = new stdClass();
  $pane->pid = 'new-a8f05c6c-565f-4008-8c86-8038bc632ea4';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_crm_contacts-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:crm_core_activity_1',
    ),
    'override_title' => 1,
    'override_title_text' => 'Contacts',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a8f05c6c-565f-4008-8c86-8038bc632ea4';
  $display->content['new-a8f05c6c-565f-4008-8c86-8038bc632ea4'] = $pane;
  $display->panels['middle'][1] = 'new-a8f05c6c-565f-4008-8c86-8038bc632ea4';
  $pane = new stdClass();
  $pane->pid = 'new-4671d85e-2e4a-44e4-883c-031bf5f169aa';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_crm_contacts-panel_pane_3';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '4671d85e-2e4a-44e4-883c-031bf5f169aa';
  $display->content['new-4671d85e-2e4a-44e4-883c-031bf5f169aa'] = $pane;
  $display->panels['middle'][2] = 'new-4671d85e-2e4a-44e4-883c-031bf5f169aa';
  $pane = new stdClass();
  $pane->pid = 'new-5b7572a2-acd5-4f8a-ad47-7366a4f93637';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_crm_contacts-panel_pane_2';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '5b7572a2-acd5-4f8a-ad47-7366a4f93637';
  $display->content['new-5b7572a2-acd5-4f8a-ad47-7366a4f93637'] = $pane;
  $display->panels['middle'][3] = 'new-5b7572a2-acd5-4f8a-ad47-7366a4f93637';

  $pane = new stdClass();
  $pane->pid = 'new-f52eec44-ce7a-4724-be08-acd1db923f77';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_crm_activities-panel_pane_3';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_bundle:crm_core_activity',
        'settings' => array(
          'type' => array(
            'sales_process' => 'sales_process',
          ),
        ),
        'context' => 'argument_entity_id:crm_core_activity_1',
        'not' => FALSE,
      ),
    ),
  );
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'f52eec44-ce7a-4724-be08-acd1db923f77';
  $display->content['new-f52eec44-ce7a-4724-be08-acd1db923f77'] = $pane;
  $display->panels['middle'][6] = 'new-f52eec44-ce7a-4724-be08-acd1db923f77';

  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-d339fb59-74ee-417d-9ecf-db1098783c7e';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['activity_template'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'contact_list_template';
  $page->task = 'page';
  $page->admin_title = 'Contact list template';
  $page->admin_description = '';
  $page->path = 'crm-core/contact';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'view any crm_core_contact entity',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_contact_list_template_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'contact_list_template';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Contact list';
  $display->uuid = '1e1daad6-c87e-40b0-bf13-adf60c503a86';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-063b1086-c96a-44f9-ab40-59b31f7e8081';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_crm_contacts-panel_pane_4';
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
  $pane->uuid = '063b1086-c96a-44f9-ab40-59b31f7e8081';
  $display->content['new-063b1086-c96a-44f9-ab40-59b31f7e8081'] = $pane;
  $display->panels['middle'][0] = 'new-063b1086-c96a-44f9-ab40-59b31f7e8081';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-063b1086-c96a-44f9-ab40-59b31f7e8081';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['contact_list_template'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'contact_view_template';
  $page->task = 'page';
  $page->admin_title = 'Contact view template';
  $page->admin_description = '';
  $page->path = 'crm-core/contact/%crm_core_contact';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'view any crm_core_contact entity',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    'crm_core_contact' => array(
      'id' => 1,
      'identifier' => 'CRM Core Contact: ID',
      'name' => 'entity_id:crm_core_contact',
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
  $handler->name = 'page_contact_view_template_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'contact_view_template';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Contact page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
          1 => 'right_sidebar',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => '100',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      'right_sidebar' => array(
        'type' => 'region',
        'title' => 'Right sidebar',
        'width' => '300',
        'width_type' => 'px',
        'parent' => 'main-row',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => array(
        'panel_tab_id_pattern' => 'region',
      ),
      'content' => NULL,
      'right_sidebar' => NULL,
      'middle' => array(
        'panel_tab_id_pattern' => 'region',
      ),
    ),
    'center' => array(
      'style' => 'tabs',
    ),
    'middle' => array(
      'style' => 'tabs',
    ),
  );
  $display->cache = array();
  $display->title = '%crm_core_contact:name-contact-name';
  $display->uuid = 'a002cee6-3743-46be-9095-f66543aaf5fd';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-75dd5ba2-e3fa-4466-b146-03a4094410ce';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'contact_view_main_tab_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:crm_core_contact_1',
    ),
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
  $pane->uuid = '75dd5ba2-e3fa-4466-b146-03a4094410ce';
  $display->content['new-75dd5ba2-e3fa-4466-b146-03a4094410ce'] = $pane;
  $display->panels['middle'][0] = 'new-75dd5ba2-e3fa-4466-b146-03a4094410ce';
  $pane = new stdClass();
  $pane->pid = 'new-d20a4404-5437-4adf-b3ee-274cd4ca7038';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_crm_activities-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:crm_core_contact_1',
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
  $pane->uuid = 'd20a4404-5437-4adf-b3ee-274cd4ca7038';
  $display->content['new-d20a4404-5437-4adf-b3ee-274cd4ca7038'] = $pane;
  $display->panels['middle'][1] = 'new-d20a4404-5437-4adf-b3ee-274cd4ca7038';
  $pane = new stdClass();
  $pane->pid = 'new-bc5e6dae-08b4-4c3a-8437-8acd39546a17';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_crm_contact_relationships-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:crm_core_contact_1',
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
  $pane->uuid = 'bc5e6dae-08b4-4c3a-8437-8acd39546a17';
  $display->content['new-bc5e6dae-08b4-4c3a-8437-8acd39546a17'] = $pane;
  $display->panels['middle'][2] = 'new-bc5e6dae-08b4-4c3a-8437-8acd39546a17';
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
  $display->content['new-88f8a7f6-6a91-4986-815a-4840fccaee01'] = $pane;
  $display->panels['middle'][3] = 'new-88f8a7f6-6a91-4986-815a-4840fccaee01';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;

  $pages['contact_view_template'] = $page;

  return $pages;
}
