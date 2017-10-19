<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\Jumpstart\Install\User;
/**
 *
 */
class UserSettings extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    $admin_role = user_role_load_by_name('administrator');

    // Change user 1, currently admin, to sws-webservices
    $account = user_load(1, TRUE);
    $edit = array();
    $edit['mail'] = "sws-developers@lists.stanford.edu";
    $edit['status'] = TRUE;
    $roles = array(DRUPAL_AUTHENTICATED_RID => TRUE, $admin_role->rid => TRUE);
    $edit['roles'] = $roles;
    $edit['timezone'] = variable_get('date_default_timezone', '');
    $account = user_save($account, $edit);

  }

  /**
   * [requirements description]
   * @return [type] [description]
   */
  public function requirements() {
    return array(
      'user',
    );
  }

}
