<?php

/**
 * @file
 * With content type "User Avatar".
 *
 * Shows User Avatar with settings.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  "title"           => t('User Avatar'),
  "description"     => t('User Avatar with custom settings'),
  "render callback" => "erpal_user_avatar_render",
  "defaults"        => array(),
  "category"        => t('ERPAL'),
  'edit form' => 'erpal_user_avatar_form',
  'required context' => new ctools_context_required(t('User'), 'user'),
);


/**
 * Run-time rendering of the body of the block.
 *
 * @param array $subtype
 *   subtype configuration.
 * @param array $conf
 *   Configuration as done at admin time.
 * @param array $args
 *   current page args.
 * @param array $context
 *   Context - in this case we don't have any.
 *
 * @return object
 *   An object with at least title and content.
 */
function erpal_user_avatar_render($subtype, $conf, $args, $context) {

  if (empty($context->data) || !variable_get('user_pictures')) {
    return FALSE;
  }
  $account = $context->data;

  $block = new stdClass();
  if (!empty($account->picture)) {
    if (is_numeric($account->picture)) {
      $account->picture = file_load($account->picture);
    }
    if (!empty($account->picture->uri)) {
      $filepath = $account->picture->uri;
    }
  }
  else {
    $filepath = variable_get('user_picture_default', '');
  }

  if (empty($filepath)) {
    return FALSE;
  }

  if (module_exists('image') && file_valid_uri($filepath) && $style = variable_get('user_picture_style', '')) {
    $image = array(
      '#theme' => 'image_style',
      '#style_name' => $conf['image_style'],
      '#path' => $filepath,
    );
  }
  else {
    $image = array(
      '#theme' => 'image',
      '#path' => $filepath,
    );
  }

  if (!empty($image)) {
    if (user_is_anonymous()) {
      $block->content = render($image);
    }
    else {
      $block->content = l(render($image), 'user/' . $account->uid, array('html' => TRUE)); 
    }
  }

  return $block;
}

/**
 * The form for user avatar settings.
 */
function erpal_user_avatar_form($form, &$form_state) {

  $conf = $form_state['conf'];
  $styles_array = image_styles();
  $styles = array();
  foreach ($styles_array as $key => $style) {
    $styles[$key] = $style['label'];
  }

  $form['image_style'] = array(
    '#type'          => 'select',
    '#title'         => t('Image style'),
    '#default_value' => $conf['image_style'],
    '#options'       => $styles,
    '#required'      => TRUE,
  );

  return $form;
}

/**
 * Save to config all settings.
 */
function erpal_user_avatar_form_submit($form, &$form_state) {
  foreach (array('image_style') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
