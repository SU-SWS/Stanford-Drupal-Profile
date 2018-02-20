<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Environment\Sites\Install;
use \ITasks\AbstractInstallTask;

class GeneralSettings extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {

  }

  /**
   * @param array $tasks
   */
  public function requirements() {
    // These are added here so they get enabled at module enable time.
    return array(
      'stanford_sites_helper',
      'stanford_sites_systemtools',
    );
  }

}
