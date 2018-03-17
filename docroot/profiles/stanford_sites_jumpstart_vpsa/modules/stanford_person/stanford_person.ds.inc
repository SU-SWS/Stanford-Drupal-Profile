<?php
/**
 * @file
 * stanford_person.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function stanford_person_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|stanford_person|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'stanford_person';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|stanford_person|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|stanford_person|stanford_huge_landscape';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'stanford_person';
  $ds_fieldsetting->view_mode = 'stanford_huge_landscape';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '21',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|stanford_person|stanford_huge_landscape'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function stanford_person_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|stanford_person|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'stanford_person';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'group_s_postcard',
        2 => 'field_s_person_title',
        3 => 'field_s_person_department',
        4 => 'group_department_school_styles',
        5 => 'group_social_media_styles',
        6 => 'field_s_person_school',
        7 => 'group_contact_info_styles',
        8 => 'body',
        9 => 'field_s_person_email',
        10 => 'field_s_person_phone_display',
        11 => 'field_s_person_office_location',
        12 => 'field_s_person_office_hours',
        13 => 'field_s_person_info_links',
        14 => 'group_s_postcard_col1',
        15 => 'group_s_postcard_col2',
        16 => 'field_s_person_facebook',
        17 => 'field_s_person_twitter',
        18 => 'field_s_person_googleplus',
        19 => 'field_s_person_linkedin',
        20 => 'field_s_person_instagram',
        21 => 'field_s_person_youtube',
        22 => 'field_s_person_vimeo',
        23 => 'field_s_person_tumblr',
        24 => 'field_s_person_pinterest',
        25 => 'field_s_person_flickr',
        26 => 'group_image_border_style',
        27 => 'field_s_person_profile_picture',
        28=> 'group_picture_credits_style',
        29 => 'field_s_person_picture_credits',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'group_s_postcard' => 'ds_content',
      'field_s_person_title' => 'ds_content',
      'field_s_person_department' => 'ds_content',
      'group_department_school_styles' => 'ds_content',
      'group_social_media_styles' => 'ds_content',
      'field_s_person_school' => 'ds_content',
      'group_contact_info_styles' => 'ds_content',
      'body' => 'ds_content',
      'field_s_person_email' => 'ds_content',
      'field_s_person_phone_display' => 'ds_content',
      'field_s_person_office_location' => 'ds_content',
      'field_s_person_office_hours' => 'ds_content',
      'field_s_person_info_links' => 'ds_content',
      'group_s_postcard_col1' => 'ds_content',
      'group_s_postcard_col2' => 'ds_content',
      'field_s_person_facebook' => 'ds_content',
      'field_s_person_twitter' => 'ds_content',
      'field_s_person_googleplus' => 'ds_content',
      'field_s_person_linkedin' => 'ds_content',
      'field_s_person_instagram' => 'ds_content',
      'field_s_person_youtube' => 'ds_content',
      'field_s_person_vimeo' => 'ds_content',
      'field_s_person_tumblr' => 'ds_content',
      'field_s_person_pinterest' => 'ds_content',
      'field_s_person_flickr' => 'ds_content',
      'group_image_border_style' => 'ds_content',
      'field_s_person_profile_picture' => 'ds_content',
      'group_picture_credits_style' => 'ds_content',
      'field_s_person_picture_credits' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|stanford_person|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|stanford_person|stanford_huge_landscape';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'stanford_person';
  $ds_layout->view_mode = 'stanford_huge_landscape';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_s_postcard',
        1 => 'field_s_person_department',
        2 => 'field_s_person_school',
        3 => 'field_s_person_profile_picture',
        4 => 'field_s_person_facebook',
        5 => 'field_s_person_twitter',
        6 => 'field_s_person_googleplus',
        7 => 'field_s_person_linkedin',
        8 => 'field_s_person_instagram',
        9 => 'field_s_person_youtube',
        10 => 'field_s_person_vimeo',
        11 => 'field_s_person_tumblr',
        12 => 'field_s_person_pinterest',
        13 => 'field_s_person_flickr',
        14 => 'title',
        15 => 'field_s_person_title',
        16 => 'group_department_school_styles',
        17 => 'group_social_media_styles',
        18 => 'group_contact_info_styles',
        19 => 'body',
        20 => 'field_s_person_email',
        21 => 'field_s_person_phone_display',
        22 => 'field_s_person_office_location',
        23 => 'field_s_person_office_hours',
        24 => 'field_s_person_info_links',
        25 => 'group_s_postcard_col1',
        26 => 'group_s_postcard_col2',
        27 => 'group_s_image_border_style',
        28 => 'group_image_credits_style',
        29 => 'field_s_person_picture_credits',
      ),
    ),
    'fields' => array(
      'field_s_person_picture_credits' => 'ds_content',
      'group_s_postcard' => 'ds_content',
      'field_s_person_department' => 'ds_content',
      'field_s_person_school' => 'ds_content',
      'field_s_person_profile_picture' => 'ds_content',
      'field_s_person_facebook' => 'ds_content',
      'field_s_person_twitter' => 'ds_content',
      'field_s_person_googleplus' => 'ds_content',
      'field_s_person_linkedin' => 'ds_content',
      'field_s_person_instagram' => 'ds_content',
      'field_s_person_youtube' => 'ds_content',
      'field_s_person_vimeo' => 'ds_content',
      'field_s_person_tumblr' => 'ds_content',
      'field_s_person_pinterest' => 'ds_content',
      'field_s_person_flickr' => 'ds_content',
      'title' => 'ds_content',
      'field_s_person_title' => 'ds_content',
      'group_department_school_styles' => 'ds_content',
      'group_social_media_styles' => 'ds_content',
      'group_contact_info_styles' => 'ds_content',
      'body' => 'ds_content',
      'group_image_credits_style' => 'ds_content',
      'field_s_person_email' => 'ds_content',
      'field_s_person_phone_display' => 'ds_content',
      'field_s_person_office_location' => 'ds_content',
      'field_s_person_office_hours' => 'ds_content',
      'field_s_person_info_links' => 'ds_content',
      'group_s_postcard_col1' => 'ds_content',
      'group_s_image_border_style' => 'ds_content',
      'group_s_postcard_col2' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|stanford_person|stanford_huge_landscape'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function stanford_person_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_huge_landscape';
  $ds_view_mode->label = 'Huge Landscape';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
    'node' => 'node',
  );
  $export['stanford_huge_landscape'] = $ds_view_mode;

  return $export;
}
