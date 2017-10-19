<?php
/**
 * @file
 * stanford_event_series.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_event_series_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function stanford_event_series_node_info() {
  $items = array(
    'stanford_event_series' => array(
      'name' => t('Stanford Event Series'),
      'base' => 'node_content',
      'description' => t('The Stanford Event Series displays a collection of related events.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
