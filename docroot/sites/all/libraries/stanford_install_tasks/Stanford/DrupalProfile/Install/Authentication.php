<?php
/**
 * @file
 * Abstract Task Class.
 */


namespace Stanford\DrupalProfile\Install;
use \ITasks\AbstractInstallTask;
use Stanford\DrupalProfile\Install\StanfordSites\SitesHelper;

/**
 *
 */
class Authentication extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    $this->stanfordSitesAddWebauthUser(
      variable_get('stanford_sites_requester_sunetid'),
      variable_get('stanford_sites_requester_name'),
      variable_get('stanford_sites_requester_email')
    );

  }


  /**
   * [stanfordSitesAddWebauthUser description].
   *
   * @param [type] $sunet
   *   [description]
   * @param string $name
   *   [description]
   * @param string $email
   *   [description]
   *
   * @return [type]        [description]
   */
  protected function stanfordSitesAddWebauthUser($sunet, $name = '', $email = '') {
    $sunet = strtolower(trim($sunet));

    if (empty($sunet)) {
      watchdog('Stanford Profile', 'Could not create user. No SUNetID available.');
      return;
    }

    $name = trim($name);
    if (empty($name)) {
      $name = $sunet . '@stanford.edu';
    }

    $email = strtolower(trim($email));
    if (empty($email)) {
      $email = $sunet . '@stanford.edu';
    }

    if (!user_load_by_name($name)) {
      $account = new stdClass();
      $account->is_new = TRUE;
      $account->name = $name;
      $account->pass = user_password();
      $account->mail = $email;
      $account->init = $sunet . '@stanford.edu';
      $account->status = TRUE;

      $sunet_role = user_role_load_by_name('SUNet User');
      $admin_role = user_role_load_by_name('administrator');
      $account->roles = array(DRUPAL_AUTHENTICATED_RID => TRUE, $sunet_role->rid => TRUE, $admin_role->rid => TRUE);
      $account->timezone = variable_get('date_default_timezone', '');
      $account = user_save($account);

      user_set_authmaps($account, array('authname_webauth' => $sunet . '@stanford.edu'));

      // Hide Local Drupal user login block. User 1 can still login from /user
      variable_set(webauth_allow_local, 0);

      watchdog('Stanford Profile', 'Created user: %user', array('%user' => $name));
    }
    else {
      watchdog('Stanford Profile', 'Could not create duplicate user: %user', array('%user' => $name));
    }
  }


  /**
   * [requirements description]
   * @return [type] [description]
   */
  public function requirements() {
    return array(
      'webauth',
      'webauth_extras',
      'user',
    );
  }

}
