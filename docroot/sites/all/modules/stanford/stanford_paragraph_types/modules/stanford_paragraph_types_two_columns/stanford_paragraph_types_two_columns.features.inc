<?php
/**
 * @file
 * stanford_paragraph_types_two_columns.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_paragraph_types_two_columns_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function stanford_paragraph_types_two_columns_paragraphs_info() {
  $items = array(
    'p_two_columns' => array(
      'name' => 'Two Columns',
      'bundle' => 'p_two_columns',
      'locked' => '1',
    ),
  );
  return $items;
}
