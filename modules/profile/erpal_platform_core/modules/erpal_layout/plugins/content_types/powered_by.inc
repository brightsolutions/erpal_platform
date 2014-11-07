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
  $erpal = sprintf(
    '<span class="erpal">%s</span>',
    l(t('ERPAL Platform'), 'http://www.erpal.info')
  );

  $powered_by = sprintf(
    '<span class="powered-by"><span class="text">%s</span> <span class="drupal">%s</span></span>',
    t('powered by'),
    l(t('Drupal'), 'http://drupal.org')
  );

  $supported_by = sprintf(
    '<span class="supported-by"><span class="text">%s</span> <span class="company">%s</span></span>',
    t('supported and maintained by'),
    l(t('Bright Solutions GmbH'), 'http://www.brightsolutions.de')
  );

  $block = new stdClass();
  $block->module = 'erpal_layout';
  $block->content = $erpal . ' ' . $powered_by . ' ' . $supported_by;

  return $block;
}
