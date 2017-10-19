<?php
/**
 * @file
 * stanford_courses_node_display.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_courses_node_display_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
