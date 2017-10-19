<?php
/**
 * @file
 * drush commands for Stanford SimpleSAML PHP.
 */

/**
 * Implements hook_drush_command().
 *
 * @return array List of drush commands.
 */
function stanford_ssp_drush_command() {
  $items = array();

  // Adds an entitlement mapping.
  $items['saml-entitlement-role'] = array(
    'description' => 'Map a SAML entitlement to a role',
    'arguments' => array(
      'entitlement' => 'A value from eduPersonEntitlement, e.g., "anchorage_support"',
      'role' => 'The name of the role, e.g., "administrator"',
    ),
    'aliases' => array('ssp-ser'),
  );

  // Creates a SSO enabled account.
  $items['saml-add-user'] = array(
    'description' => 'Add a SSO enabled user',
    'arguments' => array(
      'sunetid' => 'A sunet id',
    ),
    'options' => array(
      'name' => 'The user\'s name',
      'email' => 'The user\'s email',
      'roles' => 'Comma separated list of role names',
      'notify' => 'Send email to the user (boolean)?',
    ),
    'aliases' => array('ssp-au'),
  );

  $items['stanford-ssp-migrate-wmd'] = array(
    'description' => 'Migrate settings from the WebAuth Module for Drupal (WMD) to Stanford SimpleSAML PHP',
    'options' => array(
      'dry-run' => array(
        'description'   => "Do a dry run and see what values will be changed.",
      ),
    ),
    'aliases' => array('sspwmd'),
  );

  return $items;
}

/**
 * Map an entitlement to a role.
 * @param  [type] $entitlement [description]
 * @param  [type] $role        [description]
 * @return [type]              [description]
 */
function drush_stanford_ssp_saml_entitlement_role($entitlement, $role) {
  $entitlement = check_plain($entitlement);
  // Look up rid.
  $role_object = user_role_load_by_name($role);

  if (!$role_object) {
    drupal_set_message(t('No role exists with the name "@role"', array('@role' => $role)), 'error');
    return;
  }

  $rid = $role_object->rid;

  // Look up current role mapping, if any.
  $role_mapping = variable_get('stanford_simplesamlphp_auth_rolepopulation');
  if (!empty($role_mapping)) {
    $role_mapping .= "|";
  }

  // Add our mapping.
  $role_mapping .= $rid . ":eduPersonEntitlement,=," . $entitlement;

  // Save our mapping.
  variable_set('stanford_simplesamlphp_auth_rolepopulation', $role_mapping);
  $message = t('Mapped the "@entitlement" entitlement to the "@role" role.', array('@entitlement' => $entitlement, '@role' => $role));
  drupal_set_message($message);
  watchdog('stanford_ssp', $message);

}

/**
 * Add a SSO user.
 * @param  [type] $sunet [description]
 * @return [type]        [description]
 */
function drush_stanford_ssp_saml_add_user($sunet) {

  // Form hooks are in the admin include.
  module_load_include("inc", "stanford_ssp", "stanford_ssp.admin");

  // Patch through values to the form functions.
  $form_state["values"]["sunetid"] = check_plain($sunet);

  // User Name.
  $name = drush_get_option("name");
  if (!empty($name)) {
    $form_state["values"]["name"] = check_plain($name);
  }

  // Users email other than the defaulted one.
  $email = drush_get_option("email");
  if (!empty($email)) {
    $form_state["values"]["email"] = check_plain($email);
  }

  // A list of roles by name so we have some translation to do.
  $roles = drush_get_option("roles");
  if (!empty($roles)) {
    $xp = explode(",", $roles);
    $xp = array_map("trim", $xp);
    $xp = array_map("check_plain", $xp);
    $uroles = user_roles();
    $int = array_intersect($uroles, $xp);
    $ids = array_keys($int);
    $form_state["values"]["roles"] = $ids;
  }

  // @todo: Make this an option.
  $nofify = drush_get_option("notify");
  if (!empty($nofify) && ($nofity == "true" || (int) $notify == 1)) {
    $form_state["values"]["notify"] = TRUE;
  }

  drupal_form_submit('stanford_ssp_add_sso_user', $form_state);

}

/**
 * Implements drush_COMMANDFILE_COMMANDNAME().
 */
function drush_stanford_ssp_migrate_wmd() {
  module_load_include('module', 'stanford_ssp');
  stanford_ssp_import_webauth_settings();
}
