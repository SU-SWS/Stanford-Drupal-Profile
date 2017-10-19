<?php
/**
 * @file
 * stanford_webauth_block.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_webauth_block_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'stanford-webauth-login';
  $context->description = 'WebAuth Login Block';
  $context->tag = 'Sitewide';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'webauth-webauth_login_block' => array(
          'module' => 'webauth',
          'delta' => 'webauth_login_block',
          'region' => 'global_header',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide');
  t('WebAuth Login Block');
  $export['stanford-webauth-login'] = $context;

  return $export;
}
