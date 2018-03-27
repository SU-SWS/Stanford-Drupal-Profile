<?php
/**
 * @file
 * Contains the subsite argument default plugin.
 */

/**
 * Default argument plugin to provide a subsite as an option.
 */
class views_plugin_argument_default_subsite extends views_plugin_argument_default {

  /**
   * [option_definition description]
   * @return [type] [description]
   */
  public function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * [options_form description]
   * @param  [type] $form       [description]
   * @param  [type] $form_state [description]
   * @return [type]             [description]
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  /**
   * Only let users with administer sws permissions set/modify this
   * default plugin.
   */
  public function access() {
    return user_access('administer sws');
  }

  /**
   * [get_argument description]
   * @return [type] [description]
   */
  public function get_argument() {
    // Set up variables to make it easier to reference during the argument.
    $view = &$this->view;
    $argument = &$this->argument;
    ob_start();
    $subsite = stanford_subsites_get_active_subsite();

    if (isset($subsite->nid)) {
      $result = $subsite->nid;
    }
    else {
      $result = 0;
    }

    ob_end_clean();
    return $result;
  }
}
