<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\JumpstartVPSA\Install;
/**
 *
 */
class EnableModules extends \ITasks\AbstractInstallTask {

  /**
   * Enable a couple of final modules because they depend on everything.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    module_enable(
      array(
        'stanford_jumpstart_vpsa_permissions',
        'stanford_jumpstart_vpsa_workflows',
      )
    );

  }

}