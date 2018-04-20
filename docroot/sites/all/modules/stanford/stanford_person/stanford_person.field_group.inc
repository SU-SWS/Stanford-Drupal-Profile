<?php
/**
 * @file
 * stanford_person.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_person_field_group_info() {
  $field_groups = array();

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
    'weight' => '6',
    'children' => array(
      0 => 'field_s_person_info_links',
    ),
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
  $field_groups['group_morelink_group|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_about|node|stanford_person|stanford_cap';
  $field_group->group_name = 'group_s_about';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_cap';
  $field_group->parent_name = 'group_s_postcard_col2';
  $field_group->data = array(
    'label' => 'About',
    'weight' => '7',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'About',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-about field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_about|node|stanford_person|stanford_cap'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_contact|node|stanford_person|stanford_cap';
  $field_group->group_name = 'group_s_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_cap';
  $field_group->parent_name = 'group_s_postcard_col2';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '6',
    'children' => array(
      0 => 'field_s_person_email',
      1 => 'field_s_person_office_hours',
      2 => 'field_s_person_office_location',
      3 => 'field_s_person_phone_display',
      4 => 'group_s_personal_link_style',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-contact field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_contact|node|stanford_person|stanford_cap'] = $field_group;

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
  $field_groups['group_s_image_border_style|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_image_border_style|node|stanford_person|stanford_cap';
  $field_group->group_name = 'group_s_image_border_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_cap';
  $field_group->parent_name = 'group_s_postcard_col1';
  $field_group->data = array(
    'label' => 'Image Border Style',
    'weight' => '39',
    'children' => array(
      0 => 'field_s_person_profile_picture',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image Border Style',
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
  $field_groups['group_s_image_border_style|node|stanford_person|stanford_cap'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_interest_style|node|stanford_person|stanford_cap';
  $field_group->group_name = 'group_s_interest_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_cap';
  $field_group->parent_name = 'group_s_research_interests';
  $field_group->data = array(
    'label' => 'Interest Style',
    'weight' => '62',
    'children' => array(
      0 => 'field_s_person_interests',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Interest Style',
      'instance_settings' => array(
        'id' => '',
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
  $field_groups['group_s_interest_style|node|stanford_person|stanford_cap'] = $field_group;

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
    'children' => array(
      0 => 'body',
    ),
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
  $field_groups['group_s_person_about|node|stanford_person|default'] = $field_group;

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
    'children' => array(
      0 => 'body',
    ),
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
  $field_groups['group_s_person_about|node|stanford_person|full'] = $field_group;

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
    'weight' => '6',
    'children' => array(
      0 => 'field_s_person_weight',
      1 => 'field_s_person_profile_link',
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
  $field_groups['group_s_person_advanced|node|stanford_person|form'] = $field_group;

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
      5 => 'title',
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
  $field_groups['group_s_person_basic|node|stanford_person|form'] = $field_group;

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
      0 => 'field_s_person_education',
      1 => 'field_s_person_faculty_title',
      2 => 'field_s_person_file',
      3 => 'body',
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
  $field_groups['group_s_person_bio|node|stanford_person|form'] = $field_group;

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
  $field_groups['group_s_person_contact|node|stanford_person|form'] = $field_group;

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
  $field_groups['group_s_person_faculty|node|stanford_person|form'] = $field_group;

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
  $field_groups['group_s_person_staff|node|stanford_person|form'] = $field_group;

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
  $field_groups['group_s_person_status_style|node|stanford_person|taxonomy'] = $field_group;

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
  $field_groups['group_s_person_student|node|stanford_person|form'] = $field_group;

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
    'weight' => '8',
    'children' => array(
      0 => 'field_s_person_interests',
    ),
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
  $field_groups['group_s_person_style_interests|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_personal_link_style|node|stanford_person|stanford_cap';
  $field_group->group_name = 'group_s_personal_link_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_cap';
  $field_group->parent_name = 'group_s_contact';
  $field_group->data = array(
    'label' => 'Personal info Link Style',
    'weight' => '10',
    'children' => array(
      0 => 'field_s_person_info_links',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Personal info Link Style',
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
  $field_groups['group_s_personal_link_style|node|stanford_person|stanford_cap'] = $field_group;

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
      0 => 'field_s_person_profile_picture',
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
  $field_groups['group_s_postcard_col1|node|stanford_person|default'] = $field_group;

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
  $field_groups['group_s_postcard_col1|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_col1|node|stanford_person|stanford_cap';
  $field_group->group_name = 'group_s_postcard_col1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_cap';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Column 1',
    'weight' => '1',
    'children' => array(
      0 => 'group_s_image_border_style',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Column 1',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-postcard-col1 field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_postcard_col1|node|stanford_person|stanford_cap'] = $field_group;

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
  $field_groups['group_s_postcard_col1|node|stanford_person|stanford_taxonomy'] = $field_group;

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
      0 => 'field_s_person_education',
      1 => 'field_s_person_faculty_title',
      2 => 'field_s_person_faculty_type',
      3 => 'field_s_person_file',
      4 => 'field_s_person_student_type',
      5 => 'title',
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
  $field_groups['group_s_postcard_col2|node|stanford_person|default'] = $field_group;

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
      0 => 'field_s_person_education',
      1 => 'field_s_person_faculty_title',
      2 => 'field_s_person_faculty_type',
      3 => 'field_s_person_file',
      4 => 'title',
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
  $field_groups['group_s_postcard_col2|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_col2|node|stanford_person|stanford_cap';
  $field_group->group_name = 'group_s_postcard_col2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_cap';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Column 2',
    'weight' => '2',
    'children' => array(
      0 => 'field_s_person_education',
      1 => 'field_s_person_faculty_title',
      2 => 'field_s_person_file',
      3 => 'title',
      4 => 'group_s_about',
      5 => 'group_s_contact',
      6 => 'group_s_profile_link_style',
      7 => 'group_s_research_interests',
      8 => 'group_s_status_style',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Column 2',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-postcard-col2 field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_postcard_col2|node|stanford_person|stanford_cap'] = $field_group;

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
  $field_groups['group_s_postcard_col2|node|stanford_person|stanford_taxonomy'] = $field_group;

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
  $field_groups['group_s_postcard_col3|node|stanford_person|stanford_taxonomy'] = $field_group;

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
  $field_groups['group_s_postcard_col3|node|stanford_person|taxonomy'] = $field_group;

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
  $field_groups['group_s_postcard_content|node|stanford_person|taxonomy'] = $field_group;

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
  $field_groups['group_s_postcard_image|node|stanford_person|taxonomy'] = $field_group;

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
  $field_groups['group_s_postcard|node|stanford_person|default'] = $field_group;

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
  $field_groups['group_s_postcard|node|stanford_person|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard|node|stanford_person|stanford_cap';
  $field_group->group_name = 'group_s_postcard';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_cap';
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
        'classes' => 'postcard-right-wrap',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_postcard|node|stanford_person|stanford_cap'] = $field_group;

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
  $field_groups['group_s_postcard|node|stanford_person|stanford_taxonomy'] = $field_group;

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
  $field_groups['group_s_postcard|node|stanford_person|taxonomy'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_profile_link_style|node|stanford_person|stanford_cap';
  $field_group->group_name = 'group_s_profile_link_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_cap';
  $field_group->parent_name = 'group_s_postcard_col2';
  $field_group->data = array(
    'label' => 'Profile Link Style',
    'weight' => '8',
    'children' => array(
      0 => 'field_s_person_profile_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Profile Link Style',
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
  $field_groups['group_s_profile_link_style|node|stanford_person|stanford_cap'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_research_interests|node|stanford_person|stanford_cap';
  $field_group->group_name = 'group_s_research_interests';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_cap';
  $field_group->parent_name = 'group_s_postcard_col2';
  $field_group->data = array(
    'label' => 'Research Interests',
    'weight' => '5',
    'children' => array(
      0 => 'group_s_interest_style',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Research Interests',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-research-interests field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_research_interests|node|stanford_person|stanford_cap'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_status_style|node|stanford_person|stanford_cap';
  $field_group->group_name = 'group_s_status_style';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_person';
  $field_group->mode = 'stanford_cap';
  $field_group->parent_name = 'group_s_postcard_col2';
  $field_group->data = array(
    'label' => 'Status Style',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_person_faculty_type',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Status Style',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'summary',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_s_status_style|node|stanford_person|stanford_cap'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Advanced');
  t('Basic Info');
  t('Bio');
  t('Contact');
  t('Faculty Info');
  t('Faculty Status Style');
  t('Image Border Style');
  t('Interest Style');
  t('Interests Style');
  t('More Link group');
  t('Personal info Link Style');
  t('Postcard');
  t('Postcard Column 1');
  t('Postcard Column 2');
  t('Postcard Column 3');
  t('Postcard Content');
  t('Postcard Image');
  t('Profile Link Style');
  t('Research Interests');
  t('Staff Info');
  t('Status Style');
  t('Student Info');

  return $field_groups;
}
