<?php
/**
 * @file
 * stanford_bean_types_call_to_action.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_bean_types_call_to_action_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_cta_image_style|bean|stanford_call_to_action|default';
  $field_group->group_name = 'group_s_cta_image_style';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_call_to_action';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_cta_link';
  $field_group->data = array(
    'label' => 'Image Style',
    'weight' => '6',
    'children' => array(
      0 => 'field_s_cta_icon',
      1 => 'field_s_cta_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-cta-image-style field-group-div cta-image-icon-wrapper',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_cta_image_style|bean|stanford_call_to_action|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_cta_link|bean|stanford_call_to_action|default';
  $field_group->group_name = 'group_s_cta_link';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_call_to_action';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Link group',
    'weight' => '0',
    'children' => array(
      0 => 'group_s_cta_image_style',
      1 => 'group_s_cta_title_style',
    ),
    'format_type' => 'link',
    'format_settings' => array(
      'label' => 'Link group',
      'instance_settings' => array(
        'link_to' => 'field_s_cta_link',
        'custom_url' => '',
        'custom_url_normalize' => 0,
        'target' => 'default',
        'classes' => 'group-s-cta-link field-group-link group-s-cta-style',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_cta_link|bean|stanford_call_to_action|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_cta_title_style|bean|stanford_call_to_action|default';
  $field_group->group_name = 'group_s_cta_title_style';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_call_to_action';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_cta_link';
  $field_group->data = array(
    'label' => 'Title Style',
    'weight' => '7',
    'children' => array(
      0 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Title Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-cta-title-style field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_cta_title_style|bean|stanford_call_to_action|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Image Style');
  t('Link group');
  t('Title Style');

  return $field_groups;
}
