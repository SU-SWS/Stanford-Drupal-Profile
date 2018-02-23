<?php
/**
 * @file
 * stanford_jsa_layouts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_jsa_layouts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = '9-col-banner-fsb-homepage';
  $context->description = 'Home page layout with an 9 column banner and first sidebar';
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
        'bean-homepage-about-block' => array(
          'module' => 'bean',
          'delta' => 'homepage-about-block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'bean-jumpstart-home-page-information-' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-home-page-information-',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'bean-homepage-banner-image' => array(
          'module' => 'bean',
          'delta' => 'homepage-banner-image',
          'region' => 'content',
          'weight' => '-10',
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
        'bean-jumpstart-affiliated-programs' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-affiliated-programs',
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
  t('Home page layout with an 9 column banner and first sidebar');
  $export['9-col-banner-fsb-homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'about_location';
  $context->description = 'Context for the location page';
  $context->tag = 'About';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'about/location' => 'about/location',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-jumpstart-location-map-block' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-location-map-block',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Context for the location page');
  $export['about_location'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'academics_graduate';
  $context->description = 'All pages in the Graduate Program section';
  $context->tag = 'Academics';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'academics/graduate-programs' => 'academics/graduate-programs',
        'academics/graduate-programs/*' => 'academics/graduate-programs/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-jumpstart-degree-programs-info-f' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-degree-programs-info-f',
          'region' => 'sidebar_first',
          'weight' => '4',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Academics');
  t('All pages in the Graduate Program section');
  $export['academics_graduate'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'all_pages_but_homepage_jsa';
  $context->description = 'All pages but the home page';
  $context->tag = 'Sub-pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'stanford_jsa_layouts-1' => array(
          'module' => 'menu_block',
          'delta' => 'stanford_jsa_layouts-1',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All pages but the home page');
  t('Sub-pages');
  $export['all_pages_but_homepage_jsa'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'course_search';
  $context->description = 'Courses search page';
  $context->tag = 'Courses';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'courses/search' => 'courses/search',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-85c57f65aa0dee37d8aa5a5031e564bc' => array(
          'module' => 'views',
          'delta' => '85c57f65aa0dee37d8aa5a5031e564bc',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Courses');
  t('Courses search page');
  $export['course_search'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'courses';
  $context->description = 'All pages in the Courses section';
  $context->tag = 'Courses';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'courses' => 'courses',
        'courses/*' => 'courses/*',
        '~courses/tag*' => '~courses/tag*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-jumpstart-featured-course' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-featured-course',
          'region' => 'sidebar_first',
          'weight' => '3',
        ),
        'views-85c57f65aa0dee37d8aa5a5031e564bc' => array(
          'module' => 'views',
          'delta' => '85c57f65aa0dee37d8aa5a5031e564bc',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All pages in the Courses section');
  t('Courses');
  $export['courses'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'events_calendars';
  $context->description = 'Blocks on month and day event views';
  $context->tag = 'Events';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'events/month/*' => 'events/month/*',
        'events/day/*' => 'events/day/*',
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
  t('Blocks on month and day event views');
  t('Events');
  $export['events_calendars'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'events_node';
  $context->description = 'Blocks that show up on all Event nodes.';
  $context->tag = 'Events';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'stanford_event' => 'stanford_event',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks that show up on all Event nodes.');
  t('Events');
  $export['events_node'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'events_past';
  $context->description = 'Past Events page';
  $context->tag = 'Events';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'events/past-events' => 'events/past-events',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ad215e0528148b386833fa3db1f3b7dc' => array(
          'module' => 'views',
          'delta' => 'ad215e0528148b386833fa3db1f3b7dc',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
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
  t('Past Events page');
  $export['events_past'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'events_upcoming';
  $context->description = 'Upcoming Events page in Events section';
  $context->tag = 'Events';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'events/upcoming-events' => 'events/upcoming-events',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-stanford_events_views-page' => array(
          'module' => 'views',
          'delta' => '-exp-stanford_events_views-page',
          'region' => 'sidebar_first',
          'weight' => '3',
        ),
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
  t('Upcoming Events page in Events section');
  $export['events_upcoming'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news';
  $context->description = 'Landing page for News section';
  $context->tag = 'News';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'news/recent-news' => 'news/recent-news',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-stanford_news-page_1' => array(
          'module' => 'views',
          'delta' => '-exp-stanford_news-page_1',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'bean-jumpstart-twitter-block' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-twitter-block',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Landing page for News section');
  t('News');
  $export['news'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news_pages';
  $context->description = 'All subpages in News section';
  $context->tag = 'News';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'news/*' => 'news/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-jumpstart-twitter-block' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-twitter-block',
          'region' => 'sidebar_first',
          'weight' => '1',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All subpages in News section');
  t('News');
  $export['news_pages'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'people_administrators';
  $context->description = 'Administrators page in People section';
  $context->tag = 'People';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'people/administrators' => 'people/administrators',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-jumpstart-contact-us-postcard' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-contact-us-postcard',
          'region' => 'sidebar_first',
          'weight' => '5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Administrators page in People section');
  t('People');
  $export['people_administrators'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'people_faculty';
  $context->description = 'Faculty page in People section';
  $context->tag = 'People';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'people/faculty' => 'people/faculty',
        'people/faculty/grid' => 'people/faculty/grid',
        'people/faculty/profiles' => 'people/faculty/profiles',
        'people/faculty/list' => 'people/faculty/list',
        'people/faculty/directory' => 'people/faculty/directory',
        'people/faculty/grid/*' => 'people/faculty/grid/*',
        'people/faculty/profiles/*' => 'people/faculty/profiles/*',
        'people/faculty/list/*' => 'people/faculty/list/*',
        'people/faculty/directory/*' => 'people/faculty/directory/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-jumpstart-why-i-teach-block' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-why-i-teach-block',
          'region' => 'sidebar_first',
          'weight' => '11',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Faculty page in People section');
  t('People');
  $export['people_faculty'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'people_grad_students';
  $context->description = 'Graduate Students page in People section';
  $context->tag = 'People';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'people/graduate-students' => 'people/graduate-students',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-jumpstart-prospective-student' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-prospective-student',
          'region' => 'sidebar_first',
          'weight' => '4',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Graduate Students page in People section');
  t('People');
  $export['people_grad_students'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'people_staff';
  $context->description = 'Staff page in the People section';
  $context->tag = 'Staff';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'people/staff' => 'people/staff',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-jumpstart-contact-us-postcard' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-contact-us-postcard',
          'region' => 'sidebar_first',
          'weight' => '6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Staff');
  t('Staff page in the People section');
  $export['people_staff'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'publications_landing_page';
  $context->description = 'Landing page in Publications section';
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
        'views--exp-publications-page' => array(
          'module' => 'views',
          'delta' => '-exp-publications-page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'bean-jumpstart-publications-something' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-publications-something',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Landing page in Publications section');
  t('Publications');
  $export['publications_landing_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'publications_nodes';
  $context->description = 'All nodes in Publications section';
  $context->tag = 'Publications';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'stanford_publication' => 'stanford_publication',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-publications_common-block_4' => array(
          'module' => 'views',
          'delta' => 'publications_common-block_4',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All nodes in Publications section');
  t('Publications');
  $export['publications_nodes'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide_jsa';
  $context->description = 'Sitewide - All pages';
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
        'stanford_jsa_layouts-2' => array(
          'module' => 'menu_block',
          'delta' => 'stanford_jsa_layouts-2',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'search_box',
          'weight' => '-10',
        ),
        'menu-menu-footer-about-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-about-menu',
          'region' => 'footer',
          'weight' => '-30',
        ),
        'menu-menu-footer-academics-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-academics-menu',
          'region' => 'footer',
          'weight' => '-29',
        ),
        'menu-menu-footer-people-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-people-menu',
          'region' => 'footer',
          'weight' => '-28',
        ),
        'menu-menu-footer-news-events-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-news-events-menu',
          'region' => 'footer',
          'weight' => '-27',
        ),
        'bean-jumpstart-footer-social-media--0' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-footer-social-media--0',
          'region' => 'footer',
          'weight' => '-26',
        ),
        'bean-jumpstart-footer-contact-block' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-footer-contact-block',
          'region' => 'footer',
          'weight' => '-25',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide');
  t('Sitewide - All pages');
  $export['sitewide_jsa'] = $context;

  return $export;
}
