<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Stanford\DrupalProfile\Install\StanfordSites;

class EnableModules extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {

    // Do this now rather than in .info file because it's looking for the
    // administrator role and errors out otherwise.
    module_enable(array('stanford_sites_helper'));
    module_enable(array('stanford_sites_systemtools'));
    module_enable(array('stanford_afs_quota'));

  }

}
