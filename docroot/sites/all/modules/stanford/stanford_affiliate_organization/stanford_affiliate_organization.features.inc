<?php
/**
 * @file
 * stanford_affiliate_organization.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_affiliate_organization_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function stanford_affiliate_organization_node_info() {
  $items = array(
    'stanford_affiliate_organization' => array(
      'name' => t('Affiliate Organization'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
