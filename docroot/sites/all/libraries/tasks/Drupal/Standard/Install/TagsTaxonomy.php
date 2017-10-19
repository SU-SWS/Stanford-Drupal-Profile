<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Drupal\Standard\Install;

class TagsTaxonomy extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {
    // Create a default vocabulary named "Tags", enabled for the 'article' content type.
    $description = st('Use tags to group articles on similar topics into categories.');
    $vocabulary = (object) array(
      'name' => st('Tags'),
      'description' => $description,
      'machine_name' => 'tags',
    );
    taxonomy_vocabulary_save($vocabulary);

    $field = array(
      'field_name' => 'field_' . $vocabulary->machine_name,
      'type' => 'taxonomy_term_reference',
      // Set cardinality to unlimited for tagging.
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'settings' => array(
        'allowed_values' => array(
          array(
            'vocabulary' => $vocabulary->machine_name,
            'parent' => 0,
          ),
        ),
      ),
    );
    field_create_field($field);
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



