<?php
/**
 * @file
 * This class creates new menu links.
 */

namespace Stanford\Utility\Install;

class CreateMenuLinks extends \ITasks\AbstractInstallTask {

  /**
   * Create new menu links.
   * @param array $args A multidimensional array.
   * Each secondary array has the following keys:
   *
   * link_path: (required) The path of the menu item, which should be normalized first by calling drupal_get_normal_path() on it.
   * link_title: (required) Title to appear in menu for the link.
   * menu_name: (optional) The machine name of the menu for the link. Defaults to 'navigation'.
   * weight: (optional) Integer to determine position in menu. Default is 0.
   * expanded: (optional) Boolean that determines if the item is expanded.
   * options: (optional) An array of options, see l() for more.
   * mlid: (optional) Menu link identifier, the primary integer key for each menu link. Can be set to an existing value, or to 0 or NULL to insert a new link.
   * plid: (optional) The mlid of the parent.
   * router_path: (optional) The path of the relevant router item.
   *
   * See https://api.drupal.org/api/drupal/includes!menu.inc/function/menu_link_save/7
   */

  public function execute(&$args = array()) {


    // Rebuild the menu cache before starting this.
    drupal_static_reset();
    menu_cache_clear_all();
    menu_rebuild();
    // Loop through each of the items and save them.
    foreach ($args as $k => $v) {
      // Check to see if there is a parent declaration. If there is then find
      // the mlid of the parent item and attach it to the menu item being saved.
      if (isset($v['parent'])) {
        $v['plid'] = $args[$v['parent']]['mlid'];
        unset($v['parent']); // Remove fluff before save.
      }
      // Save the menu item.
      $mlid = menu_link_save($v);
      $v['mlid'] = $mlid;
      $args[$k] = $v;
    }
  }

}

