<?php

/**
 * Preprocessor for htmk.
 */
function cube_preprocess_html(&$vars) {
    $cube_width = theme_get_setting('cube_width');
    $vars['classes_array'][] = ($cube_width ? $cube_width : 'fixed');
}

/**
 * Preprocessor for theme('page').
 */
function cube_preprocess_page(&$vars) {
  // Automatically adjust layout for page with right sidebar content if no
  // explicit layout has been set.
  $layout = module_exists('context_layouts') ? context_layouts_get_active_layout() : NULL;
  if (arg(0) != 'admin' && !empty($vars['page']['right']) && (!$layout || $layout['layout'] == 'default')) {
    $vars['theme_hook_suggestion'] = 'page__context_layouts_cube_columns';
    drupal_add_css(drupal_get_path('theme', 'cube') . '/layout-sidebar.css');
  }
  
  // Clear out help text if empty.
  if (empty($vars['help']) || !(strip_tags($vars['help']))) {
    $vars['help'] = '';
  }  
  
  // Help text toggler link.
  $vars['help_toggler'] = l(t('Help'), $_GET['q'], array('attributes' => array('id' => 'help-toggler', 'class' => array('toggler')), 'fragment' => 'help-text'));
  
  // Overlay is enabled.
  $vars['overlay'] = (module_exists('overlay') && overlay_get_mode() === 'child');  
  
  if($vars['overlay']) {
  	
  }
  
  // Display user links
  $vars['user_links'] = _cube_user_links();
  
  // Display tabs
  $vars['primary_tabs'] = menu_primary_local_tasks();
  $vars['secondary_tabs'] = menu_secondary_local_tasks();

  if(isset($vars['title_suffix']['add_or_remove_shortcut'])) {
      $vars['add_or_remove_shortcut'] = $vars['title_suffix']['add_or_remove_shortcut'];
      unset($vars['title_suffix']['add_or_remove_shortcut']);
  }

}

function cube_preprocess_overlay(&$vars) {

}

/**
 * Implements hook_css_alter().
 * @TODO: Do this in .info once http://drupal.org/node/575298 is committed.
 */
function cube_css_alter(&$css) {
  if (isset($css['modules/overlay/overlay-child.css'])) {
    $css['modules/overlay/overlay-child.css']['data'] = drupal_get_path('theme', 'cube') . '/overlay-child.css';
  }
  if (isset($css['modules/shortcut/shortcut.css'])) {
    $css['modules/shortcut/shortcut.css']['data'] = drupal_get_path('theme', 'cube') . '/shortcut.css';
  }
}

function _cube_user_links() {
  // Add user-specific links
  global $user;
  $user_links = array();
  if (empty($user->uid)) {
    $user_links['login'] = array('title' => t('Login'), 'href' => 'user');
    // Do not display register link if registration is not allowed.
    if (variable_get('user_register', 1)) {
      $user_links['register'] = array('title' => t('Register'), 'href' => 'user/register');
    }
  }
  else {
    $user_links['account'] = array('title' => t('Hello @username', array('@username' => $user->name)), 'href' => 'user', 'html' => TRUE);
    $user_links['logout'] = array('title' => t('Logout'), 'href' => "user/logout");
  }
  return $user_links;
}
