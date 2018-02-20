<?php

namespace Stanford\JumpstartEngineering\Hopper;

use \ITasks\AbstractInstallTask;

/**
 * Department mods hopper helper class.
 */
class DeptUnMods extends AbstractInstallTask {

  /**
   * Set Content for the Add features page.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Disable and uninstall the modules that were enabled in DeptMods task.
    $modules = array(
      'stanford_jumpstart_home_dept',
      'stanford_jse_dept',
    );
    module_disable($modules);
    if (drupal_uninstall_modules($modules)) {
      drush_log('Disabled and uninstalled modules: ' . implode(', ', $modules), 'ok');
    }

    // Enable the stanford_news_views.
    $modules = array('stanford_news_views');
    if (module_enable($modules)) {
      drush_log('Enabled modules: ' . implode(', ', $modules), 'ok');
    }

  }

  /**
   * Dependencies.
   *
   * @return array
   *   An array of dependency modules.
   */
  public function requirements() {
    return array(
      'stanford_sites_jumpstart_engineering',
    );
  }

}
