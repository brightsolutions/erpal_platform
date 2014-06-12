<?php
/**
 * @file
 * Enables modules and site configuration for a erpal platform site installation.
 */
 
/**
 * Implements hook_install_tasks_alter().
 */
function erpal_platform_install_tasks_alter(&$tasks, $install_state) {
  
  $tasks['install_select_profile']['display'] = FALSE;

  _erpal_platform_set_theme('erpal_maintenance');
}


/**
 * Forces to set the erpal_maintenance theme during the installation
 */
function _erpal_platform_set_theme($target_theme) {
  if ($GLOBALS['theme'] != $target_theme) {
    unset($GLOBALS['theme']);
    drupal_static_reset();
    $GLOBALS['conf']['maintenance_theme'] = $target_theme;
    _drupal_maintenance_theme();
  }
}
 