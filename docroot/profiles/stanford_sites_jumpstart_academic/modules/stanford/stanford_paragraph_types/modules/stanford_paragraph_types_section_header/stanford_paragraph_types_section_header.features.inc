<?php
/**
 * @file
 * stanford_paragraph_types_section_header.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_paragraph_types_section_header_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function stanford_paragraph_types_section_header_paragraphs_info() {
  $items = array(
    'p_section_header' => array(
      'name' => 'Section Header',
      'bundle' => 'p_section_header',
      'locked' => '1',
    ),
  );
  return $items;
}
