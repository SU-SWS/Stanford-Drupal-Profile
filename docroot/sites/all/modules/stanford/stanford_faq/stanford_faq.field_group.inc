<?php
/**
 * @file
 * stanford_faq.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_faq_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_faq_advanced|node|faq|form';
  $field_group->group_name = 'group_s_faq_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'faq';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '7',
    'children' => array(
      0 => 'field_detailed_question',
      1 => 'field_s_faq_weight',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Advanced',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-s-faq-advanced field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_s_faq_advanced|node|faq|form'] = $field_group;

  return $export;
}
