<?php
/**
 * @file
 * stanford_jumpstart_vpsa_workflows.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_jumpstart_vpsa_workflows_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
