<?php
/**
 * @file
 * stanford_paragraph_types_dynamic.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_paragraph_types_dynamic_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_views|paragraphs_item|p_views|form';
  $field_group->group_name = 'group_p_views';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_views';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Dynamic Content',
    'weight' => '0',
    'children' => array(
      0 => 'field_p_views_view',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Dynamic Content',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-p-views field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_p_views|paragraphs_item|p_views|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Dynamic Content');

  return $field_groups;
}
