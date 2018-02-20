<?php
/**
 * @file
 * Abstract Task Class
 */

namespace ITasks;
use \ITasks\AbstractTask;

/**
 * Abstract Update Task class.
 */
abstract class AbstractUpdateTask extends AbstractTask {

  // The description of this update task.
  protected $description = "No description provided";

  /**
   * Returns the descripton of this update task. This is what replaces the
   * doc block text.
   *
   * @return string
   *   A string of descriptive text.
   */
  public function getDescription() {
    return $this->description;
  }

  /**
   * [form description]
   * @param  [type] $form        [description]
   * @param  [type] &$form_state [description]
   * @return [type]              [description]
   */
  public function form(&$form, &$form_state) {
    return;
  }

}
