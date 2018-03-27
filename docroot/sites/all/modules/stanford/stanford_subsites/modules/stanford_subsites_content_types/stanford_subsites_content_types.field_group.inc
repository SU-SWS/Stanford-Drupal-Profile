<?php
/**
 * @file
 * stanford_subsites_content_types.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_subsites_content_types_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_display_options|node|stanford_subsite|form';
  $field_group->group_name = 'group_display_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_subsite';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Subsite Branding options',
    'weight' => '7',
    'children' => array(
      0 => 'field_stanford_subsite_front',
      1 => 'field_stanford_subsite_logo',
      2 => 'field_stanford_subsite_slogan',
      3 => 'field_stanford_subsite_theme',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Subsite Branding options',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-display-options field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_display_options|node|stanford_subsite|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_subsite_info|node|stanford_subsite|form';
  $field_group->group_name = 'group_subsite_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_subsite';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Subsite information',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_stanford_subsite_2nd_line',
      2 => 'field_stanford_subsite_sname',
      3 => 'field_stanford_subsite_sub_tags',
      4 => 'field_subsite_machine_name',
      5 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-subsite-info field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_subsite_info|node|stanford_subsite|form'] = $field_group;

  return $export;
}
