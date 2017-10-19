<?php
/**
 * @file
 * stanford_jumpstart_shortcuts.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function stanford_jumpstart_shortcuts_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-admin-shortcuts.
  $menus['menu-admin-shortcuts'] = array(
    'menu_name' => 'menu-admin-shortcuts',
    'title' => 'Admin Shortcuts',
    'description' => 'A place to put shortcut links',
  );

  t('Admin Shortcuts: Shortcuts');

  return $menus;
}
