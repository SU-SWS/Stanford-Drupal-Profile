<?php
/**
 * @file
 */

$context = new stdClass();
$context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
$context->api_version = 3;
$context->name = 'stanford_jumpstart_home_serra_news_events';
$context->description = 'Homepage: large text and data treatments, bold color background, flat design (Magazine Glossy) with News and Events for dynamic content websites';
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
      'views-f73ff55b085ea49217d347de6630cd5a' => array(
        'module' => 'views',
        'delta' => 'f73ff55b085ea49217d347de6630cd5a',
        'region' => 'content_row3',
        'weight' => '-9',
      ),
      'views-stanford_events_views-block' => array(
        'module' => 'views',
        'delta' => 'stanford_events_views-block',
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
t('Homepage: large text and data treatments, bold color background, flat design (Magazine Glossy) with News and Events for dynamic content websites');
