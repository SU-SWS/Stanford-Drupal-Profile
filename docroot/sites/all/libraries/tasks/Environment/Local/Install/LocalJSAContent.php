<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Environment\Local\Install;

class LocalJSAContent extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {
    variable_set("stanford_content_server", "http://jsa-content.su.dev/jsainstall");
  }

}
