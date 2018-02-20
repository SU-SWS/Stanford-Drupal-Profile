<?php
/**
 * @file
 * Create and update users; map roles
 */

namespace Stanford\JumpstartEngineering\Install\Sites;
use \ITasks\AbstractInstallTask;

/**
 *
 */
class WMDUsersRoles extends AbstractInstallTask {

  /**
   * Create and update users; map roles
   *
   * @param array $args
   *   Installation arguments.
   *
   * @todo: Refactor this into several methods and/or a generic Utility class.
   */
  public function execute(&$args = array()) {

    // Need this for UI install.
    require_once DRUPAL_ROOT . '/includes/password.inc';

    // Get config from the install form.
    $sunetid = strtolower(trim($args['forms']['install_configure_form']['stanford_sites_requester_sunetid']));
    $fullName = $args['forms']['install_configure_form']['stanford_sites_requester_name'];
    $email = $args['forms']['install_configure_form']['stanford_sites_requester_email'];

    if (empty($sunetid)) {
      $sunetid = "jse-admins";
    }

    if (empty($fullName)) {
      $fullName = "Engineering";
    }

    if (empty($email)) {
      $email = $sunetid . "@stanford.edu";
    }

    $authName = $sunet . '@stanford.edu';
    $sunetRole = user_role_load_by_name('SUNet User');
    $ownerRole = user_role_load_by_name('site owner');

    if (!is_numeric($sunetRole->rid) || !is_numeric($ownerRole->rid)) {
      throw new \Exception("A role or roles were missing when trying to create a sunet user");
    }

    $account = new \stdClass();
    $account->is_new = TRUE;
    $account->name = $fullName;
    $account->pass = user_hash_password(user_password());
    $account->mail = $email;
    $account->init = $authName;
    $account->status = TRUE;
    $roles = array(DRUPAL_AUTHENTICATED_RID => TRUE, $sunetRole->rid => TRUE, $ownerRole->rid => TRUE);
    $account->roles = $roles;
    $account->timezone = variable_get('date_default_timezone', '');
    $account = user_save($account);

    user_set_authmaps($account, array('authname_webauth' => $authName));

    // Map soe:jse-admins to administrator role
    // drush wamr soe:jse-admins administrator.
    module_load_include('inc', 'webauth_extras', 'webauth_extras.drush');
    drush_webauth_extras_webauth_map_role('soe:jse-admins', 'administrator');

  }


  /**
   * [form description]
   * @param  [type] &$form       [description]
   * @param  [type] &$form_state [description]
   * @return [type]              [description]
   */
  public function form(&$form, &$form_state) {
    /**
     * Grab requester's SUNetID.
     * We will be setting this programatically so we do not want to present it to the user.
     */
    $form["sites"]["stanford_sites_requester_sunetid"] = array(
      "#type" => "textfield",
      "#title" => t("SUNetID."),
      "#description" => t("Requester's SUNetID."),
    );

    /**
     * Grab requester's preferred name.
     * We will be setting this programatically so we do not want to present it to the user.
     */
    $form["sites"]['stanford_sites_requester_name'] = array(
      "#type" => "textfield",
      "#title" => t("Name."),
      "#description" => t("Requester's preferred name"),
    );


    /**
     * Grab requester's preferred email.
     * We will be setting this programatically so we do not want to present it to the user.
     */
    $form["sites"]['stanford_sites_requester_email'] = array(
      "#type" => "textfield",
      "#title" => t("Email."),
      "#description" => t("Requester's preferred email."),
    );

  }

  /**
   * [requirements description].
   *
   * @return [type] [description]
   */
  public function requirements() {
    return array(
      'user',
      'webauth',
      'webauth_extras',
    );
  }

}
