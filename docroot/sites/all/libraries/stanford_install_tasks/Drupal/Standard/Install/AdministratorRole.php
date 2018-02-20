<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Drupal\Standard\Install;
use \ITasks\AbstractInstallTask;

/**
 * Class Doc Block
 */
class AdministratorRole extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {
    // Create a default role for site administrators, with all available permissions assigned.
    $admin_role = new \stdClass();
    $admin_role->name = 'administrator';
    $admin_role->weight = 2;
    user_role_save($admin_role);
    user_role_grant_permissions($admin_role->rid, array_keys(module_invoke_all('permission')));
    // Set this as the administrator role.
    variable_set('user_admin_role', $admin_role->rid);

    // Assign user 1 the "administrator" role.
    db_insert('users_roles')
      ->fields(array('uid' => 1, 'rid' => $admin_role->rid))
      ->execute();
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
