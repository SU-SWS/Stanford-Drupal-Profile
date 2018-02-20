<?php
/**
 * @file
 */

/**
 * [stanford_framework_preprocess_html description]
 * @param  [type] $vars [description]
 * @return [type]       [description]
 */
function stanford_framework_preprocess_html(&$vars) {
  // theme option variables
  $vars['choosestyle_styleoptions'] =     !empty($vars['choosestyle_styleoptions']) ? $vars['choosestyle_styleoptions'] : theme_get_setting('choosestyle_styleoptions');
  $vars['header_bkg'] =                   !empty($vars['header_bkg']) ?               $vars['header_bkg'] :               theme_get_setting('header_bkg');
  $vars['header_bkg_style'] =             !empty($vars['header_bkg_style']) ?         $vars['header_bkg_style'] :         theme_get_setting('header_bkg_style');
  $vars['header_bkg_style_front'] =       !empty($vars['header_bkg_style_front']) ?   $vars['header_bkg_style_front'] :   theme_get_setting('header_bkg_style_front');
  $vars['header_bkg_text'] =              !empty($vars['header_bkg_text']) ?          $vars['header_bkg_text'] :          theme_get_setting('header_bkg_text');
  $vars['custom_styles'] =                !empty($vars['custom_styles']) ?            $vars['custom_styles'] :            theme_get_setting('styles');
  $vars['custom_fonts'] =                 !empty($vars['custom_fonts']) ?             $vars['custom_fonts'] :             theme_get_setting('fonts');
  $vars['header_bkg_path'] =              !empty($vars['header_bkg_path']) ?          $vars['header_bkg_path'] :          theme_get_setting('header_bkg_path');

  // Variables
  $header_bkg_front =     $vars['header_bkg_style_front'];
  $choosestyle =          $vars['choosestyle_styleoptions'];
  $header_bkg_path =      $vars['header_bkg_path'];
  $header_bkg =           $vars['header_bkg'];

  // add body class based on style selected
  $vars['classes_array'][] = $vars['choosestyle_styleoptions'];
  $vars['classes_array'][] = $vars['header_bkg'];
  $vars['classes_array'][] = $vars['header_bkg_style'];
  $vars['classes_array'][] = $vars['header_bkg_text'];

  if ((!empty($header_bkg)) && ($header_bkg_front == "header-bkg-style-frontbleed")) {
    $vars['classes_array'][] = $vars['header_bkg_style_front'];
  }

  if ($choosestyle == 'style-custom') {
    $vars['classes_array'][] = $vars['choosestyle_styleoptions'] . '-' . $vars['custom_styles'];
    $vars['classes_array'][] = $vars['choosestyle_styleoptions'] . '-' . $vars['custom_fonts'];
  }

  // Default path for header background image
  if (file_uri_scheme($header_bkg_path) == 'public') {
    $header_bkg_path = file_create_url($header_bkg_path);
  }

  // If front, and full-bleed selected, add background image to page
  if ((!empty($header_bkg)) && ($header_bkg_front !== 0)) {
    drupal_add_css(
    'body.front {background-image: url('. $header_bkg_path .');}',
    array('group' => CSS_THEME, 'type' => 'inline', 'media' => 'screen', 'preprocess' => TRUE, 'weight' => '9999',));
  }

  // If header background enabled, add to header background
  if (!empty($header_bkg)) {
    drupal_add_css('.header {background-image: url('. $header_bkg_path .');}', array('group' => CSS_THEME, 'type' => 'inline', 'media' => 'screen', 'preprocess' => TRUE, 'weight' => '9999',));
  }

  // Add default apple touch icon
  $apple_icon =  array(
    '#tag' => 'link',
    '#attributes' => array(
      'href' => '/' . drupal_get_path('theme', 'stanford_framework') . '/apple-touch-icon.png',
      'rel' => 'apple-touch-icon',
    ),
  );

  $apple_icon_sizes = array(57,72,76,114,120,144,152,167,180);

  foreach($apple_icon_sizes as $size){
    $apple = array(
      '#tag' => 'link',
      '#attributes' => array(
        'href' => '/' . drupal_get_path('theme', 'stanford_framework') . '/apple-touch-icon-'.$size.'x'.$size.'.png',
        'rel' => 'apple-touch-icon',
        'sizes' => $size . 'x' . $size,
      ),
    );
    drupal_add_html_head($apple, 'apple-touch-icon-'.$size);
  }

  drupal_add_html_head($apple_icon,'apple-touch-icon');

}

/**
 * [stanford_framework_preprocess_page description]
 * @param  [type] $vars [description]
 * @return [type]       [description]
 */

function clean($string) {
   $string = str_replace(' ', '-', $string); // Replaces all spaces with hyphens.
   return preg_replace('/[^A-Za-z0-9\-]/', '', $string); // Removes special chars.
}

function stanford_framework_preprocess_page(&$vars) {
  // theme option variables
  $vars['choosestyle_styleoptions'] =       !empty($vars['choosestyle_styleoptions']) ? $vars['choosestyle_styleoptions'] : theme_get_setting('choosestyle_styleoptions');
  $vars['header_bkg'] =                     !empty($vars['header_bkg']) ? $vars['header_bkg'] : theme_get_setting('header_bkg');
  $vars['header_bkg_path'] =                !empty($vars['header_bkg_path']) ? $vars['header_bkg_path'] : theme_get_setting('header_bkg_path');
  $vars['header_bkg_style'] =               !empty($vars['header_bkg_style']) ? $vars['header_bkg_style'] : theme_get_setting('header_bkg_style');
  $vars['header_bkg_style_front'] =         !empty($vars['header_bkg_style_front']) ? $vars['header_bkg_style_front'] : theme_get_setting('header_bkg_style_front');
  $vars['header_bkg_text'] =                !empty($vars['header_bkg_text']) ? $vars['header_bkg_text'] : theme_get_setting('header_bkg_text');
  $vars['logo_image_style_classes'] =       !empty($vars['logo_image_style_classes']) ? $vars['logo_image_style_classes'] : theme_get_setting('logo_image_style_classes');
  $vars['site_title_first_line'] =          !empty($vars['site_title_first_line']) ? $vars['site_title_first_line'] : theme_get_setting('site_title_first_line');
  $vars['site_title_style_classes'] =       !empty($vars['site_title_style_classes']) ? $vars['site_title_style_classes'] : theme_get_setting('site_title_style_classes');
  $vars['site_title_second_line'] =         !empty($vars['site_title_second_line']) ? $vars['site_title_second_line'] : theme_get_setting('site_title_second_line');
  $vars['site_title_line3'] =               !empty($vars['site_title_line3']) ? $vars['site_title_line3'] : theme_get_setting('site_title_line3');
  $vars['site_title_line3_style'] =         !empty($vars['site_title_line3_style']) ? $vars['site_title_line3_style'] : theme_get_setting('site_title_line3_style');
  $vars['site_title_line4'] =               !empty($vars['site_title_line4']) ? $vars['site_title_line4'] : theme_get_setting('site_title_line4');
  $vars['site_title_line4_style'] =         !empty($vars['site_title_line4_style']) ? $vars['site_title_line4_style'] : "organization org-" . strtolower(clean($vars['site_title_line4'] ));
  $vars['site_title_line5'] =               !empty($vars['site_title_line5']) ? $vars['site_title_line5'] : theme_get_setting('site_title_line5');
  $vars['site_title_line5_style'] =         !empty($vars['site_title_line5_style']) ? $vars['site_title_line5_style'] : theme_get_setting('site_title_line5_style');
  $vars['my_site_title'] =                  !empty($vars['my_site_title']) ? $vars['my_site_title'] : variable_get('site_name');

  // Stanford logo header image
  $styles = theme_get_setting('styles');
  $header_bkg = $vars['header_bkg'];
  $header_bkg_text = $vars['header_bkg_text'];
  $choosestyle_styleoptions = $vars['choosestyle_styleoptions'];
  $logo = $vars['logo'];

  $theme_logo_pattern = "/stanford_framework\/logo\.png/";
  $default_logo = theme_get_setting('default_logo');

  // Check if the logo is actually the theme logo and has not been overridden somewhere else.
  if (preg_match($theme_logo_pattern, $logo) || empty($logo)) {
    if (($logo) && ($default_logo) && ($choosestyle_styleoptions == 'style-custom') && (($styles == 'styles-dark') || ($styles == 'styles-contrast') || ($styles == 'styles-cardinal'))) {
      $vars['logo'] = base_path() . drupal_get_path('theme', 'stanford_framework') . '/logo-white.png';
    }

    if (($logo) && ($default_logo) && ($header_bkg) && ($header_bkg_text == 'header-bkg-text-light')) {
      $vars['logo'] = base_path() . drupal_get_path('theme', 'stanford_framework') . '/logo-light.png';
    }

    if (($logo) && ($default_logo) && ($header_bkg) && ($header_bkg_text == 'header-bkg-text-dark')) {
      $vars['logo'] = base_path() . drupal_get_path('theme', 'stanford_framework') . '/logo-dark.png';
    }
  }


  switch ($choosestyle_styleoptions) {
  case "style-wilbur":
  drupal_add_css(drupal_get_path('theme', 'stanford_framework') . '/css/stanford_wilbur/stanford-wilbur.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 100, 'preprocess' => TRUE));
    break;
  case "style-jordan":
  drupal_add_css(drupal_get_path('theme', 'stanford_framework') . '/css/stanford_jordan/stanford-jordan.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 100, 'preprocess' => TRUE));
    break;
  default:
  }
  $vars['styles'] = drupal_get_css();

  $vars['stanford_links'] = array(
    'su_home' => variable_get('stanford_framework_links_su_home', 'http://www.stanford.edu"'),
    'maps' => variable_get('stanford_framework_links_maps', 'http://visit.stanford.edu/plan/maps.html'),
    'su_search' => variable_get('stanford_framework_links_su_search', 'http://www.stanford.edu/search/'),
    'terms' => variable_get('stanford_framework_links_terms', 'http://www.stanford.edu/site/terms.html'),
    'emergency' => variable_get('stanford_framework_links_emergency', 'http://emergency.stanford.edu/'),
    'copyright' => variable_get('stanford_framework_links_copyright','https://uit.stanford.edu/security/copyright-infringement'),
  );
}

/**
 * [stanford_framework_css_alter description]
 * @param  [type] $css [description]
 * @return [type]      [description]
 */
function stanford_framework_css_alter(&$css) {
  $choosestyle = theme_get_setting('choosestyle_styleoptions');
  $styles = theme_get_setting('styles');
  $fonts = theme_get_setting('fonts');

  if ($choosestyle == 'style-custom') {
  // Remove stanford_framework/stanford-framework.css and add default Stanford Light CSS.
  unset($css[drupal_get_path('theme', 'stanford_framework') . '/css/stanford_default/stanford-default.css']);
  drupal_add_css(drupal_get_path('theme', 'stanford_framework') . '/css/stanford_light/stanford-light.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 99, 'preprocess' => TRUE));

  // Styles variables.
  switch ($styles) {
    case "styles-light":
    drupal_add_css(drupal_get_path('theme', 'stanford_framework') . '/css/stanford_light/styles-light.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 100, 'preprocess' => TRUE));
    break;
    case "styles-dark":
    drupal_add_css(drupal_get_path('theme', 'stanford_framework') . '/css/stanford_light/styles-dark.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 100, 'preprocess' => TRUE));
    break;
    case "styles-bright":
    drupal_add_css(drupal_get_path('theme', 'stanford_framework') . '/css/stanford_light/styles-bright.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 100, 'preprocess' => TRUE));
    break;
    case "styles-plain":
    drupal_add_css(drupal_get_path('theme', 'stanford_framework') . '/css/stanford_light/styles-plain.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 100, 'preprocess' => TRUE));
    break;
    case "styles-rich":
    drupal_add_css(drupal_get_path('theme', 'stanford_framework') . '/css/stanford_light/styles-rich.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 100, 'preprocess' => TRUE));
    break;
    case "styles-contrast":
    drupal_add_css(drupal_get_path('theme', 'stanford_framework') . '/css/stanford_light/styles-contrast.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 100, 'preprocess' => TRUE));
    break;
    case "styles-cardinal":
    drupal_add_css(drupal_get_path('theme', 'stanford_framework') . '/css/stanford_light/styles-cardinal.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 100, 'preprocess' => TRUE));
    break;
    case "styles-vivid":
    drupal_add_css(drupal_get_path('theme', 'stanford_framework') . '/css/stanford_light/styles-vivid.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 100, 'preprocess' => TRUE));
    break;
    default:
    }

    // fonts variables
    switch ($fonts) {
    case "fonts-sans":
    drupal_add_css(drupal_get_path('theme', 'stanford_framework') . '/css/stanford_light/fonts-sans.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 98, 'preprocess' => TRUE));
    break;
    case "fonts-serif":
    drupal_add_css(drupal_get_path('theme', 'stanford_framework') . '/css/stanford_light/fonts-serif.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 98, 'preprocess' => TRUE));
    break;
    case "fonts-slab":
    drupal_add_css(drupal_get_path('theme', 'stanford_framework') . '/css/stanford_light/fonts-slab.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 98, 'preprocess' => TRUE));
    break;
    default:
    }

  }

}

/**
 * Upgrade stanford framework from 2.x - 3.x
 */
function stanford_framework_update_7300(&$sandbox) {
  // Migrate the content from line 2 to line 5.
  $settings = variable_get("theme_stanford_framework_settings", array());
  if (isset($settings["site_title_second_line"]) && !empty($settings["site_title_second_line"])) {
    $settings["site_title_line5"] = $settings["site_title_second_line"];
    $settings["site_title_second_line"] = NULL;
    variable_set("theme_stanford_framework_settings", $settings);
  }
}
