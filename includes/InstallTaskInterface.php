<?php
/**
 * @file
 * Task Interface
 */

interface InstallTaskInterface {

  /**
   * Do the task.
   *
   * @param array $args
   *   Arguments passed in from global scope.
   */
  public function execute(&$args = array());

  /**
   * Provide additional requirements.
   *
   * @return array
   *   An array of requirements.
   */
  public function requirements();


  /**
   * Install configure form alter hook callback.
   *
   * @return array
   *   An array of form fields
   */
  public function form(&$form, &$form_state);

  /**
   * Install configure form alter validate hook callback.
   */
  public function validate(&$form, &$form_state);


  /**
   * Install configure form alter submit hook callback.
   */
  public function submit(&$form, &$form_state);

}
