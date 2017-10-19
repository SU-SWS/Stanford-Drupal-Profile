<?php
function stanford_basic_form_system_theme_settings_alter(&$form, &$form_state) {
 
  // Color Palette
  $form['color_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Color Palette'),
    '#description' => t('Use these settings to change the color palette.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  
  $form['color_container']['color_classes'] = array(
    '#type'          => 'radios',
    '#title'         => t('Color palette'),
    '#default_value' => theme_get_setting('color_classes'),
    '#options'       => array(
	  'color1 ' => t('Stanford Basic - <strong><em>Default</em></strong>'),
      'color2 ' => t('Cardinal'),
	  'color3 ' => t('Sandstone'),
	  'color4 ' => t('Warm Gray'),
    ),
  );
  
  // Page Layout
  $form['layout_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Layout'),
    '#description' => t('Use these settings to adjust the page layout.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  
  $form['layout_container']['layout_classes'] = array(
    '#type'          => 'radios',
    '#title'         => t('Page width'),
    '#default_value' => theme_get_setting('layout_classes'),
    '#options'       => array(
      '' => t('Fixed width layout (960 pixels), sidebar width (159 pixels) - <strong><em>Default</em></strong>'),
	  'news ' => t('Fixed width layout (960 pixels), sidebar width (279 pixels)'),
      'wide ' => t('Flexible width layout (100%), sidebar width (16.5%)'),
    ),
  );
  
  $form['layout_container']['header_padding_classes'] = array(
    '#type'          => 'radios',
    '#title'         => t('Top padding above header text'),
    '#default_value' => theme_get_setting('header_padding_classes'),
    '#options'       => array(
      '' => t('0 pixels'),
	  'headerpadding1 ' => t('5 pixels'),
      'headerpadding2 ' => t('10 pixels - <strong><em>Default</em></strong>'),
	  'headerpadding3 ' => t('15 pixels'),
	  'headerpadding4 ' => t('20 pixels'),
	  'headerpadding5 ' => t('25 pixels'),
    ),
  );
    
  // Background Section
  $form['background_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Background Images'),
    '#description' => t('Use these settings to select different background images.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  
  // Body Background Image
  $form['background_container']['body_bg_type'] = array(
    '#type'          => 'radios',
    '#title'         => t('Body background image type'),
    '#default_value' => theme_get_setting('body_bg_type'),
    '#options'       => array(
      '' => t('Wallpaper pattern - <strong><em>Default</em></strong>'),
	  'photobg ' => t('Photo image'),
    ),
  );
  
 $form['background_container']['body_bg_classes'] = array(
    '#type'          => 'radios',
    '#title'         => t('Body background image'),
    '#default_value' => theme_get_setting('body_bg_classes'),
    '#options'       => array(
      '' => t('None - <strong><em>Default</em></strong>'),
	  'bodybg ' => t('Use my image (upload below):'),
    ),
  );
   
  // Default path for image
  $body_bg_path = theme_get_setting('body_bg_path');
  if (file_uri_scheme($body_bg_path) == 'public') {
    $body_bg_path = file_uri_target($body_bg_path);
  }
 
  // Helpful text showing the file name, disabled to avoid the user thinking it can be used for any purpose.
  $form['background_container']['body_bg_path'] = array(
    '#type' => 'hidden',
    '#title' => 'Path to background image',
    '#default_value' => $body_bg_path,
  );
  if (!empty($body_bg_path)) {
    $form['background_container']['body_bg_preview'] = array(
      '#markup' => !empty($body_bg_path) ? 
       theme('image', array('path' => theme_get_setting('body_bg_path'))) : '',
    );
  }

  // Upload field
  $form['background_container']['body_bg_upload'] = array(
    '#type' => 'file',
    '#title' => 'Upload background image',
    '#description' => 'You can upload the following image file types: *.jpg, *.gif, or *.png',
  );
  
  // Border Style
  $form['border_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Borders'),
    '#description' => t('Use these settings to change the border style.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
    
  $form['border_container']['border_classes'] = array(
    '#type'          => 'radios',
    '#title'         => t('Border style for content section'),
    '#default_value' => theme_get_setting('border_classes'),
    '#options'       => array(
	  '' => t('No borders - <strong><em>Default</em></strong>'),
      'borders' => t('Show borders'),
    ),
  );
  
  $form['border_container']['corner_classes'] = array(
    '#type'          => 'radios',
    '#title'         => t('Corner style'),
    '#default_value' => theme_get_setting('corner_classes'),
    '#options'       => array(
	  '' => t('Straight corners - <strong><em>Default</em></strong>'),
      'roundedcorners' => t('Rounded corners (not supported in Internet Explorer 8 or below)'),
    ),
  );
  
  
  // Attach custom submit handler to the form
  $form['#submit'][] = 'stanford_basic_settings_submit';
  $form['#validate'][] = 'stanford_basic_settings_validate';
}

function stanford_basic_settings_submit($form, &$form_state) {
  $settings = array();
  // Get the previous value
  $previous = 'public://' . $form['background_container']['body_bg_path']['#default_value'];
  $file = file_save_upload('body_bg_upload');
  if ($file) {
    $parts = pathinfo($file->filename);
    $destination = 'public://' . $parts['basename'];
    $file->status = FILE_STATUS_PERMANENT;
   
    if(file_copy($file, $destination, FILE_EXISTS_REPLACE)) {
      $_POST['body_bg_path'] = $form_state['values']['body_bg_path'] = $destination;
    }
  } else {
    // Avoid error when the form is submitted without specifying a new image
    $_POST['body_bg_path'] = $form_state['values']['body_bg_path'] = $previous;
  }
 
}

function stanford_basic_settings_validate($form, &$form_state) {
  $validators = array('file_validate_is_image' => array());
  // Check for a new uploaded logo.
  $file = file_save_upload('body_bg_upload', $validators);
  if (isset($file)) {
    // File upload was attempted.
    if ($file) {
      // Put the temporary file in form_values so we can save it on submit.
      $form_state['values']['body_bg_upload'] = $file;
    }
    else {
      // File upload failed.
      form_set_error('body_bg_upload', t('The background image could not be uploaded.'));
    }
  }
}