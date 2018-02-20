<?php

namespace Stanford\JumpstartEngineering\Hopper;

use \ITasks\AbstractInstallTask;

/**
 * Set the default department homepage class.
 */
class DeptSetHomepage extends AbstractInstallTask {

  /**
   * Set the homepage.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // todo: check if a homepage is specified in $args.
    $homepage = 'stanford_jumpstart_home_gibbons';
    try {
      stanford_homepage_set_default_layout($homepage);
    }
    catch (\Exception $e) {
      drush_log($e->getMessage(), 'error');
      return;
    }

    drush_log(dt('Enabled homepage: @homepage.', array('@homepage' => $homepage)), 'ok');

  }

  /**
   * Class requirements.
   */
  public function requirements() {
    return array();
  }

}
