<?php

/**
 * @file
 * A collection of private helper functions for use with the stanford_subsites.module
 */


/**
 * Gets the active subsite node based on node page and on path.
 *
 * @return object
 *   $node [subsite]  or   false
 */
function stanford_subsites_get_active_subsite() {
  global $subsite;
  $static_subsite = &drupal_static(__FUNCTION__);

  // Grab from global object first.
  if ($static_subsite) {
    return $static_subsite;
  }

  // Not found or set yet. Carry on.
  $subsite_node = FALSE;

  // First try from node.
  $a0 = arg(0);
  $a1 = arg(1);

  if ($a0 == "node" && is_numeric($a1)) {
    $node = node_load($a1);
    $enabled_types = variable_get('stanford_subsite_content_types', array());

    // Only check the node if it is "enabled"
    if (is_object($node) && in_array($node->type, $enabled_types)) {
      $subsite_node = _lookup_subsite_reference_by_node($node);
    }

  }

  // If the page being viewed is not a node then check the path.
  if (!$subsite_node) {
    $request_path = request_path();
    $subsite_node = _lookup_subsite_reference_by_path($request_path);
  }

  // Assign the global subsite variable and return the result.
  $subsite = $subsite_node;
  $static_subsite = $subsite_node;

  return $subsite_node;
}

/**
 * Get all subsite nodes.
 * @param mixed $published
 *   Either: TRUE / FALSE / "ALL"
 * @return array
 *   An array of subsite nodes
 */
function stanford_subsites_get_subsite_nodes($published = "all", $reset = FALSE) {

  // Static caching!
  $stored_nodes[$published] = &drupal_static(__FUNCTION__);
  if (is_array($stored_nodes[$published]) && count($stored_nodes[$published]) && !$reset) {
    return $stored_nodes[$published];
  }

  // Must find nodes.
  $query = db_select("node", "n")
            ->fields("n", array("nid"))
            ->condition("type", SUBSITE_CONTENT_TYPE)
            ->orderBy('title');

  // What nodes do I want...
  if ($published !== "all") {
    $query->condition("status", $published);
  }

  // Execute query.
  $results = $query->execute();

  // Load up the nids.
  $nids = array();
  while ($result = $results->fetchAssoc()) {
    $nids[] = $result['nid'];
  }

  // Load all the nodes and store to static cache.
  $stored_nodes[$published] = node_load_multiple($nids, array(), $reset);

  return $stored_nodes[$published];
}

/**
 * Lookup function for nodes by entity reference.
 *
 * _lookup_subsite_reference_by_node()
 *
 * @param object $node
 *   The currently being viewed node object.
 *
 * @return bool
 *   True if this node has a subsite / False if none.
 */
function _lookup_subsite_reference_by_node($node) {

  // If the node that is being viewed is the subsite node then just return it!
  if ($node->type == SUBSITE_CONTENT_TYPE) {
    return $node;
  }

  $term = FALSE;
  // Check for the field.
  if (isset($node->{SUBSITE_TAGS_FIELD})) {
    $term = stanford_subsites_get_subsite_term_from_node($node);
  }

  // Check for the term.
  if (!$term) {
    return FALSE;
  }

  return stanford_subsites_get_subsite_node_by_term($term);
}

/**
 * Lookup function for nodes by subsite path.
 *
 * _lookup_subsite_reference_by_path.
 *
 * @param string $path
 *   The currently viewed url path.
 *
 * @return mixed
 *   A node object of the subsite node or false if none.
 */
function _lookup_subsite_reference_by_path($path) {

  // First get all of the subsite paths.
  $subsite_paths = _get_subsite_paths();

  // Check to see if we need to add a trailing slash.
  if (!preg_match('~^https?://[^/]+$~', $path)) {
    $path .= "/";
  }

  // Check raw string for path... :( needs optimization.
  foreach ($subsite_paths as $nid => $site_path) {
    if (stripos($path, $site_path . "/") === 0) {
      return node_load($nid);
    }
  }

  return FALSE;
}

/**
 * Get the subsite base paths.
 *
 * @return array
 *   An array of subsite paths.
 */
function _get_subsite_paths() {

  $paths = cache_get('stanford_subsites_subsite_paths');
  // If cache isnt set then we need to generate it.
  if (!$paths) {
    $paths = array();
    $query = db_select('node', 'n')
              ->fields('n', array('nid'))
              ->condition('type', SUBSITE_CONTENT_TYPE)
              ->execute();

    while ($path_string = $query->fetchAssoc()) {
      $paths[$path_string['nid']] = drupal_get_path_alias("node/" . $path_string['nid']);
    }
    cache_set('stanford_subsites_subsite_paths', $paths);
    return $paths;
  }

  // Cached version.
  return $paths->data;
}


/**
 * Get taxonomy field instance.
 *
 * @param string $bundle
 *   The bundle this instance belongs to.
 *
 * @return array
 *   An array describing the instance of the reference field.
 */
function _get_tax_field_instance($bundle) {

  if (!$bundle) {
    return FALSE;
  }

  $ret = array();
  $ret['entity_type'] = "node";
  $ret['bundle'] = $bundle;
  $ret['field_name'] = SUBSITE_TAGS_FIELD;
  $ret['label'] = t('Subsite Tags');
  $ret['description'] = t("Enter the value of the subsite.");
  $ret['widget']['type'] = "taxonomy_select";
  $ret['widget']['settings']['size'] = 60;
  // $ret['widget']['settings']['autocomplete_path'] = "taxonomy/autocomplete";
  $ret['display']['default']['type'] = "hidden";
  $ret['display']['teaser']['type'] = "hidden";

  return $ret;
}

/**
 * Sets the active working space for subsites.
 *
 * Right now only sets the default subsite on node/add.
 *
 * @param int $nid
 *   The nid of the new active subsite for the working space.
 */
function stanford_subsites_set_subsite_workingspace($nid) {
  $_SESSION['active_subsite'] = $nid;
}

/**
 * Removes the active subsite working space.
 */
function stanford_subsites_clear_subsite_workingspace() {
  unset($_SESSION['active_subsite']);
}


/**
 * Get the active working space.
 *
 * @return mixed
 *   The nid of the active subsite for the working space or false.
 */
function stanford_subsites_get_subsite_workingspace() {
  if (isset($_SESSION['active_subsite']) && is_numeric($_SESSION['active_subsite'])) {
    return check_plain($_SESSION['active_subsite']);
  }
  // Not available.
  return FALSE;
}

/**
 * Creates and places a new menu and menu block.
 *
 * Creates and places a new menu and menu block specifically for this subsite
 * In the new menu a 'home' link is created to the subsite
 * menu block theme/region placement is controlled by the settings page
 * Tasks:
 *  1. Create menu
 *  2. Add subsite node as a link
 *  3. Create menu block from new menu
 *  4. Place menu block via context into region
 *
 * @param object $node
 *   The newly created subsite node (node_insert hook)
 *
 * @return array
 *   menu => the menu,
 *   menu_block => the menu block object
 */
function stanford_subsites_create_subsite_menu_and_menublock($node) {

  // Create menu ---------------------------------------------------------------

  $menu_name = stanford_subsites_get_subsite_menu_name($node);

  $menu = array(
    'menu_name' => $menu_name,
    'title' => t('Subsite Menu') . ": " . $node->{SUBSITE_MACHINE_NAME_FIELD}[LANGUAGE_NONE][0]['value'],
    'description' => t("Menu for all of this subsites links"),
  );

  // Save it.
  menu_save($menu);

  // Create menu link ----------------------------------------------------------

  // Add a link to this subsite in the new menu.
  $menu_link = array(
    "link_path" => drupal_get_normal_path('node/' . $node->nid),
    "link_title" => t("Home"),
    "menu_name" => $menu_name,
  );

  // Save it!
  menu_link_save($menu_link);

  // Let the user know with a nice message.
  drupal_set_message("A Menu for this subsite was successfully created. " . l(t("Edit the menu here »"), "admin/structure/menu/manage/" . $menu_name));

  // Create menu block ---------------------------------------------------------

  // Now create a menu block and place it.
  $menu_block = array();
  $block_ids = variable_get('menu_block_ids', array());
  $delta = empty($block_ids) ? 1 : max($block_ids) + 1;
  // Save the new array of blocks IDs.
  $block_ids[] = $delta;
  variable_set('menu_block_ids', $block_ids);

  $menu_block['delta'] = $delta;
  $menu_block['module'] = "menu_block";
  $menu_block['delta'] = $delta;
  $menu_block['title'] = "<none>";
  $menu_block['display_options'] = "advanced";
  $menu_block['title_link'] = 0;
  $menu_block['admin_title'] = t('Subsite Menu Block: ') . $menu_name;
  $menu_block['menu_name'] = $menu_name;
  $menu_block['level'] = variable_get('stanford_subsite_menu_block_level', "1");
  $menu_block['follow'] = 0;
  $menu_block['follow_parent'] = "active";
  $menu_block['depth'] = variable_get('stanford_subsite_menu_block_depth', "1");
  $menu_block['expanded'] = 0;
  $menu_block['sort'] = 0;
  $menu_block['parent_mlid'] = $menu_name . ":0";
  $menu_block['regions'] = array();
  $menu_block['visibility'] = "0";
  $menu_block['pages'] = "";
  $menu_block['roles'] = array();
  $menu_block['custom'] = "0";
  $menu_block['types'] = array();
  $menu_block['visibility__active_tab'] = "edit-path";
  $menu_block['parent'] = $menu_name . ":0";

  menu_block_block_save($delta, $menu_block);

  // Run the normal new block submission
  // (borrowed from block_add_block_form_submit).
  $query = db_insert('block')->fields(array(
    'visibility',
    'pages',
    'custom',
    'title',
    'module',
    'theme',
    'region',
    'status',
    'weight',
    'delta',
    'cache'
  ));

  foreach (list_themes() as $key => $theme) {
    if ($theme->status) {
      $region = !empty($menu_block['regions'][$theme->name]) ? $menu_block['regions'][$theme->name] : BLOCK_REGION_NONE;

      // Check to see that block does not already exist...
      db_delete("block")
        ->condition("theme", $theme->name)
        ->condition("module", $menu_block['module'])
        ->condition("delta", $delta)
        ->execute();

      $query->values(array(
        'visibility' => (int) $menu_block['visibility'],
        'pages' => trim($menu_block['pages']),
        'custom' => (int) $menu_block['custom'],
        'title' => $menu_block['title'],
        'module' => $menu_block['module'],
        'theme' => $theme->name,
        'region' => ($region == BLOCK_REGION_NONE ? '' : $region),
        'status' => 0,
        'status' => (int) ($region != BLOCK_REGION_NONE),
        'weight' => 0,
        'delta' => $delta,
        'cache' => DRUPAL_NO_CACHE,
      ));
    }
  }
  $query->execute();

  $query = db_insert('block_role')->fields(array('rid', 'module', 'delta'));
  foreach (array_filter($menu_block['roles']) as $rid) {
    $query->values(array(
      'rid' => $rid,
      'module' => $menu_block['module'],
      'delta' => $delta,
    ));
  }
  $query->execute();

  drupal_set_message(t('The Menu block has been created.'));

  return array(
    'menu' => $menu,
    'menu_block' => $menu_block,
  );

}
/**
 * Enable the menu for use on all subsite enabled content types.
 *
 * @param object $menu
 *   A fully loaded menu object
 */
function stanford_subsites_enable_menu_for_subsite_content_types($menu) {

  // Get all enabled content types from the settings form array.
  $enabled_types = variable_get('stanford_subsite_content_types', array());

  // Loop through the enabled types and add the new menu to their settings array.
  foreach ($enabled_types as $k => $type) {
    $opts = variable_get('menu_options_' . $type, array('main-menu'));
    $opts[] = $menu['menu_name'];
    variable_set('menu_options_' . $type, $opts);
  }

  // Also do subsite content types by default...
  $opts = variable_get('menu_options_' . SUBSITE_CONTENT_TYPE, array('main-menu'));
  $opts[] = $menu['menu_name'];
  variable_set('menu_options_' . SUBSITE_CONTENT_TYPE, $opts);

}


/**
 * Create subsite context.
 *
 * @param object $node
 *   The fully saved and/or loaded subsite node object.
 * @param array $args
 *   A misc array of arguments to pass in.
 *     menu => (optional) the menu associated with the subsite
 *     menu_block => (optional) the menu_block associated with the subsite
 */
function stanford_subsites_create_subsite_context($node, &$args) {

  $menu = isset($args['menu']) ? $args['menu'] : FALSE;
  $menu_block = isset($args['menu_block']) ? $args['menu_block'] : FALSE;
  $delta = isset($args['menu_block']) ? $menu_block['delta'] : 0;

  // We can cheat here a bit and re-use the menu name function.
  $context_name = stanford_subsites_get_subsite_menu_name($node);

  // Find out what region we are suspposed to be placing the menu block in by
  // getting the theme from the subsite node and comparing it to the subsite
  // configuration settings.

  $the_theme = variable_get('theme_default');
  $theme_region = FALSE;

  if (isset($node->{SUBSITE_THEME_FIELD}[LANGUAGE_NONE][0]['value']) && $node->{SUBSITE_THEME_FIELD}[LANGUAGE_NONE][0]['value'] !== "default") {
    $the_theme = $node->{SUBSITE_THEME_FIELD}[LANGUAGE_NONE][0]['value'];
  }

  // Settings from admin/config/subsites/.
  $settings = variable_get('stanford_subsite_mbtr', array());

  if (isset($settings[$the_theme]) && $settings[$the_theme] !== "stanford_subsites_dnp") {
    $theme_region = $settings[$the_theme];
  }

  $context = new stdClass();
  $context->name = $context_name;
  $context->description = "Subsite wide context for " . substr($node->{SUBSITE_NAME_FIELD}[LANGUAGE_NONE][0]['value'], 0, 210);
  $context->tag = drupal_clean_css_identifier(substr($node->{SUBSITE_NAME_FIELD}[LANGUAGE_NONE][0]['value'], 0, 32));
  $context->conditions = array(
    'active_subsite' => array(
      'values' => array(
        $node->nid => $node->nid,
      ),
    ),
  );

  if ($theme_region) {
    $context->reactions = array(
      'block' => array(
        'blocks' => array(
          "menu_block-" . $delta => array(
            'module' => "menu_block",
            'delta' => $delta,
            'region' => $theme_region,
            'weight' => -10,
          ),
        ),
      ),
    );
  }
  $context->condition_mode = 0;
  $context->table = "context";
  $context->type = "Normal";
  $context->export_type = 1;

  context_save($context);
  drupal_set_message("A subsite context was created for you. " . l(t("Edit it here") . " »", "admin/structure/context/list/" . $context_name . "/edit"));

  // ---------------------------------------------------------------------------

  pathauto_node_update_alias($node, 'insert');
  $alias = drupal_get_path_alias("node/" . $node->nid);

  $context_name = stanford_subsites_get_subsite_menu_name($node) . "-home";
  $context = new stdClass();
  $context->name = $context_name;
  $context->description = "Subsite home page context for " . substr($node->{SUBSITE_NAME_FIELD}[LANGUAGE_NONE][0]['value'], 0, 210);
  $context->tag = drupal_clean_css_identifier(substr($node->{SUBSITE_NAME_FIELD}[LANGUAGE_NONE][0]['value'], 0, 32));
  $context->conditions = array(
    'path' => array(
      'values' => array(
        $alias => $alias,
        "node/" . $node->nid => "node/" . $node->nid,
      ),
    ),

  );

  $context->condition_mode = 0;
  $context->table = "context";
  $context->type = "Normal";
  $context->export_type = 1;

  context_save($context);

  // ---------------------------------------------------------------------------

  cache_clear_all();
  $args['context'] = $context;
  return TRUE;
}

/**
 * Generates the machine name for the drupal menu for a subsite node.
 *
 * @param object $node
 *   A subsite node.
 *
 * @return string
 *   The machine name of the menu for the subsite
 */
function stanford_subsites_get_subsite_menu_name($node) {
  $filter = array(' ' => '-', '/' => '-', '[' => '-', ']' => '-');
  $term = stanford_subsites_get_subsite_term_from_node($node);
  $menu_name = strtolower(check_plain(drupal_clean_css_identifier($term->name, $filter)));

  // Max length of menu name is 32 chars.
  $menu_name = substr($menu_name, 0, 32);

  return $menu_name;
}

/**
 * Returns a fully loaded subsite term.
 *
 * @param object $node
 *   A node object.
 *
 * @return object
 *   A term object.
 */
function stanford_subsites_get_subsite_term_from_node($node) {

  if (!is_object($node)) {
    return FALSE;
  }

  $lang = LANGUAGE_NONE;
  $tid = @$node->{SUBSITE_TAGS_FIELD}[$lang][0]['tid'];

  if (!$tid) {
    return FALSE;
  }

  return taxonomy_term_load($tid);
}

/**
 * Load a subsite by the term it uses and defines.
 *
 * @param object $term
 *   A taxonomy term.
 *
 * @return mixed
 *   A subsite node or false if something went wrong.
 */
function stanford_subsites_get_subsite_node_by_term($term) {
  // Find a node by joining the taxonomy_index table to node and filtering on
  // node type and tid.
  $select = db_select("node", "n")
    ->fields("n", array("nid"))
    ->condition("ti.tid", $term->tid)
    ->condition("n.type", SUBSITE_CONTENT_TYPE)
    ->range(0, 1);

  $select->join("taxonomy_index", "ti", "n.nid = ti.nid");
  $nid = $select->execute()->fetchField();

  // If through all that we get one node. Load and return it.
  if (is_numeric($nid)) {
    return node_load($nid);
  }

  return FALSE;
}
