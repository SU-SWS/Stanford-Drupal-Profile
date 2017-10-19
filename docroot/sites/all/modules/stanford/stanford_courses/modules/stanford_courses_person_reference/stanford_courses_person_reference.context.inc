<?php
/**
 * @file
 * stanford_courses_person_reference.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_courses_person_reference_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'courses_reference';
  $context->description = 'A list of courses taught by a person.';
  $context->tag = 'Courses';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'stanford_person' => 'stanford_person',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-5c84bdc5ea8289bceed723799d38940f' => array(
          'module' => 'views',
          'delta' => '5c84bdc5ea8289bceed723799d38940f',
          'region' => 'sidebar_second',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('A list of courses taught by a person.');
  t('Courses');
  $export['courses_reference'] = $context;

  return $export;
}
