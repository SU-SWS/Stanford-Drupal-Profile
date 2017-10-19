<?php
/**
 * @file
 * stanford_bean_types.features.inc
 */

/**
 * Implements hook_bean_types_api_info().
 */
function stanford_bean_types_bean_types_api_info($module = NULL, $api = NULL) {
  if ($module == "bean" && $api == "types") {
    return array("version" => "5");
  }
}

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_bean_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
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
function stanford_bean_types_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
