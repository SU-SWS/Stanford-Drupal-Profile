<?php
/**
 * @file
 * stanford_events_export.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function stanford_events_export_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_iso_8601';
  $strongarm->value = 'c';
  $export['date_format_iso_8601'] = $strongarm;

  return $export;
}
