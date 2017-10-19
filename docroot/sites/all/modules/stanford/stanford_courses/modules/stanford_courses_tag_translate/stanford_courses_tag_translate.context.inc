<?php
/**
 * @file
 * stanford_courses_tag_translate.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_courses_tag_translate_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'courses_with_human_tags';
  $context->description = 'All pages in the Courses Tag section';
  $context->tag = 'Courses Human Tags';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'courses/tags*' => 'courses/tags*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ead51cc49a821ad67abecea4bf460afe' => array(
          'module' => 'views',
          'delta' => 'ead51cc49a821ad67abecea4bf460afe',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All pages in the Courses Tag section');
  t('Courses Human Tags');
  $export['courses_with_human_tags'] = $context;

  return $export;
}
