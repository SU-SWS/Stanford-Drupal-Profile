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
    unset($parent_tasks['JumpstartSites_stanford_sites_jumpstart_install_jumpstart_specific']);
    unset($parent_tasks['JumpstartSites_stanford_sites_jumpstart_configure_homepage']);

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

    $tasks['jsplus_menu_rules'] = array(
      'display_name' => st('Set Menu Position Rules'),
      'display' => FALSE,
      'type' => 'normal',
      'function' => 'menu_rules',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    );

    $tasks['jsplus_install_block_classes'] = array(
      'display_name' => st('JS+ Install Block Classes.'),
      'display' => TRUE,
      'type' => 'normal',
      'function' => 'install_block_classes',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    );

    $tasks['jsplus_install_redirects'] = array(
      'display_name' => st('JS+ Install Redirects.'),
      'display' => TRUE,
      'type' => 'normal',
      'function' => 'install_redirects',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    );

    $tasks['jsplus_install_jsplus'] = array(
      'display_name' => st('JS+ Install Configure.'),
      'display' => TRUE,
      'type' => 'normal',
      'function' => 'install_jsplus',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    );

    $tasks['jsplus_configure_homepage'] = array(
      'display_name' => st('Enables and sets the default homepage layouts.'),
      'display' => TRUE,
      'type' => 'normal',
      'function' => 'configure_homepage_layouts',
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
   * Insert the menu position rules.
   * @param  [type] $install_state [description]
   * @return [type]                [description]
   */
  public function menu_rules(&$install_state) {
    drush_log('JSA - Starting menu rules');

    // Define the rules.
    $rules = array();
    $rules[] = array(
      'link_title' => 'About',
      'admin_title' => 'About by path',
      'conditions' => array(
        'pages' => array(
          'pages' => 'about/*',
        ),
      ),
    );
    $rules[] = array(
      'link_title' => 'News',
      'admin_title' => 'News by content type',
      'conditions' => array(
        'content_type' => array(
          'content_type' => array(
            'stanford_news_item' => 'stanford_news_item',
          ),
        ),
      ),
    );
    $rules[] = array(
      'link_title' => 'News',
      'admin_title' => 'News by path',
      'conditions' => array(
        'pages' => array(
          'pages' => 'news/*',
        ),
      ),
    );
    $rules[] = array(
      'link_title' => 'Events',
      'admin_title' => 'Events by content type',
      'conditions' => array(
        'content_type' => array(
          'content_type' => array(
            'stanford_event' => 'stanford_event',
          ),
        ),
      ),
    );
    $rules[] = array(
      'link_title' => 'Events',
      'admin_title' => 'Events by path',
      'conditions' => array(
        'pages' => array(
          'pages' => 'events/*',
        ),
      ),
    );

    foreach ($rules as $mp_rule) {
      $this->insert_menu_rule($mp_rule);
    }

    drush_log('JSA - Finished menu rules');
  }

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

    // NODES
    // Import types
    $content_types = array(
      'stanford_event',
      'stanford_event_importer',
      'article',
      'stanford_person',
      'stanford_publication',
      'stanford_news_item',
      'stanford_course',
    );

    // Restrictions
    // These entities we do not want even if they appear in the feed.
    $restrict = array(
      '2efac412-06d7-42b4-bf75-74067879836c',   // Recent News Page
      '6d48181f-7387-40e8-81ba-199de7ede938',   // Courses Page.
    );

    $importer = new SitesContentImporter();
    $importer->set_endpoint($endpoint);
    $importer->add_import_content_type($content_types);
    $importer->add_uuid_restrictions($restrict);
    $importer->importer_content_nodes_recent_by_type();

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
      'b7a04511-fcdb-49c4-a0c0-d4340cb35746', // Announcements
      '8dc5934a-ee22-4c48-a125-d78ce3293ffa', // Jumpstart Affiliated Programs
    );

    $importer = new SitesContentImporter();
    $importer->set_endpoint($endpoint);
    $importer->set_bean_uuids($uuids);
    $importer->import_content_beans();

    drush_log('JS+ - Finished Importing Content', 'ok');

  }

  // ---------------------------------------------------------------------------

  /**
   * Install block classes
   * Insert the module, delta, and class name into the {block_class} table
   */
  public function install_block_classes(&$install_state) {
    drush_log('JS+ - Starting to install block classes.', 'status');
    // Block clases.
    $fields = array('module', 'delta', 'css_class');
    $values = array(
      array("bean","jumpstart-home-page-about","well"),
      array("bean","homepage-about-block", 'well'),
      array("bean","jumpstart-home-page-information-",'well'),
      array("bean","homepage-banner-image","block-no-bottom-margin"),
      array("bean","jumpstart-affiliated-programs","well"),
      array("bean","jumpstart-contact-us-postcard","well"),
      array("bean","jumpstart-degree-programs-info-f","well"),
      array("bean","jumpstart-featured-course","well"),
      array("bean","jumpstart-featured-event","well"),
      array("bean","jumpstart-featured-event-block","well"),
      array("bean","jumpstart-footer-contact-block","span3"),
      array("bean","jumpstart-footer-social-media--0","span3"),
      array("bean","jumpstart-footer-social-media-co","span3"),
      array("bean","jumpstart-graduate-student-sideb","well"),
      array("bean","jumpstart-homepage-announcements","well"),
      array("bean","jumpstart-homepage-testimonial-b","span6"),
      array("bean","jumpstart-home-page-academics","well"),
      array("bean","jumpstart-info-for-current-gra-0","span4 well"),
      array("bean","jumpstart-info-for-current-gra-1","span4 well"),
      array("bean","jumpstart-info-for-current-gradu","span4 well"),
      array("bean","jumpstart-info-for-current-und-0","span4 well"),
      array("bean","jumpstart-info-for-current-und-1","span4 well"),
      array("bean","jumpstart-info-for-current-under","span4 well"),
      array("bean","jumpstart-info-for-prospective-0","span4 well"),
      array("bean","jumpstart-info-for-prospective-1","span4 well"),
      array("bean","jumpstart-info-for-prospective-g","span4 well"),
      array("bean","jumpstart-info-text-block","span6"),
      array("bean","jumpstart-lead-text-with-body","span6"),
      array("bean","jumpstart-postcard-with-video","span6"),
      array("bean","jumpstart-twitter-block","well"),
      array("bean","jumpstart-why-i-teach","well"),
      array("bean","jumpstart-why-i-teach-block","well"),
      array("bean","optional-footer-block","span3"),
      array("bean","social-media","span4"),
      array("ds_extras","contact","well"),
      array("ds_extras","office_hours","well"),
      array("menu","menu-admin-shortcuts-add-feature","shortcuts-features"),
      array("menu","menu-admin-shortcuts-get-help","shortcuts-help"),
      array("menu","menu-admin-shortcuts-home","shortcuts-home"),
      array("menu","menu-admin-shortcuts-logout-link","shortcuts-logout"),
      array("menu","menu-admin-shortcuts-ready-to-la","shortcuts-launch"),
      array("menu","menu-admin-shortcuts-site-action","shortcuts-actions shortcuts-dropdown"),
      array("menu","menu-footer-news-events-menu","span2"),
      array("menu","menu-footer-people-menu","span2"),
      array("menu","menu-footer-academics-menu","span2"),
      array("menu","menu-footer-about-menu","span2"),
      array("menu","menu-related-links","span3"),
      array("stanford_jumpstart_layouts","jumpstart-launch","shortcuts-launch-block"),
      array("views","-exp-publications-page","well"),
      array("views","f73ff55b085ea49217d347de6630cd5a","well"),
      array("views","jumpstart_current_user-block","shortcuts-user"),
      array("views","publications_common-block_4","well"),
      array("views","stanford_news-block","well"),
      array("views","stanford_events_views-block","well"),
      array("views","-exp-stanford_person_staff-page","well"),
      array("views","-exp-stanford_news-page_1","well"),
      array("views","-exp-courses-search_page","well"),
      array("views","442e92af913370af5bffd333a036ceaa","well"),
      array("views","b38da907588eed2d09c10bdb381e5aaf","well"),
      array("views","4066d038591af2b511f66557e5ac41e8","well"),
      array("views","2d9147be40cd77d32915a554bf315858","well"),
      array("views","85c57f65aa0dee37d8aa5a5031e564bc","well"),
      array("views","5c84bdc5ea8289bceed723799d38940f","well"),
    );

    // Key all the values.
    $insert = db_insert('block_class')->fields($fields);
    foreach ($values as $k => $value) {
      $db_values = array_combine($fields, $value);
      $insert->values($db_values);
    }
    $insert->execute();

    drush_log('JS+ - Finished installing block classes.', 'ok');

  }

  // ---------------------------------------------------------------------------

  /**
   * Create redirects
   * Unlike block classes, we can do this in a programmatic way.
   */
  public function install_redirects(&$install_state) {
    drush_log('JS+ - Starting to install redirects', 'status');
    // Create redirects.
    $redirects = array(
      'news' => 'news/recent-news',
      'events' => 'events/upcoming-events',
      'about' => 'about/about-us',
    );

    foreach ($redirects as $source => $dest) {
      $redirect = new stdClass();
      $source_path = drupal_lookup_path('source', $source);

      if ($source_path == FALSE || $source_path == "<front>" || $source_path == "home") {
        $source_path = $source;
      }

      if (drupal_lookup_path('source', $dest)) {
        $dest = drupal_lookup_path('source', $dest);
      }

      // Check to see if redirect exists first.
      $found = redirect_load_by_source($source_path);
      if (!empty($found)) {
        // Redirect exists.
        continue;
      }

      module_invoke(
        'redirect',
        'object_prepare',
        $redirect,
        array(
          'source' => $source_path,
          'source_options' => array(),
          'redirect' => $dest,
          'redirect_options' => array(),
          'language' => LANGUAGE_NONE,
        )
      );

      if ($source_path !== $dest) {
        module_invoke('redirect', 'save', $redirect);
      }

    }

    drush_log('JS+ - Finished installing redirects.', 'ok');



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

    $page_not_found = drupal_lookup_path('source', '404');
    variable_set('site_404', $page_not_found);

    // Set menu position default setting to 'mark the rule's parent menu item as being "active".'
    variable_set('menu_position_active_link_display', 'parent');
    drush_log('JS+ - Finished install settings', 'ok');
  }

  // ---------------------------------------------------------------------------



  // ---------------------------------------------------------------------------

  /**
   * Installs and configures the menu for JS+
   * @param  [type] $install_state [description]
   */
  public function install_menu_items(&$install_state) {
    drush_log('JS+ - Starting to create menu items', 'status');
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
    // News / Subscribe
    $items['news/subscribe'] = array(
      'link_path' => drupal_get_normal_path('news/subscribe'),
      'link_title' => 'Subscribe',
      'menu_name' => 'main-menu',
      'weight' => -10,
      'router_path' => 'news/subscribe',
      'parent' => 'news',
      'customized' => 1,
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
    // Events / Past
    $items['events/past-events'] = array(
      'link_path' => 'events/past-events',
      'link_title' => 'Past Events',
      'menu_name' => 'main-menu',
      'weight' => -9,
      'parent' => 'events',
      'router_path' => drupal_get_normal_path('events/past-events'),
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
      'link_title' => 'About Us',
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
    // put the Views in the DB
    $this->save_all_default_views_to_db($install_state);
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
    // Back to code!
    $this->remove_all_default_views_from_db($install_state);
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

  /**
   * Enable a number of the home page layouts and set one to default on.
   * @param  [type] $install_state [description]
   * @return [type]                [description]
   */
  public function configure_homepage_layouts($install_state) {

    drush_log('JS+ - Configuring Home Page Layouts', 'ok');

    $default = 'stanford_jumpstart_home_palm_news_events';
    $context_status = variable_get('context_status', array());
    $homecontexts = stanford_jumpstart_home_context_default_contexts();

    $names = array_keys($homecontexts);

    // Enable these for site owners
    $enabled['stanford_jumpstart_home_lomita'] = 1;
    $enabled['stanford_jumpstart_home_mayfield_news_events'] = 1;
    $enabled['stanford_jumpstart_home_palm_news_events'] = 1;
    $enabled['stanford_jumpstart_home_panama_news_events'] = 1;
    $enabled['stanford_jumpstart_home_serra_news_events'] = 1;

    unset($context_status['']);

    foreach ($names as $context_name) {
      $context_status[$context_name] = TRUE;
      $settings = variable_get('sjh_' . $context_name, array());
      $settings['site_admin'] = isset($enabled[$context_name]);
      variable_set('sjh_' . $context_name, $settings);
    }

    $context_status[$default] = FALSE;
    unset($context_status['']);

    // Save settings
    variable_set('stanford_jumpstart_home_active', $default);
    variable_set('context_status', $context_status);

    drush_log('JS+ - Finished Configuring Home Page Layouts', 'ok');

  }



}
