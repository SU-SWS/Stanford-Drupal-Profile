<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Stanford\DrupalProfile\Install;
use \ITasks\AbstractInstallTask;

class SearchBlock extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {
    $blocks = array(
      array(
        'module' => 'search',
        'delta' => 'form',
        'theme' => 'open_framework',
        'status' => 1,
        'weight' => -1,
        'region' => 'search_box',
        'pages' => '',
        'cache' => -1,
      ),
      array(
        'module' => 'search',
        'delta' => 'form',
        'theme' => 'stanford_framework',
        'status' => 1,
        'weight' => -1,
        'region' => 'search_box',
        'pages' => '',
        'cache' => -1,
      ),
      array(
        'module' => 'search',
        'delta' => 'form',
        'theme' => 'stanford_jordan',
        'status' => 1,
        'weight' => -1,
        'region' => 'search_box',
        'pages' => '',
        'cache' => -1,
      ),
      array(
        'module' => 'search',
        'delta' => 'form',
        'theme' => 'stanford_light',
        'status' => 1,
        'weight' => -1,
        'region' => 'search_box',
        'pages' => '',
        'cache' => -1,
      ),
      array(
        'module' => 'search',
        'delta' => 'form',
        'theme' => 'stanford_wilbur',
        'status' => 1,
        'weight' => -1,
        'region' => 'search_box',
        'pages' => '',
        'cache' => -1,
      ),
    );
    $query = db_insert('block')->fields(array('module', 'delta', 'theme', 'status', 'weight', 'region', 'pages', 'cache'));
    foreach ($blocks as $block) {
      $query->values($block);
    }
    $query->execute();
  }

  /**
   * @param array $tasks
   */
  public function requirements() {
    return array(
      'block',
      'search',
    );
  }

}
