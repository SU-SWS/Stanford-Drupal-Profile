<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Drupal\Standard\Install;
use \ITasks\AbstractInstallTask;

class ArticleImageFieldInstance extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {
    // Many of the following values will be defaulted, they're included here as an illustrative examples.
    // See http://api.drupal.org/api/function/field_create_instance/7
    $instance = array(
      'field_name' => 'field_image',
      'entity_type' => 'node',
      'label' => 'Image',
      'bundle' => 'article',
      'description' => st('Upload an image to go with this article.'),
      'required' => FALSE,

      'settings' => array(
        'file_directory' => 'field/image',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'alt_field' => TRUE,
        'title_field' => '',
      ),

      'widget' => array(
        'type' => 'image_image',
        'settings' => array(
          'progress_indicator' => 'throbber',
          'preview_image_style' => 'thumbnail',
        ),
        'weight' => -1,
      ),

      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'image',
          'settings' => array('image_style' => 'large', 'image_link' => ''),
          'weight' => -1,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'image',
          'settings' => array('image_style' => 'medium', 'image_link' => 'content'),
          'weight' => -1,
        ),
      ),
    );
    field_create_instance($instance);
  }

  /**
   * [requirements description]
   * @return [type] [description]
   */
  public function requirements() {
    return array(
      'image',
      'file',
      'field',
      'node',
    );
  }

}
