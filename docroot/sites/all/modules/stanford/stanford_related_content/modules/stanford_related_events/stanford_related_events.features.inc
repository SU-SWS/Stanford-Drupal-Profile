<?php
/**
 * @file
 * stanford_related_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_related_events_ctools_plugin_api($module = null, $api = null) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
