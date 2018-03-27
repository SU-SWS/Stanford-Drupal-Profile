<?php
/**
 * @file
 * stanford_faq.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function stanford_faq_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_faq';
  $strongarm->value = array();
  $export['menu_options_faq'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_faq_default';
  $strongarm->value = array(
    'title' => array(
      'region' => 'main',
      'weight' => '-5',
      'has_required' => TRUE,
      'title' => 'Question',
    ),
    'additional_settings' => array(
      'region' => 'main',
      'weight' => '99',
      'has_required' => FALSE,
      'title' => 'Vertical tabs',
      'hidden' => 0,
    ),
    'actions' => array(
      'region' => 'main',
      'weight' => '100',
      'has_required' => FALSE,
      'title' => 'Save',
      'hidden' => 0,
    ),
    'body' => array(
      'region' => 'main',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => 'Answer',
      'hidden' => 0,
    ),
    'field_detailed_question' => array(
      'region' => 'main',
      'weight' => '5',
      'has_required' => FALSE,
      'title' => 'Detailed question',
      'hidden' => 1,
    ),
    'field_s_faq_category' => array(
      'region' => 'main',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => 'Display Categories',
      'hidden' => 0,
    ),
  );
  $export['nodeformscols_field_placements_faq_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_faq';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_faq'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_faq_pattern';
  $strongarm->value = 'faq/[node:title]';
  $export['pathauto_node_faq_pattern'] = $strongarm;

  return $export;
}
