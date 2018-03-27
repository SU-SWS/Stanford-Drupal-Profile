<?php
/**
 * @file for page callbacks
 */

/**
 * Callback function for admin/config/subsites/dashboard.
 *
 * A page callback to display the administration dashboard page. Contains many
 * blocks and some extra css. This page is themed with a special theme template.
 *
 * @param string $subsite_path_alias
 *   A the path alias from the URL of the subsite node we are using. Defaults to
 *   all.
 *
 * @return array
 *   A render array of page content.
 */
function stanford_subsites_admin_dash_dashboard($subsite_path_alias = NULL) {
  $subsite = NULL;

  // Set the working space.
  if (!is_null($subsite_path_alias) && $subsite_path_alias !== "all") {
    $path = drupal_lookup_path("source", $subsite_path_alias);
    $parts = explode("/", $path);
    if ($parts[0] == "node" && is_numeric($parts[1])) {
      $subsite = node_load($parts[1]);
    }
  }
  else {
    stanford_subsites_clear_subsite_workingspace();
  }

  // If subsite node exists.
  if (!empty($subsite->nid)) {
    stanford_subsites_set_subsite_workingspace($subsite->nid);
  }

  $output = array();
  $output['#show_messages'] = TRUE;
  $output['#theme'] = "page_subsite_dashboard";
  $output["#attached"] = array(
    'css' => array(
      drupal_get_path('module', "stanford_subsites_admin_dash") . "/css/subsites.admin.dash.css",
    ),
  );

  // ---------------------------------------------------------------------------
  // ---------------------------------------------------------------------------

  // Main top region.
  // ---------------------------

  $block = block_load('stanford_subsites_admin_dash', 'subsites_dashboard_banner');
  $output['main_top']['subsite_banner'] = _block_get_renderable_array(_block_render_blocks(array($block)));

  // Content region.
  // ----------------------------

  $block = block_load('stanford_subsites_admin_dash', 'subsites_dashboard_content');
  $output['content']['manage_content'] = _block_get_renderable_array(_block_render_blocks(array($block)));

  $block = block_load('stanford_subsites_admin_dash', 'subsites_dashboard_blocks');
  $output['content']['manage_blocks'] = _block_get_renderable_array(_block_render_blocks(array($block)));

  $block = block_load('stanford_subsites_admin_dash', 'subsites_dashboard_contexts');
  $output['content']['manage_contexts'] = _block_get_renderable_array(_block_render_blocks(array($block)));

  // Sidebar right region.
  // ---------------------------

  // Create new block.
  $block = block_load('stanford_subsites_admin_dash', 'subsites_dashboard_create_new');
  $output['sidebar_second']['new_stuff'] = _block_get_renderable_array(_block_render_blocks(array($block)));

  $block = block_load('stanford_subsites_admin_dash', 'subsites_dashboard_edit_subs');
  $output['sidebar_second']['edit_stuff'] = _block_get_renderable_array(_block_render_blocks(array($block)));

  return $output;
}
