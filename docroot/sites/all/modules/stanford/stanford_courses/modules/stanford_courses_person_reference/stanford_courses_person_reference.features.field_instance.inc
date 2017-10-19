<?php
/**
 * @file
 * stanford_courses_person_reference.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function stanford_courses_person_reference_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'field_collection_item-field_s_course_section_info-field_s_course_person'
  $field_instances['field_collection_item-field_s_course_section_info-field_s_course_person'] = array(
    'bundle' => 'field_s_course_section_info',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This field shows the instructor for this course section.  Start typing the person\'s name and select from the auto-complete list that appears. (e.g., Jane Stanford).',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_s_course_person',
    'label' => 'Instructor',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Co Instructor');
  t('Instructor');
  t('This field shows the instructor for this course section.  Start typing the person\'s name and select from the auto-complete list that appears. (e.g., Jane Stanford).');

  return $field_instances;
}
