<?php
/**
 * @file
 * stanford_person.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_person_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
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
function stanford_person_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function stanford_person_node_info() {
  $items = array(
    'stanford_person' => array(
      'name' => t('Person'),
      'base' => 'node_content',
      'description' => t('The person content type maintains information about a person. A person can be staff, faculty, student, and alumni.'),
      'has_title' => '1',
      'title_label' => t('Display Name'),
      'help' => t('This form captures information about a person. First and last name are required.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
