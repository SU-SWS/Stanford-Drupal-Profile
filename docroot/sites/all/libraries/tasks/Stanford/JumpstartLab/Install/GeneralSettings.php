<?php

namespace Stanford\JumpstartLab\Install;

use \ITasks\AbstractInstallTask;

/**
 * Class GeneralSettings.
 *
 * @package Stanford\JumpstartLab\Install
 */
class GeneralSettings extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {
    // Set the home page.
    $home = drupal_lookup_path('source', 'home');
    variable_set('site_frontpage', $home);

    // Set the default theme.
    variable_set('theme_default', 'stanford_framework');

    // Set menu position default setting to 'mark the rule's parent menu item
    // as being "active"'.
    variable_set('menu_position_active_link_display', 'parent');
  }

}
