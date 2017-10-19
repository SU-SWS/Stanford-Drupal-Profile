<?php
/**
 * @file
 * stanford_bean_types.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function stanford_bean_types_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_bean__stanford_banner';
  $strongarm->value = array(
    'view_modes' => array(
      'default' => array(
        'custom_settings' => FALSE,
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
      'stanford_9_col_banner' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_12_col_banner' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_full_width_banner_short' => array(
        'custom_settings' => TRUE,
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
      'large_landscape' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_callout_block' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_tiles' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '1',
        ),
        'metatags' => array(
          'weight' => '40',
        ),
        'label' => array(
          'weight' => '0',
        ),
        'revision' => array(
          'weight' => '4',
        ),
        'view_mode' => array(
          'weight' => '3',
        ),
        'redirect' => array(
          'weight' => '5',
        ),
      ),
      'display' => array(
        'title' => array(
          'default' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'stanford_full_width_banner_short' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_bean__stanford_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_bean__stanford_postcard';
  $strongarm->value = array(
    'view_modes' => array(
      'default' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_12_col_banner_tall' => array(
        'weight' => '-5',
        'visible' => TRUE,
        'custom_settings' => FALSE,
      ),
      'stanford_9_col_banner' => array(
        'weight' => '-5',
        'visible' => TRUE,
        'custom_settings' => FALSE,
      ),
      'stanford_12_col_banner' => array(
        'weight' => '-5',
        'visible' => TRUE,
        'custom_settings' => FALSE,
      ),
      'stanford_6_col_photo_landscape' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_4_col_header' => array(
        'custom_settings' => TRUE,
      ),
      'stanford_3_col_header' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'metatags' => array(
          'weight' => '40',
        ),
      ),
      'display' => array(
        'title' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'stanford_6_col_photo_landscape' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'stanford_4_col_header' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'stanford_3_col_header' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_bean__stanford_postcard'] = $strongarm;

  return $export;
}
