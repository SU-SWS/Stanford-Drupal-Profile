<?php

/**
 * @file
 * Stanford Image Styles Drush Commands.
 */

/**
 * Implements hook_drush_command().
 */
function stanford_image_styles_drush_command() {
  $items = array();
  $items['stanford-image-styles-behat'] = array(
    'aliases' => array('sis-behat'),
  );
  return $items;
}

/**
 * Print out behat test for all image styles in this module.
 */
function drush_stanford_image_styles_behat() {
  module_load_include('inc', 'stanford_image_styles', 'stanford_image_styles.features');
  module_load_include('inc', 'image', 'image.admin');
  $styles = stanford_image_styles_image_default_styles();

  $i_should_see = '';
  $effects = '';
  foreach ($styles as $name => $style) {
    $style = image_style_load($name);

    $i_should_see .= 'And I should see "' . $style['label'] . "\"\n";
    $effects .= "Then I am on \"admin/config/media/image-styles/edit/$name\"\n";

    foreach ($style['effects'] as $effect) {
      $summary = $effect['label'];
      if (isset($effect['summary theme'])) {
        $summary .= ' ' . theme($effect['summary theme'], array('data' => $effect['data']));
      }

      $effects .= "And I should see \"$summary\"\n";
    }
  }

  drush_print($i_should_see);
  drush_print($effects);
}
