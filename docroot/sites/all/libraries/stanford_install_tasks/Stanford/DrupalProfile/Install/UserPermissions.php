<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Stanford\DrupalProfile\Install;
use \ITasks\AbstractInstallTask;

class UserPermissions extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {

    // Revoke a few stupid default permissions.
    user_role_revoke_permissions(DRUPAL_ANONYMOUS_RID, array('access comments'));
    user_role_revoke_permissions(DRUPAL_AUTHENTICATED_RID, array('post comments', 'skip comment approval'));

    // User registration - only site administrators can create new user accounts.
    variable_set('user_register', 0);
  }

  /**
   * @param array $tasks
   */
  public function requirements() {
    return array(
      'user',
    );
  }

}
