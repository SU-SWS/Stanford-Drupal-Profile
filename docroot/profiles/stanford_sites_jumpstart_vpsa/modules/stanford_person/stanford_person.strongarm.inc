<?php
/**
 * @file
 * stanford_person.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function stanford_person_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_stanford_person';
  $strongarm->value = 'edit-ds-extras';
  $export['additional_settings__active_tab_stanford_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_stanford_person';
  $strongarm->value = '[node:field-s-person-first-name] [node:field-s-person-last-name]';
  $export['ant_pattern_stanford_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_stanford_person';
  $strongarm->value = 0;
  $export['ant_php_stanford_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_stanford_person';
  $strongarm->value = '2';
  $export['ant_stanford_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_stanford_person';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_stanford_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_stanford_person';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_stanford_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_stanford_person';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_stanford_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_region_blocks';
  $strongarm->value = array(
    's_news_image' => array(
      'title' => 'News Image',
      'info' => 'node_stanford_news_item_full',
    ),
    'office_hours' => array(
      'title' => 'Office Hours',
      'info' => 'node_stanford_person_full',
    ),
    'contact' => array(
      'title' => 'Contact',
      'info' => 'node_stanford_person_full',
    ),
    'research_interests' => array(
      'title' => 'Research Interests',
      'info' => 'node_stanford_person_full',
    ),
    'full_width_bleed' => array(
      'title' => 'Full Width Bleed',
      'info' => 'node_stanford_person_stanford_huge_landscape',
    ),
  );
  $export['ds_extras_region_blocks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_region_to_block';
  $strongarm->value = 1;
  $export['ds_extras_region_to_block'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_switch_view_mode';
  $strongarm->value = 1;
  $export['ds_extras_switch_view_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_view_modes_stanford_person';
  $strongarm->value = array(
    0 => 'default',
    1 => 'full',
    2 => 'stanford_huge_landscape',
  );
  $export['ds_extras_view_modes_stanford_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__stanford_person';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_8_col_banner' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_taxonomy' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_medium_icon' => array(
        'custom_settings' => FALSE,
      ),
      '300_flexwidth' => array(
        'custom_settings' => FALSE,
      ),
      'taxonomy' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_half_page_profile' => array(
        'custom_settings' => FALSE,
      ),
      'stanford_huge_landscape' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '12',
        ),
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '9',
        ),
        'redirect' => array(
          'weight' => '10',
        ),
        'xmlsitemap' => array(
          'weight' => '11',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__stanford_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_stanford_person';
  $strongarm->value = array();
  $export['menu_options_stanford_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_stanford_person';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_stanford_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_stanford_person_default';
  $strongarm->value = array(
    'title' => array(
      'region' => 'main',
      'weight' => '0',
      'has_required' => FALSE,
      'title' => 'Display Name',
      'hidden' => 0,
    ),
    'additional_settings' => array(
      'region' => 'main',
      'weight' => '41',
      'has_required' => FALSE,
      'title' => 'Vertical tabs',
      'hidden' => 0,
    ),
    'actions' => array(
      'region' => 'main',
      'weight' => '42',
      'has_required' => FALSE,
      'title' => 'Save',
      'hidden' => 0,
    ),
    'body' => array(
      'region' => 'main',
      'weight' => '10',
      'has_required' => FALSE,
      'title' => 'Profile / Bio',
      'hidden' => 0,
    ),
    'field_s_person_affiliation' => array(
      'region' => 'main',
      'weight' => '5',
      'has_required' => FALSE,
      'title' => 'Affiliation',
      'hidden' => 1,
    ),
    'field_s_person_cohort' => array(
      'region' => 'main',
      'weight' => '27',
      'has_required' => FALSE,
      'title' => 'Cohort',
      'hidden' => 1,
    ),
    'field_s_person_dissertatn_title' => array(
      'region' => 'main',
      'weight' => '29',
      'has_required' => FALSE,
      'title' => 'Dissertation Title',
      'hidden' => 1,
    ),
    'field_s_person_education' => array(
      'region' => 'main',
      'weight' => '16',
      'has_required' => FALSE,
      'title' => 'Degrees / Education',
      'hidden' => 1,
    ),
    'field_s_person_email' => array(
      'region' => 'main',
      'weight' => '33',
      'has_required' => FALSE,
      'title' => 'Email',
      'hidden' => 0,
    ),
    'field_s_person_faculty_title' => array(
      'region' => 'main',
      'weight' => '12',
      'has_required' => FALSE,
      'title' => 'Title and Department',
      'hidden' => 1,
    ),
    'field_s_person_faculty_type' => array(
      'region' => 'main',
      'weight' => '31',
      'has_required' => FALSE,
      'title' => 'Faculty Status',
      'hidden' => 1,
    ),
    'field_s_person_fax_display' => array(
      'region' => 'main',
      'weight' => '35',
      'has_required' => FALSE,
      'title' => 'Fax',
      'hidden' => 1,
    ),
    'field_s_person_file' => array(
      'region' => 'main',
      'weight' => '19',
      'has_required' => FALSE,
      'title' => 'File',
      'hidden' => 1,
    ),
    'field_s_person_first_name' => array(
      'region' => 'main',
      'weight' => '1',
      'has_required' => TRUE,
      'title' => 'First name',
    ),
    'field_s_person_graduation_year' => array(
      'region' => 'main',
      'weight' => '30',
      'has_required' => FALSE,
      'title' => 'Graduation Year',
      'hidden' => 1,
    ),
    'field_s_person_info_links' => array(
      'region' => 'main',
      'weight' => '40',
      'has_required' => FALSE,
      'title' => 'Website',
      'hidden' => 0,
    ),
    'field_s_person_interests' => array(
      'region' => 'main',
      'weight' => '32',
      'has_required' => FALSE,
      'title' => 'Fields of Interest',
      'hidden' => 1,
    ),
    'field_s_person_last_name' => array(
      'region' => 'main',
      'weight' => '3',
      'has_required' => TRUE,
      'title' => 'Last Name',
    ),
    'field_s_person_mail_address_dspl' => array(
      'region' => 'main',
      'weight' => '38',
      'has_required' => FALSE,
      'title' => 'Mailing Address',
      'hidden' => 1,
    ),
    'field_s_person_mail_code' => array(
      'region' => 'main',
      'weight' => '39',
      'has_required' => FALSE,
      'title' => 'Mail Code',
      'hidden' => 1,
    ),
    'field_s_person_middle_name' => array(
      'region' => 'main',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => 'Middle name',
      'hidden' => 0,
    ),
    'field_s_person_office_hours' => array(
      'region' => 'main',
      'weight' => '37',
      'has_required' => FALSE,
      'title' => 'Office Hours',
      'hidden' => 0,
    ),
    'field_s_person_office_location' => array(
      'region' => 'main',
      'weight' => '36',
      'has_required' => FALSE,
      'title' => 'Office',
      'hidden' => 0,
    ),
    'field_s_person_phone_display' => array(
      'region' => 'main',
      'weight' => '34',
      'has_required' => FALSE,
      'title' => 'Phone',
      'hidden' => 0,
    ),
    'field_s_person_profile_picture' => array(
      'region' => 'main',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => 'Profile Picture',
      'hidden' => 0,
    ),
    'field_s_person_staff_type' => array(
      'region' => 'main',
      'weight' => '9',
      'has_required' => FALSE,
      'title' => 'Staff Type',
      'hidden' => 1,
    ),
    'field_s_person_student_type' => array(
      'region' => 'main',
      'weight' => '26',
      'has_required' => FALSE,
      'title' => 'Student Type',
      'hidden' => 1,
    ),
    'field_s_person_study' => array(
      'region' => 'main',
      'weight' => '28',
      'has_required' => FALSE,
      'title' => 'Field of Study',
      'hidden' => 1,
    ),
    'field_s_person_weight' => array(
      'region' => 'main',
      'weight' => '8',
      'has_required' => FALSE,
      'title' => 'Sorting Weight',
      'hidden' => 1,
    ),
    'field_s_person_facebook' => array(
      'region' => 'main',
      'weight' => '7',
      'has_required' => FALSE,
      'title' => 'Facebook',
      'hidden' => 0,
    ),
    'field_s_person_twitter' => array(
      'region' => 'main',
      'weight' => '13',
      'has_required' => FALSE,
      'title' => 'Twitter',
      'hidden' => 0,
    ),
    'field_s_person_googleplus' => array(
      'region' => 'main',
      'weight' => '14',
      'has_required' => FALSE,
      'title' => 'GooglePlus',
      'hidden' => 0,
    ),
    'field_s_person_linkedin' => array(
      'region' => 'main',
      'weight' => '17',
      'has_required' => FALSE,
      'title' => 'LinkedIn',
      'hidden' => 0,
    ),
    'field_s_person_instagram' => array(
      'region' => 'main',
      'weight' => '20',
      'has_required' => FALSE,
      'title' => 'Instagram',
      'hidden' => 0,
    ),
    'field_s_person_youtube' => array(
      'region' => 'main',
      'weight' => '21',
      'has_required' => FALSE,
      'title' => 'YouTube',
      'hidden' => 0,
    ),
    'field_s_person_vimeo' => array(
      'region' => 'main',
      'weight' => '22',
      'has_required' => FALSE,
      'title' => 'Vimeo',
      'hidden' => 0,
    ),
    'field_s_person_tumblr' => array(
      'region' => 'main',
      'weight' => '23',
      'has_required' => FALSE,
      'title' => 'Tumblr',
      'hidden' => 0,
    ),
    'field_s_person_pinterest' => array(
      'region' => 'main',
      'weight' => '24',
      'has_required' => FALSE,
      'title' => 'Pinterest',
      'hidden' => 0,
    ),
    'field_s_person_flickr' => array(
      'region' => 'main',
      'weight' => '25',
      'has_required' => FALSE,
      'title' => 'Flickr',
      'hidden' => 0,
    ),
    'field_s_person_title' => array(
      'region' => 'main',
      'weight' => '11',
      'has_required' => FALSE,
      'title' => 'Job Title',
      'hidden' => 0,
    ),
    'field_s_person_department' => array(
      'region' => 'main',
      'weight' => '15',
      'has_required' => FALSE,
      'title' => 'Office/Department',
      'hidden' => 0,
    ),
    'field_s_person_school' => array(
      'region' => 'main',
      'weight' => '18',
      'has_required' => FALSE,
      'title' => 'Unit/School',
      'hidden' => 1,
    ),
    'field_s_person_view_profile' => array(
      'region' => 'main',
      'weight' => '6',
      'has_required' => FALSE,
      'title' => 'View profile',
      'hidden' => 0,
    ),
  );
  $export['nodeformscols_field_placements_stanford_person_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_stanford_person';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_stanford_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_stanford_person';
  $strongarm->value = '1';
  $export['node_preview_stanford_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_stanford_person';
  $strongarm->value = 0;
  $export['node_submitted_stanford_person'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_stanford_person_pattern';
  $strongarm->value = 'people/[node:title]';
  $export['pathauto_node_stanford_person_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_stanford_faculty_type_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_stanford_faculty_type_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_stanford_field_of_study_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_stanford_field_of_study_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_stanford_interests_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_stanford_interests_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_stanford_student_type_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_stanford_student_type_pattern'] = $strongarm;

  return $export;
}
