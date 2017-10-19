<?php
/**
 * @file
 * stanford_publication_landing_page_context.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_publication_landing_page_context_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'stanford_publications_landing_page';
  $context->description = 'Landing page blocks in publications section from the feature';
  $context->tag = 'Publications';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'publications' => 'publications',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-c88cdc295cb2555db2a2ca439158c3a8' => array(
          'module' => 'views',
          'delta' => 'c88cdc295cb2555db2a2ca439158c3a8',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Landing page blocks in publications section from the feature');
  t('Publications');
  $export['stanford_publications_landing_page'] = $context;

  return $export;
}
