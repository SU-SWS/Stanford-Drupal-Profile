<?php
function stanfordmodern_form_system_theme_settings_alter(&$form, &$form_state) {
	
  // Page Layout
  $form['layout_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Page Layout'),
    '#description' => t('Use these settings to change the layout of the page.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  
  $form['layout_container']['layout_classes'] = array(
    '#type'          => 'radios',
    '#title'         => t('Select page layout'),
    '#default_value' => theme_get_setting('layout_classes'),
    '#options'       => array(
      '' => t('Fixed 960 px width, with standard 159 px sidebar(s) - <strong><em>Default</em></strong>'),
	  'news ' => t('Fixed 960 px width, with wide 279px sidebar'),
      'wide ' => t('Flexible 100% width, with flexible 16.5% sidebar(s)'),
    ),
  );
  
  $form['layout_container']['header_classes'] = array(
    '#type'          => 'radios',
    '#title'         => t('Select banner site title area to the right of Stanford signature'),
    '#default_value' => theme_get_setting('header_classes'),
    '#options'       => array(
      '' => t('Standard 450 px banner site title area - <strong><em>Default</em></strong>'),
      'sitename ' => t('Long 675 px banner site title area - requires all blocks (e.g., search block) to be removed from the header region'),
    ),
  );
    
  $form['layout_container']['icon_classes'] = array(
    '#type'          => 'radios',
    '#title'         => t('Select sidebar header image display'),
    '#default_value' => theme_get_setting('icon_classes'),
    '#options'       => array(
      '' => t('No sidebar header images - <strong><em>Default</em></strong>'),
	  'icon ' => t('Use sidebar header images'),
    ),
  );
  
  // Front Page Banner Graphic
  $form['banner_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Front Page Image'),
    '#description' => t('Use these settings to add an image to the front page.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  
  $form['banner_container']['banner_classes'] = array(
    '#type'          => 'radios',
    '#title'         => t('Select image display'),
    '#default_value' => theme_get_setting('banner_classes'),
    '#options'       => array(
      '' => t('No image - <strong><em>Default</em></strong>'),
	  'banner ' => t('Use image below:<br><br><table>
	  <tr><th style="padding-right: 30px;">Front page layout</th><th>Image dimensions</th></tr>
	  <tr><td style="padding-right: 30px;">Fixed 960 px width, with standard 159 px sidebar(s)</td><td>754 x 160 px</td></tr>
	  <tr><td style="padding-right: 30px;">Fixed 960 px width, with wide 279 px sidebar</td><td>635 x 160 px</td></tr>
	  <tr><td style="padding-right: 30px;">Fixed 960 px width, with no sidebars</td><td>940 x 160 px</td></tr>
	  </table>'),
    ),
  );
   
  // Default path for image
  $banner_image_path = theme_get_setting('banner_image_path');
  if (file_uri_scheme($banner_image_path) == 'public') {
    $banner_image_path = file_uri_target($banner_image_path);
  }
 
  // Helpful text showing the file name, disabled to avoid the user thinking it can be used for any purpose.
  $form['banner_container']['banner_image_path'] = array(
    '#type' => 'textfield',
    '#title' => 'Path to front page banner image',
    '#default_value' => $banner_image_path,
    '#disabled' => TRUE,
  );

  // Upload field
  $form['banner_container']['banner_image_upload'] = array(
    '#type' => 'file',
    '#title' => 'Upload front page banner image',
    '#description' => 'You can upload the following image file types: *.jpg, *.gif, or *.png',
  );

  // Attach custom submit handler to the form
  $form['#submit'][] = 'stanfordmodern_settings_submit';
}

function stanfordmodern_settings_submit($form, &$form_state) {
  $settings = array();
  // Get the previous value
  $previous = 'public://' . $form['banner_container']['banner_image_path']['#default_value'];
 
  $file = file_save_upload('banner_image_upload');
  if ($file) {
    $parts = pathinfo($file->filename);
    $destination = 'public://' . $parts['basename'];
    $file->status = FILE_STATUS_PERMANENT;
   
    if(file_copy($file, $destination, FILE_EXISTS_REPLACE)) {
      $_POST['banner_image_path'] = $form_state['values']['banner_image_path'] = $destination;
      // If new file has a different name than the old one, delete the old
      if ($destination != $previous) {
        drupal_unlink($previous);
      }
    }
  } else {
    // Avoid error when the form is submitted without specifying a new image
    $_POST['banner_image_path'] = $form_state['values']['banner_image_path'] = $previous;
  }
 
}