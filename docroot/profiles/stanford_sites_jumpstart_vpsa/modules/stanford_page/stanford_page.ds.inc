<?php
/**
 * @file
 * stanford_page.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function stanford_page_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|stanford_page|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'stanford_page';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_s_postcard',
        2 => 'body',
        4 => 'field_s_page_file',
        5 => 'field_s_image_info',
        6 => 'group_s_postcard_image',
        7 => 'group_s_postcard_content',
      ),
      'testimonial' => array(
        1 => 'field_s_page_testimonial',
        3 => 'field_s_page_testimonial_author',
      ),
    ),
    'fields' => array(
      'group_s_postcard' => 'ds_content',
      'field_s_page_testimonial' => 'testimonial',
      'body' => 'ds_content',
      'field_s_page_testimonial_author' => 'testimonial',
      'field_s_page_file' => 'ds_content',
      'field_s_image_info' => 'ds_content',
      'group_s_postcard_image' => 'ds_content',
      'group_s_postcard_content' => 'ds_content',
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
  $export['node|stanford_page|full'] = $ds_layout;

  return $export;
}
