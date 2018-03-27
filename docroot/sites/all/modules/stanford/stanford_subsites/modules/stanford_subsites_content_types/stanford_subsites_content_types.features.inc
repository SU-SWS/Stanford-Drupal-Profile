<?php
/**
 * @file
 * stanford_subsites_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_subsites_content_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function stanford_subsites_content_types_node_info() {
  $items = array(
    'stanford_subsite' => array(
      'name' => t('Subsite'),
      'base' => 'node_content',
      'description' => t('The landing page and configuration page for a subsite. This content type allows content authors to select a new theme, logo, and site name through the content type. Users can then create content that reference subsite nodes in order to have those settings applied to them. '),
      'has_title' => '1',
      'title_label' => t('Page Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
