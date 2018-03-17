<?php
/**
 * @file
 * stanford_jsa_roles.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function stanford_jsa_roles_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access bean overview'.
  $permissions['access bean overview'] = array(
    'name' => 'access bean overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access jumpstart features'.
  $permissions['access jumpstart features'] = array(
    'name' => 'access jumpstart features',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'stanford_jumpstart',
  );

  // Exported permission: 'access jumpstart help'.
  $permissions['access jumpstart help'] = array(
    'name' => 'access jumpstart help',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'stanford_jumpstart',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer bean settings'.
  $permissions['administer bean settings'] = array(
    'name' => 'administer bean settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer bean types'.
  $permissions['administer bean types'] = array(
    'name' => 'administer bean types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer beans'.
  $permissions['administer beans'] = array(
    'name' => 'administer beans',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer block classes'.
  $permissions['administer block classes'] = array(
    'name' => 'administer block classes',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'block_class',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer contexts'.
  $permissions['administer contexts'] = array(
    'name' => 'administer contexts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'context_ui',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer menu positions'.
  $permissions['administer menu positions'] = array(
    'name' => 'administer menu positions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu_position',
  );

  // Exported permission: 'administer meta tags'.
  $permissions['administer meta tags'] = array(
    'name' => 'administer meta tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer redirects'.
  $permissions['administer redirects'] = array(
    'name' => 'administer redirects',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'redirect',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer stanford date timepicker'.
  $permissions['administer stanford date timepicker'] = array(
    'name' => 'administer stanford date timepicker',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'stanford_date_timepicker',
  );

  // Exported permission: 'administer stanford homepage'.
  $permissions['administer stanford homepage'] = array(
    'name' => 'administer stanford homepage',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'stanford_jumpstart_home',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'user',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'convert from stanford page to landing page'.
  $permissions['convert from stanford page to landing page'] = array(
    'name' => 'convert from stanford page to landing page',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'stanford_landing_page_node_convert',
  );

  // Exported permission: 'create stanford_course content'.
  $permissions['create stanford_course content'] = array(
    'name' => 'create stanford_course content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create stanford_course_importer content'.
  $permissions['create stanford_course_importer content'] = array(
    'name' => 'create stanford_course_importer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create stanford_event content'.
  $permissions['create stanford_event content'] = array(
    'name' => 'create stanford_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create stanford_event_importer content'.
  $permissions['create stanford_event_importer content'] = array(
    'name' => 'create stanford_event_importer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create stanford_event_series content'.
  $permissions['create stanford_event_series content'] = array(
    'name' => 'create stanford_event_series content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create stanford_gallery content'.
  $permissions['create stanford_gallery content'] = array(
    'name' => 'create stanford_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create stanford_landing_page content'.
  $permissions['create stanford_landing_page content'] = array(
    'name' => 'create stanford_landing_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create stanford_news_item content'.
  $permissions['create stanford_news_item content'] = array(
    'name' => 'create stanford_news_item content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create stanford_page content'.
  $permissions['create stanford_page content'] = array(
    'name' => 'create stanford_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create stanford_person content'.
  $permissions['create stanford_person content'] = array(
    'name' => 'create stanford_person content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create stanford_publication content'.
  $permissions['create stanford_publication content'] = array(
    'name' => 'create stanford_publication content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'path',
  );

  // Exported permission: 'delete any stanford_course content'.
  $permissions['delete any stanford_course content'] = array(
    'name' => 'delete any stanford_course content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any stanford_course_importer content'.
  $permissions['delete any stanford_course_importer content'] = array(
    'name' => 'delete any stanford_course_importer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any stanford_event content'.
  $permissions['delete any stanford_event content'] = array(
    'name' => 'delete any stanford_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any stanford_event_importer content'.
  $permissions['delete any stanford_event_importer content'] = array(
    'name' => 'delete any stanford_event_importer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any stanford_event_series content'.
  $permissions['delete any stanford_event_series content'] = array(
    'name' => 'delete any stanford_event_series content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any stanford_gallery content'.
  $permissions['delete any stanford_gallery content'] = array(
    'name' => 'delete any stanford_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any stanford_landing_page content'.
  $permissions['delete any stanford_landing_page content'] = array(
    'name' => 'delete any stanford_landing_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any stanford_news_item content'.
  $permissions['delete any stanford_news_item content'] = array(
    'name' => 'delete any stanford_news_item content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any stanford_page content'.
  $permissions['delete any stanford_page content'] = array(
    'name' => 'delete any stanford_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any stanford_person content'.
  $permissions['delete any stanford_person content'] = array(
    'name' => 'delete any stanford_person content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any stanford_publication content'.
  $permissions['delete any stanford_publication content'] = array(
    'name' => 'delete any stanford_publication content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own stanford_course content'.
  $permissions['delete own stanford_course content'] = array(
    'name' => 'delete own stanford_course content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own stanford_course_importer content'.
  $permissions['delete own stanford_course_importer content'] = array(
    'name' => 'delete own stanford_course_importer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own stanford_event content'.
  $permissions['delete own stanford_event content'] = array(
    'name' => 'delete own stanford_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own stanford_event_importer content'.
  $permissions['delete own stanford_event_importer content'] = array(
    'name' => 'delete own stanford_event_importer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own stanford_event_series content'.
  $permissions['delete own stanford_event_series content'] = array(
    'name' => 'delete own stanford_event_series content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own stanford_gallery content'.
  $permissions['delete own stanford_gallery content'] = array(
    'name' => 'delete own stanford_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own stanford_landing_page content'.
  $permissions['delete own stanford_landing_page content'] = array(
    'name' => 'delete own stanford_landing_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own stanford_news_item content'.
  $permissions['delete own stanford_news_item content'] = array(
    'name' => 'delete own stanford_news_item content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own stanford_page content'.
  $permissions['delete own stanford_page content'] = array(
    'name' => 'delete own stanford_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own stanford_person content'.
  $permissions['delete own stanford_person content'] = array(
    'name' => 'delete own stanford_person content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own stanford_publication content'.
  $permissions['delete own stanford_publication content'] = array(
    'name' => 'delete own stanford_publication content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in news_categories'.
  $permissions['delete terms in news_categories'] = array(
    'name' => 'delete terms in news_categories',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in publication_type'.
  $permissions['delete terms in publication_type'] = array(
    'name' => 'delete terms in publication_type',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in stanford_event_audience'.
  $permissions['delete terms in stanford_event_audience'] = array(
    'name' => 'delete terms in stanford_event_audience',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in stanford_event_categories'.
  $permissions['delete terms in stanford_event_categories'] = array(
    'name' => 'delete terms in stanford_event_categories',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in stanford_event_type'.
  $permissions['delete terms in stanford_event_type'] = array(
    'name' => 'delete terms in stanford_event_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in stanford_faculty_type'.
  $permissions['delete terms in stanford_faculty_type'] = array(
    'name' => 'delete terms in stanford_faculty_type',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in stanford_field_of_study'.
  $permissions['delete terms in stanford_field_of_study'] = array(
    'name' => 'delete terms in stanford_field_of_study',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in stanford_interests'.
  $permissions['delete terms in stanford_interests'] = array(
    'name' => 'delete terms in stanford_interests',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in stanford_slide_category'.
  $permissions['delete terms in stanford_slide_category'] = array(
    'name' => 'delete terms in stanford_slide_category',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in stanford_staff_type'.
  $permissions['delete terms in stanford_staff_type'] = array(
    'name' => 'delete terms in stanford_staff_type',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in stanford_student_type'.
  $permissions['delete terms in stanford_student_type'] = array(
    'name' => 'delete terms in stanford_student_type',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any stanford_course content'.
  $permissions['edit any stanford_course content'] = array(
    'name' => 'edit any stanford_course content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any stanford_course_importer content'.
  $permissions['edit any stanford_course_importer content'] = array(
    'name' => 'edit any stanford_course_importer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any stanford_event content'.
  $permissions['edit any stanford_event content'] = array(
    'name' => 'edit any stanford_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any stanford_event_importer content'.
  $permissions['edit any stanford_event_importer content'] = array(
    'name' => 'edit any stanford_event_importer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any stanford_event_series content'.
  $permissions['edit any stanford_event_series content'] = array(
    'name' => 'edit any stanford_event_series content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any stanford_gallery content'.
  $permissions['edit any stanford_gallery content'] = array(
    'name' => 'edit any stanford_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any stanford_landing_page content'.
  $permissions['edit any stanford_landing_page content'] = array(
    'name' => 'edit any stanford_landing_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any stanford_news_item content'.
  $permissions['edit any stanford_news_item content'] = array(
    'name' => 'edit any stanford_news_item content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any stanford_page content'.
  $permissions['edit any stanford_page content'] = array(
    'name' => 'edit any stanford_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any stanford_person content'.
  $permissions['edit any stanford_person content'] = array(
    'name' => 'edit any stanford_person content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any stanford_publication content'.
  $permissions['edit any stanford_publication content'] = array(
    'name' => 'edit any stanford_publication content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit bean view mode'.
  $permissions['edit bean view mode'] = array(
    'name' => 'edit bean view mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit meta tags'.
  $permissions['edit meta tags'] = array(
    'name' => 'edit meta tags',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit own stanford_course content'.
  $permissions['edit own stanford_course content'] = array(
    'name' => 'edit own stanford_course content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own stanford_course_importer content'.
  $permissions['edit own stanford_course_importer content'] = array(
    'name' => 'edit own stanford_course_importer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own stanford_event content'.
  $permissions['edit own stanford_event content'] = array(
    'name' => 'edit own stanford_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own stanford_event_importer content'.
  $permissions['edit own stanford_event_importer content'] = array(
    'name' => 'edit own stanford_event_importer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own stanford_event_series content'.
  $permissions['edit own stanford_event_series content'] = array(
    'name' => 'edit own stanford_event_series content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own stanford_gallery content'.
  $permissions['edit own stanford_gallery content'] = array(
    'name' => 'edit own stanford_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own stanford_landing_page content'.
  $permissions['edit own stanford_landing_page content'] = array(
    'name' => 'edit own stanford_landing_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own stanford_news_item content'.
  $permissions['edit own stanford_news_item content'] = array(
    'name' => 'edit own stanford_news_item content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own stanford_page content'.
  $permissions['edit own stanford_page content'] = array(
    'name' => 'edit own stanford_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own stanford_person content'.
  $permissions['edit own stanford_person content'] = array(
    'name' => 'edit own stanford_person content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own stanford_publication content'.
  $permissions['edit own stanford_publication content'] = array(
    'name' => 'edit own stanford_publication content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in news_categories'.
  $permissions['edit terms in news_categories'] = array(
    'name' => 'edit terms in news_categories',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in publication_type'.
  $permissions['edit terms in publication_type'] = array(
    'name' => 'edit terms in publication_type',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in stanford_event_audience'.
  $permissions['edit terms in stanford_event_audience'] = array(
    'name' => 'edit terms in stanford_event_audience',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in stanford_event_categories'.
  $permissions['edit terms in stanford_event_categories'] = array(
    'name' => 'edit terms in stanford_event_categories',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in stanford_event_type'.
  $permissions['edit terms in stanford_event_type'] = array(
    'name' => 'edit terms in stanford_event_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in stanford_faculty_type'.
  $permissions['edit terms in stanford_faculty_type'] = array(
    'name' => 'edit terms in stanford_faculty_type',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in stanford_field_of_study'.
  $permissions['edit terms in stanford_field_of_study'] = array(
    'name' => 'edit terms in stanford_field_of_study',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in stanford_interests'.
  $permissions['edit terms in stanford_interests'] = array(
    'name' => 'edit terms in stanford_interests',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in stanford_slide_category'.
  $permissions['edit terms in stanford_slide_category'] = array(
    'name' => 'edit terms in stanford_slide_category',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in stanford_staff_type'.
  $permissions['edit terms in stanford_staff_type'] = array(
    'name' => 'edit terms in stanford_staff_type',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in stanford_student_type'.
  $permissions['edit terms in stanford_student_type'] = array(
    'name' => 'edit terms in stanford_student_type',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'jumpstart assign administrator role'.
  $permissions['jumpstart assign administrator role'] = array(
    'name' => 'jumpstart assign administrator role',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'stanford_jumpstart',
  );

  // Exported permission: 'jumpstart use full block'.
  $permissions['jumpstart use full block'] = array(
    'name' => 'jumpstart use full block',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'stanford_jumpstart',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'see disabled homepage options'.
  $permissions['see disabled homepage options'] = array(
    'name' => 'see disabled homepage options',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'stanford_jumpstart_home',
  );

  // Exported permission: 'see enabled homepage options'.
  $permissions['see enabled homepage options'] = array(
    'name' => 'see enabled homepage options',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'stanford_jumpstart_home',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'show format selection for bean'.
  $permissions['show format selection for bean'] = array(
    'name' => 'show format selection for bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for field_collection_item'.
  $permissions['show format selection for field_collection_item'] = array(
    'name' => 'show format selection for field_collection_item',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for node'.
  $permissions['show format selection for node'] = array(
    'name' => 'show format selection for node',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for taxonomy_term'.
  $permissions['show format selection for taxonomy_term'] = array(
    'name' => 'show format selection for taxonomy_term',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for user'.
  $permissions['show format selection for user'] = array(
    'name' => 'show format selection for user',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'stanford jumpstart admin shortcuts'.
  $permissions['stanford jumpstart admin shortcuts'] = array(
    'name' => 'stanford jumpstart admin shortcuts',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'stanford_jumpstart_shortcuts',
  );

  // Exported permission: 'stanford jumpstart clear caches'.
  $permissions['stanford jumpstart clear caches'] = array(
    'name' => 'stanford jumpstart clear caches',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'stanford_jumpstart_shortcuts',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use text format content_editor_text_format'.
  $permissions['use text format content_editor_text_format'] = array(
    'name' => 'use text format content_editor_text_format',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view advanced help popup'.
  $permissions['view advanced help popup'] = array(
    'name' => 'view advanced help popup',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'advanced_help',
  );

  // Exported permission: 'view advanced help topic'.
  $permissions['view advanced help topic'] = array(
    'name' => 'view advanced help topic',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'advanced_help',
  );

  // Exported permission: 'view bean page'.
  $permissions['view bean page'] = array(
    'name' => 'view bean page',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view bean revisions'.
  $permissions['view bean revisions'] = array(
    'name' => 'view bean revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'system',
  );

  return $permissions;
}
