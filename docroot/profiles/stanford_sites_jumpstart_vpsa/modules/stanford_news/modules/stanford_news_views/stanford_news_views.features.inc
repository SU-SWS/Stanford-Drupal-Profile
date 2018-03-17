<?php
/**
 * @file
 * stanford_news_views.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_news_views_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function stanford_news_views_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
