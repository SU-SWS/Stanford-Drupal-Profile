<?php
/**
 * @file
 * stanford_fellowship.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function stanford_fellowship_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_stanford_fellowship';
  $strongarm->value = 0;
  $export['comment_anonymous_stanford_fellowship'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_stanford_fellowship';
  $strongarm->value = 1;
  $export['comment_default_mode_stanford_fellowship'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_stanford_fellowship';
  $strongarm->value = '50';
  $export['comment_default_per_page_stanford_fellowship'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_stanford_fellowship';
  $strongarm->value = 1;
  $export['comment_form_location_stanford_fellowship'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_stanford_fellowship';
  $strongarm->value = '1';
  $export['comment_preview_stanford_fellowship'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_stanford_fellowship';
  $strongarm->value = '1';
  $export['comment_stanford_fellowship'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_stanford_fellowship';
  $strongarm->value = 1;
  $export['comment_subject_field_stanford_fellowship'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__stanford_fellowship';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_8_col_banner' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'taxonomy' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_huge_landscape' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '14',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '15',
        ),
        'redirect' => array(
          'weight' => '17',
        ),
        'xmlsitemap' => array(
          'weight' => '16',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__stanford_fellowship'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_stanford_fellowship';
  $strongarm->value = array();
  $export['menu_options_stanford_fellowship'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_stanford_fellowship';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_stanford_fellowship'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_stanford_fellowship';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_stanford_fellowship'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_stanford_fellowship';
  $strongarm->value = '1';
  $export['node_preview_stanford_fellowship'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_stanford_fellowship';
  $strongarm->value = 0;
  $export['node_submitted_stanford_fellowship'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_stanford_fellowship_pattern';
  $strongarm->value = 'fellowship/[node:title]';
  $export['pathauto_node_stanford_fellowship_pattern'] = $strongarm;

  return $export;
}
