<?php
/**
 * @file
 * stanford_person_layouts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_person_layouts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'stanford_people_all_pages';
  $context->description = 'Context for all people pages';
  $context->tag = 'People';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'people/*' => 'people/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-8116868180a8a203a7d1a990228283dc' => array(
          'module' => 'views',
          'delta' => '8116868180a8a203a7d1a990228283dc',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for all people pages');
  t('People');
  $export['stanford_people_all_pages'] = $context;


  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'stanford_people_faculty_pages';
  $context->description = 'Context for all faculty pages';
  $context->tag = 'People';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~people/faculty/directory' => '~people/faculty/directory',
        '~people/faculty/profiles' => '~people/faculty/profiles',
        '~people/faculty/list' => '~people/faculty/list',
        '~people/faculty/cap-list' => '~people/faculty/cap-list',
        '~people/faculty/grid' => '~people/faculty/grid',
        'people/faculty' => 'people/faculty',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-b38da907588eed2d09c10bdb381e5aaf' => array(
          'module' => 'views',
          'delta' => 'b38da907588eed2d09c10bdb381e5aaf',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for all faculty pages');
  t('People');
  $export['stanford_people_faculty_pages'] = $context;


  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'stanford_people_staff_pages';
  $context->description = 'Context for all staff pages';
  $context->tag = 'People';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~people/staff/directory' => '~people/staff/directory',
        '~people/staff/profiles' => '~people/staff/profiles',
        '~people/staff/lists' => '~people/staff/lists',
        '~people/staff/list' => '~people/staff/list',
        '~people/staff/cap-list' => '~people/staff/cap-list',
        '~people/staff/grid' => '~people/staff/grid',
        'people/staff' => 'people/staff',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-stanford_person_staff-page' => array(
          'module' => 'views',
          'delta' => '-exp-stanford_person_staff-page',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for all staff pages');
  t('People');
  $export['stanford_people_staff_pages'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'stanford_people_student_pages';
  $context->description = 'Context for all student pages';
  $context->tag = 'People';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~people/students/directory' => '~people/students/directory',
        '~people/students/profiles' => '~people/students/profiles',
        '~people/students/list' => '~people/students/list',
        '~people/students/cap-list' => '~people/students/cap-list',
        '~people/students/lists' => '~people/students/lists',
        '~people/students/grid' => '~people/students/grid',
        'people/student' => 'people/student',
        'people/student/*' => 'people/student/*',
        'people/students' => 'people/students',
        'people/students/*' => 'people/students/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-442e92af913370af5bffd333a036ceaa' => array(
          'module' => 'views',
          'delta' => '442e92af913370af5bffd333a036ceaa',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for all student pages');
  t('People');
  $export['stanford_people_student_pages'] = $context;

  return $export;
}
