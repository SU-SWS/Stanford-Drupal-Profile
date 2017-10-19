<?php
/**
 * @file
 * stanford_courses_node_display.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function stanford_courses_node_display_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|stanford_course|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'stanford_course';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'section_information' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_s_course_code' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'course-code',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_s_course_subject' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'course-subject',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|stanford_course|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function stanford_courses_node_display_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'section_information';
  $ds_field->label = 'Section Information';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'stanford_course|*';
  $ds_field->properties = array(
    'block' => 'views|courses_reference-section_info',
    'block_render' => '1',
  );
  $export['section_information'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function stanford_courses_node_display_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|stanford_course|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'stanford_course';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_s_postcard',
        1 => 'group_s_postcard_content',
        2 => 'field_s_course_ec_link',
        3 => 'group_morelink_group',
        4 => 'group_coursenum_group',
        5 => 'section_information',
        6 => 'field_s_course_subject',
        7 => 'body',
        8 => 'field_s_course_code',
        9 => 'group_s_postcard_image',
        10 => 'field_s_image_info',
      ),
    ),
    'fields' => array(
      'group_s_postcard' => 'ds_content',
      'group_s_postcard_content' => 'ds_content',
      'field_s_course_ec_link' => 'ds_content',
      'group_morelink_group' => 'ds_content',
      'group_coursenum_group' => 'ds_content',
      'section_information' => 'ds_content',
      'field_s_course_subject' => 'ds_content',
      'body' => 'ds_content',
      'field_s_course_code' => 'ds_content',
      'group_s_postcard_image' => 'ds_content',
      'field_s_image_info' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|stanford_course|default'] = $ds_layout;

  return $export;
}
