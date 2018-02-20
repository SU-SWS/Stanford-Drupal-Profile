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
class SAMLSettings extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {
  }

  /**
   * Dependencies.
   */
  public function requirements() {
    return array(
      'stanford_saml_block',
      'stanford_ssp',
    );
  }

}
