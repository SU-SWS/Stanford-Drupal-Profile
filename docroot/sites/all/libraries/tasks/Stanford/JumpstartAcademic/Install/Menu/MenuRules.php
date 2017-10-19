<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\JumpstartAcademic\Install\Menu;
/**
 *
 */
class MenuRules extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    //module_load_include('inc', 'menu_position', 'menu_position.admin');
    # Set menu position default setting to 'mark the rule's parent menu item as being "active".'
    variable_set('menu_position_active_link_display', 'parent');
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
      'link_title' => 'Academics',
      'admin_title' => 'Academics by path',
      'conditions' => array(
        'pages' => array(
          'pages' => 'academics/*',
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
    $rules[] = array(
      'link_title' => 'People',
      'admin_title' => 'People by content type',
      'conditions' => array(
        'content_type' => array(
          'content_type' => array(
            'stanford_person' => 'stanford_person',
          ),
        ),
      ),
    );
    $rules[] = array(
      'link_title' => 'People',
      'admin_title' => 'People by path',
      'conditions' => array(
        'pages' => array(
          'pages' => 'people/*',
        ),
      ),
    );
    $rules[] = array(
      'link_title' => 'Publications',
      'admin_title' => 'Publications by content type',
      'conditions' => array(
        'content_type' => array(
          'content_type' => array(
            'stanford_publication' => 'stanford_publication',
          ),
        ),
      ),
    );
    $vocabulary = taxonomy_vocabulary_machine_name_load('stanford_faculty_type');
    $vid = $vocabulary->vid;
    $rules[] = array(
      'link_title' => 'People',
      'admin_title' => 'Faculty by taxonomy',
      'conditions' => array(
        'taxonomy' => array(
          'vid' => $vid,
          'tid' => array(),
        ),
      ),
    );
    $vocabulary = taxonomy_vocabulary_machine_name_load('stanford_staff_type');
    $vid = $vocabulary->vid;
    $rules[] = array(
      'link_title' => 'People',
      'admin_title' => 'Staff by taxonomy',
      'conditions' => array(
        'taxonomy' => array(
          'vid' => $vid,
          'tid' => array(),
        ),
      ),
    );
    $vocabulary = taxonomy_vocabulary_machine_name_load('stanford_student_type');
    $vid = $vocabulary->vid;
    $rules[] = array(
      'link_title' => 'People',
      'admin_title' => 'Students by taxonomy',
      'conditions' => array(
        'taxonomy' => array(
          'vid' => $vid,
          'tid' => array(),
        ),
      ),
    );
    $vocabulary = taxonomy_vocabulary_machine_name_load('news_categories');
    $vid = $vocabulary->vid;
    $rules[] = array(
      'link_title' => 'News',
      'admin_title' => 'News by taxonomy',
      'conditions' => array(
        'taxonomy' => array(
          'vid' => $vid,
          'tid' => array(),
        ),
      ),
    );

    foreach ($rules as $mp_rule) {
      $rule = new \Stanford\Utility\Install\InsertMenuRule();
      $rule->insert_menu_rule($mp_rule);
    }

  }

}
