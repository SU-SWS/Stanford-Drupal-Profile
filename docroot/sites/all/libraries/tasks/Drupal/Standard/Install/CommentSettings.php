<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Drupal\Standard\Install;

class CommentSettings extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {

    // Enable default permissions for system roles.
    user_role_grant_permissions(DRUPAL_ANONYMOUS_RID, array('access comments'));
    user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, array('access comments', 'post comments', 'skip comment approval'));

  }

  /**
   * [requirements description]
   * @return [type] [description]
   */
  public function requirements() {
    return  array(
      'comment',
    );
  }

}
