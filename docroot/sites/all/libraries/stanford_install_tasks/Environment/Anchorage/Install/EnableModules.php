<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Environment\Anchorage\Install;
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
    // Nothing to see here.
  }

  /**
   * Dependencies.
   */
  public function requirements() {
    return array(
      'anchorage_helper',
    );
  }

}
