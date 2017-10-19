<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Environment\Sites\Install\User;
/**
 *
 */
class SunetUser extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Need this for UI install.
    require_once DRUPAL_ROOT . '/includes/password.inc';

    $sunet = $args['forms']['install_configure_form']['stanford_sites_requester_sunetid'];
    $fullName = $args['forms']['install_configure_form']['stanford_sites_requester_name'];
    $email = $args['forms']['install_configure_form']['stanford_sites_requester_email'];

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
    $account->init = $authname;
    $account->status = TRUE;
    $roles = array(DRUPAL_AUTHENTICATED_RID => TRUE, $sunetRole->rid => TRUE, $ownerRole->rid => TRUE);
    $account->roles = $roles;
    $account->timezone = variable_get('date_default_timezone', '');
    $account = user_save($account);

    user_set_authmaps($account, array('authname_webauth' => $authname));
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
   * @param $form
   * @param $form_state
   */
  public function validate(&$form, &$form_state) {
    $values = $form_state['values'];
    $keys = array(
      "stanford_sites_requester_sunetid",
      "stanford_sites_requester_name",
      "stanford_sites_requester_email",
    );

    foreach ($keys as $key) {
      if (empty($values[$key])) {
        form_set_error($key, $key . " must not be empty.");
      }
    }
  }

  /**
   * [requirements description].
   *
   * @return [type] [description]
   */
  public function requirements() {
    return array(
      'user',
    );
  }

}
