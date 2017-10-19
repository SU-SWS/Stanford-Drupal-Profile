<?php
/**
 * @file
 * Hooks for simpleSAMLphp Authentication module.
 */

/**
 * Allows the use of custom logic to alter the roles assigned to a user.
 *
 * Whenever a user's roles are evaluated this hook will be called, allowing
 * custom logic to be used to alter or even completely replace the roles
 * evaluated.
 *
 * @param array &$roles
 *   The roles that have been selected for the current user
 *   by the role evaluation process, in the format array($rid => $rid)
 */
function hook_stanford_simplesamlphp_auth_user_roles_alter(&$roles) {
  global $stanford_simplesamlphp_auth_saml_attributes;
  if (isset($stanford_simplesamlphp_auth_saml_attributes['roles'])) {
    // The roles provided by the IdP.
    $sso_roles = $stanford_simplesamlphp_auth_saml_attributes['roles'];

    // Match role names in the saml attributes to local role names.
    $user_roles = array_intersect(user_roles(), $sso_roles);

    foreach (array_keys($user_roles) as $rid) {
      $roles[$rid] = $rid;
    }
  }
}

/**
 * Allows other modules to decide whether user with the given set of
 * attributes is allowed to log in via SSO or not.
 *
 * Each implementation should take care of displaying errors, there is no
 * message implementation at hook invocation. Implementations should return
 * a boolean indicating the success of the access check. Access will be denied
 * if any implementations return FALSE.
 *
 * @param array $attributes
 *   An array of attributes.
 *
 * @return bool
 *   True or false.
 */
function hook_stanford_simplesamlphp_auth_allow_login(array $attributes) {
  if (in_array('student', $attributes)) {
    return FALSE;
  }
  else {
    return TRUE;
  }
}

/**
 * Allows other modules to perform an additional authentication step prior
 * to logging in given the set of attributes and user object.
 *
 * Each implementation should take care of displaying errors or redirecting
 * to appropriate error pages, there is no message implementation at hook
 * invocation.
 *
 * @param array $attributes
 *   An array of attributes.
 * @param object $ext_user
 *   The user object for the current user.
 */
function hook_stanford_simplesamlphp_auth_pre_login(array $attributes, $ext_user) {
  // Disallow students from logging in with a specific role.
  if ($ext_user['roles'] == '3' && (in_array('student', $attributes))) {
    drupal_goto('some-error-page-path');
    exit();
  }
}
