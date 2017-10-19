<?php
/**
 * @file
 * stanford_jumpstart_login.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_jumpstart_login_context_default_contexts() {
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

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'stanford-simplesamlphp-login';
  $context->description = 'SimpleSAMLphp Login Block';
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
        'stanford_ssp-stanford_ssp_login_block' => array(
          'module' => 'stanford_ssp',
          'delta' => 'stanford_ssp_login_block',
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
  t('SimpleSAMLphp Login Block');
  $export['stanford-simplesamlphp-login'] = $context;

  return $export;
}
