<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Environment\Local\Install;
use \ITasks\AbstractInstallTask;

class ImageAllowInsecureDerivatives extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {
    variable_set("image_allow_insecure_derivatives", TRUE);
  }

  /**
   * @param array $tasks
   */
  public function requirements() {
    return array(
      // List some development modules here.
    );
  }

}
