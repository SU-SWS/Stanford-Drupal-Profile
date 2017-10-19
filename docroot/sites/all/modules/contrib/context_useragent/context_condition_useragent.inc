<?php

/**
 * Expose paths as a context condition.
 */
class context_condition_useragent extends context_condition {
  /**
   * Omit condition values. We will provide a custom input form for our conditions.
   */
  function condition_values() {
    return array();
  }

  /**
   * Condition form.
   */
  function condition_form($context) {
    $form = parent::condition_form($context);
    unset($form['#options']);
    $form['#type'] = 'textfield';
    $form['#description'] = t('A regular expression pattern to match the useragent against.  Example: !d', array('!d' => '<code>Firefox</code>'));
    return $form;
  }

  /**
   * Condition form submit handler.
   */
  function condition_form_submit($values) {
    $values = (string) $values;
    $values = array($values);
    return $values;
  }

  /**
   * Execute.
   */
  function execute() {
    if ($this->condition_used()) {
      $browser = $_SERVER['HTTP_USER_AGENT'];
      foreach ($this->get_contexts() as $context) {
        $useragents = $this->fetch_from_context($context, 'values');
        if ($this->match($browser, $useragents)) {
          $this->condition_met($context);
        }
      }
    }
  }

  /**
   * Match the subject against a set of regex patterns.
   * Similar to drupal_match_path() but also handles negation through the use
   * of the ~ character.
   *
   * @param mixed $subject
   *   The subject string or an array of strings to be matched.
   * @param array $patterns
   *   An array of patterns. Any patterns that begin with ~ are considered
   *   negative or excluded conditions.
   * @param boolean $path
   *   Whether the given subject should be matched as a Drupal path. If TRUE,
   *   '<front>' will be replaced with the site frontpage when matching against
   *   $patterns.
   */
  protected function match($subject, $pattern) {
    $match = FALSE;
    $positives = $negatives = 0;
    $pattern = !is_array($pattern) ? $pattern : $pattern[0];
    if (preg_match("/$pattern/", $subject)) {
      $match = TRUE;
    }
    return $match;
  }
}
