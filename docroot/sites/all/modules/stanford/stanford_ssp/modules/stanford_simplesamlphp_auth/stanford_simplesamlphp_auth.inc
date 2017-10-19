<?php

/**
 * @file
 * Contains non-hook implementations.
 */

/**
 * Handles the log in and authentication of a user with SAML attributes.
 */
function stanford_simplesamlphp_handle_user_login_register() {
  global $user;
  $authname = stanford_simplesamlphp_auth_get_authname();
  $username = stanford_simplesamlphp_auth_get_username();

  // Look for a matching local Drupal user that we can pair with.
  $ext_user = stanford_simplesamlphp_auth_find_external_user($authname);

  // If local matching is enabled look for a Local Drupal user.
  if (!$ext_user && variable_get("stanford_simplesamlphp_auth_autoenablesaml", FALSE)) {
    $ext_user = stanford_simplesamlphp_auth_find_local_user($username);

    // If we have found a match we need to make sure we add the authmap.
    if ($ext_user) {
      user_set_authmaps($ext_user, array('authname_stanford_simplesamlphp_auth' => $authname));
    }

  }

  // Delegate the creation of a new user if allowed and we did not find one.
  if (!$ext_user && stanford_simplesamlphp_auth_is_auto_provision_enabled()) {
    $ext_user = stanford_simplesamlphp_auth_user_register();
  }

  // If no external user then access denied as no user could be created and no
  // user was found.
  if (!$ext_user) {
    // Cannot do an access denied here as it creates a redirect loop.
    // @todo: Handle this moar better.
    drupal_set_message(t("Sorry, but you do not have access to this page."), "error");
    drupal_not_found();
    exit();
  }

  // Set the global user object to our logged in and/or new user.
  $user = $ext_user;
}

/**
 * Find a local user that matches the SAML attributes by the authmap table.
 */
function stanford_simplesamlphp_auth_find_external_user($authname) {

  // See if we can load the user by authname.
  if (stanford_simplesamlphp_auth_user_has_authmap($authname)) {
    return user_external_load($authname);
  }

  return FALSE;
}

/**
 * Match SAML Attributes to local accounts.
 *
 * Trys to find a local account that matches the SAML attributes by trying to
 * match up user properties to saml attributes.
 */
function stanford_simplesamlphp_auth_find_local_user($username) {

  // See if we can load the user by username.
  $ext_user = user_load_by_name($username);

  // If we cannot load the user by authname try to load the user by email.
  if (!$ext_user) {
    $mail = stanford_simplesamlphp_auth_get_email();
    $ext_user = user_load_by_mail($mail);
  }

  // Give opportunity to load user according to load a different user according to fields received in the auth.
  $auth_field = variable_get('simplesamlphp_auth_unique_id', 'eduPersonPrincipalName');
  $attributes = stanford_simplesamlphp_auth_get_saml_attributes();
  drupal_alter("saml_ext_user", $ext_user, $attributes, $auth_field);

  // If we have a user we return it..
  if ($ext_user) {
    return $ext_user;
  }

  return FALSE;
}

/**
 * Boolean check for autoenable feature.
 *
 * @return bool
 *   Returns TRUE is users can be auto registered.
 */
function stanford_simplesamlphp_auth_is_auto_provision_enabled() {
  return variable_get("stanford_simplesamlphp_auth_registerusers", FALSE);
}

/**
 * Asks all modules if current federated user is allowed to login.
 *
 * @return bool
 *   Returns FALSE if at least one module returns FALSE
 */
function stanford_simplesamlphp_auth_allow_user_by_attribute() {
  $attributes = stanford_simplesamlphp_auth_get_saml_attributes();
  foreach (module_implements('stanford_simplesamlphp_auth_allow_login') as $module) {
    if (module_invoke($module, 'stanford_simplesamlphp_auth_allow_login', $attributes) === FALSE) {
      return FALSE;
    }
  }
  return TRUE;
}

/**
 * Creates a new Drupal account for a SAML authenticated user.
 *
 * This function assumes that all validation has been performed on user values.
 *
 * @return object
 *   The newly create Drupal user object.
 */
function stanford_simplesamlphp_auth_user_register() {
  global $user;
  $authname = stanford_simplesamlphp_auth_get_authname();
  $username = stanford_simplesamlphp_auth_get_username();
  $email = stanford_simplesamlphp_auth_get_email();

  // Validate the name.
  if (!stanford_simplesamlphp_auth_valid_username($username)) {
    $username = stanford_simplesamlphp_auth_get_valid_username($username);
  }

  // Muy importanto.
  $roles = stanford_simplesamlphp_auth_rolepopulation(variable_get('stanford_simplesamlphp_auth_rolepopulation', ''));

  // Populate a new user object.
  $userinfo = array(
    'name' => $username,
    'pass' => user_password(),
    'init' => $email,
    'mail' => $email,
    'status' => 1,
    'access' => REQUEST_TIME,
    'roles' => $roles,
    'timezone' => drupal_get_user_timezone(),
  );

  // Save the user.
  $account = user_save(drupal_anonymous_user(), $userinfo);

  // Terminate if an error occurred during user_save().
  if (!$account) {
    throw new Exception(t("Error creating user account."));
  }

  // Add to the authmap table.
  user_set_authmaps($account, array("authname_stanford_simplesamlphp_auth" => $authname));

  // Allow others to alter the default roles of the new user.
  drupal_alter('stanford_simplesamlphp_auth_user_roles', $account);

  return $account;
}

/**
 * Logs an SAML-authenticated user into Drupal.
 *
 * @param object $ext_user
 *   The Drupal user object to be logged in.
 *
 * @throws Exception
 */
function stanford_simplesamlphp_auth_log_the_user_in($ext_user = NULL) {

  global $user;
  $authname = stanford_simplesamlphp_auth_get_authname();
  $saml = stanford_simplesamlphp_auth_get_saml_info();
  $source = $saml['source'];

  // Log user in.
  if (!is_null($ext_user)) {
    $user = $ext_user;
  }

  watchdog('user', 'Session opened for %name.', array('%name' => $user->name));
  // Update the user table timestamp noting user has logged in.
  // This is also used to invalidate one-time login links.
  $user->login = REQUEST_TIME;
  db_update('users')
    ->fields(array('login' => $user->login))
    ->condition('uid', $user->uid)
    ->execute();

  // Regenerate the session ID to prevent against session fixation attacks.
  // This is called before hook_user in case one of those functions fails
  // or incorrectly does a redirect which would leave the old session in place.
  drupal_session_regenerate();

  $edit = array();
  user_module_invoke('login', $edit, $user);

  // If for some reason the user account was not able to be created we should
  // let the end user know.
  if (empty($user->uid)) {
    // We were unable to register this new user on the site.
    // We let the user know about this, log an error, and redirect to home.
    drupal_set_message(t("We are sorry. While you have successfully authenticated, we were unable to create an account for you on this site. Please ask the site administrator to provision access for you."), 'error');
    watchdog('stanford_simplesamlphp_auth', 'Unable to register %authname using simplesamlphp_auth', array('%authname' => $authname), WATCHDOG_ERROR);
    $source->logout(base_path());
  }

}

/**
 * Denies non-SAML-authenticated access to the site for configured Drupal roles.
 */
function stanford_simplesamlphp_auth_moderate_local_login() {
  global $user;
  $saml = stanford_simplesamlphp_auth_get_saml_info();
  $source = $saml['source'];

  // If we forbid users from logging in using local accounts.
  if (!variable_get('stanford_simplesamlphp_auth_allowdefaultlogin', TRUE)) {
    // If the user has NOT been authenticated via simpleSAML...
    if (!$source->isAuthenticated()) {
      // FYI: Until Drupal issue #754560 is corrected this message will never be
      // seen by the user.
      drupal_set_message(t("We are sorry, users are not permitted to log in using local accounts."));
      // Destroy the user's session (log out).
      stanford_simplesamlphp_auth_destroy_drupal_session();
    }
  }
  // If we are allowing users to log in with local accounts.
  else {
    // If the user has NOT been authenticated via simpleSAML.
    if (!$source->isAuthenticated()) {
      // See if we limit this privilege to specified users.
      $str_users_allowed_local = variable_get('stanford_simplesamlphp_auth_allowdefaultloginusers', '');
      // See if we limit this privilege to specified roles.
      $array_roles_allowed_local = variable_get('stanford_simplesamlphp_auth_allowdefaultloginroles', array());

      // If user IDs or roles are specified, we let them in, but everyone else
      // gets logged out.
      if (drupal_strlen($str_users_allowed_local) || $array_roles_allowed_local) {

        // Convert the string into an array.
        // @todo Perform a test to make sure that only numbers, spaces, or
        // commas are in the string.
        $array_users_allowed_local = explode(',', $str_users_allowed_local);

        // If we still have something to work with.
        if (0 < count($array_users_allowed_local) || 0 < count($array_roles_allowed_local)) {
          // Log the user out of Drupal if:
          // 1) the current user's uid is NOT in the list of allowed uids
          // 2) or their role does not match and allowed mixed mode role.
          $match_roles = array_intersect(array_keys($user->roles), $array_roles_allowed_local);
          if (!in_array($user->uid, $array_users_allowed_local) && count($match_roles) == 0) {
            // User is logged into Drupal, but may not be logged into
            // simpleSAML.  If this is the case we're supposed to log the user
            // out of Drupal.

            // FYI: Until Drupal issue #754560 is corrected this message will
            // never be seen by the user.
            drupal_set_message(t("We are sorry, you are not permitted to log in using a local account."));

            // The least we can do is write something to the watchdog so someone
            // will know what's happening.
            watchdog('stanford_simplesamlphp_auth', 'User %name not authorized to log in using local account.', array('%name' => $user->name));

            stanford_simplesamlphp_auth_destroy_drupal_session();
          }
        }
      }
    }
  }
}

/**
 * Returns the SAML information static variable.
 *
 * @return array
 *   SAML information array. see autoload.
 */
function stanford_simplesamlphp_auth_get_saml_info() {
  return drupal_static("stanford_simplesamlphp_auth_autoload", NULL);
}

/**
 * Returns the SAML instance object: SimpleSAML_Configuration::getInstance()
 *
 * @return object
 *   SimpleSAML_Configuration::getInstance()
 */
function stanford_simplesamlphp_auth_get_saml_instance() {
  $saml = stanford_simplesamlphp_auth_get_saml_info();
  if (isset($saml['instance'])) {
    return $saml['instance'];
  }
  throw new Exception("SAML instance not available. Be sure to have autoloaded.");
}

/**
 * Returns the SAML instance object: SimpleSAML_Configuration::getInstance()
 *
 * @return object
 *   SimpleSAML_Auth_Simple->getAttributes()
 */
function stanford_simplesamlphp_auth_get_saml_attributes() {
  $saml = stanford_simplesamlphp_auth_get_saml_info();
  if (isset($saml['attributes'])) {
    return $saml['attributes'];
  }
  throw new Exception("SAML attributes not available. Be sure to have autoloaded.");
}

/**
 * Return any attributes provided by the SAML IDP.
 *
 * @param string $attribute
 *   (optional) The attribute whose value to return.  Can be skipped if all
 *   attribute values are requested.
 *
 * @return mixed
 *   If an attribute was provided, the value of the attribute is returned.
 *   Otherwise, an array of all attribute values is returned, keyed by
 *   attribute.
 */
function stanford_simplesamlphp_auth_get_attributes($attribute = NULL) {
  $attributes = stanford_simplesamlphp_auth_get_saml_attributes();
  if (is_null($attribute)) {
    return $attributes;
  }
  if (isset($attributes[$attribute])) {
    return $attributes[$attribute];
  }
  throw new Exception("Could not find attribute: " . $attribute . " in SAML attributes");
}

/**
 * Determine if the current user is authenticated through SAML.
 *
 * @return bool
 *   TRUE if the current user is authenticated through SAML.  FALSE otherwise.
 */
function stanford_simplesamlphp_auth_is_authenticated() {

  $saml = stanford_simplesamlphp_auth_get_saml_info();
  $source = $saml['source'];

  // Assume that the user isn't authenticated until proven otherwise.
  $authenticated = FALSE;

  // If the associated global variable exists, and the auth flag is set, note
  // it.
  if (isset($source) && $source->isAuthenticated()) {
    $authenticated = TRUE;
  }

  // Return the result.
  return $authenticated;
}

/**
 * Set a logged out cookie for user.
 *
 * @param string $type
 *   The key of the cookie message type.
 */
function stanford_simplesamlphp_auth_set_logged_out_cookie($type = "") {
  $name = "stanford_simplesamlphp_auth_message";
  $expire = time() + (60 * 60); // 1 hour.
  $path = base_path();
  $domain = stanford_simplesamlphp_auth_get_host();
  $value = "";
  $text = "";

  // Destroy any cookie first:
  setcookie($name, $value, -1, $path, $domain);

  switch ($type) {
    case "local_disabled":
      $text = "We're sorry, but local Drupal account login has been disabled.";
      $error_type = "error";
      break;

    case "not_authorized":
      $text = "We're sorry, but that account is not authorized for this website.";
      $error_type = "error";
      break;

    default:
      $value = "";
      $error_type = "";
  }

  if (empty($text)) {
    return;
  }

  $value = array($text, $error_type);
  $value = serialize($value);
  setcookie($name, $value, $expire, $path, $domain);
}

/**
 * Gets and processes the cookie in order to set a message for the logged out user.
 */
function stanford_simplesamlphp_auth_get_logged_out_cookie() {
  if (isset($_COOKIE['stanford_simplesamlphp_auth_message'])) {
    $path = "/";
    $domain = stanford_simplesamlphp_auth_get_host();
    $values = unserialize($_COOKIE['stanford_simplesamlphp_auth_message']);
    drupal_set_message(check_plain($values[0]), check_plain($values[1]));
    // Kill the cookie.
    setcookie("stanford_simplesamlphp_auth_message", "", -1, $path, $domain);
  }
}

/**
 * Helper function stolen from symphony.
 *
 * Gets and returns the domain name (host)
 */
function stanford_simplesamlphp_auth_get_host() {
  $possibleHostSources = array(
    'HTTP_X_FORWARDED_HOST',
    'HTTP_HOST',
    'SERVER_NAME',
    'SERVER_ADDR',
  );
  $sourceTransformations = array(
    "HTTP_X_FORWARDED_HOST" => function($value) {
      $elements = explode(',', $value);
      return trim(end($elements));
    }
  );

  $host = '';
  foreach ($possibleHostSources as $source) {
    if (!empty($host)) {
      break;
    }

    if (empty($_SERVER[$source])) {
      continue;
    }

    $host = $_SERVER[$source];
    if (array_key_exists($source, $sourceTransformations)) {
      $host = $sourceTransformations[$source]($host);
    }
  }

  // Remove port number from host.
  $host = preg_replace('/:\d+$/', '', $host);

  return trim($host);
}

/**
 * Validates a name for a user.
 *
 * @param string $name
 *   The string name.
 *
 * @return bool
 *   True if valid name and not already taken.
 */
function stanford_simplesamlphp_auth_valid_username($name = "") {

  // An empty response means valid name.
  $error = user_validate_name($name);
  if (!empty($error)) {
    return FALSE;
  }

  // Check if username exists in db.
  $found = (bool) db_select('users')
    ->fields('users', array('uid'))
    ->condition('name', $name)
    ->range(0, 1)
    ->execute()
    ->fetchField();

  if ($found) {
    return FALSE;
  }

  // Name string checks out.
  return TRUE;
}

/**
 * Generates a unique name for the user if it already exists by appending an integer.
 *
 * @param string $name
 *   The name.
 *
 * @return mixed
 *   Could be anything.
 */
function stanford_simplesamlphp_auth_get_valid_username($name) {
  $trys = 1;
  $name_clone = $name . $trys;
  while (!stanford_simplesamlphp_auth_valid_username($name_clone)) {
    $trys++;
    $name_clone = $name . $trys;
  }

  return $name_clone;
}

/**
 * Checks if authentication via SimpleSAMLphp should be activated.
 *
 * @param bool $show_inactive_msg
 *   Whether to display the "module not activated" message.
 *
 * @return bool
 *   TRUE if simplesamlphp_auth is enabled.
 */
function stanford_simplesamlphp_auth_is_enabled($show_inactive_msg = FALSE) {
  global $user;

  $failure = NULL;
  $is_activated = variable_get('stanford_simplesamlphp_auth_activate');
  $basedir = variable_get('stanford_simplesamlphp_auth_installdir', '/usr/share/simplesamlphp');

  if ($is_activated) {
    // Make sure we know where SimpleSAMLphp is.
    if (!file_exists($basedir)) {
      $failure = t('SimpleSAMLphp could not be found at %basedir . The simplesamlphp_auth module cannot function until the path to the local SimpleSAMLphp instance is configured.', array('%basedir' => $basedir));
      watchdog('stanford_simplesamlphp_auth', $failure, NULL, WATCHDOG_WARNING);
    }

  }
  else {
    $failure = t('SimpleSAMLphp auth is not yet activated.');
  }

  // If there were no failures, then it should be activated.
  if (!$failure) {
    return TRUE;
  }
  else {

    // Communicate but don't be too annoying.
    if ($show_inactive_msg && (1 == $user->uid || user_access('access administration pages')) && (preg_match('/admin\/people/', request_uri()) || preg_match('/admin\/modules/', request_uri()) || preg_match('/admin\/config/', request_uri()))) {
      drupal_set_message($failure);
    }
  }
  return FALSE;
}

/**
 * Gets the authname attribute from the SAML assertion.
 *
 * @return string
 *   The authname attribute.
 *
 * @throws Exception
 *   Throws an exception if no valid unique id attribute is set in SAML session.
 */
function stanford_simplesamlphp_auth_get_authname() {
  $attributes = stanford_simplesamlphp_auth_get_saml_attributes();

  if (isset($attributes[variable_get('stanford_simplesamlphp_auth_unique_id', 'eduPersonPrincipalName')])) {
    return $attributes[variable_get('stanford_simplesamlphp_auth_unique_id', 'eduPersonPrincipalName')][0];
  }
  else {
    throw new Exception(t('Error in simplesamlphp_auth.module: no valid unique id attribute set.'));
  }

}

/**
 * Gets the username attribute from the SAML assertion.
 *
 * @return string
 *   The username attribute.
 *
 * @throws Exception
 *   Throws an exception if no valid unique id attribute is set in SAML session.
 */
function stanford_simplesamlphp_auth_get_username() {
  $attributes = stanford_simplesamlphp_auth_get_saml_attributes();

  if (isset($attributes[variable_get('stanford_simplesamlphp_auth_user_name', 'displayName')])) {
    return $attributes[variable_get('stanford_simplesamlphp_auth_user_name', 'displayName')][0];
  }
  else {
    throw new Exception(t('Error in simplesamlphp_auth.module: no valid unique id attribute set.'));
  }

}

/**
 * Gets the mail attribute.
 *
 * @return string
 *   The mail attribute.
 */
function stanford_simplesamlphp_auth_get_email() {
  $attributes = stanford_simplesamlphp_auth_get_saml_attributes();

  if (isset($attributes[variable_get('stanford_simplesamlphp_auth_mailattr', 'mail')])) {
    return $attributes[variable_get('stanford_simplesamlphp_auth_mailattr', 'mail')][0];
  }
  // If no valid mail attribute, cheat, and look for the sunet.
  elseif (isset($attributes['uid'])) {
    return $attributes['uid'][0] . "@stanford.edu";
  }
  else {
    throw new Exception(t('Error in stanford_simplesamlphp_auth.module: No valid mail attribute set.'));
  }

}

/**
 * See if the user has an authmap record for simplesamlphp_auth.
 */
function stanford_simplesamlphp_auth_user_has_authmap($authname) {
  $authmaps = user_get_authmaps($authname);
  $return = 0;

  if (is_array($authmaps)) {
    $return = in_array('stanford_simplesamlphp_auth', array_keys($authmaps));
  }

  return $return;
}

/**
 * Logs out a user who has an active Drupal session but not with simpleSAML.
 */
function stanford_simplesamlphp_auth_destroy_drupal_session() {
  module_load_include('pages.inc', 'user');
  user_logout();
}
