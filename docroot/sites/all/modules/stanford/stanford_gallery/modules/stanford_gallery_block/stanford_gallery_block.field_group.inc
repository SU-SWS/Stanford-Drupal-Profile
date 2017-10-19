<?php
/**
 * @file
 * stanford_gallery_block.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_gallery_block_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gal_admin|bean|stanford_gallery|form';
  $field_group->group_name = 'group_gal_admin';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Administrative Settings',
    'weight' => '10',
    'children' => array(
      0 => 'revision',
      1 => 'redirect',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-gal-admin field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_gal_admin|bean|stanford_gallery|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gal_settings|bean|stanford_gallery|form';
  $field_group->group_name = 'group_gal_settings';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Gallery Settings',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_gallery_reference',
      1 => 'field_s_gallery_show_body',
      2 => 'field_s_gallery_view_mode',
      3 => 'title',
      4 => 'view_mode',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Gallery Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-gal-settings field-group-tab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_gal_settings|bean|stanford_gallery|form'] = $field_group;

  return $export;
}
