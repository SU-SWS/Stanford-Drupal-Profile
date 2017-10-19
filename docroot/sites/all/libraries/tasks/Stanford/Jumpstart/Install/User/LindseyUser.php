<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\Jumpstart\Install\User;
/**
 *
 */
class LindseyUser extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    $editor_role = user_role_load_by_name('editor');

    // Create a Lindsey user for testing and give her the "editor" role.
    // drush --root=$siteroot ucrt Lindsey --password="lindsey" --mail="sws-developers+lindsey@lists.stanford.edu"
    // drush --root=$siteroot urol "editor" Lindsey.
    if (isset($editor_role->rid)) {
      $lindsey = new \stdClass();
      $lindsey->is_new = TRUE;
      $lindsey->name = 'Lindsey';
      $lindsey->pass = user_hash_password('lindsey');
      $lindsey->mail = "sws-developers+lindsey@lists.stanford.edu";
      $lindsey->init = "sws-developers+lindsey@lists.stanford.edu";
      $lindsey->status = TRUE;
      $lindsey_roles = array(DRUPAL_AUTHENTICATED_RID => TRUE, $editor_role->rid => TRUE);
      $lindsey->roles = $lindsey_roles;
      $lindsey->timezone = variable_get('date_default_timezone', '');
      $lindsey = user_save($lindsey);
    }

  }

}






