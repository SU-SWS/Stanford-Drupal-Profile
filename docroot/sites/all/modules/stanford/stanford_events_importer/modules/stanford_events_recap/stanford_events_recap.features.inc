<?php
/**
 * @file
 * stanford_events_recap.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_events_recap_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
