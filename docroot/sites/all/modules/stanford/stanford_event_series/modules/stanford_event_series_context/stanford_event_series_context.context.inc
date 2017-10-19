<?php
/**
 * @file
 * stanford_event_series_context.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_event_series_context_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'event_series';
  $context->description = 'Blocks that show up on all Event Series nodes.';
  $context->tag = 'Events';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'stanford_event_series' => 'stanford_event_series',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-9f6372645d6fc08fabe9ca8a6d8ba157' => array(
          'module' => 'views',
          'delta' => '9f6372645d6fc08fabe9ca8a6d8ba157',
          'region' => 'content_lower',
          'weight' => '-10',
        ),
        'views-a9c39f329de245648d5ebeee11565ada' => array(
          'module' => 'views',
          'delta' => 'a9c39f329de245648d5ebeee11565ada',
          'region' => 'content_lower',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks that show up on all Event Series nodes.');
  t('Events');
  $export['event_series'] = $context;

  return $export;
}
