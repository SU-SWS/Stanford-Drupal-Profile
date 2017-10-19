<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Environment\Sites\Install;
/**
 *
 */
class WebauthExtras extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // If we're using WMD, enable the webauth_extras module.
    variable_set('webauth_link_text', "SUNetID Login");
    variable_set('webauth_allow_local', 0);

    // Map itservices:webservices to administrator role
    // drush wamr itservices:webservices administrator.
    module_load_include('inc', 'webauth_extras', 'webauth_extras.drush');
    drush_webauth_extras_webauth_map_role('itservices:webservices', 'administrator');

  }

  /**
   * Dependencies.
   * @return [type] [description]
   */
  public function requirements() {
    return array(
      'webauth_extras',
    );
  }

}
