<?php
/**
 * @file
 * stanford_private_page_section.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_private_page_section_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
