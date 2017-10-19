<?php
/**
 * @file
 * stanford_gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_gallery_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
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
function stanford_gallery_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function stanford_gallery_node_info() {
  $items = array(
    'stanford_gallery' => array(
      'name' => t('Gallery'),
      'base' => 'node_content',
      'description' => t('A content type that allows content authors to create a thumbnail gallery of images with a modal pop up.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
