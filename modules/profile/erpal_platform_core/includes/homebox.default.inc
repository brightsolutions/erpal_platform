<?php

/**
 * @file
 * Contains default homeboxes for ERPAL Platform.
 */
function _erpal_platform_core_homebox_defaults() {
  $homeboxes = array();

  $homeboxes['dashboard'] = array(
    'regions' => 2,
    'cache' => 0,
    'color' => 0,
    'colors' =>
      array(
        0 => '#E4F0F8',
        1 => '#E4F0F8',
        2 => '#E4F0F8',
        3 => '#E4F0F8',
        4 => '#E4F0F8',
        5 => '#E4F0F8',
      ),
    'blocks' =>
      array(
        'views_erpal_crm_contacts-block_1' =>
          array(
            'module' => 'views',
            'delta' => 'erpal_crm_contacts-block_1',
            'region' => 1,
            'movable' => 1,
            'status' => 1,
            'open' => 1,
            'closable' => 1,
            'title' => '',
            'weight' => -14,
          ),
        'views_erpal_order-block_1' =>
          array(
            'module' => 'views',
            'delta' => 'erpal_order-block_1',
            'region' => 2,
            'movable' => 1,
            'status' => 1,
            'open' => 1,
            'closable' => 1,
            'title' => '',
            'weight' => -13,
          ),
        'views_erpal_crm_activities-block_1' =>
          array(
            'module' => 'views',
            'delta' => 'erpal_crm_activities-block_1',
            'region' => 1,
            'movable' => 1,
            'status' => 1,
            'open' => 1,
            'closable' => 1,
            'title' => '',
            'weight' => -13,
          ),
        'views_erpal_quote-block_1' =>
          array(
            'module' => 'views',
            'delta' => 'erpal_quote-block_1',
            'region' => 2,
            'movable' => 1,
            'status' => 1,
            'open' => 1,
            'closable' => 1,
            'title' => '',
            'weight' => -14,
          ),
        'views_d0afc51f00108852c945d9f0fbc2962b' =>
          array(
            'module' => 'views',
            'delta' => 'd0afc51f00108852c945d9f0fbc2962b',
            'region' => 2,
            'movable' => 1,
            'status' => 1,
            'open' => 1,
            'closable' => 1,
            'title' => '',
            'weight' => -12,
          ),
        'views_erpal_invoice-block_1' =>
          array(
            'module' => 'views',
            'delta' => 'erpal_invoice-block_1',
            'region' => 2,
            'movable' => 1,
            'status' => 1,
            'open' => 1,
            'closable' => 1,
            'title' => '',
            'weight' => -11,
          ),
      ),
    'widths' => array(),
    'title' => 'Dashboard',
    'path' => 'home',
    'menu' => 0,
    'enabled' => 1,
    'auto_save' => 1,
    'full' => 1,
    'roles' =>
      array(
        0 => 'authenticated user',
      ),
  );

  return $homeboxes;
}