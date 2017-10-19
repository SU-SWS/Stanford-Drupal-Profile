<?php
/**
 * @file
 * stanford_courses_tag_translate.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function stanford_courses_tag_translate_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-stanford_course-field_s_course_tag_human'
  $field_instances['node-stanford_course-field_s_course_tag_human'] = array(
    'bundle' => 'stanford_course',
    'deleted' => 0,
    'description' => 'The human translated text version of the tags that come from explore courses',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_course_tag_human',
    'label' => 'Course Tags Human',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Course Tags Human');
  t('The human translated text version of the tags that come from explore courses');

  return $field_instances;
}
