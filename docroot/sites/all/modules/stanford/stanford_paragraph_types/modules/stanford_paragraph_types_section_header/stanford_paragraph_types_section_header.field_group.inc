<?php
/**
 * @file
 * stanford_paragraph_types_section_header.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_paragraph_types_section_header_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_section_header|paragraphs_item|p_section_header|default';
  $field_group->group_name = 'group_p_section_header';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_section_header';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Wrapper',
    'weight' => '0',
    'children' => array(
      0 => 'field_p_section_heading',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Wrapper',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-p-section-header field-group-html-element',
        'element' => 'h2',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_p_section_header|paragraphs_item|p_section_header|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_section_header|paragraphs_item|p_section_header|form';
  $field_group->group_name = 'group_section_header';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_section_header';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Section Header',
    'weight' => '0',
    'children' => array(
      0 => 'field_p_section_color',
      1 => 'field_p_section_heading',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-section-header field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_section_header|paragraphs_item|p_section_header|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Section Header');
  t('Wrapper');

  return $field_groups;
}
