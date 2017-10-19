<?php
/**
 * @file
 * This function saves all of the available views in to the database so that
 * the menu system can find them.
 */

namespace Stanford\Utility\Install;

/**
 * Menu imports process does not find any paths from views defined in
 * features at this point. We will need to make it aware of them before
 * trying to import the menus links. Menu import uses drupal_valid_path() in
 * order to determine if a path is valid. drupal_valid_path() looks into the
 * menu router table for paths. At this point the menu_router table does not
 * have any views urls.
 *
 * menu_rebuild() doesn't work. Nice try!
 */

class ViewsToDB extends \ITasks\AbstractInstallTask {


  public function execute(&$args = array()) {

    // Load up and save all views to the db.
    $implements = module_implements('views_default_views');
    $views = array();
    foreach ($implements as $module_name) {
      $views += call_user_func($module_name . "_views_default_views");
    }

    // Initialize! Alive!
    foreach ($views as $view) {
      $view->save(); // this unfortunately enables (turns on) the view as well.
    }

  }

  /**
   *
   */
  public function requirements() {
    return array(
      'views',
    );
  }

}

