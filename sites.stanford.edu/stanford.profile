<?php
﻿/**
 * Return an array of the modules to be enabled when this profile is installed.
 *
 * @return
 *   An array of modules to enable.
 */
function stanford_profile_modules() {
  $modules = array(
    'auto_nodetitle',
    'block',
    'color',
    'content',
    'css_injector',
    'date_api',
    'date_timezone',
    'dblog',
    'email',
    'features',
    'fieldgroup',
    'filefield',
    'filter',
    'help',
    'imagefield',
    'insert',
    'jquery_ui',
    'link',
    'menu',
    'node',
    'nodeformcols',
    'nodereference',
    'number',
    'optionwidgets',
    'path',
    'pathauto',
    'pathologic',
    'semanticviews',
    'su_it_services',
    'system',
    'taxonomy',
    'text',
    'token',
    'upload',
    'user',
    'userreference',
    'views',
    'views_ui',
    'wysiwyg',
  );

  // Enables webauth module if requested.
  $fields = get_stanford_installer();
  if ($fields['sd_enable_webauth'] == 'on') {
    array_push($modules, 'webauth');
  }
  
  return $modules;
}



/**
 * Return a description of the profile for the initial installation screen.
 *
 * @return
 *   An array with keys 'name' and 'description' describing this profile,
 *   and optional 'language' to override the language selection for
 *   language-specific profiles.
 */
function stanford_profile_details() {
  return array(
    'name' => 'Drupal at Stanford',
    'description' => 'Select this profile to enable some basic Drupal functionality and the default theme.'
    'language' => 'en',
  );
}

/**
 * Return a list of tasks that this profile supports.
 *
 * @return
 *   A keyed array of tasks the profile will perform during
 *   the final stage. The keys of the array will be used internally,
 *   while the values will be displayed to the user in the installer
 *   task list.
 */
function stanford_profile_task_list() {
}

/**
 * Perform any final installation tasks for this profile.
 *
 * The installer goes through the profile-select -> locale-select
 * -> requirements -> database -> profile-install-batch
 * -> locale-initial-batch -> configure -> locale-remaining-batch
 * -> finished -> done tasks, in this order, if you don't implement
 * this function in your profile.
 *
 * If this function is implemented, you can have any number of
 * custom tasks to perform after 'configure', implementing a state
 * machine here to walk the user through those tasks. First time,
 * this function gets called with $task set to 'profile', and you
 * can advance to further tasks by setting $task to your tasks'
 * identifiers, used as array keys in the hook_profile_task_list()
 * above. You must avoid the reserved tasks listed in
 * install_reserved_tasks(). If you implement your custom tasks,
 * this function will get called in every HTTP request (for form
 * processing, printing your information screens and so on) until
 * you advance to the 'profile-finished' task, with which you
 * hand control back to the installer. Each custom page you
 * return needs to provide a way to continue, such as a form
 * submission or a link. You should also set custom page titles.
 *
 * You should define the list of custom tasks you implement by
 * returning an array of them in hook_profile_task_list(), as these
 * show up in the list of tasks on the installer user interface.
 *
 * Remember that the user will be able to reload the pages multiple
 * times, so you might want to use variable_set() and variable_get()
 * to remember your data and control further processing, if $task
 * is insufficient. Should a profile want to display a form here,
 * it can; the form should set '#redirect' to FALSE, and rely on
 * an action in the submit handler, such as variable_set(), to
 * detect submission and proceed to further tasks. See the configuration
 * form handling code in install_tasks() for an example.
 *
 * Important: Any temporary variables should be removed using
 * variable_del() before advancing to the 'profile-finished' phase.
 *
 * @param $task
 *   The current $task of the install system. When hook_profile_tasks()
 *   is first called, this is 'profile'.
 * @param $url
 *   Complete URL to be used for a link or form action on a custom page,
 *   if providing any, to allow the user to proceed with the installation.
 *
 * @return
 *   An optional HTML string to display to the user. Only used if you
 *   modify the $task, otherwise discarded.
 */
function stanford_profile_tasks(&$task, $url) {

  // Change the authenticated user role from rid 3 (due to mysql server
  //  replication and autoincrement value) to 2.
  adjust_authuser_rid();

  // Insert default user-defined node types into the database. For a complete
  // list of available node type attributes, refer to the node type API
  // documentation at: http://api.drupal.org/api/HEAD/function/hook_node_info.
  $types = array(
    array(
      'type' => 'page',
      'name' => st('Page'),
      'module' => 'node',
      'description' => st("A <em>page</em> is a simple method for creating and displaying information that rarely changes, such as an \"About us\" section of a website."),
      'custom' => TRUE,
      'modified' => TRUE,
      'locked' => FALSE,
      'help' => '',
      'min_word_count' => '',
    ),
  );

  foreach ($types as $type) {
    $type = (object) _node_type_set_defaults($type);
    node_type_save($type);
  }

  // Default page to not be promoted, revisions enabled, and have comments disabled.
  variable_set('node_options_page', array('status', 'revision'));
  variable_set('comment_page', COMMENT_NODE_DISABLED);

  /**
   * File System
   */

  // Set to public file downloads.
  variable_set('file_downloads', 1);

  // Default upload quotas
  $uploadsize_default = 2;
  $usersize_default = 100;
  variable_set('upload_uploadsize_default', $uploadsize_default);
  variable_set('upload_usersize_default', $usersize_default);

  /**
   * Security
   */

  // Remove password from emails that get sent by the system
  $user_mail_register_admin_created_body = "!username,\n\nA site administrator at !site has created an account for you. You may now log in to !login_uri using the following username and password:\n\nusername: !username\n\n\nYou may also log in by clicking on this link or copying and pasting it in your browser:\n\n!login_url\n\nThis is a one-time login, so it can be used only once.\n\nAfter logging in, you will be redirected to !edit_uri so you can change your password.\n\n\n--  !site team";
  variable_set('user_mail_register_admin_created_body', $user_mail_register_admin_created_body);
  
  $user_mail_register_no_approval_required_body = "!username,\n\nThank you for registering at !site. You may now log in to !login_uri using the following username and password:\n\nusername: !username\n\n\nYou may also log in by clicking on this link or copying and pasting it in your browser:\n\n!login_url\n\nThis is a one-time login, so it can be used only once.\n\nAfter logging in, you will be redirected to !edit_uri so you can change your password.\n\n\n--  !site team";
  variable_set('user_mail_register_no_approval_required_body', $user_mail_register_no_approval_required_body);
  
  // User registration - only site administrators can create new user accounts
  $user_register = 0;
  variable_set('user_register', $user_register);

  /**
   * Display elements
   */

  // Don't display date and author information for page nodes by default.
  $theme_settings = variable_get('theme_settings', array());
  $theme_settings['toggle_node_info_page'] = FALSE;
  variable_set('theme_settings', $theme_settings);
    
  // Remove "Powered by Drupal" block from footer
  $block_module = 'system';
  db_query("UPDATE {blocks} SET status = %d WHERE module = '%s' AND delta = %d", 0, $block_module, 0);

  // Error reporting
  $error_level = 0;
  variable_set('error_level', $error_level);
  
  /**
   * Theming
   */

  // Enable the admin theme, and set it for content editing as well
  $admin_theme = 'rubik';
  db_query("UPDATE {system} SET status = 1 WHERE type = 'theme' and name = ('%s')", $admin_theme);
  variable_set('admin_theme', $admin_theme);
  variable_set('node_admin_theme', $admin_theme);
  
  // If the organization is a department, enable the department themes.
  if ($fields['org_type'] == 'dept') {
    variable_set('su_department_themes', 1);
  }

  // Departments' preferred theme is Stanford Modern
  // Groups and individuals' preferred theme is Stanford Basic
  // Official groups can have the Stanford Modern theme enabled by ITS
  if ($fields['org_type'] == 'dept') {
    $preferred_themes = array('stanfordmodern', 'garland');
  } else {
    $preferred_themes = array('stanfordbasic', 'garland');
  }

  // Install the preferred theme
  $themes = system_theme_data();
  foreach ($preferred_themes as $theme) {
    if (array_key_exists($theme, $themes)) {
      system_initialize_theme_blocks($theme);
      db_query("UPDATE {system} SET status = 1 WHERE type = 'theme' and name = ('%s')", $theme);
      variable_set('theme_default', $theme);
      break;
    }
  }

  // Enable the admin theme, and set it for content editing as well
  $admin_theme = 'rubik';
  db_query("UPDATE {system} SET status = 1 WHERE type = 'theme' and name = ('%s')", $admin_theme);
  variable_set('admin_theme', $admin_theme);
  variable_set('node_admin_theme', $admin_theme);

  /**
   * Date and time settings
   */

  // Disable user-configurable timezones by default
  $user_configurable_timezones = 0;
  variable_set('configurable_timezones', $user_configurable_timezones);
  
  // Set default timezone
  $default_timezone_name = "America/Los_Angeles";
  $default_timezone_offset = -28800;
  variable_set('date_default_timezone_name', $default_timezone_name);
  variable_set('date_default_timezone', $default_timezone_offset);

  /**
   * Input formats
   */

  // Retrieve the ID of the Filtered HTML format (on replicated servers we can't trust it to be 1)
  $filtered_html_id = db_result(db_query("SELECT format FROM {filter_formats} WHERE name = 'Filtered HTML'"));

  // Set the default input format to the Filtered HTML version
  variable_set('filter_default_format', $filtered_html_id);

  // Create configuration for CKEditor
  $ckeditor_configuration = serialize(array (
    'default' => 1,
    'user_choose' => 0,
    'show_toggle' => 1,
    'theme' => 'advanced',
    'language' => 'en',
    'buttons' => array (
      'default' => array (
        'Bold' => 1,
        'Italic' => 1,
        'JustifyLeft' => 1,
        'JustifyCenter' => 1,
        'JustifyRight' => 1,
        'BulletedList' => 1,
        'NumberedList' => 1,
        'Outdent' => 1,
        'Indent' => 1,
        'Link' => 1,
        'Unlink' => 1,
        // 'Anchor' => 1,  //CKEditor anchor links use deprecated named anchor link syntax - jbickar
        'Image' => 1,
        'Blockquote' => 1,
        'Source' => 1,
        'PasteFromWord' => 1,
        'Format' => 1,
        'Table' => 1,
        // 'SpellChecker' => 1,  //SpellChecker is ad-supported and has an awful interface - jbickar
      ),
      'drupal' => array (
        'break' => 1,
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
    'apply_source_formatting' => 0,
    'paste_auto_cleanup_on_paste' => 0,
    'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6,div',
    'css_setting' => 'none',
    'css_path' => '',
    'css_classes' => '',
  ));

  // Add CKEditor to wysiwyg  
  db_query("INSERT INTO {wysiwyg} SET format = ('%s'), editor = 'ckeditor', settings = ('%s')", $filtered_html_id, $ckeditor_configuration);

  // Update the list of HTML tags allowed for the filtered HTML input format
  $allowed_html = '<a> <blockquote> <br> <cite> <code> <em> <h2> <h3> <h4> <h5> <h6> <iframe> <li> <ol> <p> <strong> <ul>';
  variable_set('allowed_html_' . $filtered_html_id, $allowed_html);

  /**
   * Cleanup
   */

  // These can now go away.
  // @db_query("DROP TABLE install_settings");

  // Update the menu router information.
  menu_rebuild();
}

/**
 * Implementation of hook_form_alter().
 *
 * Allows the profile to alter the site-configuration form. This is
 * called through custom invocation, so $form_state is not populated.
 */
function stanford_form_alter(&$form, $form_state, $form_id) {
  $fields = get_stanford_installer ();
  if ($form_id == 'install_configure') {

    // General form settings.
    $form['intro']['#value'] = st('Please fill out the following values:');
    $form['site_information']['#collapsible']  = TRUE;
    $form['admin_account']['#value']           = '';
    $form['admin_account']['markup']['#value'] = '';
    $form['admin_account']['#title']           = 'Administrator Account';

    // Site settings.
    $form['site_information']['site_name']['#default_value'] = $fields['site_name'];
    $form['site_information']['site_mail']['#default_value'] = $fields['site_mail'];
    $form['site_information']['site_mail']['#type'] = 'hidden';

    // Admin account settings.
    $form['admin_account']['account']['mail']['#default_value'] = $fields['site_mail'];
    $form['admin_account']['account']['name']['#default_value'] = 'admin';
    $form['admin_account']['account']['mail']['#type'] = 'hidden';
    $form['admin_account']['account']['name']['#type'] = 'hidden';

    // Server settings.
    $form['server_settings']['clean_url']['#type'] = 'hidden';
    $form['server_settings']['clean_url']['#default_value'] = 1;
    $form['server_settings']['date_default_timezone']['#type'] = 'hidden';
    $form['server_settings']['date_default_timezone']['#default_value'] = -25200;

    // Hide the automatic updates block.
    unset($form['server_settings']['update_status_module']);
  }
}

// Check the installed settings, by looking at a special table we created just
//  for that purpose in the Drupal DB.
function get_stanford_installer () {
  $fields = array ();
  $result = db_query("SELECT * FROM install_settings");
  while ($row = db_fetch_object($result)) {
    $fields[$row->name] = $row->value;
  }
  return $fields;
}

// Change the default rid for the authenticated user role.  Drupal expects it
// to be 2, and while you can change the setting in a file, bad modules
// apparently don't respect that setting.
function adjust_authuser_rid () {
  $result = db_query("UPDATE role SET rid='1' WHERE name='anonymous user'");
  $result = db_query("UPDATE role SET rid='2' WHERE name='authenticated user'");
}
