<?php
/**
 * @file
 * stanford_help.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_help_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function stanford_help_node_info() {
  $items = array(
    'stanford_help_page' => array(
      'name' => t('Help Page'),
      'base' => 'node_content',
      'description' => t('Content type to house site specific help.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
