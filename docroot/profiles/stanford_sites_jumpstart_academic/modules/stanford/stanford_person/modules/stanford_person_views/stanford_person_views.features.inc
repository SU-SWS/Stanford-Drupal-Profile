<?php
/**
 * @file
 * stanford_person_views.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_person_views_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function stanford_person_views_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
