<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Stanford\DrupalProfile\Install\StanfordSites;
use \ITasks\AbstractInstallTask;

class DisableModules extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {
    module_disable(array('update', 'comment'));
  }

}
