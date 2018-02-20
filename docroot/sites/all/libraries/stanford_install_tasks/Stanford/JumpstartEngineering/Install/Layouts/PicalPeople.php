<?php
/**
 * @file
 * Configure PICAL stanford_person node display.
 */

namespace Stanford\JumpstartEngineering\Install\Layouts;
use \ITasks\AbstractInstallTask;

/**
 *
 */
class PicalPeople extends AbstractInstallTask {

  /**
   * Configure PICAL stanford_person node display.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {
    $context_status = variable_get('context_status', array());
    // Disable this context - We don't want the "Why I teach block".
    $context_status['people_faculty'] = TRUE;
    variable_set('context_status', $context_status);
  }

}
