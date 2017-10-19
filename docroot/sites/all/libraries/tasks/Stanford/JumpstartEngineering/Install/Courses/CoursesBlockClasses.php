<?php
/**
 * @file
 * Add block classes
 */

namespace Stanford\JumpstartEngineering\Install\Courses;
/**
 *
 */
class CoursesBlockClasses extends \ITasks\AbstractInstallTask {

  /**
   * Set Block Classes.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Install default Courses block classes.
    $values = array(
      array("views","-exp-courses-search_page","well")
    );

    foreach ($values as $k => $value) {
      $update = db_update('block')->fields(array('css_class' => $value[2]));
      $update->condition('module',$value[0]);
      $update->condition('delta',$value[1]);
      $update->execute();
    }
    
    CoursesBlockClasses_set_context();
  }
  /**
   *
   */
  public function requirements() {
    return array(
      'block_class',
    );
  }

}

/**
 * Callback to set context for courses.
 */
function CoursesBlockClasses_set_context() {
  
  $context = new \stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'courses';
  $context->description = 'All pages in the Courses section';
  $context->tag = 'Courses';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'courses' => 'courses',
        'courses/*' => 'courses/*',
        '~courses/tag*' => '~courses/tag*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-jumpstart-featured-course' => array(
          'module' => 'bean',
          'delta' => 'jumpstart-featured-course',
          'region' => 'sidebar_first',
          'weight' => '3',
        ),
        'views-exp-courses-search_page' => array(
          'module' => 'views',
          'delta' => '-exp-courses-search_page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  
  context_save($context);
}
