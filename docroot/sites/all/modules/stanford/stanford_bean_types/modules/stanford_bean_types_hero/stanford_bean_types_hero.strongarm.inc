<?php
/**
 * @file
 * stanford_bean_types_hero.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function stanford_bean_types_hero_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_bean__stanford_hero_block';
  $strongarm->value = array(
    'view_modes' => array(
      'default' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_12_col_banner_tall' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_12_col_banner' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_3_col_header' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_4_col_header' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_6_col_photo_landscape' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_8_col_banner' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_9_col_banner' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_banner_fw_short_credits' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_full_width_banner_short' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_header_150_width_left' => array(
        'custom_settings' => FALSE,
      ),
      'large_landscape' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_tiles' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'label' => array(
          'weight' => '0',
        ),
        'title' => array(
          'weight' => '3',
        ),
        'revision' => array(
          'weight' => '4',
        ),
        'view_mode' => array(
          'weight' => '5',
        ),
        'redirect' => array(
          'weight' => '6',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_bean__stanford_hero_block'] = $strongarm;

  return $export;
}
