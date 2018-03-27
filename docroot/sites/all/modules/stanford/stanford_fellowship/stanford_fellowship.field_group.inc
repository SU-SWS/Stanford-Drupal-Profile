<?php
/**
 * @file
 * stanford_fellowship.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_fellowship_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_addl_info|node|stanford_fellowship|default';
  $field_group->group_name = 'group_addl_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_fellowship';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Information',
    'weight' => '6',
    'children' => array(
      0 => 'field_s_fellowship_amount_award',
      1 => 'field_s_fellowship_contact_info',
      2 => 'field_s_fellowship_number_award',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Additional Information',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-addl-info field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_addl_info|node|stanford_fellowship|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_application_materials|node|stanford_fellowship|default';
  $field_group->group_name = 'group_application_materials';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_fellowship';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_highlighted';
  $field_group->data = array(
    'label' => 'Application Materials',
    'weight' => '2',
    'children' => array(
      0 => 'field_s_fellowship_applic_links',
      1 => 'field_s_fellowship_applic_mater',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Application Materials',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'well span6 column',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_application_materials|node|stanford_fellowship|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_application_materials|node|stanford_fellowship|form';
  $field_group->group_name = 'group_application_materials';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_fellowship';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Application Materials',
    'weight' => '2',
    'children' => array(
      0 => 'field_s_fellowship_applic_mater',
      1 => 'field_s_fellowship_applic_links',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-application-materials field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_application_materials|node|stanford_fellowship|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_application|node|stanford_fellowship|default';
  $field_group->group_name = 'group_application';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_fellowship';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Application',
    'weight' => '5',
    'children' => array(
      0 => 'field_s_fellowship_applic_proces',
      1 => 'field_s_fellowship_selection',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Application',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-application field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_application|node|stanford_fellowship|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_application|node|stanford_fellowship|form';
  $field_group->group_name = 'group_application';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_fellowship';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Application',
    'weight' => '9',
    'children' => array(
      0 => 'field_s_fellowship_applic_proces',
      1 => 'field_s_fellowship_selection',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-application field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_application|node|stanford_fellowship|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|stanford_fellowship|default';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_fellowship';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '2',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Content',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-content field-group-div postcard',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_content|node|stanford_fellowship|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dates|node|stanford_fellowship|form';
  $field_group->group_name = 'group_dates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_fellowship';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Important Dates',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_fellowship_campus_applic',
      1 => 'field_s_fellowship_deadline_peri',
      2 => 'field_s_fellowship_info_session',
      3 => 'field_s_fellowship_campus_interv',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-dates field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_dates|node|stanford_fellowship|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_eligibility|node|stanford_fellowship|default';
  $field_group->group_name = 'group_eligibility';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_fellowship';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Eligibility',
    'weight' => '4',
    'children' => array(
      0 => 'field_s_fellowship_eligibility',
      1 => 'field_s_fellowship_open_to',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Eligibility',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-eligibility field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_eligibility|node|stanford_fellowship|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_eligibility|node|stanford_fellowship|form';
  $field_group->group_name = 'group_eligibility';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_fellowship';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Eligibility',
    'weight' => '8',
    'children' => array(
      0 => 'field_s_fellowship_eligibility',
      1 => 'field_s_fellowship_open_to',
      2 => 'field_s_fellowship_requirements',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-eligibility field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_eligibility|node|stanford_fellowship|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_highlighted|node|stanford_fellowship|default';
  $field_group->group_name = 'group_highlighted';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_fellowship';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Highlighted',
    'weight' => '0',
    'children' => array(
      0 => 'group_application_materials',
      1 => 'group_important_dates',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Highlighted',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-highlighted field-group-div span12',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_highlighted|node|stanford_fellowship|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_important_dates|node|stanford_fellowship|default';
  $field_group->group_name = 'group_important_dates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_fellowship';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_highlighted';
  $field_group->data = array(
    'label' => 'Important Dates',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_fellowship_campus_applic',
      1 => 'field_s_fellowship_campus_interv',
      2 => 'field_s_fellowship_deadline_peri',
      3 => 'field_s_fellowship_info_session',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Important Dates',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-important-dates field-group-div well span6 column',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_important_dates|node|stanford_fellowship|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_content|node|stanford_fellowship|default';
  $field_group->group_name = 'group_s_postcard_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_fellowship';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_postcard';
  $field_group->data = array(
    'label' => 'Postcard Content',
    'weight' => '2',
    'children' => array(
      0 => 'body',
      1 => 'field_s_fellowship_duration',
      2 => 'field_s_fellowship_external',
      3 => 'field_s_fellowship_location',
      4 => 'field_s_fellowship_organization',
      5 => 'field_s_fellowship_related_links',
      6 => 'field_s_fellowship_requirements',
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
  $export['group_s_postcard_content|node|stanford_fellowship|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard|node|stanford_fellowship|default';
  $field_group->group_name = 'group_s_postcard';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_fellowship';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Postcard',
    'weight' => '43',
    'children' => array(
      0 => 'group_s_postcard_content',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-postcard field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard|node|stanford_fellowship|default'] = $field_group;

  return $export;
}
