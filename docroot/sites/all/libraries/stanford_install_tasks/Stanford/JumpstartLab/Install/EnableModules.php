<?php

namespace Stanford\JumpstartLab\Install;

use \ITasks\AbstractInstallTask;

/**
 * Class EnableModules.
 *
 * @package Stanford\JumpstartLab\Install
 */
class EnableModules extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {
    // This is enabled here because it depends on items that are in
    // other install tasks so it cannot be a dependency or it will get
    // installed too early.
    module_enable(array(
      "stanford_jumpstart_lab_permissions",
    ));
  }

}
