<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\DrupalCamp\Install;
use \ITasks\AbstractInstallTask;

/**
 *
 */
class UserPermissions extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {
    $this->authenticated();
    $this->anonymous();
  }

  /**
   * [administrator description]
   * @return [type] [description]
   */
  protected function authenticated() {
    // $role = user_role_load_by_name('authenticated user');
    // $rid = $role->rid;
    $rid = DRUPAL_AUTHENTICATED_RID;
    $perms = array(
      'bean' => array(
        'view any stanford_banner bean',
        'view any stanford_big_text_block bean',
        'view any stanford_contact bean',
        'view any stanford_icon_block bean',
        'view any stanford_large_block bean',
        'view any stanford_postcard bean',
        'view any stanford_social_media_connect bean',
        'view any stanford_testimonial_block bean',
      ),
      'better_formats' => array(
        'show format tips',
        'show more format tips link',
      ),
      'user' => array(
        'access user profiles',
        'change own username',
        'cancel account',
      ),
      'search' => array(
        'search content',
      ),
      'node' => array(
        'access content',
        'create stanford_session content',
        'edit own stanford_session content',
        'delete own stanford_session content',
      ),
      'filter' => array(
        'use text format filtered_html',
      ),
      'file_entity' => array(
        'view files',
      ),
    );
    $this->save($rid, $perms);
  }

  /**
   * [administrator description]
   * @return [type] [description]
   */
  protected function anonymous() {
    // $role = user_role_load_by_name('anonymous user');
    // $rid = $role->rid;
    $rid = DRUPAL_ANONYMOUS_RID;
    $perms = array(
      'bean' => array(
        'view any stanford_banner bean',
        'view any stanford_big_text_block bean',
        'view any stanford_contact bean',
        'view any stanford_icon_block bean',
        'view any stanford_large_block bean',
        'view any stanford_postcard bean',
        'view any stanford_social_media_connect bean',
        'view any stanford_testimonial_block bean',
      ),
      'user' => array(
        'access user profiles',
      ),
      'search' => array(
        'search content',
      ),
      'node' => array(
        'access content',
      ),
      'filter' => array(
        'use text format filtered_html',
      ),
      'file_entity' => array(
        'view files',
      ),
    );
    $this->save($rid, $perms);
  }

  /**
   * [save description]
   * @param  array  $perms [description]
   * @return [type]        [description]
   */
  protected function save($rid = 0, $permissions = array()) {
    foreach ($permissions as $module => $permission_list) {
      foreach ($permission_list as $name) {
          db_merge('role_permission')
          ->key(array(
              'rid' => $rid,
              'permission' => $name,
          ))
          ->fields(array(
              'module' => $module,
          ))
          ->execute();
      }
    }
    drupal_static_reset('user_access');
    drupal_static_reset('user_role_permissions');
  }

  /**
   * Dependencies.
   */
  public function requirements() {
    return array(
      'user',
    );
  }

}
