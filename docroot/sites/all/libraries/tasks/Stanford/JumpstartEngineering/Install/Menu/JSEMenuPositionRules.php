<?php
/**
 * @file
 * Create JSE Menu Position rules.
 */

namespace Stanford\JumpstartEngineering\Install\Menu;
/**
 *
 */
class JSEMenuPositionRules extends \ITasks\AbstractInstallTask {

  /**
   * Create Menu Position rules.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    # Set menu position default setting to 'mark the rule's parent menu item as being "active".'
    variable_set('menu_position_active_link_display', 'parent');

    // Define the rules.
    $rules = array();
    $rules[] = array(
      'link_title' => 'About',
      'admin_title' => 'About by path',
      'machine_name' => 'about_by_path',
      'conditions' => array(
        'pages' => array(
          'pages' => 'about/*',
        ),
      ),
    );
    $rules[] = array(
      'link_title' => 'Research',
      'admin_title' => 'Research by path',
      'machine_name' => 'research_by_path',
      'conditions' => array(
        'pages' => array(
          'pages' => 'research/*',
        ),
      ),
    );
    $rules[] = array(
      'link_title' => 'Resources',
      'admin_title' => 'Resources by path',
      'machine_name' => 'resources_by_path',
      'conditions' => array(
        'pages' => array(
          'pages' => 'resources/*',
        ),
      ),
    );
    $rules[] = array(
      'link_title' => 'News',
      'admin_title' => 'News by content type',
      'machine_name' => 'news_by_content_type',
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
      'machine_name' => 'news_by_path',
      'conditions' => array(
        'pages' => array(
          'pages' => 'news/*',
        ),
      ),
    );
    $rules[] = array(
      'link_title' => 'Events',
      'admin_title' => 'Events by content type',
      'machine_name' => 'events_by_content_type',
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
      'machine_name' => 'events_by_path',
      'conditions' => array(
        'pages' => array(
          'pages' => 'events/*',
        ),
      ),
    );
    $rules[] = array(
      'link_title' => 'People',
      'admin_title' => 'People by content type',
      'machine_name' => 'people_by_content_type',
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
      'machine_name' => 'people_by_path',
      'conditions' => array(
        'pages' => array(
          'pages' => 'people/*',
        ),
      ),
    );
    $rules[] = array(
      'link_title' => 'Publications',
      'admin_title' => 'Publications by content type',
      'machine_name' => 'publications_by_content_type',
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
      'machine_name' => 'faculty_by_taxonomy',
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
      'machine_name' => 'staff_by_taxonomy',
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
      'machine_name' => 'students_by_taxonomy',
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
      'machine_name' => 'news_by_taxonomy',
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
