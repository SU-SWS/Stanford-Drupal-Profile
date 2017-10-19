<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\Jumpstart\Install\User;
/**
 *
 */
class HowardUser extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    $owner_role = user_role_load_by_name('site owner');

    // Create a Howard user for testing and give him the "site owner" role
    // drush ucrt Howard --password="howard" --mail="sws-developers+howard@lists.stanford.edu"
    // drush  urol "site owner" Howard.
    if (isset($owner_role->rid)) {
      $howard = new \stdClass();
      $howard->is_new = TRUE;
      $howard->name = 'Howard';
      $howard->pass = user_hash_password('howard');
      $howard->mail = "sws-developers+howard@lists.stanford.edu";
      $howard->init = "sws-developers+howard@lists.stanford.edu";
      $howard->status = TRUE;
      $howard_roles = array(DRUPAL_AUTHENTICATED_RID => TRUE, $owner_role->rid => TRUE);
      $howard->roles = $howard_roles;
      $howard->timezone = variable_get('date_default_timezone', '');
      $howard = user_save($howard);
    }

  }

}
