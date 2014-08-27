<?php

/*
 * Implementation of hook_install_tasks().
 */

function stanford_install_tasks($install_state) {
  $tasks['stanford_sites_tasks'] = array(
    'display_name' => st('Do configuration tasks for the Stanford Sites hosting environment'),
    'display' => FALSE,
    'type' => 'normal',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
  );

  return $tasks;
}

function stanford_sites_tasks() {
  /**
   * General stuff.
   */
  /**
   * Configure CKEditor and WYSIWYG.
   */

  // Create configuration for CKEditor
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
  'block_formats' => 'p','address','pre','h2','h3','h4','h5','h6',
  'css_setting' => 'theme',
  'css_path' => '',
  'css_classes' => ''
  ));

  // Add CKEditor to wysiwyg
  $query = db_insert('wysiwyg')
    ->fields(array(
      'format' => 'filtered_html',
      'editor' => 'ckeditor',
      'settings' => $ckeditor_configuration,
    ));
  $query->execute();

  // Set errors only to go to the log
  variable_set('error_level', 0);

  /**
   * File system settings.
   */

  //Set private directory
  $private_directory = 'sites/default/files/private';
  variable_set('file_private_path', $private_directory);
  //system_check_directory() is expecting a $form_element array
  $element = array();
  $element['#value'] = $private_directory;
  //check that the public directory exists; create it if it does not
  system_check_directory($element);

  //Set public directory
  $public_directory = 'sites/default/files';
  variable_set('file_public_path', $public_directory);
  //Set default scheme to public file handling
  variable_set('file_default_scheme', 'public');
  //system_check_directory() is expecting a $form_element array
  $element = array();
  $element['#value'] = $public_directory;
  $element['#name'] = 'file_public_path';
  //check that the public directory exists; create it if it does not
  system_check_directory($element);

  //Enable the stanford_sites_helper module and the webauth module
  //Do this now rather than in .info file because it's looking for the administrator role and errors out otherwise
  module_enable(array('stanford_sites_helper', 'webauth'));
  
  //Make the Seven admin theme use our favicon
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
  
  //Make the default pathauto setting be [node:title]
  $pathauto_node_pattern = '[node:title]';
  variable_set('pathauto_node_pattern', $pathauto_node_pattern);


  stanford_sites_add_webauth_user(
    variable_get('stanford_sites_requester_sunetid'),
    variable_get('stanford_sites_requester_name'),
    variable_get('stanford_sites_requester_email')
  );

    
  /**
   * Tasks for all sites on the service
   */
  module_disable(array('update'));
  module_enable(array('stanford_sites_systemtools'));

  /**
   * Set temp file directory.
   */
  $tmpdir = variable_get('stanford_sites_tmpdir', file_directory_temp());
  variable_set('file_temporary_path', $tmpdir);
  //system_check_directory() is expecting a $form_element array
  $element = array();
  $element['#value'] = $tmpdir;
  //check that the temp directory exists; create it if it does not
  system_check_directory($element);

  /**
   *  Departments' preferred theme is Stanford Wilbur.
   *  Groups' and individuals' preferred theme is Open Framework.
   *  Official groups can have the Stanford Wilbur theme enabled by ITS.
   */
  $org_type = variable_get('stanford_sites_org_type');
  if ($org_type == 'dept') {
    $preferred_themes = array(
      'theme_default' => 'stanford_wilbur',
      'admin_theme' => 'seven',
      'node_admin_theme' => 1,
      'open_framework',
      'stanford_framework',
      'stanford_jordan',
    );
    theme_enable($preferred_themes);
    foreach ($preferred_themes as $var => $theme) {
      if (!is_numeric($var)) {
        variable_set($var, $theme);
      }
    }
  } else {
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
 * Checks to see if the current Drupal install is on one of the Stanford Sites 
 * hosting servers. Note: no longer using this, but keeping the code because arriving
 * at a reliable test took some work.
 * 
 * @return
 *   TRUE if it is; FALSE if it isn't.
 */
function stanford_sites_hosted() {
  //This directory only should exist on the sites-* servers
  $dir = "/etc/drupal-service";
  //Check if it exists and is a directory
  if(file_exists($dir) && is_dir($dir)) {
    return TRUE;
  }
  else{
    return FALSE;
  }
}


/**
 * Add a WebAuth user 
 * 
 */
function stanford_sites_add_webauth_user($sunet, $name = '', $email = '') {
  $sunet = strtolower(trim($sunet));

  if (empty($sunet)) {
    watchdog('Stanford Profile','Could not create user. No SUNetID available.');
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
    $account = new stdClass;
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

    // hide Local Drupal user login block. User 1 can still login from /user
    variable_set(webauth_allow_local, 0);

    watchdog('Stanford Profile','Created user: %user', array('%user' => $name));    
  }
  else {
    watchdog('Stanford Profile','Could not create duplicate user: %user', array('%user' => $name)); 
  }
}
