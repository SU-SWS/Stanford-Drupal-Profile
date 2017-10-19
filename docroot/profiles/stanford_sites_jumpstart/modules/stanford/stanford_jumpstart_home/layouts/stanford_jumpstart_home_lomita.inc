<?php
/**
 * @file
 */

$context = new stdClass();
$context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
$context->api_version = 3;
$context->name = 'stanford_jumpstart_home_lomita';
$context->description = 'Homepage: large image body background, full bleed (Sunset Delorean)';
$context->tag = 'Home Page';
$context->conditions = array(
  'path' => array(
    'values' => array(
      '<front>' => '<front>',
    ),
  ),
);
$context->reactions = array(
  'block' => array(
    'blocks' => array(
      'bean-jumpstart-lead-text-with-body' => array(
        'module' => 'bean',
        'delta' => 'jumpstart-lead-text-with-body',
        'region' => 'main_top',
        'weight' => '-10',
      ),
      'bean-jumpstart-postcard-with-video' => array(
        'module' => 'bean',
        'delta' => 'jumpstart-postcard-with-video',
        'region' => 'main_top',
        'weight' => '-9',
      ),
    ),
  ),
);
$context->condition_mode = 0;

// Translatables
// Included for use with string extractors like potx.
t('Home Page');
t('Homepage: large image body background, full bleed (Sunset Delorean)');
