<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Drupal\Standard\Install;
use \ITasks\AbstractInstallTask;

class ArticleContentType extends AbstractInstallTask {

  // Add a short description.
  protected $description = "Installs the Drupal Standard Arcticle content type.";

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    $type = array(
      'type' => 'article',
      'name' => st('Article'),
      'base' => 'node_content',
      'description' => st('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'custom' => 1,
      'modified' => 1,
      'locked' => 0,
    );

    $rdf = array(
      'type' => 'node',
      'bundle' => 'article',
      'mapping' => array(
        'field_image' => array(
          'predicates' => array('og:image', 'rdfs:seeAlso'),
          'type' => 'rel',
        ),
        'field_tags' => array(
          'predicates' => array('dc:subject'),
          'type' => 'rel',
        ),
      ),
    );

    $type = node_type_set_defaults($type);
    node_type_save($type);
    node_add_body_field($type);

    // Save RDF
    rdf_mapping_save($rdf);

    // Default "Basic page" to not be promoted and have comments disabled.
    variable_set('node_options_page', array('status'));
    variable_set('comment_page', COMMENT_NODE_HIDDEN);

    // Don't display date and author information for "Basic page" nodes by default.
    variable_set('node_submitted_page', FALSE);

  }

  /**
   * [requirements description]
   * @return [type] [description]
   */
  public function requirements() {
    return array(
      'node',
      'rdf',
    );
  }

}
