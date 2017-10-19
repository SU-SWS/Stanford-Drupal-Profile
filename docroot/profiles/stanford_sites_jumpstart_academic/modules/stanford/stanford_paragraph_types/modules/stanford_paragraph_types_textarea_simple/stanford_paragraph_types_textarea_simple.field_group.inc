<?php
/**
 * @file
 * stanford_paragraph_types_textarea_simple.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_paragraph_types_textarea_simple_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_p_ws_style|paragraphs_item|p_wysiwyg_simple|default';
  $field_group->group_name = 'group_p_ws_style';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'p_wysiwyg_simple';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'WYSIWYG Simple Style',
    'weight' => '0',
    'children' => array(
      0 => 'field_p_ws_body',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'WYSIWYG Simple Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-p-ws-style field-group-div p_ws_container',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_p_ws_style|paragraphs_item|p_wysiwyg_simple|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('WYSIWYG Simple Style');

  return $field_groups;
}
