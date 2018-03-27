<?php
/**
 * @file
 * stanford_jumpstart_vpsa_layouts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_jumpstart_vpsa_layouts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vpsa_all_pages_but_homepage';
  $context->description = 'VPSA All pages but the home page and landing pages';
  $context->tag = 'Sub-pages';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~landing_page_content_type' => '~landing_page_content_type',
      ),
    ),
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'stanford_jsvpsa_layouts-4' => array(
          'module' => 'menu_block',
          'delta' => 'stanford_jsvpsa_layouts-4',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sub-pages');
  t('VPSA All pages but the home page and landing pages');
  $export['vpsa_all_pages_but_homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vpsa_events_related';
  $context->description = 'VPSA Related Events page';
  $context->tag = 'Events';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'events/related-events' => 'events/related-events',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-934c9b9d8d2d2f2b37f050dcd3bba83c' => array(
          'module' => 'views',
          'delta' => '934c9b9d8d2d2f2b37f050dcd3bba83c',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Events');
  t('VPSA Related Events page');
  $export['vpsa_events_related'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vpsa_homepage_dickinson';
  $context->description = 'VPSA homepage layout with banner, events, news, custom blocks';
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
        'bean-full-width-banner-short' => array(
          'module' => 'bean',
          'delta' => 'full-width-banner-short',
          'region' => 'fullwidth_top',
          'weight' => '-10',
        ),
        'bean-vpsa-large-about-block' => array(
          'module' => 'bean',
          'delta' => 'vpsa-large-about-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'bean-vpsa-quick-links' => array(
          'module' => 'bean',
          'delta' => 'vpsa-quick-links',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-f73ff55b085ea49217d347de6630cd5a' => array(
          'module' => 'views',
          'delta' => 'f73ff55b085ea49217d347de6630cd5a',
          'region' => 'content_row3',
          'weight' => '-10',
        ),
        'views-stanford_events_views-block' => array(
          'module' => 'views',
          'delta' => 'stanford_events_views-block',
          'region' => 'content_row3',
          'weight' => '-9',
        ),
        'bean-vpsa-custom-block-' => array(
          'module' => 'bean',
          'delta' => 'vpsa-custom-block-',
          'region' => 'content_row3',
          'weight' => '-8',
        ),
        'bean-jumpstart-footer-social-media--0' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-footer-social-media--0',
          'region' => 'main_lower',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Home Page');
  t('VPSA homepage layout with banner, events, news, custom blocks');
  $export['vpsa_homepage_dickinson'] = $context;

  $context = new stdClass();
  $context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vpsa_homepage_ellison';
  $context->description = 'VPSA homepage layout with banner, events, news, quick links';
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
        'bean-full-width-banner-short' => array(
          'module' => 'bean',
          'delta' => 'full-width-banner-short',
          'region' => 'fullwidth_top',
          'weight' => '-10',
        ),
        'bean-vpsa-large-about-block' => array(
          'module' => 'bean',
          'delta' => 'vpsa-large-about-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-stanford_events_views-block_1' => array(
          'module' => 'views',
          'delta' => 'stanford_events_views-block_1',
          'region' => 'content',
          'weight' => '-9',
        ),
        'bean-jumpstart-footer-social-media--0' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-footer-social-media--0',
          'region' => 'content',
          'weight' => '-8',
        ),
        'bean-vpsa-quick-links' => array(
          'module' => 'bean',
          'delta' => 'vpsa-quick-links',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-f73ff55b085ea49217d347de6630cd5a' => array(
          'module' => 'views',
          'delta' => 'f73ff55b085ea49217d347de6630cd5a',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Home Page');
  t('VPSA homepage layout with banner, events, news, quick links');
  $export['vpsa_homepage_ellison'] = $context;

  $context = new stdClass();
  $context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vpsa_homepage_melville';
  $context->description = 'VPSA homepage layout with banner, news, story telling';
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
        'bean-full-width-banner-short' => array(
          'module' => 'bean',
          'delta' => 'full-width-banner-short',
          'region' => 'fullwidth_top',
          'weight' => '-10',
        ),
        'bean-vpsa-story-telling-block' => array(
          'module' => 'bean',
          'delta' => 'vpsa-story-telling-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'bean-vpsa-custom-block-' => array(
          'module' => 'bean',
          'delta' => 'vpsa-custom-block-',
          'region' => 'content_row3',
          'weight' => '-10',
        ),
        'views-f73ff55b085ea49217d347de6630cd5a' => array(
          'module' => 'views',
          'delta' => 'f73ff55b085ea49217d347de6630cd5a',
          'region' => 'content_row3',
          'weight' => '-9',
        ),
        'bean-vpsa-quick-links' => array(
          'module' => 'bean',
          'delta' => 'vpsa-quick-links',
          'region' => 'content_row3',
          'weight' => '-8',
        ),
        'bean-jumpstart-footer-social-media--0' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-footer-social-media--0',
          'region' => 'main_lower',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Home Page');
  t('VPSA homepage layout with banner, news, story telling');
  $export['vpsa_homepage_melville'] = $context;

  $context = new stdClass();
  $context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vpsa_homepage_morrison';
  $context->description = 'VPSA homepage layout with banner, events, news, story telling';
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
        'bean-full-width-banner-short' => array(
          'module' => 'bean',
          'delta' => 'full-width-banner-short',
          'region' => 'fullwidth_top',
          'weight' => '-10',
        ),
        'bean-vpsa-story-telling-block' => array(
          'module' => 'bean',
          'delta' => 'vpsa-story-telling-block',
          'region' => 'main_top',
          'weight' => '-10',
        ),
        'bean-vpsa-custom-block-' => array(
          'module' => 'bean',
          'delta' => 'vpsa-custom-block-',
          'region' => 'main_upper',
          'weight' => '-10',
        ),
        'bean-vpsa-custom-block-2' => array(
          'module' => 'bean',
          'delta' => 'vpsa-custom-block-2',
          'region' => 'main_upper',
          'weight' => '-9',
        ),
        'bean-vpsa-quick-links' => array(
          'module' => 'bean',
          'delta' => 'vpsa-quick-links',
          'region' => 'main_upper',
          'weight' => '-8',
        ),
        'views-f73ff55b085ea49217d347de6630cd5a' => array(
          'module' => 'views',
          'delta' => 'f73ff55b085ea49217d347de6630cd5a',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'bean-jumpstart-footer-social-media--0' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-footer-social-media--0',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-stanford_events_views-block_1' => array(
          'module' => 'views',
          'delta' => 'stanford_events_views-block_1',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Home Page');
  t('VPSA homepage layout with banner, events, news, story telling');
  $export['vpsa_homepage_morrison'] = $context;

  $context = new stdClass();
  $context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vpsa_jumpstart_homepage';
  $context->description = 'VPSA homepage layout with carousel, events, news';
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
        'views-e0d332942ed45c1f9bc1cad46fc018d6' => array(
          'module' => 'views',
          'delta' => 'e0d332942ed45c1f9bc1cad46fc018d6',
          'region' => 'main_upper',
          'weight' => '-10',
        ),
        'views-stanford_events_views-block_3' => array(
          'module' => 'views',
          'delta' => 'stanford_events_views-block_3',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-stanford_news-block_1' => array(
          'module' => 'views',
          'delta' => 'stanford_news-block_1',
          'region' => 'content',
          'weight' => '-8',
        ),
        'bean-jumpstart-footer-social-media--0' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-footer-social-media--0',
          'region' => 'sidebar_second',
          'weight' => '-32',
        ),
        'bean-homepage-about-block' => array(
          'module' => 'bean',
          'delta' => 'homepage-about-block',
          'region' => 'sidebar_second',
          'weight' => '-31',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Home Page');
  t('VPSA homepage layout with carousel, events, news');
  $export['vpsa_jumpstart_homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vpsa_news';
  $context->description = 'Blocks placed on all announcement/news pages.';
  $context->tag = 'News';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'stanford_news_item' => 'stanford_news_item',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-news_external_source-block' => array(
          'module' => 'views',
          'delta' => 'news_external_source-block',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks placed on all announcement/news pages.');
  t('News');
  $export['vpsa_news'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vpsa_sitewide';
  $context->description = 'VPSA Sitewide - All pages';
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
        'stanford_jsvpsa_layouts-1' => array(
          'module' => 'menu_block',
          'delta' => 'stanford_jsvpsa_layouts-1',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'search_box',
          'weight' => '-10',
        ),
        'bean-vpsa-student-affairs-block' => array(
          'module' => 'bean',
          'delta' => 'vpsa-student-affairs-block',
          'region' => 'footer',
          'weight' => '-20',
        ),
        'bean-vpsa-helpful-links-footer-block' => array(
          'module' => 'bean',
          'delta' => 'vpsa-helpful-links-footer-block',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'bean-jumpstart-footer-contact-block' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-footer-contact-block',
          'region' => 'footer',
          'weight' => '-1',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide');
  t('VPSA Sitewide - All pages');
  $export['vpsa_sitewide'] = $context;

  return $export;
}
