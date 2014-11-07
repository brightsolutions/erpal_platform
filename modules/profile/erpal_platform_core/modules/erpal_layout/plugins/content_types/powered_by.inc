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
  $powered_by = sprintf(
    '<span class="powered-by-text">%s</span> <span class="drupal-text">%s</span>',
    t('powered by'),
    l(t('Drupal'), 'http://drupal.org')
  );

  $supported_by = sprintf(
    '<span class="support-by"><span class="supported-by-text">%s</span> <span class="supported-by-company">%s</span></span>',
    t('supported and maintained by'),
    l(t('Bright Solutions GmbH'), 'http://www.brightsolutions.de')
  );

  $block = new stdClass();
  $block->module = 'erpal_layout';
  $block->content = '<div class="powered-by-content">' . $powered_by . ' ' . $supported_by . '</div>';

  return $block;
}
