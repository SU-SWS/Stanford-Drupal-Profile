<?php
/**
 * @file
 * stanford_metatag_nobots.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_metatag_nobots_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'block_robots';
  $context->description = 'Blocks search engine robots from crawling your site. DISABLE ON PRODUCTION WEBSITES.';
  $context->tag = 'Development';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'http_header' => array(
      'http_header' => array(
        'extra_headers' => 'X-Robots-Tag: noindex,nofollow,noarchive',
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks search engine robots from crawling your site. DISABLE ON PRODUCTION WEBSITES.');
  t('Development');
  $export['block_robots'] = $context;

  return $export;
}
