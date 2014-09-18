<?php
/**
 * @file
 * Default Installation Class for Jumpstart.
 * @author Shea McKinney <sheamck@stanford.edu>
 * @author John Bickar <jbickar@stanford.edu>
 */

/**
 * JumpStart Installation Profile Class
 */
class JumpstartSitesPlus extends JumpstartSites {

  /**
   * This function returns additional installation tasks that need to be
   * executed in order. This should install before any child tasks although
   * a child may alter that.
   * @return array an array of tasks to be performed after all the modules have
   * been enabled and installed.
   */
  public function get_install_tasks(&$install_state) {

     // Get parent tasks.
    $parent_tasks = parent::get_install_tasks($install_state);

    // Remove some tasks...
    unset($parent_tasks['JumpstartSites_stanford_sites_jumpstart_import_content']);
    unset($parent_tasks['JumpstartSites_stanford_sites_jumpstart_install_install_menu_items']);

    $tasks = array();

    $tasks['jsplus_import_content'] = array(
      'display_name' => st('JS+ Import Content.'),
      'display' => TRUE,
      'type' => 'normal',
      'function' => 'import_content',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    );

    $tasks['jsplus_install_menu_items'] = array(
      'display_name' => st('JS+ Install Menus.'),
      'display' => TRUE,
      'type' => 'normal',
      'function' => 'install_menu_items',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    );

    $tasks['jsplus_install_jsplus'] = array(
      'display_name' => st('JS+ Install Configure.'),
      'display' => TRUE,
      'type' => 'normal',
      'function' => 'install_jsplus',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    );

    $this->prepare_tasks($tasks, get_class());
    return array_merge($parent_tasks, $tasks);
  }

  /**
   * Adds a jumpstart sites fieldset and configuration options to the
   * installation process.
   * @param  [array] $form       [the install configuration form]
   * @param  [array] $form_state [the form state]
   * @return [array]             [the altered form array]
   */
  public function get_config_form(&$form, &$form_state) {
    // Get parent altered configuration first.
    $form = parent::get_config_form($form, $form_state);
    return $form;
   }

  /**
   * Handles the submit hook on the configuration form.
   * @param  [array] $form       [the form array]
   * @param  [array] $form_state [the form state]
   */
  public function get_config_form_submit($form, &$form_state) {

    $jumpstart_vars = array();
    foreach ($form['jumpstart'] as $key => $value) {
      if (substr($key, 1) == "#") { continue; }
      if (!isset($value['#value'])) { continue; }
      $jumpstart_vars[$key] = check_plain($value['#value']);
    }

    variable_set('stanford_jumpstart_install', $jumpstart_vars);
  }

  // TASKS
  // ///////////////////////////////////////////////////////////////////////////

  // ---------------------------------------------------------------------------

  /**
   * Import content from the content server.
   * @param  [type] $install_state [description]
   * @return [type]                [description]
   */
  public function import_content(&$install_state) {

    drush_log('JS+ - Importing Content', 'status');

    // Get base resources.
    $this->load_sites_content_importer_files($install_state);

     // Now that the library exists lets add our own custom processors.
    require_once "ImporterFieldProcessorCustomFieldSDestinationPublish.php";
    require_once "ImporterFieldProcessorCustomBody.php";

    // Where we getting the stuff man?
    $endpoint = (!empty($vars['fetch_endpoint'])) ? $vars['fetch_endpoint'] : 'https://sites.stanford.edu/jsa-content/jsainstall';

    // Restrictions
    // These entities we do not want even if they appear in the feed.
    $restrict = array(
      'tags',              // tags vocabulary
      'sites_products',    // products vocabulary
    );

    // Vocabularies.
    $importer = new SitesContentImporter();
    $importer->set_endpoint($endpoint);
    $importer->add_restricted_vocabularies($restrict);
    $importer->import_vocabulary_trees();

    // JS+ ONLY CONTENT
    $filters = array('sites_products' => array('41'));  // 41 is term id for JS+
    $view_importer = new SitesContentImporterViews();
    $view_importer->set_endpoint($endpoint);
    $view_importer->set_resource('content');
    $view_importer->set_filters($filters);
    $view_importer->import_content_by_views_and_filters();

    // BEANS
    $uuids = array(
      'e813c236-7400-4f43-ad18-736617ceb28e', // Jumpstart Home Page Banner Image.
      '8c4ed672-debf-45a5-8dfc-ef42794b975b', // Jumpstart Homepage Tall Banner
      'b66a5774-d0d1-44eb-abda-7aa8ea4eea0e', // Jumpstart Home Page About Block
      'b880d372-ef1c-4c85-93e8-6a47726d98c2', // Jumpstart Postcard with Video
      '2066e872-9547-40be-9342-dbfb81248589', // Jumpstart Footer Social Media Connect Block
      'ba352284-7aec-4044-a6dc-7e60441c2ccf', // Jumpstart Home Page In the Spotlight Block
      '864a97ac-ecd9-43b8-94be-da553c1e0426', // Jumpstart Footer Contact Block
      '67045bcc-06fc-4db8-9ef4-dd0ebb4e6d72', // Jumpstart Footer Optional Block
      'd643d114-c4bc-47b0-b0df-dbf1dc673a1a', // Jumpstart Info Text Block
      'f00c9906-971f-4d9d-b75c-23db1499318c', // Jumpstart Homepage Mission Block 2 (this should be 1, I think)
      '008d2300-a00d-4de9-bdce-39f7bc9f312d', // Jumpstart Homepage Mission Block 2
      '7c1bdc2c-cd07-4404-8403-8bdbe7ebc9bb', // Jumpstart Homepage Testimonial Block
      '68d11514-1a52-4716-94b4-3ef0110e75b2', // Jumpstart Lead Text With Body
      '8c4ed672-debf-45a5-8dfc-ef42794b975b', // Jumpstart Homepage Tall Banner
      'b7a04511-fcdb-49c4-a0c0-d4340cb35746', // Announcements
    );

    $importer = new SitesContentImporter();
    $importer->set_endpoint($endpoint);
    $importer->set_bean_uuids($uuids);
    $importer->import_content_beans();

    drush_log('JS+ - Finished Importing Content', 'ok');

  }

  // ---------------------------------------------------------------------------

  /**
   * Base configuraiton for jumpstart sites :O
   * Set variables, enable themes, adjust blocks, and set pathologic
   * @param  [array] $install_state [the current installation state]
   */
  public function install_jsplus(&$install_state) {
    drush_log('JS+ - Starting install settings', 'status');
    $site_name  = variable_get('site_name', "Stanford Jumpstart Plus");

    // Set the home page
    $home = drupal_lookup_path('source', 'home');
    variable_set('site_frontpage', $home);

    // Set the default theme
    variable_set('theme_default', 'stanford_framework');

    drush_log('JS+ - Finished install settings', 'ok');
  }

  // ---------------------------------------------------------------------------



  // ---------------------------------------------------------------------------

  /**
   * Installs and configures the menu for JS+
   * @param  [type] $install_state [description]
   */
  public function install_menu_items(&$install_state) {
    drush_log('JS+ - starting create menu items', 'ok');
    $items = array();

    // Rebuild the menu cache before starting this.
    drupal_static_reset();
    menu_cache_clear_all();
    menu_rebuild();

    // News Landing
    $items['news'] = array(
      'link_path' => drupal_get_normal_path('news'),
      'link_title' => 'News',
      'menu_name' => 'main-menu',
      'weight' => -9,
    );
    // News / Recent News
    $items['news/recent-news'] = array(
      'link_path' => 'news/recent-news',
      'link_title' => 'Recent News',
      'menu_name' => 'main-menu',
      'weight' => -9,
      'router_path' => 'news/recent-news',
      'parent' => 'news',
      'customized' => 1,
    );
    // Events Landing
    $items['events'] = array(
      'link_path' => drupal_get_normal_path('events'),
      'link_title' => 'Events',
      'menu_name' => 'main-menu',
      'weight' => -8,
    );
    // Events / Upcoming
    $items['events/upcoming-events'] = array(
      'link_path' => 'events/upcoming-events',
      'link_title' => 'Upcoming Events',
      'menu_name' => 'main-menu',
      'weight' => -10,
      'parent' => 'events',
      'router_path' => 'events/upcoming-events',
      'customized' => 1,
    );
    // Research
    $items['research'] = array(
      'link_path' => drupal_get_normal_path('research'),
      'link_title' => 'Research',
      'menu_name' => 'main-menu',
      'weight' => -7,
    );
    // People
    $items['people'] = array(
      'link_path' => drupal_get_normal_path('people'),
      'link_title' => 'People',
      'menu_name' => 'main-menu',
      'weight' => -6,
    );
    // Programs
    $items['programs'] = array(
      'link_path' => drupal_get_normal_path('programs'),
      'link_title' => 'Programs',
      'menu_name' => 'main-menu',
      'weight' => -5,
    );
    // About
    $items['about'] = array(
      'link_path' => drupal_get_normal_path('about'),
      'link_title' => 'About',
      'menu_name' => 'main-menu',
      'weight' => -4,
    );
    // About / About Us
    $items['about/about-us'] = array(
      'link_path' => drupal_get_normal_path('about/about-us'),
      'link_title' => 'Contact',
      'menu_name' => 'main-menu',
      'weight' => -8,
      'parent' => 'about', // must be saved prior to contact item.
    );
    // About / Contact
    $items['about/contact'] = array(
      'link_path' => drupal_get_normal_path('about/contact'),
      'link_title' => 'Contact',
      'menu_name' => 'main-menu',
      'weight' => -7,
      'parent' => 'about', // must be saved prior to contact item.
    );


    // Loop through each of the items and save them.
    foreach ($items as $k => $v) {

      // Check to see if there is a parent declaration. If there is then find
      // the mlid of the parent item and attach it to the menu item being saved.
      if (isset($v['parent'])) {
        $v['plid'] = $items[$v['parent']]['mlid'];
        unset($v['parent']); // Remove fluff before save.
      }

      // Save the menu item.
      $mlid = menu_link_save($v);
      $v['mlid'] = $mlid;
      $items[$k] = $v;

    }

    drush_log('JS+ - Finished create menu items', 'ok');


    // The home link weight needs to change.

    $home_search = db_select('menu_links', 'ml')
      ->fields('ml', array('mlid'))
      ->condition('menu_name', 'main-menu')
      ->condition('link_path', '<front>')
      ->condition('link_title', 'Home')
      ->execute()
      ->fetchAssoc();

    if (is_numeric($home_search['mlid'])) {
      $menu_link = menu_link_load($home_search['mlid']);
      $menu_link['weight'] = -50;
      menu_link_save($menu_link);
    }

    drush_log('JS+ - Finished updating menu wieghts', 'ok');
  }



}
