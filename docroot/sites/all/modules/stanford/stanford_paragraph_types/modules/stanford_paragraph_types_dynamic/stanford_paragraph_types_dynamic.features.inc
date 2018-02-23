<?php
/**
 * @file
 * stanford_paragraph_types_dynamic.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_paragraph_types_dynamic_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function stanford_paragraph_types_dynamic_paragraphs_info() {
  $items = array(
    'p_views' => array(
      'name' => 'Dynamic Content',
      'bundle' => 'p_views',
      'locked' => '1',
    ),
  );
  return $items;
}
