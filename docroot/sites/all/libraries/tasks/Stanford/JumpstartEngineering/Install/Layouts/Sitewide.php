<?php
/**
 * @file
 * Configure the sitewide layout.
 */

namespace Stanford\JumpstartEngineering\Install\Layouts;
/**
 *
 */
class Sitewide extends \ITasks\AbstractInstallTask {

  /**
   * Configure the sitewide layout.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    $context_status = variable_get('context_status', array());

    // Disables this context.
    $context_status['sitewide_jsa'] = TRUE;

    variable_set('context_status', $context_status);

  }

}
