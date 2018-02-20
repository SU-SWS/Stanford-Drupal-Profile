<?php

namespace Stanford\Jumpstart\Install;

use \ITasks\AbstractInstallTask;

/**
 * Class AddFeaturesPage.
 *
 * @package Stanford\Jumpstart\Install
 */
class VersionIdentifier extends AbstractInstallTask {

  /**
   * Set a couple of db variables so we can keep track of this profile.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {
    $info = system_get_info('module', variable_get('install_profile', $args['parameters']['profile']));
    variable_set('stanford_jumpstart_original', array(
      'installed_date' => time(),
      'installed_version' => $info['version'],
    ));
  }

}
