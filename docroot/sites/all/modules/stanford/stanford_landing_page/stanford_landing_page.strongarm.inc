<?php
/**
 * @file
 * stanford_landing_page.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function stanford_landing_page_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_field_collection_item__field_landing_page_item';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_12_col_banner' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_3_col_header' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_4_col_header' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_6_col_banner' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_6_col_banner_short' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_6_col_banner_tall' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_8_col_banner' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_8_col_banner_short' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_8_col_banner_tall' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_9_col_banner' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_9_col_banner_short' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_icon_square' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_large_scaled' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_large_square' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_medium_square' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_sm_profile' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_small_square' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_thumbnail_square' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_blocks' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_list' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_tiles' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_block' => array(
        'custom_settings' => FALSE,
      ),
      'large_landscape' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_12_col_banner_tall' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_6_col_photo_landscape' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_icon_profile' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_circles' => array(
        'custom_settings' => FALSE,
      ),
      'caw_banner' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'redirect' => array(
          'weight' => '5',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_field_collection_item__field_landing_page_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__stanford_landing_page';
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
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_8_col_banner' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '10',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '8',
        ),
        'redirect' => array(
          'weight' => '9',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__stanford_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_stanford_landing_page';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_stanford_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_stanford_landing_page';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_stanford_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_stanford_landing_page';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_stanford_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_stanford_landing_page';
  $strongarm->value = '1';
  $export['node_preview_stanford_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_stanford_landing_page';
  $strongarm->value = 0;
  $export['node_submitted_stanford_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_stanford_landing_page_pattern';
  $strongarm->value = '[node:menu-link:parents:join-path]/[node:title]';
  $export['pathauto_node_stanford_landing_page_pattern'] = $strongarm;

  return $export;
}
