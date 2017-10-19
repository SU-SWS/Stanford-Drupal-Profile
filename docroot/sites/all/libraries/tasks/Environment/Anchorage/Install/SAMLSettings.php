<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Environment\Anchorage\Install;
/**
 *
 */
class SAMLSettings extends \ITasks\AbstractInstallTask {

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



