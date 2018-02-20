<?php

namespace Stanford\JumpstartEngineering\Install\Courses;
use \ITasks\AbstractInstallTask;

/**
 * Disable Courses module on JSE sites class.
 */
class DisableCourses extends AbstractInstallTask {

  /**
   * Disable Courses module on JSE sites.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Load up required modules.
    $required_modules = array('redirect', 'pathauto');
    foreach ($required_modules as $rm) {
      module_load_include('module', $rm, $rm . '.module');
      if (!module_exists($rm)) {
        throw new Exception($rm . ' module not available');
      }
    }

    // Disable the courses modules.
    $modules = array(
      'stanford_course_views',
      'stanford_courses_administration',
      'stanford_courses',
      'stanford_feeds_helper',
    );
    module_disable($modules);

    if (drupal_uninstall_modules($modules, FALSE)) {
      drush_log('Disabled and uninstalled modules: ' . implode(', ', $modules), 'ok');
    }
    else {
      throw new Exception('Error when uninstalling modules: ' . implode(', ', $modules));
    }

    // Publish courses node.
    $query = new \EntityFieldQuery();

    $entities = $query->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'stanford_page')
      ->propertyCondition('title', 'Courses Deprecated')
      ->execute();

    if (!empty($entities['node'])) {

      $node = node_load(array_shift(array_keys($entities['node'])));
      path_node_delete($node);
      $node->status = 1;
      $node->title = 'Courses';
      $node->path['alias'] = 'courses';
      $node->menu = array(
        'enabled' => 1,
      );
      node_save($node);
      redirect_delete_by_path('courses-deprecated');
      $alias = array(
        'source' => 'node/' . $node->nid,
        'alias' => 'about/courses',
      );
      path_save($alias);
      drush_log('Published node: ' . $node->title . ' ' . $node->nid, 'ok');
    }

  }

}
