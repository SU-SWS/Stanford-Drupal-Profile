<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\Jumpstart\Install\Block;
/**
 *
 */
class BlockSettings extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // This is needed here after enabling themes so that blocks get built into
    // the blocks table with the new themes.
    drupal_flush_all_caches();

    // If we're using WMD hide the block.
    // @todo: Refactor this out once environment stuff is set.
    if (module_exists("webauth")) {
      db_update('block')
        ->fields(array('status' => 0))
        ->condition('module', 'webauth')
        ->condition('delta', 'webauth_login_block')
        ->execute();
    }

    // If we are using the sites_helper module hide the block.
    if (module_exists("stanford_sites_helper")) {
      db_update('block')
        ->fields(array('status' => 0))
        ->condition('module', 'stanford_sites_helper')
        ->condition('delta', 'firststeps')
        ->execute();
      db_update('block')
        ->fields(array('status' => 0))
        ->condition('module', 'stanford_sites_helper')
        ->condition('delta', 'helplinks')
        ->execute();
    }

    // Always hide blocks.
    db_update('block')
      ->fields(array('status' => 0))
      ->condition('module', 'system')
      ->condition('delta', 'navigation')
      ->execute();

    db_update('block')
      ->fields(array('status' => 0))
      ->condition('module', 'search')
      ->condition('delta', 'form')
      ->execute();

    db_update('block')
      ->fields(array('status' => 0))
      ->condition('module', 'user')
      ->condition('delta', 'login')
      ->execute();

  }

  /**
   * [requirements description]
   * @return [type] [description]
   */
  public function requirements() {
    return array(
      'system',
      'search',
      'user',
    );
  }

}
