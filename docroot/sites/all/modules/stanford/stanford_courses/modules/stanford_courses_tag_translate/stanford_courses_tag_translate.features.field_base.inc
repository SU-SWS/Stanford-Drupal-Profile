<?php
/**
 * @file
 * stanford_courses_tag_translate.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function stanford_courses_tag_translate_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_s_course_tag_human'
  $field_bases['field_s_course_tag_human'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_tag_human',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'course_tags_human',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
