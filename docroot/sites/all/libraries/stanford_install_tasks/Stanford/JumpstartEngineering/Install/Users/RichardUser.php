<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\JumpstartEngineering\Install\Users;
use \ITasks\AbstractInstallTask;

/**
 *
 */
class RichardUser extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    $site_member_role = user_role_load_by_name('site member');

    // Create a Richard user for testing and give her the "editor" role.
    // drush --root=$siteroot ucrt Richard --password="Richard" --mail="sws-developers+Richard@lists.stanford.edu"
    // drush --root=$siteroot urol "editor" Richard.
    if (isset($site_member_role->rid)) {
      $Richard = new \stdClass();
      $Richard->is_new = TRUE;
      $Richard->name = 'richard';
      $Richard->pass = user_hash_password('richard');
      $Richard->mail = "sws-developers+Richard@lists.stanford.edu";
      $Richard->init = "sws-developers+Richard@lists.stanford.edu";
      $Richard->status = TRUE;
      $Richard_roles = array(DRUPAL_AUTHENTICATED_RID => TRUE, $site_member_role->rid => TRUE);
      $Richard->roles = $Richard_roles;
      $Richard->timezone = variable_get('date_default_timezone', '');
      $Richard = user_save($Richard);
    }

  }

}
