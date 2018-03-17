<?php
/**
 * @file
 * stanford_jsa_layouts.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function stanford_jsa_layouts_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-footer-about-menu.
  $menus['menu-footer-about-menu'] = array(
    'menu_name' => 'menu-footer-about-menu',
    'title' => 'About',
    'description' => 'The <em>Footer About menu</em> is used to show the major pages in the About section of the site.',
  );
  // Exported menu: menu-footer-academics-menu.
  $menus['menu-footer-academics-menu'] = array(
    'menu_name' => 'menu-footer-academics-menu',
    'title' => 'Academics',
    'description' => 'The <em>Footer Academics menu</em> is used to show the major pages in the Academics section of the site.',
  );
  // Exported menu: menu-footer-news-events-menu.
  $menus['menu-footer-news-events-menu'] = array(
    'menu_name' => 'menu-footer-news-events-menu',
    'title' => 'News and Events',
    'description' => 'The <em>Footer News and Events menu</em> is used to show the major pages in the News and Events sections of the site.',
  );
  // Exported menu: menu-footer-people-menu.
  $menus['menu-footer-people-menu'] = array(
    'menu_name' => 'menu-footer-people-menu',
    'title' => 'People',
    'description' => 'The <em>Footer People menu</em> is used to show the major pages in the People section of the site.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Academics');
  t('Main menu');
  t('News and Events');
  t('People');
  t('The <em>Footer About menu</em> is used to show the major pages in the About section of the site.');
  t('The <em>Footer Academics menu</em> is used to show the major pages in the Academics section of the site.');
  t('The <em>Footer News and Events menu</em> is used to show the major pages in the News and Events sections of the site.');
  t('The <em>Footer People menu</em> is used to show the major pages in the People section of the site.');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');


  return $menus;
}
