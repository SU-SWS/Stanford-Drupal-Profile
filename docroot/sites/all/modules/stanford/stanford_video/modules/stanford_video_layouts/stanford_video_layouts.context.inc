<?php
/**
 * @file
 * stanford_video_layouts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_video_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'stanford_videos_grid';
  $context->description = '';
  $context->tag = 'Stanford Video';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'videos/recent-videos/grid' => 'videos/recent-videos/grid',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-c4e9e2109e6fdc9aaa4ac754d089c6f5' => array(
          'module' => 'views',
          'delta' => 'c4e9e2109e6fdc9aaa4ac754d089c6f5',
          'region' => 'sidebar_first',
          'weight' => '5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Videos');
  $export['stanford_videos_grid'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'stanford_videos_recent';
  $context->description = '';
  $context->tag = 'Stanford Video';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'videos/recent-videos' => 'videos/recent-videos',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-fa7c8c2679ca3bd8c7ab56f89ee7a418' => array(
          'module' => 'views',
          'delta' => 'fa7c8c2679ca3bd8c7ab56f89ee7a418',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Videos');
  $export['stanford_videos_recent'] = $context;

  return $export;
}
