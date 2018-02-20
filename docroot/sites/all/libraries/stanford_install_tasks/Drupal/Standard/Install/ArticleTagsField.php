<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Drupal\Standard\Install;
use \ITasks\AbstractInstallTask;

class ArticleTagsField extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {
    $help = st('Enter a comma-separated list of words to describe your content.');
    $instance = array(
      'field_name' => 'field_tags',
      'entity_type' => 'node',
      'label' => 'Tags',
      'bundle' => 'article',
      'description' => $help,
      'widget' => array(
        'type' => 'taxonomy_autocomplete',
        'weight' => -4,
      ),
      'display' => array(
        'default' => array(
          'type' => 'taxonomy_term_reference_link',
          'weight' => 10,
        ),
        'teaser' => array(
          'type' => 'taxonomy_term_reference_link',
          'weight' => 10,
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
      'taxonomy',
      'field',
    );
  }

}
