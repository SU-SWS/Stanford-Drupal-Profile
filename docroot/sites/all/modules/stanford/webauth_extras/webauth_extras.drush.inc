<?php

function webauth_extras_drush_command() {
  $items = array();

  $items['webauth-add-user'] = array(
    'description' => 'Add a new WebAuth user',
	'arguments' => array(
	  'sunetid' => 'The SUNetID of the user',
	),
	'options' => array(
	  'name' => array(
	    'description'   => "The user's name",
		'example-value' => "Leland Stanford",
	  ),
	  'email' => array(
	    'description' => "The user's email address",
		'example-value' => "leland.stanford@stanford.edu",
	  ),
      'make-admin' => array(
        'description' => "Make the user an admin",
      ),
	),
	'aliases' => array('waau'),
  );
  $items['webauth-map-role'] = array(
    'description' => 'Map a workgroup to a Drupal role',
    'arguments' => array(
      'workgroup' => 'The workgroup you would like to map',
      'role' => 'The Drupal role you would like to map to',
    ),
    'examples' => array(
      'drush wamr stanford:staff administrator' => 'Maps the "stanford:staff" workgroup to the Drupal "administrator" role',
    ),
    'aliases' => array('wamr'),
  );
  $items['webauth-write-htaccess'] = array(
    'description' => 'Write the WebAuth .htaccess file to disk. Performs the same function as saving the configuration through the GUI.',
    'aliases' => array('wawh'),
  );
  return $items;
}

function drush_webauth_extras_webauth_add_user_validate($sunet = '') {
  $sunet = strtolower(trim($sunet));

  // Can't create a user without a SUNetID
  if (empty($sunet)) {
    return drush_set_error(dt('Please specify a SUNetID'));
  }

  // Make sure there isn't an entry in the authmap table
  // Authmap entries use the SUNetID@stanford.edu format
  $authname = $sunet . '@stanford.edu';

  // user_get_authmaps returns 0 if there are no authmaps,
  // or a keyed array if there are authmap entries
  $authmaps = user_get_authmaps($authname);

  if ((($authmaps) !== 0) && ($authmaps['webauth'] == $authname)) {
    return drush_set_error('Could not create user. Authname ' . $authname . ' already exists. Has the user already been created with a different username but the same SUNetID?');
  }

  // If no name is specified, use the default name (sunetid + @stanford.edu)
  $name = trim(drush_get_option('name'));
  if (empty($name)) {
    $name  = $authname;
  }

  // Check that there is no user with the same name
  if (user_load_by_name($name)) {
    return drush_set_error('Could not create user. Username ' . $name . ' already exists.');
  }

  // If no email was specified, we'll use the default (sunetid + @stanford.edu)
  $default_email = $sunet . '@stanford.edu';

  $email = strtolower(trim(drush_get_option('email'))); 

  if (!empty($email) && !valid_email_address($email)) {
    return drush_set_error('Could not create user. Email ' . $email . ' is not valid.');
  }

  if (empty($email)) { 
    $email = $default_email;
  }

  // Check that there is no user with the same email
  // Drupal will let us create the user with a duplicate email, but
  // the user will run into issues when making changes to their profile
  if (user_load_by_mail($email)) {
    return drush_set_error('Could not create user. Email ' . $email . ' already in use.');
  }

  drush_set_option('name',  $name);
  drush_set_option('email', $email);
}

function drush_webauth_extras_webauth_add_user($sunet = '') {
  $sunet = strtolower(trim($sunet));
  $authname = $sunet . '@stanford.edu';
  $name  = drush_get_option('name');
  $email = drush_get_option('email');


  $account = new stdClass;
  $account->is_new = TRUE;
  $account->name = $name;
  $account->pass = user_password();
  $account->mail = $email;
  $account->init = $sunet . '@stanford.edu';
  $account->status = TRUE;

  $sunet_role = user_role_load_by_name('SUNet User');

  $roles = array(DRUPAL_AUTHENTICATED_RID => TRUE, $sunet_role->rid => TRUE);

  // Make the user an admin if the make-admin flag was set
  if (drush_get_option('make-admin')) {
    $admin_role = user_role_load_by_name('administrator');
    $roles[$admin_role->rid] = TRUE;
  }

  $account->roles = $roles;
  $account->timezone = variable_get('date_default_timezone', '');
  $account = user_save($account);

  user_set_authmaps($account, array('authname_webauth' => $authname));

  watchdog('WebAuth','Created user through drush: %user', array('%user' => $name));    
}

/**
 * Implements drush_COMMANDFILE_COMMANDNAME().
 */
function drush_webauth_extras_webauth_map_role($workgroup, $role) {
  //get a $role object from the role name
  $role = user_role_load_by_name($role);
  //db_insert into webauth_roles ($role->rid, $workgroup)
  $query = db_insert('webauth_roles')
    ->fields(array(
      'rid' => $role->rid,
      'wa_group' => $workgroup,
  ))
  ->execute();
  //write to the .htaccess
  webauth_write_htaccess();
}

/**
 * Implements drush COMMANDFILE_COMMANDNAME_validate().
 */
function drush_webauth_extras_webauth_map_role_validate($workgroup, $role) {
  $role = user_role_load_by_name($role);
  if(!$role) {
    return drush_set_error('NO_ROLE_EXISTS', dt('No such role with that name exists. Check your spelling  and try again.'));
  }
  $query = db_query("SELECT * FROM {webauth_roles} WHERE rid = :rid AND wa_group = :wa_group",
    array(':rid' => $role->rid, ':wa_group' => $workgroup));
  if ($query->fetchField()) {
    return drush_set_error('MAPPING_EXISTS', dt('This workgroup is already mapped to this Drupal role!'));
  }
  if (preg_match("/^[-_\w\d\~]+:[\w\d-_]+$/", $workgroup) == 0) {
    return drush_set_error('WORKGROUP_NAME', dt('There was an error in your workgroup name. Please make sure you entered it correctly.'));
}

}

/**
 * Implements drush_COMMANDFILE_COMMANDNAME().
 */
function drush_webauth_extras_webauth_write_htaccess() {
  //write to the .htaccess
  webauth_write_htaccess();
}

