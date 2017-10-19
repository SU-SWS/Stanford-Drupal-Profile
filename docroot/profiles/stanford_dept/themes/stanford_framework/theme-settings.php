<?php
/**
 * @file
 * @author [author] <[email]>
 */




/**
 * [stanford_framework_form_system_theme_settings_alter description]
 * @param  [type] $form       [description]
 * @param  [type] $form_state [description]
 * @return [type]             [description]
 */
function stanford_framework_form_system_theme_settings_alter(&$form, &$form_state) {

  drupal_add_css(drupal_get_path('theme', 'stanford_framework') . "/css/theme-settings.css");
  drupal_add_js(drupal_get_path('theme', 'stanford_framework') . "/js/theme-settings.js");

  // Override parent options
  // -----------------------------------------------------------------

  $form['theme_settings']['#collapsible'] = TRUE;
  $form['theme_settings']['#collapsed'] = TRUE;

  $form['logo']['#collapsible'] = TRUE;
  $form['logo']['#collapsed'] = TRUE;

  $form['favicon']['#collapsible'] = TRUE;
  $form['favicon']['#collapsed'] = TRUE;

  $form['responsive_container']['#collapsible'] = TRUE;
  $form['responsive_container']['#collapsed'] = TRUE;

  $form['layout_container']['#collapsible'] = TRUE;
  $form['layout_container']['#collapsed'] = TRUE;
  $form['layout_container']['#title'] = t('Hidden Elements');

  $form['background_container']['#collapsible'] = TRUE;
  $form['background_container']['#collapsed'] = TRUE;

  // Hide border options from everyone.
  $form['border_container']['#access'] = FALSE;


  // My Theme Options
  // -----------------------------------------------------------------


  // Choose style
  $form['choosestyle_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Choose Style'),
    '#description' => t('Choose the style you would like your site to use.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['choosestyle_container']['choosestyle_styleoptions'] = array(
    '#type'          => 'radios',
    '#title'         => t('Choose a style'),
    '#default_value' => theme_get_setting('choosestyle_styleoptions'),
    '#options'       => array(
      'style-default' => t('Default'),
      'style-wilbur' => t('Wilbur'),
      'style-jordan' => t('Jordan'),
      'style-custom' => t('Custom'),
    ),
  );

  // Header Text
  $form['header_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Site Title'),
    '#description' => t('Use these settings to adjust the text display and logo image.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Site Title Line 1 Container
  $form['header_container']['site_title_line1_container'] = array('#type' => 'fieldset',
    '#title' => t('Line 1'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['header_container']['site_title_line1_container']['site_title_first_line'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Text'),
    '#default_value' => theme_get_setting('site_title_first_line'),
    '#description'   => t('<em>(This will replace the Drupal default site title)</em>'),
  );

  $form['header_container']['site_title_line1_container']['site_title_style_classes'] = array(
    '#type'          => 'radios',
    '#title'         => t('Style'),
    '#default_value' => theme_get_setting('site_title_style_classes'),
    '#options'       => array(
      '' => t('title case - <strong><em>Default</em></strong>'),
      'site-title-uppercase' => t('bold and uppercase (reserved for schools)'),
      'site-title-small-letters' => t('small letters'),
      'site-title-very-small-letters' => t('super small letters'),
    ),
  );

  // Site Title Line 2 Container
  $form['header_container']['site_title_line2_container'] = array('#type' => 'fieldset',
    '#title' => t('Line 2'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['header_container']['site_title_line2_container']['site_title_second_line'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Text'),
    '#default_value' => theme_get_setting('site_title_second_line'),
    '#description'   => t('<em>(This will replace the Drupal default site title)</em>'),
  );

  // Site Title Line 3 Container
  $form['header_container']['site_title_line3_container'] = array('#type' => 'fieldset',
    '#title' => t('Line 3'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['header_container']['site_title_line3_container']['site_title_line3'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Text'),
    '#default_value' => theme_get_setting('site_title_line3'),
    '#description'   => t('<em>(This will replace the Drupal default site title)</em>'),
  );

  $form['header_container']['site_title_line3_container']['site_title_line3_style'] = array(
    '#type'          => 'radios',
    '#title'         => t('Style'),
    '#default_value' => theme_get_setting('site_title_line3_style') ? theme_get_setting('site_title_line3_style') : "",
    '#options'       => array(
      '' => t('regular italics - <strong><em>Default</em></strong>'),
      'site-title-small-italics' => t('small italics'),
      'site-title-small-title-case' => t('small title case'),
    ),
  );

  // Site Title Line 4 Container
  $form['header_container']['site_title_line4_container'] = array('#type' => 'fieldset',
    '#title' => t('Line 4'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['header_container']['site_title_line4_container']['site_title_line4'] = array(
    '#type'          => 'radios',
    '#title'         => t('Choose an organization'),
    '#default_value' => theme_get_setting('site_title_line4') ? theme_get_setting('site_title_line4') : "",
    '#options'       => array(
      '' => t('None'),
      'Engineering' => t('Engineering'),
      'School of H&S' => t('School of H&S'),
      'Business Affairs' => t('Business Affairs'),
      'University IT' => t('University IT'),
    ),
  );

  // Site Title Line 5 Container
  $form['header_container']['site_title_line5_container'] = array('#type' => 'fieldset',
    '#title' => t('Line 5'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['header_container']['site_title_line5_container']['site_title_line5'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Text'),
    '#default_value' => theme_get_setting('site_title_line5'),
  );

  $form['header_container']['site_title_line5_container']['site_title_line5_style'] = array(
    '#type'          => 'radios',
    '#title'         => t('Style'),
    '#default_value' => theme_get_setting('site_title_line5_style') ? theme_get_setting('site_title_line5_style') : "",
    '#options'       => array(
      '' => t('title case - <strong><em>Default</em></strong>'),
      'site-title-new-line-uppercase' => t('bold and uppercase (reserved for schools)'),
    ),
  );

  // Logo Image Container
  $form['header_container']['logo_image_container'] = array('#type' => 'fieldset',
    '#title' => t('Logo image'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['header_container']['logo_image_container']['logo_image_style_classes'] = array(
    '#type'          => 'radios',
    '#title'         => t('Style'),
    '#default_value' => theme_get_setting('logo_image_style_classes'),
    '#options'       => array(
      '' => t('Hide logo image in mobile - <strong><em>Default</em></strong>'),
      'logo-mobile ' => t('Show logo image in mobile'),
    ),
  );

  // THEME OPTIONS FROM STANFORD LIGHT
  // Design Container
  $form['design_container'] = array('#type' => 'fieldset',
    '#title' => t('Customize design'),
    '#description' => t('Use these settings to adjust the style and typography of your site.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#states' => array(
      'visible' => array(   // action to take.
        ':input[name=choosestyle_styleoptions]' => array('value' => 'style-custom'),
      ),
    ),
  );

  // Styles
  $form['design_container']['styles'] = array(
    '#type'          => 'radios',
    '#title'         => t('Choose styles'),
    '#default_value' => theme_get_setting('styles'),
    '#options'       => array(
      'styles-light' => "<span class=\"design-style ds-light\">" . t('Light') . "</span>",
      'styles-dark' => "<span class=\"design-style ds-dark\">" . t('Dark') . "</span>",
      'styles-plain' => "<span class=\"design-style ds-plain\">" . t('Plain') . "</span>",
      'styles-rich' => "<span class=\"design-style ds-rich\">" . t('Rich') . "</span>",
      'styles-bright' => "<span class=\"design-style ds-bright\">" . t('Bright') . "</span>",
      'styles-contrast' => "<span class=\"design-style ds-high\">" . t('High Contrast') . "</span>",
      'styles-cardinal' => "<span class=\"design-style ds-cardinal\">" . t('Cardinal') . "</span>",
      'styles-vivid' => "<span class=\"design-style ds-vivid\">" . t('Vivid') . "</span>",
    ),
  );

  // Fonts
  $form['design_container']['fonts'] = array(
    '#type'          => 'radios',
    '#title'         => t('Choose fonts'),
    '#default_value' => theme_get_setting('fonts'),
    '#options'       => array(
      'fonts-sans' => "<span class=\"design-font df-sans\">" . t('Sans Serif') . "</span>",
      'fonts-serif' => "<span class=\"design-font df-serif\">" . t('Serif') . "</span>",
      'fonts-slab' => "<span class=\"design-font df-slab\">" . t('Slab Serif') . "</span>",
    ),
  );

  // Header Background Container
  $form['header_bkg_container'] = array('#type' => 'fieldset',
    '#title' => t('Header Background'),
    '#description' => t('Use these settings to enable a header background image.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Header background image
  $form['header_bkg_container']['header_bkg'] = array(
    '#type'          => 'radios',
    '#title'         => t('Enable header background image'),
    '#default_value' => theme_get_setting('header_bkg'),
    '#options'       => array(
      '' => t('None - <strong><em>Default</em></strong>'),
      'header-bkg' => t('Use my image (upload below):'),
    ),
  );

  // Default path for header background image
  $header_bkg_path = theme_get_setting('header_bkg_path');
  if (file_uri_scheme($header_bkg_path) == 'public') {
    $header_bkg_path = file_uri_target($header_bkg_path);
  }

  // Helpful text showing the file name, disabled to avoid the user thinking it can be used for any purpose.
  $form['header_bkg_container']['header_bkg_path'] = array(
    '#type' => 'hidden',
    '#title' => 'Path to header background image',
    '#default_value' => $header_bkg_path,
  );

  if (!empty($header_bkg_path)) {
    $form['header_bkg_container']['header_bkg_preview'] = array(
      '#markup' => !empty($header_bkg_path) ?
       theme('image', array('path' => theme_get_setting('header_bkg_path'))) : '',
    );
  }

  // Upload header background image field
  $form['header_bkg_container']['header_bkg_upload'] = array(
    '#type' => 'file',
    '#title' => 'Upload header background image',
    '#description' => 'You can upload the following image file types: *.jpg, *.gif, or *.png',
  );

  // Header background front page style
  $form['header_bkg_container']['header_bkg_style_front'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('<strong>Display as full-bleed body background image on homepage</strong>'),
    '#default_value' => theme_get_setting('header_bkg_style_front'),
    '#return_value' => 'header-bkg-style-frontbleed',
  );

  // Header background image style
  $form['header_bkg_container']['header_bkg_style'] = array(
    '#type'          => 'radios',
    '#title'         => t('Choose header background image style'),
    '#default_value' => theme_get_setting('header_bkg_style'),
    '#options'       => array(
      'header-bkg-image' => t('Stretch to fill header - <strong><em>Default</em></strong>'),
      'header-bkg-wallpaper' => t('Wallpaper pattern'),
    ),
  );

  // Header background text color
  $form['header_bkg_container']['header_bkg_text'] = array(
    '#type'          => 'radios',
    '#title'         => t('Choose header text color'),
    '#default_value' => theme_get_setting('header_bkg_text'),
    '#options'       => array(
      'header-bkg-text-light' => t('Light - <strong><em>Default</em></strong>'),
      'header-bkg-text-dark' => t('Dark'),
    ),
  );

  // Weights
  // ------------------------------------------------------

  // Weights are done at the end of the form to allow for easier update
  $form['choosestyle_container']['#weight'] = 0;
  $form['design_container']['#weight'] = 5;
  $form['header_container']['#weight'] = 10;
  $form['header_bkg_container']['#weight'] = 15;
  $form['background_container']['#weight'] = 20;
  $form['responsive_container']['#weight'] = 25;
  $form['layout_container']['#weight'] = 30;
  $form['theme_settings']['#weight'] = 35;
  $form['logo']['#weight'] = 40;
  $form['favicon']['#weight'] = 45;
  $form['packages_container']['#weight'] = 50;

  // Attach custom submit handler to the form
  $form['#submit'][] = 'stanford_framework_settings_submit';
  $form['#validate'][] = 'stanford_framework_settings_validate';

}


/**
 * [stanford_framework_settings_submit description]
 * @param  [type] $form       [description]
 * @param  [type] $form_state [description]
 * @return [type]             [description]
 */
function stanford_framework_settings_submit($form, &$form_state) {
  $settings = array();
  // Get the previous value
  $previous = 'public://' . $form['header_bkg_container']['header_bkg_path']['#default_value'];
  $file = file_save_upload('header_bkg_upload');
  if ($file) {
    $parts = pathinfo($file->filename);
    $destination = 'public://' . $parts['basename'];
    $file->status = FILE_STATUS_PERMANENT;

    if(file_copy($file, $destination, FILE_EXISTS_REPLACE)) {
      $_POST['header_bkg_path'] = $form_state['values']['header_bkg_path'] = $destination;
    }
  } else {
    // Avoid error when the form is submitted without specifying a new image
    $_POST['header_bkg_path'] = $form_state['values']['header_bkg_path'] = $previous;
  }

}

/**
 * [stanford_framework_settings_validate description]
 * @param  [type] $form       [description]
 * @param  [type] $form_state [description]
 * @return [type]             [description]
 */
function stanford_framework_settings_validate($form, &$form_state) {
  $validators = array('file_validate_is_image' => array());
  // Check for a new uploaded logo.
  $file = file_save_upload('header_bkg_upload', $validators);
  if (isset($file)) {
    // File upload was attempted.
    if ($file) {
      // Put the temporary file in form_values so we can save it on submit.
      $form_state['values']['header_bkg_upload'] = $file;
    }
    else {
      // File upload failed.
      form_set_error('header_bkg_upload', t('The background image could not be uploaded.'));
    }
  }
}

