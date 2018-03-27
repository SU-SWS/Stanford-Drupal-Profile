<?php

/**
 * Expose active subsite properties as a context condition.
 */
class context_condition_active_subsite extends context_condition {

  /**
   * Returns the values that can be selected (subsite nodes).
   *
   * @return array
   *   An array of condition values (subsite nodes)
   */
  public function condition_values() {
    $values = array();
    $values['any'] = "-- " . t("Any Subsite") . " --";
    $values['none'] = "-- " . t("No Active Subsite") . " --";

    // Get all subsite nodes.
    $query = db_select('node', 'n')
              ->fields('n', array('nid', 'title'))
              ->condition('type', SUBSITE_CONTENT_TYPE)
              ->execute();

    while ($result = $query->fetchAssoc()) {
      $values[$result['nid']] = check_plain($result['title']);
    }

    return $values;
  }

  /**
   * Execute the condition.
   */
  public function execute() {

    // Grab subsites array.
    $subsite = stanford_subsites_get_active_subsite();

    if (!$subsite) {
      // Grab all the contexts.
      foreach ($this->get_contexts("none") as $context) {
        $this->condition_met($context, "none");
      }
      return;
    }

    // Loop through contexts with nid value and assert condition met.
    foreach ($this->get_contexts($subsite->nid) as $context) {
      $this->condition_met($context, $subsite->nid);
    }

    // Grab all the contexts.
    foreach ($this->get_contexts("any") as $context) {
      if (isset($subsite->nid)) {
        $this->condition_met($context, "any");
      }
    }

  }


}
