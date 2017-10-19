<?php
/**
 * @file
 * stanford_paragraph_types_two_columns.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_paragraph_types_two_columns_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_2p_style|paragraphs_item|p_two_columns|form';
  $field_group->group_name = 'group_p_2p_style';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_two_columns';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Style',
    'weight' => '0',
    'children' => array(
      0 => 'field_p_2p_body',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Style',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-p-2p-style field-group-fieldset 2p_container',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_p_2p_style|paragraphs_item|p_two_columns|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Style');

  return $field_groups;
}
