<?php
/**
 * @file
 * stanford_subsites_content_types.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function stanford_subsites_content_types_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_stanford_subsite';
  $strongarm->value = 0;
  $export['node_submitted_stanford_subsite'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_stanford_subsite_pattern';
  $strongarm->value = '[node:field_stanford_subsite_sname]';
  $export['pathauto_node_stanford_subsite_pattern'] = $strongarm;

  return $export;
}
