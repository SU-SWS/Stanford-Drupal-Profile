<?php
/**
 * @file
 * Code for the Stanford Jumpstart Pettit Homepage layout.
 *  @author Caryl Westerberg <cjwest@stanford.edu>
 */
$context = new stdClass();
$context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
$context->api_version = 3;
$context->name = 'stanford_jumpstart_home_pettit';
$context->description = 'Homepage: Pettit layout with full-width banner, news, events, and a large custom block';
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
      'bean-jumpstart-home-page-full-width-b' => array(
        'module' => 'bean',
        'delta' => 'jumpstart-home-page-full-width-b',
        'region' => 'fullwidth_top',
        'weight' => '-10',
      ),
      'bean-homepage-about-block' => array(
        'module' => 'bean',
        'delta' => 'homepage-about-block',
        'region' => 'content_lower',
        'weight' => '-20',
      ),
      // News.
      'views-f73ff55b085ea49217d347de6630cd5a' => array(
        'module' => 'views',
        'delta' => 'f73ff55b085ea49217d347de6630cd5a',
        'region' => 'content_lower',
        'weight' => '-18',
      ),
      // News Extras.
      'views-9bf4ec9695a5b13242ba5a4898a6b635' => array(
        'module' => 'views',
        'delta' => '9bf4ec9695a5b13242ba5a4898a6b635',
        'region' => 'content_lower',
        'weight' => '-16',
      ),
      'bean-jumpstart-large-custom-block' => array(
        'module' => 'bean',
        'delta' => 'jumpstart-large-custom-block',
        'region' => 'content_bottom',
        'weight' => '-10',
      ),
      'views-stanford_events_views-block' => array(
        'module' => 'views',
        'delta' => 'stanford_events_views-block',
        'region' => 'content_bottom',
        'weight' => '-9',
      ),
    ),
  ),
);
$context->condition_mode = 0;

// Translatables
// Included for use with string extractors like potx.
t('Home Page');
t('Homepage: Pettit layout with full-width banner, news, events, and a large custom block');
