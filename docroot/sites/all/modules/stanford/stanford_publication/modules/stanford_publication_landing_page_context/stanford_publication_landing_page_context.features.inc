<?php
/**
 * @file
 * stanford_publication_landing_page_context.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_publication_landing_page_context_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
