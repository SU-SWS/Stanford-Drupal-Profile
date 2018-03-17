<?php
/**
 * @file
 * stanford_events_importer.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function stanford_events_importer_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_event_importer-blank_source_1-cast_to_int';
  $feeds_tamper->importer = 'stanford_event_importer';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'cast_to_int';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Cast to integer';
  $export['stanford_event_importer-blank_source_1-cast_to_int'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_event_importer-blank_source_1-default_value';
  $feeds_tamper->importer = 'stanford_event_importer';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '0',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set default value';
  $export['stanford_event_importer-blank_source_1-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_event_importer-xpathparser_0-html_entity_decode';
  $feeds_tamper->importer = 'stanford_event_importer';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['stanford_event_importer-xpathparser_0-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_event_importer-xpathparser_15-string_to_unix_timestamp';
  $feeds_tamper->importer = 'stanford_event_importer';
  $feeds_tamper->source = 'xpathparser:15';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['stanford_event_importer-xpathparser_15-string_to_unix_timestamp'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_event_importer-xpathparser_3-string_to_unix_timestamp';
  $feeds_tamper->importer = 'stanford_event_importer';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['stanford_event_importer-xpathparser_3-string_to_unix_timestamp'] = $feeds_tamper;

  return $export;
}
