<?php
/**
 * @file
 * stanford_bean_types_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function stanford_bean_types_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create any stanford_banner bean'.
  $permissions['create any stanford_banner bean'] = array(
    'name' => 'create any stanford_banner bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any stanford_big_text_block bean'.
  $permissions['create any stanford_big_text_block bean'] = array(
    'name' => 'create any stanford_big_text_block bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any stanford_contact bean'.
  $permissions['create any stanford_contact bean'] = array(
    'name' => 'create any stanford_contact bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any stanford_icon_block bean'.
  $permissions['create any stanford_icon_block bean'] = array(
    'name' => 'create any stanford_icon_block bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any stanford_large_block bean'.
  $permissions['create any stanford_large_block bean'] = array(
    'name' => 'create any stanford_large_block bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any stanford_postcard bean'.
  $permissions['create any stanford_postcard bean'] = array(
    'name' => 'create any stanford_postcard bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any stanford_social_media_connect bean'.
  $permissions['create any stanford_social_media_connect bean'] = array(
    'name' => 'create any stanford_social_media_connect bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any stanford_testimonial_block bean'.
  $permissions['create any stanford_testimonial_block bean'] = array(
    'name' => 'create any stanford_testimonial_block bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any stanford_banner bean'.
  $permissions['delete any stanford_banner bean'] = array(
    'name' => 'delete any stanford_banner bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any stanford_big_text_block bean'.
  $permissions['delete any stanford_big_text_block bean'] = array(
    'name' => 'delete any stanford_big_text_block bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any stanford_contact bean'.
  $permissions['delete any stanford_contact bean'] = array(
    'name' => 'delete any stanford_contact bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any stanford_icon_block bean'.
  $permissions['delete any stanford_icon_block bean'] = array(
    'name' => 'delete any stanford_icon_block bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any stanford_large_block bean'.
  $permissions['delete any stanford_large_block bean'] = array(
    'name' => 'delete any stanford_large_block bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any stanford_postcard bean'.
  $permissions['delete any stanford_postcard bean'] = array(
    'name' => 'delete any stanford_postcard bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any stanford_social_media_connect bean'.
  $permissions['delete any stanford_social_media_connect bean'] = array(
    'name' => 'delete any stanford_social_media_connect bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any stanford_testimonial_block bean'.
  $permissions['delete any stanford_testimonial_block bean'] = array(
    'name' => 'delete any stanford_testimonial_block bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any stanford_banner bean'.
  $permissions['edit any stanford_banner bean'] = array(
    'name' => 'edit any stanford_banner bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any stanford_big_text_block bean'.
  $permissions['edit any stanford_big_text_block bean'] = array(
    'name' => 'edit any stanford_big_text_block bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any stanford_contact bean'.
  $permissions['edit any stanford_contact bean'] = array(
    'name' => 'edit any stanford_contact bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any stanford_icon_block bean'.
  $permissions['edit any stanford_icon_block bean'] = array(
    'name' => 'edit any stanford_icon_block bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any stanford_large_block bean'.
  $permissions['edit any stanford_large_block bean'] = array(
    'name' => 'edit any stanford_large_block bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any stanford_postcard bean'.
  $permissions['edit any stanford_postcard bean'] = array(
    'name' => 'edit any stanford_postcard bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any stanford_social_media_connect bean'.
  $permissions['edit any stanford_social_media_connect bean'] = array(
    'name' => 'edit any stanford_social_media_connect bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any stanford_testimonial_block bean'.
  $permissions['edit any stanford_testimonial_block bean'] = array(
    'name' => 'edit any stanford_testimonial_block bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any stanford_banner bean'.
  $permissions['view any stanford_banner bean'] = array(
    'name' => 'view any stanford_banner bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any stanford_big_text_block bean'.
  $permissions['view any stanford_big_text_block bean'] = array(
    'name' => 'view any stanford_big_text_block bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any stanford_contact bean'.
  $permissions['view any stanford_contact bean'] = array(
    'name' => 'view any stanford_contact bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any stanford_icon_block bean'.
  $permissions['view any stanford_icon_block bean'] = array(
    'name' => 'view any stanford_icon_block bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'site owner' => 'site owner',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any stanford_large_block bean'.
  $permissions['view any stanford_large_block bean'] = array(
    'name' => 'view any stanford_large_block bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any stanford_postcard bean'.
  $permissions['view any stanford_postcard bean'] = array(
    'name' => 'view any stanford_postcard bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any stanford_social_media_connect bean'.
  $permissions['view any stanford_social_media_connect bean'] = array(
    'name' => 'view any stanford_social_media_connect bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any stanford_testimonial_block bean'.
  $permissions['view any stanford_testimonial_block bean'] = array(
    'name' => 'view any stanford_testimonial_block bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
