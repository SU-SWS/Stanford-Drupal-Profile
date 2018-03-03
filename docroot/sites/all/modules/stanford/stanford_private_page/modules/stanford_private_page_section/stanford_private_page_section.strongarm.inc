<?php
/**
 * @file
 * stanford_private_page_section.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function stanford_private_page_section_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_stanford_private_page';
  $strongarm->value = array(
    0 => 'menu-menu-private-pages',
  );
  $export['menu_options_stanford_private_page'] = $strongarm;

  return $export;
}
