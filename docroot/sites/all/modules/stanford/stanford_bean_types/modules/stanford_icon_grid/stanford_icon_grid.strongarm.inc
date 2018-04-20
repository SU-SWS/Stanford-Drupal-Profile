<?php
/**
 * @file
 * stanford_icon_grid.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function stanford_icon_grid_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_field_collection_item__field_s_icon_ext_columns';
  $strongarm->value = array(
    'view_modes' => array(
      'stanford_block' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_list' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_tiles' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_12_col_banner_tall' => array(
        'custom_settings' => FALSE,
      ),
      'gallery_large' => array(
        'custom_settings' => FALSE,
      ),
      'gallery_medium' => array(
        'custom_settings' => FALSE,
      ),
      'gallery_small' => array(
        'custom_settings' => FALSE,
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
      'stanford_6_col_banner' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_6_col_banner_short' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_6_col_banner_tall' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_6_col_photo_landscape' => array(
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
      'stanford_banner_850x400' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_banner_fw_short_credits' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_full_width_banner' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_full_width_banner_short' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_icon_profile' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_icon_scaled' => array(
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
        'custom_settings' => FALSE,
      ),
      'stanford_sm_landscape_scaled' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_sm_profile' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_sm_scaled' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_small_square' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_thumbnail_square' => array(
        'custom_settings' => FALSE,
      ),
      'large_landscape' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_field_collection_item__field_s_icon_ext_columns'] = $strongarm;

  return $export;
}
