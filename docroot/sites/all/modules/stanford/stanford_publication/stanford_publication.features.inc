<?php
/**
 * @file
 * stanford_publication.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_publication_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function stanford_publication_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function stanford_publication_node_info() {
  $items = array(
    'stanford_publication' => array(
      'name' => t('Publication'),
      'base' => 'node_content',
      'description' => t('A publication can be a book, an article, a poem, etc.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
