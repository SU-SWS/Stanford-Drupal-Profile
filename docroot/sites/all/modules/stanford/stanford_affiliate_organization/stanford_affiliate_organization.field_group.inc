<?php
/**
 * @file
 * stanford_affiliate_organization.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_affiliate_organization_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_affiliate_advanced|node|stanford_affiliate_organization|form';
  $field_group->group_name = 'group_s_affiliate_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_affiliate_organization';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '7',
    'children' => array(
      0 => 'field_s_affiliate_type',
      1 => 'field_s_affiliate_weight',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Advanced',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-s-affiliate-advanced field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_s_affiliate_advanced|node|stanford_affiliate_organization|form'] = $field_group;

  return $export;
}
