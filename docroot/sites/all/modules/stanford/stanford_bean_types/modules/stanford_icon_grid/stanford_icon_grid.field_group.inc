<?php
/**
 * @file
 * stanford_icon_grid.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_icon_grid_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_more_link|field_collection_item|field_s_icon_ext_columns|stanford_block';
  $field_group->group_name = 'group_more_link';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_icon_ext_columns';
  $field_group->mode = 'stanford_block';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Read More',
    'weight' => '3',
    'children' => array(
      0 => 'field_s_icon_ext_columns_links',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Read More',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'more-link',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_more_link|field_collection_item|field_s_icon_ext_columns|stanford_block'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_read_more|field_collection_item|field_s_icon_ext_columns|stanford_list';
  $field_group->group_name = 'group_read_more';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_icon_ext_columns';
  $field_group->mode = 'stanford_list';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Read More',
    'weight' => '3',
    'children' => array(
      0 => 'field_s_icon_ext_columns_links',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Read More',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'read-more',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_read_more|field_collection_item|field_s_icon_ext_columns|stanford_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_icon_ext_columns_icon|field_collection_item|field_s_icon_ext_columns|form';
  $field_group->group_name = 'group_s_icon_ext_columns_icon';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_icon_ext_columns';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Icon',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_icon_ext_columns_bg_colo',
      1 => 'field_s_icon_ext_columns_up_icon',
      2 => 'field_s_icon_ext_columns_fa_icon',
      3 => 'field_s_icon_ext_columns_style',
      4 => 'field_s_icon_ext_columns_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-s-icon-ext-columns-icon field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_s_icon_ext_columns_icon|field_collection_item|field_s_icon_ext_columns|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_more_link_style|field_collection_item|field_s_icon_ext_columns|default';
  $field_group->group_name = 'group_s_more_link_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_icon_ext_columns';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'More Link Style',
    'weight' => '3',
    'children' => array(
      0 => 'field_s_icon_ext_columns_links',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'More Link Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'more-link',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_more_link_style|field_collection_item|field_s_icon_ext_columns|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_title_styles|field_collection_item|field_s_icon_ext_columns|default';
  $field_group->group_name = 'group_s_title_styles';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_icon_ext_columns';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Title Styles',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_icon_ext_columns_title',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Title Styles',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'h2',
        'show_label' => '0',
        'label_element' => 'h2',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_s_title_styles|field_collection_item|field_s_icon_ext_columns|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_title_styles|field_collection_item|field_s_icon_ext_columns|stanford_block';
  $field_group->group_name = 'group_title_styles';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_icon_ext_columns';
  $field_group->mode = 'stanford_block';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Title Styles',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_icon_ext_columns_title',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Title Styles',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'h2',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_title_styles|field_collection_item|field_s_icon_ext_columns|stanford_block'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_title_style|field_collection_item|field_s_icon_ext_columns|stanford_list';
  $field_group->group_name = 'group_title_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_icon_ext_columns';
  $field_group->mode = 'stanford_list';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Title Style',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_icon_ext_columns_title',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Title Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'h2',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_title_style|field_collection_item|field_s_icon_ext_columns|stanford_list'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Icon');
  t('More Link Style');
  t('Read More');
  t('Title Style');
  t('Title Styles');

  return $field_groups;
}
