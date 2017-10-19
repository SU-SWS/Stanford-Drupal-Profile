<?php
/**
 * @file
 * stanford_courses_tag_translate.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_courses_tag_translate_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
