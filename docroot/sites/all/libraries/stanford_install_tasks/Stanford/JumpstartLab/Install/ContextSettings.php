<?php

namespace Stanford\JumpstartLab\Install;

use \ITasks\AbstractInstallTask;

/**
 * Class ContextSettings.
 *
 * @package Stanford\JumpstartLab\Install
 */
class ContextSettings extends AbstractInstallTask {

  /**
   * Disable some contexts.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {
    $contexts = variable_get('context_status', array());
    $contexts['stanford_people_staff_pages'] = TRUE;
    variable_set('context_status', $contexts);
  }

}
