<?php
/**
 * @file
 * stanford_jumpstart_vpsa_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function stanford_jumpstart_vpsa_permissions_user_default_permissions() {
  $permissions = array();

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
      'site owner' => 'site owner',
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
      'student assistant' => 'student assistant',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access jumpstart features'.
  $permissions['access jumpstart features'] = array(
    'name' => 'access jumpstart features',
    'roles' => array(
      'administrator' => 'administrator',
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
      'student assistant' => 'student assistant',
    ),
    'module' => 'stanford_jumpstart',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer bean settings'.
  $permissions['administer bean settings'] = array(
    'name' => 'administer bean settings',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
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

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
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

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer stanford date timepicker'.
  $permissions['administer stanford date timepicker'] = array(
    'name' => 'administer stanford date timepicker',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'stanford_date_timepicker',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
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

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
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

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'file_entity',
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

  // Exported permission: 'create stanford_private_page content'.
  $permissions['create stanford_private_page content'] = array(
    'name' => 'create stanford_private_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create stanford_slide content'.
  $permissions['create stanford_slide content'] = array(
    'name' => 'create stanford_slide content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create stanford_video content'.
  $permissions['create stanford_video content'] = array(
    'name' => 'create stanford_video content',
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
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'path',
  );

  // Exported permission: 'delete any audio files'.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any image files'.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
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
      'editor' => 'editor',
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

  // Exported permission: 'delete any stanford_private_page content'.
  $permissions['delete any stanford_private_page content'] = array(
    'name' => 'delete any stanford_private_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any stanford_slide content'.
  $permissions['delete any stanford_slide content'] = array(
    'name' => 'delete any stanford_slide content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any stanford_video content'.
  $permissions['delete any stanford_video content'] = array(
    'name' => 'delete any stanford_video content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any video files'.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own audio files'.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own document files'.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own image files'.
  $permissions['delete own image files'] = array(
    'name' => 'delete own image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own stanford_event content'.
  $permissions['delete own stanford_event content'] = array(
    'name' => 'delete own stanford_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
      'student assistant' => 'student assistant',
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

  // Exported permission: 'delete own stanford_gallery content'.
  $permissions['delete own stanford_gallery content'] = array(
    'name' => 'delete own stanford_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
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
      'editor' => 'editor',
      'site owner' => 'site owner',
      'student assistant' => 'student assistant',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own stanford_page content'.
  $permissions['delete own stanford_page content'] = array(
    'name' => 'delete own stanford_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own stanford_person content'.
  $permissions['delete own stanford_person content'] = array(
    'name' => 'delete own stanford_person content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own stanford_private_page content'.
  $permissions['delete own stanford_private_page content'] = array(
    'name' => 'delete own stanford_private_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own stanford_slide content'.
  $permissions['delete own stanford_slide content'] = array(
    'name' => 'delete own stanford_slide content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own stanford_video content'.
  $permissions['delete own stanford_video content'] = array(
    'name' => 'delete own stanford_video content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own video files'.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'file_entity',
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

  // Exported permission: 'delete terms in stanford_event_audience'.
  $permissions['delete terms in stanford_event_audience'] = array(
    'name' => 'delete terms in stanford_event_audience',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in stanford_event_categories'.
  $permissions['delete terms in stanford_event_categories'] = array(
    'name' => 'delete terms in stanford_event_categories',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in stanford_event_type'.
  $permissions['delete terms in stanford_event_type'] = array(
    'name' => 'delete terms in stanford_event_type',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in stanford_slide_category'.
  $permissions['delete terms in stanford_slide_category'] = array(
    'name' => 'delete terms in stanford_slide_category',
    'roles' => array(
      'administrator' => 'administrator',
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

  // Exported permission: 'download any audio files'.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any image files'.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any video files'.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own audio files'.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own document files'.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own image files'.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own video files'.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'ds_switch stanford_person'.
  $permissions['ds_switch stanford_person'] = array(
    'name' => 'ds_switch stanford_person',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'edit any audio files'.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any stanford_event content'.
  $permissions['edit any stanford_event content'] = array(
    'name' => 'edit any stanford_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
      'student assistant' => 'student assistant',
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

  // Exported permission: 'edit any stanford_gallery content'.
  $permissions['edit any stanford_gallery content'] = array(
    'name' => 'edit any stanford_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
      'student assistant' => 'student assistant',
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
      'student assistant' => 'student assistant',
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
      'student assistant' => 'student assistant',
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
      'student assistant' => 'student assistant',
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
      'student assistant' => 'student assistant',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any stanford_private_page content'.
  $permissions['edit any stanford_private_page content'] = array(
    'name' => 'edit any stanford_private_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
      'student assistant' => 'student assistant',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any stanford_slide content'.
  $permissions['edit any stanford_slide content'] = array(
    'name' => 'edit any stanford_slide content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
      'student assistant' => 'student assistant',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any stanford_video content'.
  $permissions['edit any stanford_video content'] = array(
    'name' => 'edit any stanford_video content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
      'student assistant' => 'student assistant',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any video files'.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own audio files'.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own document files'.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own image files'.
  $permissions['edit own image files'] = array(
    'name' => 'edit own image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own stanford_event content'.
  $permissions['edit own stanford_event content'] = array(
    'name' => 'edit own stanford_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
      'student assistant' => 'student assistant',
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

  // Exported permission: 'edit own stanford_gallery content'.
  $permissions['edit own stanford_gallery content'] = array(
    'name' => 'edit own stanford_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
      'student assistant' => 'student assistant',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own stanford_landing_page content'.
  $permissions['edit own stanford_landing_page content'] = array(
    'name' => 'edit own stanford_landing_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
      'student assistant' => 'student assistant',
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
      'student assistant' => 'student assistant',
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

  // Exported permission: 'edit own stanford_private_page content'.
  $permissions['edit own stanford_private_page content'] = array(
    'name' => 'edit own stanford_private_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own stanford_slide content'.
  $permissions['edit own stanford_slide content'] = array(
    'name' => 'edit own stanford_slide content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own stanford_video content'.
  $permissions['edit own stanford_video content'] = array(
    'name' => 'edit own stanford_video content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own video files'.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'file_entity',
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

  // Exported permission: 'edit terms in stanford_event_audience'.
  $permissions['edit terms in stanford_event_audience'] = array(
    'name' => 'edit terms in stanford_event_audience',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in stanford_event_categories'.
  $permissions['edit terms in stanford_event_categories'] = array(
    'name' => 'edit terms in stanford_event_categories',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in stanford_event_type'.
  $permissions['edit terms in stanford_event_type'] = array(
    'name' => 'edit terms in stanford_event_type',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in stanford_slide_category'.
  $permissions['edit terms in stanford_slide_category'] = array(
    'name' => 'edit terms in stanford_slide_category',
    'roles' => array(
      'administrator' => 'administrator',
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
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'student assistant' => 'student assistant',
    ),
    'module' => 'search',
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
      'student assistant' => 'student assistant',
    ),
    'module' => 'stanford_jumpstart_shortcuts',
  );

  // Exported permission: 'stanford jumpstart clear caches'.
  $permissions['stanford jumpstart clear caches'] = array(
    'name' => 'stanford jumpstart clear caches',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'stanford_jumpstart_shortcuts',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'administrator' => 'administrator',
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
      'student assistant' => 'student assistant',
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
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'filter',
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
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view private files'.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
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
      'student assistant' => 'student assistant',
    ),
    'module' => 'system',
  );

  return $permissions;
}
