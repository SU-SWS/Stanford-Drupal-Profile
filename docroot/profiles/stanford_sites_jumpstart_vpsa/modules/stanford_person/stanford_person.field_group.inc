<?php
/**
 * @file
 * stanford_person.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_person_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_info_styles|node|stanford_person|default';
  $field_group->group_name = 'group_contact_info_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_postcard_col2';
  $field_group->data = array(
    'label' => 'Contact Info Styles',
    'weight' => '4',
    'children' => array(
      0 => 'field_s_person_email',
      1 => 'field_s_person_info_links',
      2 => 'field_s_person_office_hours',
      3 => 'field_s_person_office_location',
      4 => 'field_s_person_phone_display',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact Info Styles',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'descriptor',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_contact_info_styles|node|stanford_person|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_info_styles|node|stanford_person|full';
  $field_group->group_name = 'group_contact_info_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_s_postcard_col2';
  $field_group->data = array(
    'label' => 'Contact Info Styles',
    'weight' => '40',
    'children' => array(
      0 => 'field_s_person_email',
      1 => 'field_s_person_info_links',
      2 => 'field_s_person_office_hours',
      3 => 'field_s_person_office_location',
      4 => 'field_s_person_phone_display',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact Info Styles',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'descriptor',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_contact_info_styles|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_info_styles|node|stanford_person|stanford_huge_landscape';
  $field_group->group_name = 'group_contact_info_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_huge_landscape';
  $field_group->parent_name = 'group_s_postcard_col2';
  $field_group->data = array(
    'label' => 'Contact Info Styles',
    'weight' => '25',
    'children' => array(
      0 => 'field_s_person_email',
      1 => 'field_s_person_info_links',
      2 => 'field_s_person_office_hours',
      3 => 'field_s_person_office_location',
      4 => 'field_s_person_phone_display',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact Info Styles',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'descriptor',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_contact_info_styles|node|stanford_person|stanford_huge_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_department_school_styles|node|stanford_person|default';
  $field_group->group_name = 'group_department_school_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_postcard_col2';
  $field_group->data = array(
    'label' => 'Department School Styles',
    'weight' => '2',
    'children' => array(
      0 => 'field_s_person_department',
      1 => 'field_s_person_school',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Department School Styles',
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
  $export['group_department_school_styles|node|stanford_person|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_department_school_styles|node|stanford_person|full';
  $field_group->group_name = 'group_department_school_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_s_postcard_col2';
  $field_group->data = array(
    'label' => 'Department School Styles',
    'weight' => '38',
    'children' => array(
      0 => 'field_s_person_department',
      1 => 'field_s_person_school',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Department School Styles',
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
  $export['group_department_school_styles|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_department_school_styles|node|stanford_person|stanford_huge_landscape';
  $field_group->group_name = 'group_department_school_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_huge_landscape';
  $field_group->parent_name = 'group_s_postcard_col2';
  $field_group->data = array(
    'label' => 'Department School Styles',
    'weight' => '23',
    'children' => array(
      0 => 'field_s_person_department',
      1 => 'field_s_person_school',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Department School Styles',
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
  $export['group_department_school_styles|node|stanford_person|stanford_huge_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_facebook_styles|node|stanford_person|full';
  $field_group->group_name = 'group_facebook_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_social_media_styles';
  $field_group->data = array(
    'label' => 'Facebook Styles',
    'weight' => '35',
    'children' => array(
      0 => 'field_s_person_facebook',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Facebook Styles',
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
  $export['group_facebook_styles|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_facebook_styles|node|stanford_person|stanford_huge_landscape';
  $field_group->group_name = 'group_facebook_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_huge_landscape';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Facebook Styles',
    'weight' => '29',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Facebook Styles',
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
  $export['group_facebook_styles|node|stanford_person|stanford_huge_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_flickr_styles|node|stanford_person|full';
  $field_group->group_name = 'group_flickr_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_social_media_styles';
  $field_group->data = array(
    'label' => 'Flickr Styles',
    'weight' => '44',
    'children' => array(
      0 => 'field_s_person_flickr',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Flickr Styles',
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
  $export['group_flickr_styles|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_flickr_styles|node|stanford_person|stanford_huge_landscape';
  $field_group->group_name = 'group_flickr_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_huge_landscape';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Flickr Styles',
    'weight' => '38',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Flickr Styles',
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
  $export['group_flickr_styles|node|stanford_person|stanford_huge_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_googleplus_styles|node|stanford_person|full';
  $field_group->group_name = 'group_googleplus_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_social_media_styles';
  $field_group->data = array(
    'label' => 'GooglePlus Styles',
    'weight' => '37',
    'children' => array(
      0 => 'field_s_person_googleplus',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'GooglePlus Styles',
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
  $export['group_googleplus_styles|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_googleplus_styles|node|stanford_person|stanford_huge_landscape';
  $field_group->group_name = 'group_googleplus_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_huge_landscape';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'GooglePlus Styles',
    'weight' => '31',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'GooglePlus Styles',
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
  $export['group_googleplus_styles|node|stanford_person|stanford_huge_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_image_border_styles|field_collection_item|field_s_image_info|stanford_half_page_profile';
  $field_group->group_name = 'group_image_border_styles';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_half_page_profile';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Styles',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_image_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Styles',
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
  $export['group_image_border_styles|field_collection_item|field_s_image_info|stanford_half_page_profile'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_image_border_styles|field_collection_item|field_s_image_info|stanford_huge_landscape';
  $field_group->group_name = 'group_image_border_styles';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_image_info';
  $field_group->mode = 'stanford_huge_landscape';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Border Styles',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_image_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Styles',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'border-simple-nowidth border-shadow',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_image_border_styles|field_collection_item|field_s_image_info|stanford_huge_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_image_border_style|node|stanford_person|default';
  $field_group->group_name = 'group_image_border_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_postcard_col1';
  $field_group->data = array(
    'label' => 'Image Border Styles',
    'weight' => '41',
    'children' => array(
      0 => 'field_s_person_profile_picture',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Styles',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'border-simple-nowidth border-shadow',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_image_border_style|node|stanford_person|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_image_credits_style|node|stanford_person|stanford_huge_landscape';
  $field_group->group_name = 'group_image_credits_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_huge_landscape';
  $field_group->parent_name = 'group_s_postcard_col2';
  $field_group->data = array(
    'label' => 'Image Credits Style',
    'weight' => '27',
    'children' => array(
      0 => 'field_s_person_picture_credits',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Credits Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'credits',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_image_credits_style|node|stanford_person|stanford_huge_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_instagram_styles|node|stanford_person|full';
  $field_group->group_name = 'group_instagram_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_social_media_styles';
  $field_group->data = array(
    'label' => 'Instagram Styles',
    'weight' => '39',
    'children' => array(
      0 => 'field_s_person_instagram',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Instagram Styles',
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
  $export['group_instagram_styles|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_instagram_styles|node|stanford_person|stanford_huge_landscape';
  $field_group->group_name = 'group_instagram_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_huge_landscape';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Instagram Styles',
    'weight' => '33',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Instagram Styles',
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
  $export['group_instagram_styles|node|stanford_person|stanford_huge_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_linkedin_styles|node|stanford_person|full';
  $field_group->group_name = 'group_linkedin_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_social_media_styles';
  $field_group->data = array(
    'label' => 'LinkedIn Styles',
    'weight' => '38',
    'children' => array(
      0 => 'field_s_person_linkedin',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'LinkedIn Styles',
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
  $export['group_linkedin_styles|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_linkedin_styles|node|stanford_person|stanford_huge_landscape';
  $field_group->group_name = 'group_linkedin_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_huge_landscape';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'LinkedIn Styles',
    'weight' => '32',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'LinkedIn Styles',
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
  $export['group_linkedin_styles|node|stanford_person|stanford_huge_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_morelink_group|node|stanford_person|full';
  $field_group->group_name = 'group_morelink_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'More Link group',
    'weight' => '2',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'More Link group',
      'instance_settings' => array(
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
  $export['group_morelink_group|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_picture_credits_style|node|stanford_person|default';
  $field_group->group_name = 'group_picture_credits_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_postcard_col2';
  $field_group->data = array(
    'label' => 'Image Credits Style',
    'weight' => '6',
    'children' => array(
      0 => 'field_s_person_picture_credits',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Credits Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'credits',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_picture_credits_style|node|stanford_person|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pinterest_styles|node|stanford_person|full';
  $field_group->group_name = 'group_pinterest_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_social_media_styles';
  $field_group->data = array(
    'label' => 'Pinterest Styles',
    'weight' => '43',
    'children' => array(
      0 => 'field_s_person_pinterest',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Pinterest Styles',
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
  $export['group_pinterest_styles|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pinterest_styles|node|stanford_person|stanford_huge_landscape';
  $field_group->group_name = 'group_pinterest_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_huge_landscape';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pinterest Styles',
    'weight' => '37',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Pinterest Styles',
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
  $export['group_pinterest_styles|node|stanford_person|stanford_huge_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|node|stanford_person|full';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_s_postcard_col1';
  $field_group->data = array(
    'label' => 'Image Border Style',
    'weight' => '29',
    'children' => array(
      0 => 'field_s_person_profile_picture',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style',
      'instance_settings' => array(
        'classes' => 'border-simple-nowidth border-shadow',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_image_border_style|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|node|stanford_person|stanford_huge_landscape';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_huge_landscape';
  $field_group->parent_name = 'group_s_postcard_col1';
  $field_group->data = array(
    'label' => 'Image Border Style',
    'weight' => '50',
    'children' => array(
      0 => 'field_s_person_profile_picture',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style',
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
  $export['group_s_image_border_style|node|stanford_person|stanford_huge_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_person_about|node|stanford_person|default';
  $field_group->group_name = 'group_s_person_about';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'About',
    'weight' => '1',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'About',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_person_about|node|stanford_person|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_person_about|node|stanford_person|full';
  $field_group->group_name = 'group_s_person_about';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'About',
    'weight' => '1',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'About',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_person_about|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_person_advanced|node|stanford_person|form';
  $field_group->group_name = 'group_s_person_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '8',
    'children' => array(
      0 => 'field_s_person_weight',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Advanced',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_s_person_advanced|node|stanford_person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_person_basic|node|stanford_person|form';
  $field_group->group_name = 'group_s_person_basic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_person_affiliation',
      1 => 'field_s_person_first_name',
      2 => 'field_s_person_last_name',
      3 => 'field_s_person_middle_name',
      4 => 'field_s_person_profile_picture',
      5 => 'field_s_person_view_profile',
      6 => 'field_s_person_picture_credits',
      7 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Basic Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_person_basic|node|stanford_person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_person_bio|node|stanford_person|form';
  $field_group->group_name = 'group_s_person_bio';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bio',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_s_person_education',
      2 => 'field_s_person_faculty_title',
      3 => 'field_s_person_file',
      4 => 'field_s_person_title',
      5 => 'field_s_person_department',
      6 => 'field_s_person_school',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Bio',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_s_person_bio|node|stanford_person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_person_contact|node|stanford_person|form';
  $field_group->group_name = 'group_s_person_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '2',
    'children' => array(
      0 => 'field_s_person_email',
      1 => 'field_s_person_fax_display',
      2 => 'field_s_person_info_links',
      3 => 'field_s_person_mail_address_dspl',
      4 => 'field_s_person_mail_code',
      5 => 'field_s_person_office_hours',
      6 => 'field_s_person_office_location',
      7 => 'field_s_person_phone_display',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_s_person_contact|node|stanford_person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_person_faculty|node|stanford_person|form';
  $field_group->group_name = 'group_s_person_faculty';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Faculty Info',
    'weight' => '3',
    'children' => array(
      0 => 'field_s_person_faculty_type',
      1 => 'field_s_person_interests',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Faculty Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_s_person_faculty|node|stanford_person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_person_social_media|node|stanford_person|form';
  $field_group->group_name = 'group_s_person_social_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social Media',
    'weight' => '6',
    'children' => array(
      0 => 'field_s_person_facebook',
      1 => 'field_s_person_twitter',
      2 => 'field_s_person_googleplus',
      3 => 'field_s_person_linkedin',
      4 => 'field_s_person_instagram',
      5 => 'field_s_person_youtube',
      6 => 'field_s_person_vimeo',
      7 => 'field_s_person_tumblr',
      8 => 'field_s_person_pinterest',
      9 => 'field_s_person_flickr',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Social Media',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-s-person-social-media field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_s_person_social_media|node|stanford_person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_person_staff|node|stanford_person|form';
  $field_group->group_name = 'group_s_person_staff';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Staff Info',
    'weight' => '5',
    'children' => array(
      0 => 'field_s_person_staff_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Staff Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_s_person_staff|node|stanford_person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_person_status_style|node|stanford_person|taxonomy';
  $field_group->group_name = 'group_s_person_status_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'taxonomy';
  $field_group->parent_name = 'group_s_postcard_content';
  $field_group->data = array(
    'label' => 'Faculty Status Style',
    'weight' => '11',
    'children' => array(
      0 => 'field_s_person_faculty_type',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Faculty Status Style',
      'instance_settings' => array(
        'classes' => 'normal',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_person_status_style|node|stanford_person|taxonomy'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_person_student|node|stanford_person|form';
  $field_group->group_name = 'group_s_person_student';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Student Info',
    'weight' => '4',
    'children' => array(
      0 => 'field_s_person_cohort',
      1 => 'field_s_person_dissertatn_title',
      2 => 'field_s_person_graduation_year',
      3 => 'field_s_person_student_type',
      4 => 'field_s_person_study',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Student Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_s_person_student|node|stanford_person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_person_style_interests|node|stanford_person|full';
  $field_group->group_name = 'group_s_person_style_interests';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Interests Style',
    'weight' => '3',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Interests Style',
      'instance_settings' => array(
        'classes' => 'descriptor descriptor-btn',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_person_style_interests|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_col1|node|stanford_person|default';
  $field_group->group_name = 'group_s_postcard_col1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Column 1',
    'weight' => '28',
    'children' => array(
      0 => 'group_image_border_style',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Column 1',
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
  $export['group_s_postcard_col1|node|stanford_person|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_col1|node|stanford_person|full';
  $field_group->group_name = 'group_s_postcard_col1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Column 1',
    'weight' => '28',
    'children' => array(
      0 => 'group_s_image_border_style',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Column 1',
      'instance_settings' => array(
        'classes' => 'postcard-image',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_col1|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_col1|node|stanford_person|stanford_huge_landscape';
  $field_group->group_name = 'group_s_postcard_col1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_huge_landscape';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Column 1',
    'weight' => '49',
    'children' => array(
      0 => 'group_s_image_border_style',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Column 1',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'postcard-image',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_col1|node|stanford_person|stanford_huge_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_col1|node|stanford_person|stanford_taxonomy';
  $field_group->group_name = 'group_s_postcard_col1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_taxonomy';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Column 1',
    'weight' => '9',
    'children' => array(
      0 => 'field_s_person_education',
      1 => 'field_s_person_profile_picture',
      2 => 'group_s_postcard',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Column 1',
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
  $export['group_s_postcard_col1|node|stanford_person|stanford_taxonomy'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_col2|node|stanford_person|default';
  $field_group->group_name = 'group_s_postcard_col2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Column 2',
    'weight' => '29',
    'children' => array(
      0 => 'field_s_person_title',
      1 => 'body',
      2 => 'title',
      3 => 'group_picture_credits_style',
      4 => 'group_contact_info_styles',
      5 => 'group_department_school_styles',
      6 => 'group_social_media_styles',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Column 2',
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
  $export['group_s_postcard_col2|node|stanford_person|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_col2|node|stanford_person|full';
  $field_group->group_name = 'group_s_postcard_col2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Column 2',
    'weight' => '29',
    'children' => array(
      0 => 'body',
      1 => 'field_s_person_title',
      2 => 'title',
      3 => 'group_contact_info_styles',
      4 => 'group_social_media_styles',
      5 => 'group_department_school_styles',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Column 2',
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
  $export['group_s_postcard_col2|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_col2|node|stanford_person|stanford_huge_landscape';
  $field_group->group_name = 'group_s_postcard_col2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_huge_landscape';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Column 2',
    'weight' => '50',
    'children' => array(
      0 => 'field_s_person_title',
      1 => 'body',
      2 => 'title',
      3 => 'group_image_credits_style',
      4 => 'group_contact_info_styles',
      5 => 'group_department_school_styles',
      6 => 'group_social_media_styles',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Column 2',
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
  $export['group_s_postcard_col2|node|stanford_person|stanford_huge_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_col2|node|stanford_person|stanford_taxonomy';
  $field_group->group_name = 'group_s_postcard_col2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_taxonomy';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Column 2',
    'weight' => '10',
    'children' => array(
      0 => 'body',
      1 => 'field_s_person_faculty_title',
      2 => 'field_s_person_faculty_type',
      3 => 'field_s_person_office_hours',
      4 => 'field_s_person_phone_display',
      5 => 'field_s_person_student_type',
      6 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Column 2',
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
  $export['group_s_postcard_col2|node|stanford_person|stanford_taxonomy'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_col3|node|stanford_person|stanford_taxonomy';
  $field_group->group_name = 'group_s_postcard_col3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_taxonomy';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Column 3',
    'weight' => '11',
    'children' => array(
      0 => 'field_s_person_interests',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_s_postcard_col3|node|stanford_person|stanford_taxonomy'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_col3|node|stanford_person|taxonomy';
  $field_group->group_name = 'group_s_postcard_col3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'taxonomy';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Column 3',
    'weight' => '2',
    'children' => array(
      0 => 'field_s_person_interests',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Column 3',
      'instance_settings' => array(
        'classes' => 'descriptor descriptor-btn postcard-col3',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_col3|node|stanford_person|taxonomy'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_content|node|stanford_person|taxonomy';
  $field_group->group_name = 'group_s_postcard_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'taxonomy';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Content',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_person_email',
      1 => 'field_s_person_office_hours',
      2 => 'field_s_person_office_location',
      3 => 'field_s_person_phone_display',
      4 => 'field_s_person_student_type',
      5 => 'title',
      6 => 'group_s_person_status_style',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Content',
      'instance_settings' => array(
        'classes' => 'postcard-col2',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_content|node|stanford_person|taxonomy'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_image|node|stanford_person|taxonomy';
  $field_group->group_name = 'group_s_postcard_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'taxonomy';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Image',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_person_profile_picture',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Image',
      'instance_settings' => array(
        'classes' => 'postcard-col1',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_image|node|stanford_person|taxonomy'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard|node|stanford_person|default';
  $field_group->group_name = 'group_s_postcard';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Postcard',
    'weight' => '0',
    'children' => array(
      0 => 'group_s_postcard_col1',
      1 => 'group_s_postcard_col2',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard',
      'instance_settings' => array(
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
  $export['group_s_postcard|node|stanford_person|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard|node|stanford_person|full';
  $field_group->group_name = 'group_s_postcard';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Postcard',
    'weight' => '0',
    'children' => array(
      0 => 'group_s_postcard_col1',
      1 => 'group_s_postcard_col2',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard',
      'instance_settings' => array(
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
  $export['group_s_postcard|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard|node|stanford_person|stanford_huge_landscape';
  $field_group->group_name = 'group_s_postcard';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_huge_landscape';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Postcard',
    'weight' => '0',
    'children' => array(
      0 => 'group_s_postcard_col1',
      1 => 'group_s_postcard_col2',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard',
      'instance_settings' => array(
        'id' => '',
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
  $export['group_s_postcard|node|stanford_person|stanford_huge_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard|node|stanford_person|stanford_taxonomy';
  $field_group->group_name = 'group_s_postcard';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_taxonomy';
  $field_group->parent_name = 'group_s_postcard_col1';
  $field_group->data = array(
    'label' => 'Postcard',
    'weight' => '0',
    'children' => array(
      0 => 'group_s_postcard_col1',
      1 => 'group_s_postcard_col2',
      2 => 'group_s_postcard_col3',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard',
      'instance_settings' => array(
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
  $export['group_s_postcard|node|stanford_person|stanford_taxonomy'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard|node|stanford_person|taxonomy';
  $field_group->group_name = 'group_s_postcard';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'taxonomy';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Postcard',
    'weight' => '0',
    'children' => array(
      0 => 'group_s_postcard_col3',
      1 => 'group_s_postcard_content',
      2 => 'group_s_postcard_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard',
      'instance_settings' => array(
        'classes' => 'view-stanford-person postcard-left',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard|node|stanford_person|taxonomy'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social_media_styles|node|stanford_person|default';
  $field_group->group_name = 'group_social_media_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_postcard_col2';
  $field_group->data = array(
    'label' => 'Social Media Styles',
    'weight' => '3',
    'children' => array(
      0 => 'field_s_person_facebook',
      1 => 'field_s_person_flickr',
      2 => 'field_s_person_googleplus',
      3 => 'field_s_person_instagram',
      4 => 'field_s_person_linkedin',
      5 => 'field_s_person_pinterest',
      6 => 'field_s_person_tumblr',
      7 => 'field_s_person_twitter',
      8 => 'field_s_person_vimeo',
      9 => 'field_s_person_youtube',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Social Media Styles',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'social-links',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_social_media_styles|node|stanford_person|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social_media_styles|node|stanford_person|full';
  $field_group->group_name = 'group_social_media_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_s_postcard_col2';
  $field_group->data = array(
    'label' => 'Social Media Styles',
    'weight' => '39',
    'children' => array(
      0 => 'group_facebook_styles',
      1 => 'group_twitter_styles',
      2 => 'group_googleplus_styles',
      3 => 'group_linkedin_styles',
      4 => 'group_instagram_styles',
      5 => 'group_youtube_styles',
      6 => 'group_vimeo_styles',
      7 => 'group_tumblr_styles',
      8 => 'group_pinterest_styles',
      9 => 'group_flickr_styles',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Social Media Styles',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'social-links',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_social_media_styles|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social_media_styles|node|stanford_person|stanford_huge_landscape';
  $field_group->group_name = 'group_social_media_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_huge_landscape';
  $field_group->parent_name = 'group_s_postcard_col2';
  $field_group->data = array(
    'label' => 'Social Media Styles',
    'weight' => '24',
    'children' => array(
      0 => 'field_s_person_facebook',
      1 => 'field_s_person_flickr',
      2 => 'field_s_person_googleplus',
      3 => 'field_s_person_instagram',
      4 => 'field_s_person_linkedin',
      5 => 'field_s_person_pinterest',
      6 => 'field_s_person_tumblr',
      7 => 'field_s_person_twitter',
      8 => 'field_s_person_vimeo',
      9 => 'field_s_person_youtube',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Social Media Styles',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'social-links',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_social_media_styles|node|stanford_person|stanford_huge_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tumblr_styles|node|stanford_person|full';
  $field_group->group_name = 'group_tumblr_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_social_media_styles';
  $field_group->data = array(
    'label' => 'Tumblr Styles',
    'weight' => '42',
    'children' => array(
      0 => 'field_s_person_tumblr',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Tumblr Styles',
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
  $export['group_tumblr_styles|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tumblr_styles|node|stanford_person|stanford_huge_landscape';
  $field_group->group_name = 'group_tumblr_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_huge_landscape';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tumblr Styles',
    'weight' => '36',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Tumblr Styles',
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
  $export['group_tumblr_styles|node|stanford_person|stanford_huge_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_twitter_styles|node|stanford_person|full';
  $field_group->group_name = 'group_twitter_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_social_media_styles';
  $field_group->data = array(
    'label' => 'Twitter Styles',
    'weight' => '36',
    'children' => array(
      0 => 'field_s_person_twitter',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Twitter Styles',
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
  $export['group_twitter_styles|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_twitter_styles|node|stanford_person|stanford_huge_landscape';
  $field_group->group_name = 'group_twitter_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_huge_landscape';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Twitter Styles',
    'weight' => '30',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Twitter Styles',
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
  $export['group_twitter_styles|node|stanford_person|stanford_huge_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vimeo_styles|node|stanford_person|full';
  $field_group->group_name = 'group_vimeo_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_social_media_styles';
  $field_group->data = array(
    'label' => 'Vimeo Styles',
    'weight' => '41',
    'children' => array(
      0 => 'field_s_person_vimeo',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Vimeo Styles',
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
  $export['group_vimeo_styles|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vimeo_styles|node|stanford_person|stanford_huge_landscape';
  $field_group->group_name = 'group_vimeo_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_huge_landscape';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Vimeo Styles',
    'weight' => '35',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Vimeo Styles',
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
  $export['group_vimeo_styles|node|stanford_person|stanford_huge_landscape'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_youtube_styles|node|stanford_person|full';
  $field_group->group_name = 'group_youtube_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_social_media_styles';
  $field_group->data = array(
    'label' => 'YouTube Styles',
    'weight' => '40',
    'children' => array(
      0 => 'field_s_person_youtube',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'YouTube Styles',
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
  $export['group_youtube_styles|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_youtube_styles|node|stanford_person|stanford_huge_landscape';
  $field_group->group_name = 'group_youtube_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_huge_landscape';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'YouTube Styles',
    'weight' => '34',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'YouTube Styles',
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
  $export['group_youtube_styles|node|stanford_person|stanford_huge_landscape'] = $field_group;

  return $export;
}
