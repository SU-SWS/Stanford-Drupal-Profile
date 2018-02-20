<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\JumpstartPlus\Install;
use \ITasks\AbstractInstallTask;

/**
 *
 */
class EnableModules extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {
    module_enable(array("stanford_jsplus_permissions"));
  }

}
