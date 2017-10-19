<?php
function stanford_light_preprocess_html(&$vars) {
  // theme option variables
  $vars['red_bar'] = theme_get_setting('red_bar');
  $vars['header_bkg'] = theme_get_setting('header_bkg'); 
  $vars['header_bkg_style'] = theme_get_setting('header_bkg_style'); 
  $vars['header_bkg_text'] = theme_get_setting('header_bkg_text');
}

function stanford_light_preprocess_page(&$vars) {
  // theme option variables
  $styles = theme_get_setting('styles'); 
  $fonts = theme_get_setting('fonts');
  $vars['header_bkg'] = theme_get_setting('header_bkg'); 
  $vars['header_bkg_path'] = theme_get_setting('header_bkg_path'); 

  // styles variables
  if ($styles == 'styles-light') {
  drupal_add_css(path_to_theme() . '/css/styles-light.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 500, 'preprocess' => FALSE));
  }
  if ($styles == 'styles-dark') {
  drupal_add_css(path_to_theme() . '/css/styles-dark.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 500, 'preprocess' => FALSE));
  }
  if ($styles == 'styles-bright') {
  drupal_add_css(path_to_theme() . '/css/styles-bright.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 500, 'preprocess' => FALSE));
  }
  if ($styles == 'styles-plain') {
  drupal_add_css(path_to_theme() . '/css/styles-plain.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 500, 'preprocess' => FALSE));
  }
  if ($styles == 'styles-rich') {
  drupal_add_css(path_to_theme() . '/css/styles-rich.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 500, 'preprocess' => FALSE));
  }
  if ($styles == 'styles-contrast') {
  drupal_add_css(path_to_theme() . '/css/styles-contrast.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 500, 'preprocess' => FALSE));
  }
  if ($styles == 'styles-cardinal') {
  drupal_add_css(path_to_theme() . '/css/styles-cardinal.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 500, 'preprocess' => FALSE));
  }
    
  // fonts variables
  if ($fonts == 'fonts-sans') {
  drupal_add_css(path_to_theme() . '/css/fonts-sans.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 600, 'preprocess' => FALSE));
  }
  if ($fonts == 'fonts-serif') {
  drupal_add_css(path_to_theme() . '/css/fonts-serif.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 600, 'preprocess' => FALSE));
  }
  if ($fonts == 'fonts-slab') {
  drupal_add_css(path_to_theme() . '/css/fonts-slab.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 600, 'preprocess' => FALSE));
  }
  
  $vars['styles'] = drupal_get_css();
}