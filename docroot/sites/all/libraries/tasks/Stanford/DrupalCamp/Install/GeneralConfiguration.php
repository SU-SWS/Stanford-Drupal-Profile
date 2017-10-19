<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\DrupalCamp\Install;
/**
 *
 */
class GeneralConfiguration extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {
    // Set the home page.
    variable_set("site_frontpage", drupal_get_normal_path("welcome-stanford-drupalcamp"));
    // variable_set("site_403", drupal_get_normal_path("403"));
    variable_set("site_404", drupal_get_normal_path("404"));
    variable_set("site_slogan", "It's camp");
  }

  /**
   * Dependencies.
   */
  public function requirements() {
    return array(
      'adminimal_admin_menu',
      'admin_menu',
    );
  }

}
