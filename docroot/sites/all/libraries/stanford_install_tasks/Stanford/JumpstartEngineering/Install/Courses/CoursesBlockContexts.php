<?php

namespace Stanford\JumpstartEngineering\Install\Courses;

use \ITasks\AbstractInstallTask;

/**
 * Set courses context class.
 */
class CoursesBlockContexts extends AbstractInstallTask {

  /**
   * Set Block Contexts for courses.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

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

  /**
   * Class requirements.
   */
  public function requirements() {
    return array(
      'context',
    );
  }

}
