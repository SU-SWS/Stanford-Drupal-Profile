<?php

namespace Stanford\JumpstartEngineering\Install\Courses;
use \ITasks\AbstractInstallTask;

/**
 * Enable Courses on JSE sites class.
 */
class EnableCourses extends AbstractInstallTask {

  /**
   * Enable Courses on JSE sites.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Load and verify required modules are available.
    $required_modules = array('redirect', 'pathauto', 'features');
    foreach ($required_modules as $rm) {
      module_load_include('module', $rm, $rm . '.module');
      if (!module_exists($rm)) {
        throw new Exception($rm . ' module not available');
      }
    }

    // Enable the courses modules.
    $modules = array(
      'stanford_courses',
      'stanford_course_views',
      'stanford_courses_administration',
    );

    if (module_enable($modules, TRUE)) {
      features_revert_module('stanford_course_views');
      drush_log('Enabled modules: ' . implode(', ', $modules), 'ok');
    }
    else {
      throw new Exception('Error when enabling modules: ' . implode(', ', $modules));
    }

    // Unpublish courses node.
    $query = new \EntityFieldQuery();

    $entities = $query->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'stanford_page')
      ->propertyCondition('title', 'Courses')
      ->execute();

    if (!empty($entities['node'])) {
      $node = node_load(array_shift(array_keys($entities['node'])));
      path_node_delete($node);
      $node->status = 0;
      $node->title = 'Courses Deprecated';
      $node->path['alias'] = 'courses-deprecated';
      $node->path['pathauto'] = 0;
      $node->menu = array(
        'enabled' => 0,
      );
      node_save($node);
      redirect_delete_by_path('courses');
      redirect_delete_by_path('about/courses');
      path_delete(array('source' => 'courses'));
      path_delete(array('source' => 'about/courses'));
      drush_log('Unpublished node: ' . $node->title . ' ' . $node->nid, 'ok');
    }
  }

  /**
   * Verify if Courses should be enabled.
   *
   * If the stanford_courses module has been enabled, don't enable anything.
   */
  public function verify() {
    if (module_exists('stanford_courses')) {
      drush_log('The Stanford Courses module is already enabled.', 'notice');
      return FALSE;
    }
    return TRUE;
  }

}
