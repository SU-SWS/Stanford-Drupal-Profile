<?php
/**
 * @file
 * stanford_slides.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_slides_ctools_plugin_api($module = NULL, $api = NULL) {
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
function stanford_slides_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function stanford_slides_node_info() {
  $items = array(
    'stanford_slide' => array(
      'name' => t('Stanford Slide'),
      'base' => 'node_content',
      'description' => t('Used when the image is not associated with content.  For slideshows, rotating images, etc.
Basically just the image field collection (no body text) with a link, type, and weight.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
