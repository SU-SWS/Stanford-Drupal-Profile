<?php
/**
 * @file
 * stanford_private_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_private_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function stanford_private_page_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function stanford_private_page_node_info() {
  $items = array(
    'stanford_private_page' => array(
      'name' => t('Private Page'),
      'base' => 'node_content',
      'description' => t('Similar in structure to the Stanford Page, with the Content Access module the Stanford Private Page provides pages within a site that can have restricted viewing privileges. It has an image field collection, image insert, and a file insert. By default the Stanford Private Page URL starts with /private.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
