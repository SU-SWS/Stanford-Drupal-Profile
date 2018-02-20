<?php

/**
 * @file
 * stanford_field_formatters.drush.inc
 */

use Symfony\Component\Yaml\Parser;

/**
 * Implements hook_drush_command.
 */
function stanford_field_formatters_drush_command() {
  $items = array();
  $items['stanford-field-formatters-font-awesome'] = array(
    'aliases' => array('sff-fa'),
  );
  return $items;
}

/**
 *
 */
function drush_stanford_field_formatters_font_awesome() {
  $yaml = 'https://raw.githubusercontent.com/FortAwesome/Font-Awesome/master/src/icons.yml';
  $request = drupal_http_request($yaml);

  $fa_icons = array();
  $yaml = new Parser();
  $value = $yaml->parse($request->data);
  foreach ($value['icons'] as $icon) {
    if (!empty($icon['categories'])) {
      foreach ($icon['categories'] as $category) {
        $fa_icons[$category][$icon['id']] = $icon['name'];
      }
      if(count($icon['categories']) > 1){
        drush_print($icon['id']);
      }
    }
    else {
      $fa_icons['Other'][$icon['id']] = $icon;
    }
  }

  ksort($fa_icons);
  foreach ($fa_icons as &$group) {
    asort($group);
  }

  $json_string = json_encode($fa_icons, JSON_PRETTY_PRINT);
  $file = fopen(drupal_get_path('module', 'stanford_field_formatters'). '/css/font-awesome.json', 'w');
  fwrite($file, $json_string);
  fclose($file);
}
