<?php
/**
 * @file
 * stanford_image.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function stanford_image_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_field_collection_item__field_s_image_info';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_med_profile' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_6_col_banner' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_8_col_banner' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_9_col_banner' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_12_col_banner' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_thumbnail' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_thmb_landscape' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_thmb_profile' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_thmb_square' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_sm_landscape' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_sm_profile' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_sm_square' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_medium' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_med_landscape' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_med_square' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_large' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_large_landscape' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_large_profile' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_large_square' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_3_col_header' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_3_col_well_header' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_3_col_well_profile' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_4_col_header' => array(
        'custom_settings' => TRUE,
      ),
      '6_col_header' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_6_col_header_short' => array(
        'custom_settings' => FALSE,
      ),
      'icon' => array(
        'custom_settings' => FALSE,
      ),
      'test' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_large_scaled' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_medium_square' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_small_square' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_thumbnail_square' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_6_col_banner_short' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_6_col_banner_tall' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_8_col_banner_short' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_8_col_banner_tall' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_9_col_banner_short' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_icon_square' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_12_col_banner_tall' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_6_col_photo_landscape' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_icon_profile' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_icon_scaled' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_sm_scaled' => array(
        'custom_settings' => TRUE,
      ),
      'large_landscape' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_block' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_callout_block' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_list' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_tiles' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_full_width_banner' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_full_width_banner_short' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_huge_landscape' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_banner_850x400' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'redirect' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_field_collection_item__field_s_image_info'] = $strongarm;

  return $export;
}
