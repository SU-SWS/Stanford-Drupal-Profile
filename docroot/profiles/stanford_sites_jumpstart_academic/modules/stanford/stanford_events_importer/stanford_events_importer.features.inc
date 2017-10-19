<?php
/**
 * @file
 * stanford_events_importer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_events_importer_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "data" && $api == "data_default") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
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
function stanford_events_importer_node_info() {
  $items = array(
    'stanford_event' => array(
      'name' => t('Stanford Event'),
      'base' => 'node_content',
      'description' => t('An event pulled in from <a href="http://events.stanford.edu">events.stanford.edu</a>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'stanford_event_importer' => array(
      'name' => t('Stanford Event Importer'),
      'base' => 'node_content',
      'description' => t('This is a meta content type with which you can create Stanford Event Importer Feeds. Give it a title (eg, "Featured Events") and choose <strong>either</strong> a category <strong>or</strong> an organization. Full documentation of the Stanford Events Drupal Feed Service is available at <a href="http://events.stanford.edu/xml/drupal/">http://events.stanford.edu/xml/drupal/</a>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
