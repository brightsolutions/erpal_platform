<?php

/**
 * @file
 * Plugin definition.
 */

$plugin = array(
  'title' => t('Powered by'),
  'description' => t('Shows the powered by information'),
  'category' => t('ERPAL'),
  'render callback' => 'powered_by_content_type_render',
  'defaults' => array(
    'types' => array(),
    'field_name' => '',
  ),
);

/**
 * Render callback.
 */
function powered_by_content_type_render($subtype, $conf, $args, $context) {
  $powered_by = '<span class="powered_by_text">' . t('powered by') . '</span><span class="drupal_text"> ' . l(t('Drupal'), 'http://drupal.org') . '</span>';
  $supported_by = '<span class="supported_by_text">' . t('supported and maintained by') . '</span><span class="bs_text"> ' . l(t('Bright Solutions GmbH'), 'http://www.brightsolutions.de') . '</span>';
  $support_powered_by = '<div class="support_powered_by">' . $powered_by . ' - ' . $supported_by . '</div>';

  $block = new stdClass();
  $block->module = 'erpal_layout';
  $block->content = '<div class="powered_by_content">' . $support_powered_by . '<div class="bs_powered_by_logo"></div></div>';

  return $block;
}
