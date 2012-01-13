<?php

/*
 * Implementation of hook_install_tasks().
 */

function stanford_profile_install_tasks($install_state) {
  $tasks = array();
  //$tasks['stanford_content_types_create'] = array();
  $tasks['stanford_date_variables'] = array();
  return $tasks;
}

/*
 * Create content type(s).
 */
function stanford_content_types_create() {
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
}

/*
 * Set date variables.
 */
function stanford_date_variables() {
  // Disable user-configurable timezones by default
  $user_configurable_timezones = 0;
  variable_set('configurable_timezones', $user_configurable_timezones);
  
  // Date and timezone settings
  $default_timezone_name = "America/Los_Angeles";
  variable_set('date_default_timezone', $default_timezone_name);

  $date_first_day = 0;
  $date_format_long = "l, F j, Y - H:i";
  $date_format_medium = "D, Y-m-d H:i";
  $date_format_short = "Y-m-d H:i";
  variable_set('date_first_day', $date_first_day);
  variable_set('date_format_long', $date_format_long);
  variable_set('date_format_medium', $date_format_medium);
  variable_set('date_format_short', $date_format_short);
}

/*
  // Default page to not be promoted, revisions enabled, and have comments disabled.
  variable_set('node_options_page', array('status', 'revision'));
  variable_set('comment_page', COMMENT_NODE_DISABLED);

  // Don't display date and author information for page nodes by default.
  $theme_settings = variable_get('theme_settings', array());
  $theme_settings['toggle_node_info_page'] = FALSE;
  variable_set('theme_settings', $theme_settings);
    
  // Set the default input format to the Filtered HTML version
  $filtered_html_id = db_result(db_query("SELECT format FROM {filter_formats} WHERE name = 'Filtered HTML'"));
  variable_set('filter_default_format', $filtered_html_id);

  // Enable the admin theme, and set it for content editing as well
  $admin_theme = 'rubik';
  db_query("UPDATE {system} SET status = 1 WHERE type = 'theme' and name = ('%s')", $admin_theme);
  variable_set('admin_theme', $admin_theme);
  variable_set('node_admin_theme', $admin_theme);
  
  // Remove password from emails that get sent by the system
  $user_mail_register_admin_created_body = "!username,\n\nA site administrator at !site has created an account for you. You may now log in to !login_uri using the following username and password:\n\nusername: !username\n\n\nYou may also log in by clicking on this link or copying and pasting it in your browser:\n\n!login_url\n\nThis is a one-time login, so it can be used only once.\n\nAfter logging in, you will be redirected to !edit_uri so you can change your password.\n\n\n--  !site team";
  variable_set('user_mail_register_admin_created_body', $user_mail_register_admin_created_body);
  
  $user_mail_register_no_approval_required_body = "!username,\n\nThank you for registering at !site. You may now log in to !login_uri using the following username and password:\n\nusername: !username\n\n\nYou may also log in by clicking on this link or copying and pasting it in your browser:\n\n!login_url\n\nThis is a one-time login, so it can be used only once.\n\nAfter logging in, you will be redirected to !edit_uri so you can change your password.\n\n\n--  !site team";
  variable_set('user_mail_register_no_approval_required_body', $user_mail_register_no_approval_required_body);
  
  // User registration - only site administrators can create new user accounts
  $user_register = 0;
  variable_set('user_register', $user_register);
  
  // Remove "Powered by Drupal" block from footer
  $block_module = 'system';
  db_query("UPDATE {blocks} SET status = %d WHERE module = '%s' AND delta = %d", 0, $block_module, 0);

  // Disable user-configurable timezones by default
  $user_configurable_timezones = 0;
  variable_set('configurable_timezones', $user_configurable_timezones);
  
  // Date and timezone settings
  $default_timezone_name = "America/Los_Angeles";
//  $default_timezone_offset = -28800;
  $date_first_day = 0;
  $date_format_long = "l, F j, Y - H:i";
  $date_format_medium = "D, Y-m-d H:i";
  $date_format_short = "Y-m-d H:i";
  variable_set('date_default_timezone_name', $default_timezone_name);
//  variable_set('date_default_timezone', $default_timezone_offset);
  variable_set('date_first_day', $date_first_day);
  variable_set('date_format_long', $date_format_long);
  variable_set('date_format_medium', $date_format_medium);
  variable_set('date_format_short', $date_format_short);
  // Default upload quotas
  $uploadsize_default = 2;
  $usersize_default = 100;
  variable_set('upload_uploadsize_default', $uploadsize_default);
  variable_set('upload_usersize_default', $usersize_default);
  
  // Error reporting
  $error_level = 0;
  variable_set('error_level', $error_level);
  
  // Create configuration for CKEditor
  $ckeditor_configuration = serialize(array (
    'default' => 1,
    'user_choose' => 0,
    'show_toggle' => 1,
    'theme' => 'advanced',
    'language' => 'en',
    'buttons' => 
    array (
      'default' => 
      array (
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
//        'Anchor' => 1,  //CKEditor anchor links use deprecated named anchor link syntax - jbickar
        'Image' => 1,
        'Blockquote' => 1,
        'Source' => 1,
        'PasteFromWord' => 1,
        'Format' => 1,
        'Table' => 1,
//        'SpellChecker' => 1,  //SpellChecker is ad-supported and has an awful interface - jbickar
      ),
      'drupal' => 
      array (
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
 
  // Update the default timezone
  variable_set('date_default_timezone', -25200);
   
  // Update the menu router information.
  menu_rebuild();


/**
 * Implementation of hook_form_alter().
 *
 * Allows the profile to alter the site-configuration form. This is
 * called through custom invocation, so $form_state is not populated.
 */
function stanford_form_alter(&$form, $form_state, $form_id) {
  if ($form_id == 'install_configure') {
    // Set default for site name field.
    $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
    unset($form['server_settings']['update_status_module']);
  }
}
