<?php
/**
 * @file
 * stanford_jse_layouts.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_jse_layouts_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
