<?php
/**
 * @file
 * stanford_news_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_news_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
