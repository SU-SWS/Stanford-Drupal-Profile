<?php
/**
 * @file
 * stanford_metatag_nobots.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_metatag_nobots_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
