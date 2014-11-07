<?php

/**
 * @file
 * With content type "Usermenu Welcome".
 *
 * Shows logged-in Username with a welcome-message based on the time of day.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  "title" => t('Usermenu Welcome'),
  "description" => t('Logged-in User-info with Greeting'),
  "render callback" => "erpal_usermenu_welcome_render",
  "defaults" => array(
    'greeting' => t('Hey')
  ),
  "category" => t('ERPAL'),
  'edit form' => 'erpal_usermenu_welcome_form',
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
 *   An object with at least content.
 */
function erpal_usermenu_welcome_render($subtype, $conf, $args, $contexts) {
  $account = $contexts->data;

  if (!empty($contexts)) {
    $greeting = ctools_context_keyword_substitute($conf['greeting'], array(), $contexts);
  }

  $block = new stdClass();
  $block->content = t("$greeting, !user!", array('!user' => l(format_username($account), 'user/' . $account->uid)));

  return $block;
}

/**
 * The form for usermenu welcome settings.
 */
function erpal_usermenu_welcome_form($form, &$form_state) {
  $greet = $form_state['conf']['greeting'];

  $form['greeting'] = array(
    '#type' => 'textfield',
    '#title' => t('Welcome text'),
    '#default_value' => ($greet) ? $greet : $form_state['plugin']['defaults']['greeting'],
    '#required' => TRUE,
  );

  return $form;
}

/**
 * Save to config all settings.
 */
function erpal_usermenu_welcome_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
