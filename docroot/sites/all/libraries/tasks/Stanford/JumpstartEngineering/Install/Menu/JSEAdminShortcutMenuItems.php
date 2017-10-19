<?php
/**
 * @file
 * Create menu items for the site actions menu (admin shortcuts)
 */

namespace Stanford\JumpstartEngineering\Install\Menu;
use Stanford\Utility\Install\CreateMenuLinks;

/**
 *
 */
class JSEAdminShortcutMenuItems extends \ITasks\AbstractInstallTask {

  /**
   * Create menu items.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Get the parent link id for the "Site actions" menu item
    $plid = array();
    $parent = 'admin/stanford/jumpstart/shortcuts/site-actions';
    $menu_name = 'menu-admin-shortcuts';
    $menu_info = db_select('menu_links', 'ml')
      ->condition('ml.link_path', $parent)
      ->condition('ml.menu_name', $menu_name)
      ->fields('ml', array('mlid', 'plid'))
      ->execute()
      ->fetchAll();

    foreach ($menu_info as $key => $value) {
      $plid[] = $menu_info[$key]->mlid;
    }

    // Manage meta tags.
    $items['admin/stanford/jumpstart/shortcuts/site-actions/manage-metatags'] = array(
      'link_path' => drupal_get_normal_path('admin/config/search/metatags'),
      'link_title' => 'Manage Meta Tags',
      'menu_name' => 'menu-admin-shortcuts',
      'plid' => $plid[0],
      'weight' => 30,
    );

    // Manage redirects.
    $items['admin/stanford/jumpstart/shortcuts/site-actions/manage-redirects'] = array(
      'link_path' => drupal_get_normal_path('admin/config/search/redirect'),
      'link_title' => 'Manage URL Redirects',
      'menu_name' => 'menu-admin-shortcuts',
      'plid' => $plid[0],
      'weight' => 32,
    );

    $linker = new \Stanford\Utility\Install\CreateMenuLinks();
    $linker->execute($items);

  }

}
