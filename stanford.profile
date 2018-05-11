<?php

/**
 * Implementation of hook_install_tasks().
 */
function stanford_install_tasks($install_state) {

  // Detect which environment we are running and add
  // those specific tasks to the installation.
  $environment = _stanford_detect_environment();

  // Any and all environment tasks go here.
  $tasks['stanford_profile_tasks'] = array(
    'display_name' => st('Do configuration tasks for the Stanford Sites hosting environment'),
    'display' => FALSE,
    'type' => 'normal',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
  );

  // ACSF Specific Tasks go here.
  if ($environment == "acsf") {
    $tasks['stanford_acsf_tasks'] = array(
      'display_name' => st('Do configuration tasks for the ACSF hosting environment'),
      'display' => FALSE,
      'type' => 'normal',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    );
  }

  // Anchorage Specific Tasks go here.
  if ($environment == "anchorage") {
    $tasks['stanford_anchorage_tasks'] = array(
      'display_name' => st('Do configuration tasks for the Anchorage hosting environment'),
      'display' => FALSE,
      'type' => 'normal',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    );
  }

  // Sites specific tasks go here.
  // ACSF Specific Tasks go here.
  if ($environment == "sites") {
    $tasks['stanford_sites_tasks'] = array(
      'display_name' => st('Do configuration tasks for the Stanford Sites hosting environment'),
      'display' => FALSE,
      'type' => 'normal',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    );
  }

  // Clean up functions for all of them.
  $tasks['stanford_install_finished'] = array(
    'display_name' => st('Clean up before finishing'),
    'display' => FALSE,
    'type' => 'normal',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
  );

  return $tasks;
}

/**
 * Installation tasks for any environment.
 */
function stanford_profile_tasks() {

  // Enable the stanford_sites_helper module
  // Do this now rather than in .info file because install looking for the
  // administrator role and errors out otherwise.
  module_enable(array('stanford_sites_helper'));
  module_enable(array('stanford_sites_systemtools'));
  $remove = array('update', 'comment');
  module_disable($remove);
  drupal_uninstall_modules($remove);

  // Create configuration for CKEditor.
  $ckeditor_configuration = serialize(array(
  'default' => 1,
  'user_choose' => 0,
  'show_toggle' => 1,
  'theme' => 'advanced',
  'language' => 'en',
  'buttons' => array(
    'default' => array(
      'Bold' => 1,
      'Italic' => 1,
      'BulletedList' => 1,
      'NumberedList' => 1,
      'Outdent' => 1,
      'Indent' => 1,
      'Undo' => 1,
      'Redo' => 1,
      'Link' => 1,
      'Unlink' => 1,
      'Blockquote' => 1,
      'Cut' => 1,
      'Copy' => 1,
      'Paste' => 1,
      'PasteText' => 1,
      'PasteFromWord' => 1,
      'Format' => 1,
      'SelectAll' => 1,
    ),
  ),
  'toolbar_loc' => 'top',
  'toolbar_align' => 'left',
  'path_loc' => 'bottom',
  'resizing' => 1,
  'verify_html' => 1,
  'preformatted' => 0,
  'convert_fonts_to_spans' => 1,
  'remove_linebreaks' => 1,
  'apply_source_formatting' => 1,
  'paste_auto_cleanup_on_paste' => 1,
  'block_formats' => [
    'p',
    'address',
    'pre',
    'h2',
    'h3',
    'h4',
    'h5',
    'h6'
  ],
  'css_setting' => 'theme',
  'css_path' => '',
  'css_classes' => ''
  ));

  // Add CKEditor to wysiwyg.
  $query = db_insert('wysiwyg')
    ->fields(array(
      'format' => 'filtered_html',
      'editor' => 'ckeditor',
      'settings' => $ckeditor_configuration,
    ));
  $query->execute();

  // Set errors only to go to the log.
  variable_set('error_level', 0);

  // Make the Seven admin theme use our favicon.
  $theme_seven_settings = array(
    'toggle_logo' => 1,
    'toggle_name' => 1,
    'toggle_slogan' => 1,
    'toggle_node_user_picture' => 1,
    'toggle_comment_user_picture' => 1,
    'toggle_comment_user_verification' => 1,
    'toggle_favicon' => 1,
    'toggle_main_menu' => 1,
    'toggle_secondary_menu' => 1,
    'default_logo' => 1,
    'logo_path' => '',
    'logo_upload' => '',
    'default_favicon' => 0,
    'favicon_path' => 'profiles/stanford/favicon.ico',
    'favicon_upload' => '',
    'favicon_mimetype' => 'image/vnd.microsoft.icon',
  );
  variable_set('theme_seven_settings', $theme_seven_settings);

  // Make the default pathauto setting be [node:title].
  $pathauto_node_pattern = '[node:title]';
  variable_set('pathauto_node_pattern', $pathauto_node_pattern);

  // Departments' preferred theme is Stanford Wilbur.
  // Groups' and individuals' preferred theme is Open Framework.
  // Official groups can have the Stanford Wilbur theme enabled by ITS.
  $org_type = variable_get('stanford_sites_org_type');
  if ($org_type == 'dept') {
    $preferred_themes = array(
      'theme_default' => 'stanford_wilbur',
      'admin_theme' => 'seven',
      'node_admin_theme' => 1,
      'open_framework' => NULL,
      'stanford_framework' => NULL,
      'stanford_jordan' => NULL,
    );
    theme_enable($preferred_themes);
    foreach ($preferred_themes as $var => $theme) {
      if (!is_numeric($var)) {
        variable_set($var, $theme);
      }
    }
  }
  else {
    $preferred_themes = array(
      'theme_default' => 'stanford_light',
      'admin_theme' => 'seven',
      'node_admin_theme' => 1,
      'open_framework'
    );
    theme_enable($preferred_themes);
    foreach ($preferred_themes as $var => $theme) {
      if (!is_numeric($var)) {
        variable_set($var, $theme);
      }
    }
  }

}

/**
 * Installation tasks for acsf environment.
 */
function stanford_acsf_tasks() {

  // Enable the environment dependant modules.
  $enable = array(
    'acsf',
    'acsf_helper',
    'paranoia',
    'newrelic_appname',
    'stanford_ssp',
    'stanford_saml_block'
  );
  module_enable($enable);

  // Remove this dependency because it conflicts with our login.
  $modules = array('acsf_openid', 'openid');
  module_disable($modules, FALSE);
  drupal_uninstall_modules($modules, FALSE);

  // Change some configuration in the saml paths:
  $ah_stack = getenv('AH_SITE_GROUP') ?? 'cardinald7';
  $ah_env = getenv('AH_SITE_ENVIRONMENT') ?? '02test';
  $pathtosimplesaml = "/var/www/html/" . $ah_stack . "." . $ah_env . "/simplesamlphp";
  variable_set('stanford_simplesamlphp_auth_installdir', $pathtosimplesaml);

  // Add an admin user so that stanford_ssp can pick it up.
  module_load_include('inc', 'stanford_simplesamlphp_auth', 'stanford_simplesamlphp_auth');
  stanford_sites_add_admin_user(
    variable_get('stanford_sites_requester_sunetid'),
    variable_get('stanford_sites_requester_name'),
    variable_get('stanford_sites_requester_email')
  );
}

/**
 * Installation tasks for anchorage environment.
 */
function stanford_anchorage_tasks() {
  // Set private and public file directory.
  stanford_profile_default_file_dir_settings();

  $auth_method = variable_get('stanford_sites_auth_method', 'webauth');
  if ($auth_method == 'simplesamlphp') {
    module_enable(array('simplesamlphp_auth', 'stanford_ssp'));
    // Add an admin user so that stanford_ssp can pick it up.
    stanford_sites_add_admin_user(
      variable_get('stanford_sites_requester_sunetid'),
      variable_get('stanford_sites_requester_name'),
      variable_get('stanford_sites_requester_email')
    );
  }

  // S3 config.
  $enable_s3fs = variable_get('enable_s3fs', 0);
  if ($enable_s3fs == 1) {
    module_enable(array('s3fs'));
    // Leave file_default_scheme as "public", as we are configuring s3fs to take
    // over the public file system, below.
    // variable_set('file_default_scheme', 's3');.
    variable_set('s3fs_use_https', 1);
    variable_set('s3fs_cache_control_header', 'max-age=1209600');
    variable_set('s3fs_use_s3_for_public', 1);
    variable_set('s3fs_use_s3_for_private', 1);
  }

}

/**
 * Installation tasks for sites environment.
 */
function stanford_sites_tasks() {
  // Set private and public file directory.
  stanford_profile_default_file_dir_settings();

  $auth_method = variable_get('stanford_sites_auth_method', 'webauth');
  if ($auth_method == 'webauth') {
    module_enable(array('webauth'));
    module_enable(array('stanford_afs_quota'));

    stanford_sites_add_webauth_user(
      variable_get('stanford_sites_requester_sunetid'),
      variable_get('stanford_sites_requester_name'),
      variable_get('stanford_sites_requester_email')
    );
  }

}

/**
 * Set public, private, and tmp file directory for default install.
 *
 * ACSF does not use these settings and has them hard-coded in to their
 * environment so they do not need to be set.
 */
function stanford_profile_default_file_dir_settings() {

  // Set private directory.
  $private_directory = 'sites/default/files/private';
  variable_set('file_private_path', $private_directory);
  // system_check_directory() is expecting a $form_element array.
  $element = array();
  $element['#value'] = $private_directory;
  // Check that the public directory exists; create it if it does not.
  system_check_directory($element);

  // Set public directory.
  $public_directory = 'sites/default/files';
  variable_set('file_public_path', $public_directory);
  // Set default scheme to public file handling.
  variable_set('file_default_scheme', 'public');
  // system_check_directory() is expecting a $form_element array.
  $element = array();
  $element['#value'] = $public_directory;
  $element['#name'] = 'file_public_path';
  // Check that the public directory exists; create it if it does not.
  system_check_directory($element);

  // Set temp file directory.
  $tmpdir = variable_get('stanford_sites_tmpdir', file_directory_temp());
  variable_set('file_temporary_path', $tmpdir);
  // system_check_directory() is expecting a $form_element array.
  $element = array();
  $element['#value'] = $tmpdir;
  // Check that the temp directory exists; create it if it does not.
  system_check_directory($element);
}

/**
 * Add a admin user.
 *
 * Adds an admin user when installing on non-sites platforms.
 *
 * @param string $sunet
 *   Sunet id.
 * @param string $name
 *   Person's full name.
 * @param string $email
 *   The email address. Usually sunetid + stanford.edu.
 */
function stanford_sites_add_admin_user($sunet, $name = '', $email = '') {
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

    $admin_role = user_role_load_by_name('administrator');
    $account->roles = array(
      DRUPAL_AUTHENTICATED_RID => TRUE,
      $admin_role->rid => TRUE
    );
    $account->timezone = variable_get('date_default_timezone', '');
    $account = user_save($account);
    watchdog('Stanford Profile', 'Created user: %user', array('%user' => $name));
  }
  else {
    watchdog('Stanford Profile', 'Could not create duplicate user: %user', array('%user' => $name));
  }
}

/**
 * Add a WebAuth user.
 *
 * Adds a webauth user when installing on the sites platform.
 *
 * @param string $sunet
 *   Sunet id.
 * @param string $name
 *   Person's full name.
 * @param string $email
 *   The email address. Usually sunetid + stanford.edu.
 */
function stanford_sites_add_webauth_user($sunet, $name = '', $email = '') {
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
    $account->roles = array(
      DRUPAL_AUTHENTICATED_RID => TRUE,
      $sunet_role->rid => TRUE,
      $admin_role->rid => TRUE
    );
    $account->timezone = variable_get('date_default_timezone', '');
    $account = user_save($account);

    user_set_authmaps($account, array('authname_webauth' => $sunet . '@stanford.edu'));

    // Hide Local Drupal user login block. User 1 can still login from /user.
    variable_set(webauth_allow_local, 0);

    watchdog('Stanford Profile', 'Created user: %user', array('%user' => $name));
  }
  else {
    watchdog('Stanford Profile', 'Could not create duplicate user: %user', array('%user' => $name));
  }
}

/**
 * Final installation task.
 */
function stanford_install_finished() {
  module_enable(array('stanford_page'));
  features_revert_module('stanford_page');
  drupal_flush_all_caches();
  watchdog("stanford", "Finished reverting stanford_page and flushing caches.");
}

/**
 * Returns a string representing the environment being installed on.
 *
 * @return string
 *   The string name of the environment being installed.
 */
function _stanford_detect_environment() {

  // Check for ACQUIA environment var.
  $is_ah = getenv('AH_SITE_ENVIRONMENT');
  if (!empty($is_ah)) {
    return 'acsf';
  }

  // Check for sites environment
  // This directory only should exist on the sites-* servers.
  $dir = "/etc/drupal-service";
  // Check if it exists and is a directory.
  if (file_exists($dir) && is_dir($dir)) {
    return 'sites';
  }

  // Check for anchorage IDP.
  if (getenv('ENV_IDP') == "https://idpproxy.anchorage.stanford.edu/idp") {
    return 'anchorage';
  }

  // Default to local.
  return 'local';
}

/**
 * Implements hook_system_info_alter().
 *
 * @param array $info
 *   The .info file contents, passed by reference so that it can be altered.
 * @param array $file
 *   Full information about the module or theme, including $file->name, and
 *   $file->filename.
 * @param string $type
 *   Either 'module' or 'theme', depending on the type of .info file that was
 *   passed.
 */
function stanford_system_info_alter(&$info, $file, $type) {
  // Disallow a few themes from being enabled by hiding them from the UI.
  if (
    isset($info['project']) &&
    ($info['project'] == 'stanford_framework' ||
    $info['project'] == 'stanford_jordan' ||
    $info['project'] == 'stanford_wilbur' ||
    $info['project'] == 'cube' ||
    $info['project'] == 'rubik' ||
    $info['project'] == 'tao')
  ) {
    $info['hidden'] = TRUE;
  }

  // Disallow any jumpstart modules.
  if (
    isset($info['project']) &&
    (preg_match("/^stanford_jumpstart/", $info['project']) ||
    preg_match("/^stanford_jsl/", $info['project']) ||
    preg_match("/^stanford_jse/", $info['project']) ||
    preg_match("/^stanford_jsplus/", $info['project']) ||
    preg_match("/^stanford_jsa/", $info['project']))
  ) {
    $info['hidden'] = TRUE;
    return;
  }

  // Hide some items by name.
  if (
    isset($info['name']) &&
    (preg_match("/Stanford Site/", $info['name']) ||
    preg_match("/Stanford Jumpstart/", $info['name']) ||
    preg_match("/VPSA/", $info['name']) ||
    preg_match("/Stanford JSA/", $info['name']) ||
    preg_match("/JSE/", $info['name']))
  ) {
    $info['hidden'] = TRUE;
    return;
  }
}
