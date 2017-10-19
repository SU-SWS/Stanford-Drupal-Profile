<?php
/**
 * @file
 * stanford_bean_types.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_bean_types_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_first_group|bean|stanford_testimonial_block|default';
  $field_group->group_name = 'group_first_group';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_testimonial_block';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_postcard';
  $field_group->data = array(
    'label' => 'first group',
    'weight' => '16',
    'children' => array(
      0 => 'group_s_circle_image_style',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'first group',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_first_group|bean|stanford_testimonial_block|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_postcard_content|bean|stanford_icon_block|default';
  $field_group->group_name = 'group_postcard_content';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_icon_block';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_postcard';
  $field_group->data = array(
    'label' => 'Postcard Content',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_icon_body',
      1 => 'field_s_icon_link',
      2 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Content',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'postcard-content',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_postcard_content|bean|stanford_icon_block|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_postcard_icon|bean|stanford_icon_block|default';
  $field_group->group_name = 'group_postcard_icon';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_icon_block';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_postcard';
  $field_group->data = array(
    'label' => 'Postcard Icon',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_icon_icon',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Icon',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-postcard-icon field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_postcard_icon|bean|stanford_icon_block|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_postcard|bean|stanford_icon_block|default';
  $field_group->group_name = 'group_postcard';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_icon_block';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Postcard',
    'weight' => '0',
    'children' => array(
      0 => 'group_postcard_content',
      1 => 'group_postcard_icon',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'postcard-left',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_postcard|bean|stanford_icon_block|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_postcard|bean|stanford_testimonial_block|default';
  $field_group->group_name = 'group_postcard';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_testimonial_block';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'postcard',
    'weight' => '7',
    'children' => array(
      0 => 'group_first_group',
      1 => 'group_second_group',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'postcard',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'postcard-right',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_postcard|bean|stanford_testimonial_block|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_big_text_style|bean|stanford_big_text_block|default';
  $field_group->group_name = 'group_s_big_text_style';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_big_text_block';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Big Text',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_big_text_block_lead_text',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Big Text',
      'instance_settings' => array(
        'classes' => 'group-s-big-text-style field-group-div big-text',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_big_text_style|bean|stanford_big_text_block|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_circle_image_style|bean|stanford_testimonial_block|default';
  $field_group->group_name = 'group_s_circle_image_style';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_testimonial_block';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_first_group';
  $field_group->data = array(
    'label' => 'Circle Image',
    'weight' => '9',
    'children' => array(
      0 => 'field_s_image_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Circle Image',
      'instance_settings' => array(
        'classes' => 'group-s-circle-image-style field-group-div circle-image',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_circle_image_style|bean|stanford_testimonial_block|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_contact_us_address|bean|stanford_contact|default';
  $field_group->group_name = 'group_s_contact_us_address';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_contact';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Address',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_contact_address_line_1',
      1 => 'field_s_contact_address_line_2',
      2 => 'field_s_contact_city_state_zip',
      3 => 'field_s_contact_address_line_3',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Address',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_contact_us_address|bean|stanford_contact|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_credits_style|bean|stanford_testimonial_block|default';
  $field_group->group_name = 'group_s_credits_style';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_testimonial_block';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_second_group';
  $field_group->data = array(
    'label' => 'Credits',
    'weight' => '19',
    'children' => array(
      0 => 'field_s_testimonial_credits',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Credits',
      'instance_settings' => array(
        'classes' => 'group-s-credits-style field-group-div credits',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_credits_style|bean|stanford_testimonial_block|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_more_link_style|bean|stanford_big_text_block|default';
  $field_group->group_name = 'group_s_more_link_style';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_big_text_block';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'More Link',
    'weight' => '2',
    'children' => array(
      0 => 'field_s_big_text_block_more_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'More Link',
      'instance_settings' => array(
        'classes' => 'group-s-more-link-style field-group-div more-link',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_more_link_style|bean|stanford_big_text_block|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_more_link_style|bean|stanford_testimonial_block|default';
  $field_group->group_name = 'group_s_more_link_style';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_testimonial_block';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_second_group';
  $field_group->data = array(
    'label' => 'More Link',
    'weight' => '20',
    'children' => array(
      0 => 'field_testimonial_more_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'More Link',
      'instance_settings' => array(
        'classes' => 'group-s-more-link-style field-group-div more-link',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_more_link_style|bean|stanford_testimonial_block|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_content|bean|stanford_postcard|default';
  $field_group->group_name = 'group_s_postcard_content';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_postcard';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Content',
    'weight' => '8',
    'children' => array(
      0 => 'field_s_postcard_body',
      1 => 'field_s_postcard_file',
      2 => 'field_s_postcard_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Content',
      'instance_settings' => array(
        'classes' => 'postcard-content',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_content|bean|stanford_postcard|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_content|bean|stanford_postcard|stanford_3_col_header';
  $field_group->group_name = 'group_s_postcard_content';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_postcard';
  $field_group->mode = 'stanford_3_col_header';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Content',
    'weight' => '3',
    'children' => array(
      0 => 'field_s_postcard_body',
      1 => 'field_s_postcard_file',
      2 => 'field_s_postcard_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Content',
      'instance_settings' => array(
        'classes' => 'postcard-content',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_content|bean|stanford_postcard|stanford_3_col_header'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_content|bean|stanford_postcard|stanford_4_col_header';
  $field_group->group_name = 'group_s_postcard_content';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_postcard';
  $field_group->mode = 'stanford_4_col_header';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Content',
    'weight' => '7',
    'children' => array(
      0 => 'field_s_postcard_body',
      1 => 'field_s_postcard_file',
      2 => 'field_s_postcard_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Content',
      'instance_settings' => array(
        'classes' => 'postcard-content',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_content|bean|stanford_postcard|stanford_4_col_header'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_content|bean|stanford_postcard|stanford_6_col_photo_landscape';
  $field_group->group_name = 'group_s_postcard_content';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_postcard';
  $field_group->mode = 'stanford_6_col_photo_landscape';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Content',
    'weight' => '7',
    'children' => array(
      0 => 'field_s_postcard_body',
      1 => 'field_s_postcard_file',
      2 => 'field_s_postcard_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Content',
      'instance_settings' => array(
        'classes' => 'postcard-content',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_content|bean|stanford_postcard|stanford_6_col_photo_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_content|bean|stanford_postcard|stanford_med_profile';
  $field_group->group_name = 'group_s_postcard_content';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_postcard';
  $field_group->mode = 'stanford_med_profile';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Content',
    'weight' => '7',
    'children' => array(
      0 => 'field_s_postcard_body',
      1 => 'field_s_postcard_file',
      2 => 'field_s_postcard_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Content',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_content|bean|stanford_postcard|stanford_med_profile'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_image|bean|stanford_postcard|default';
  $field_group->group_name = 'group_s_postcard_image';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_postcard';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Image',
    'weight' => '6',
    'children' => array(
      0 => 'field_s_image_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Image',
      'instance_settings' => array(
        'classes' => 'postcard',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_image|bean|stanford_postcard|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_image|bean|stanford_postcard|stanford_3_col_header';
  $field_group->group_name = 'group_s_postcard_image';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_postcard';
  $field_group->mode = 'stanford_3_col_header';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Image',
    'weight' => '2',
    'children' => array(
      0 => 'field_s_image_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Image',
      'instance_settings' => array(
        'classes' => 'postcard',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_image|bean|stanford_postcard|stanford_3_col_header'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_image|bean|stanford_postcard|stanford_4_col_header';
  $field_group->group_name = 'group_s_postcard_image';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_postcard';
  $field_group->mode = 'stanford_4_col_header';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Image',
    'weight' => '6',
    'children' => array(
      0 => 'field_s_image_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Image',
      'instance_settings' => array(
        'classes' => 'postcard',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_image|bean|stanford_postcard|stanford_4_col_header'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_image|bean|stanford_postcard|stanford_6_col_photo_landscape';
  $field_group->group_name = 'group_s_postcard_image';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_postcard';
  $field_group->mode = 'stanford_6_col_photo_landscape';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Image',
    'weight' => '6',
    'children' => array(
      0 => 'field_s_image_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Image',
      'instance_settings' => array(
        'classes' => 'postcard',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_image|bean|stanford_postcard|stanford_6_col_photo_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_image|bean|stanford_postcard|stanford_med_profile';
  $field_group->group_name = 'group_s_postcard_image';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_postcard';
  $field_group->mode = 'stanford_med_profile';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Image',
    'weight' => '6',
    'children' => array(
      0 => 'field_s_image_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Image',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_image|bean|stanford_postcard|stanford_med_profile'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard|bean|stanford_postcard|default';
  $field_group->group_name = 'group_s_postcard';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_postcard';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Postcard',
    'weight' => '0',
    'children' => array(
      0 => 'group_s_postcard_content',
      1 => 'group_s_postcard_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard',
      'instance_settings' => array(
        'classes' => 'postcard',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard|bean|stanford_postcard|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard|bean|stanford_postcard|stanford_3_col_header';
  $field_group->group_name = 'group_s_postcard';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_postcard';
  $field_group->mode = 'stanford_3_col_header';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Postcard',
    'weight' => '1',
    'children' => array(
      0 => 'group_s_postcard_image',
      1 => 'group_s_postcard_content',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard',
      'instance_settings' => array(
        'classes' => 'postcard',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard|bean|stanford_postcard|stanford_3_col_header'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard|bean|stanford_postcard|stanford_4_col_header';
  $field_group->group_name = 'group_s_postcard';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_postcard';
  $field_group->mode = 'stanford_4_col_header';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Postcard',
    'weight' => '1',
    'children' => array(
      0 => 'group_s_postcard_image',
      1 => 'group_s_postcard_content',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard',
      'instance_settings' => array(
        'classes' => 'postcard',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard|bean|stanford_postcard|stanford_4_col_header'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard|bean|stanford_postcard|stanford_6_col_photo_landscape';
  $field_group->group_name = 'group_s_postcard';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_postcard';
  $field_group->mode = 'stanford_6_col_photo_landscape';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Postcard',
    'weight' => '1',
    'children' => array(
      0 => 'group_s_postcard_image',
      1 => 'group_s_postcard_content',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard',
      'instance_settings' => array(
        'classes' => 'postcard',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard|bean|stanford_postcard|stanford_6_col_photo_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard|bean|stanford_postcard|stanford_med_profile';
  $field_group->group_name = 'group_s_postcard';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_postcard';
  $field_group->mode = 'stanford_med_profile';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Postcard',
    'weight' => '1',
    'children' => array(
      0 => 'group_s_postcard_image',
      1 => 'group_s_postcard_content',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard|bean|stanford_postcard|stanford_med_profile'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_quote_style|bean|stanford_testimonial_block|default';
  $field_group->group_name = 'group_s_quote_style';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_testimonial_block';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_second_group';
  $field_group->data = array(
    'label' => 'Quote',
    'weight' => '18',
    'children' => array(
      0 => 'field_s_testimonial_quote',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Quote',
      'instance_settings' => array(
        'classes' => 'group-s-quote-style field-group-div quote',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_quote_style|bean|stanford_testimonial_block|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_second_group|bean|stanford_testimonial_block|default';
  $field_group->group_name = 'group_second_group';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_testimonial_block';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_postcard';
  $field_group->data = array(
    'label' => 'second group',
    'weight' => '17',
    'children' => array(
      0 => 'group_s_credits_style',
      1 => 'group_s_more_link_style',
      2 => 'group_s_quote_style',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'second group',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_second_group|bean|stanford_testimonial_block|default'] = $field_group;

  return $export;
}
