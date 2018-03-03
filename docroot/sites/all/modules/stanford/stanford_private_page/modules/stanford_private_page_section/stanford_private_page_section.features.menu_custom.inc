<?php
/**
 * @file
 * stanford_private_page_section.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function stanford_private_page_section_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-menu-private-pages.
  $menus['menu-menu-private-pages'] = array(
    'menu_name' => 'menu-menu-private-pages',
    'title' => 'Private Pages',
    'description' => 'The <em>Private Pages</em> menu contains links to private pages.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Private Pages');
  t('The <em>Private Pages</em> menu contains links to private pages.');


  return $menus;
}
