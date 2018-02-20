<?php
/**
 * @file
 * Abstract Task Class
 */

namespace Drupal\Standard\Install;
use \ITasks\AbstractInstallTask;

class StandardBlocks extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *  Installation arguments.
   */
  public function execute(&$args = array()) {
    // Enable some standard blocks.
    $default_theme = variable_get('theme_default', 'bartik');
    $admin_theme = 'seven';
    $admin_blocks = array(
      array(
        'module' => 'node',
        'delta' => 'recent',
        'theme' => $admin_theme,
        'status' => 1,
        'weight' => 10,
        // Region is set to 'dashboard_main' in the Standard installation profile, but we don't want dashboard as a dependency.
        'region' => -1,
        'pages' => '',
        'cache' => -1,
      ),
      array(
        'module' => 'system',
        'delta' => 'main',
        'theme' => $admin_theme,
        'status' => 1,
        'weight' => 0,
        'region' => 'content',
        'pages' => '',
        'cache' => -1,
      ),
      array(
        'module' => 'system',
        'delta' => 'help',
        'theme' => $admin_theme,
        'status' => 1,
        'weight' => 0,
        'region' => 'help',
        'pages' => '',
        'cache' => -1,
      ),
      array(
        'module' => 'user',
        'delta' => 'login',
        'theme' => $admin_theme,
        'status' => 1,
        'weight' => 10,
        'region' => 'content',
        'pages' => '',
        'cache' => -1,
      ),
      array(
        'module' => 'user',
        'delta' => 'new',
        'theme' => $admin_theme,
        'status' => 1,
        'weight' => 0,
        // Region is set to 'dashboard_main' in the Standard installation profile, but we don't want dashboard as a dependency.
        'region' => -1,
        'pages' => '',
        'cache' => -1,
      ),
      array(
        'module' => 'search',
        'delta' => 'form',
        'theme' => $admin_theme,
        'status' => 1,
        'weight' => -10,
        // Region is set to 'dashboard_main' in the Standard installation profile, but we don't want dashboard as a dependency.
        'region' => -1,
        'pages' => '',
        'cache' => -1,
      ),
    );

    $query = db_insert('block')->fields(array('module', 'delta', 'theme', 'status', 'weight', 'region', 'pages', 'cache'));
    foreach ($admin_blocks as $block) {
      $query->values($block);
    }

    $query->execute();


    $default_blocks = array(
      array(
        'module' => 'system',
        'delta' => 'main',
        'theme' => $default_theme,
        'status' => 1,
        'weight' => 0,
        'region' => 'content',
        'pages' => '',
        'cache' => -1,
      ),
      array(
        'module' => 'search',
        'delta' => 'form',
        'theme' => $default_theme,
        'status' => 1,
        'weight' => -1,
        'region' => 'sidebar_first',
        'pages' => '',
        'cache' => -1,
      ),
      array(
        'module' => 'user',
        'delta' => 'login',
        'theme' => $default_theme,
        'status' => 1,
        'weight' => 0,
        'region' => 'sidebar_first',
        'pages' => '',
        'cache' => -1,
      ),
      array(
        'module' => 'system',
        'delta' => 'navigation',
        'theme' => $default_theme,
        'status' => 1,
        'weight' => 0,
        'region' => 'sidebar_first',
        'pages' => '',
        'cache' => -1,
      ),
      // No one will miss me.
      // array(
      //   'module' => 'system',
      //   'delta' => 'powered-by',
      //   'theme' => $default_theme,
      //   'status' => 1,
      //   'weight' => 10,
      //   'region' => 'footer',
      //   'pages' => '',
      //   'cache' => -1,
      // ),
      array(
        'module' => 'system',
        'delta' => 'help',
        'theme' => $default_theme,
        'status' => 1,
        'weight' => 0,
        'region' => 'help',
        'pages' => '',
        'cache' => -1,
      ),

    );

    foreach ($default_blocks as $block) {
      $query = db_update('block')
        ->fields($block)
        ->condition("module", $block['module'])
        ->condition("theme", $block['theme'])
        ->condition("delta", $block['delta'])
        ->execute();
    }

  }

  /**
   * [requirements description]
   * @return [type] [description]
   */
  public function requirements() {
    return array(
      'user',
      'search',
      'system',
      'node',
      // 'dashboard', // We don't want to enable dashboard. See comments above.
    );
  }

}
