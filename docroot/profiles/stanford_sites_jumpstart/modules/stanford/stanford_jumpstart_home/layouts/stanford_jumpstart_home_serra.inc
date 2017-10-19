<?php
/**
 * @file
 */

$context = new stdClass();
$context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
$context->api_version = 3;
$context->name = 'stanford_jumpstart_home_serra';
$context->description = 'Homepage: large text and data treatments, bold color background, flat design (Magazine Glossy)';
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
      'bean-jumpstart-info-text-block' => array(
        'module' => 'bean',
        'delta' => 'jumpstart-info-text-block',
        'region' => 'main_top',
        'weight' => '-9',
      ),
      'bean-jumpstart-homepage-mission-block' => array(
        'module' => 'bean',
        'delta' => 'jumpstart-homepage-mission-block',
        'region' => 'content_row2',
        'weight' => '-10',
      ),
      'bean-jumpstart-homepage-mission-blo-0' => array(
        'module' => 'bean',
        'delta' => 'jumpstart-homepage-mission-blo-0',
        'region' => 'content_row2',
        'weight' => '-9',
      ),
      'bean-homepage-about-block' => array(
        'module' => 'bean',
        'delta' => 'homepage-about-block',
        'region' => 'content_row3',
        'weight' => '-10',
      ),
      'bean-flexi-block-for-the-home-page' => array(
        'module' => 'bean',
        'delta' => 'flexi-block-for-the-home-page',
        'region' => 'content_row3',
        'weight' => '-9',
      ),
      'bean-jumpstart-homepage-announcements' => array(
        'module' => 'bean',
        'delta' => 'jumpstart-homepage-announcements',
        'region' => 'content_row3',
        'weight' => '-8',
      ),
    ),
  ),
);
$context->condition_mode = 0;

// Translatables
// Included for use with string extractors like potx.
t('Home Page');
t('Homepage: large text and data treatments, bold color background, flat design (Magazine Glossy)');
