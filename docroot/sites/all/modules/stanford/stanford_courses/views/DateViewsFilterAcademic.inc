<?php

/**
 * @file
 * Academic date filter handler.
 *
 * This filter allows views admins to put in exceptions to the date filter where
 * the filter range and be dependant on the current date.
 */

/**
 * Class DateViewsFilterAcademic.
 */
class DateViewsFilterAcademic extends date_views_filter_handler_simple {

  private $simpleOps = array();

  /**
   * {@inheritdoc}
   */
  public function extra_options_submit($form, &$form_state) {

    // Errors occur if this is not unset.
    // From Pook:
    // basically when you add a date filter it starts with the granularity form,
    // then after submitting that it goes to the actual value form. it kept
    // giving me an error after trying to save the granularity form.
    // Clues here: https://api.drupal.org/api/views/includes%21admin.inc/function/views_ui_add_form_to_stack/7.x-3.x
    unset($form_state['view']->stack);

    parent::extra_options_submit($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function operators() {
    // Store the simple operator for our own use later.
    // eg: > , <, =, !=.
    $operators = parent::operators();
    foreach ($operators as $key => $operator) {
      if ($operator['method'] == 'op_simple') {
        $this->simpleOps[] = $key;
      }
    }
    return $operators;
  }

  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['add_exception'] = array('default' => 0);
    $options['exception'] = array(
      'contains' => array(
        'from' => array(
          'contains' => array(
            'month' => array('default' => 1),
            'day' => array('default' => 1),
          ),
        ),
        'to' => array(
          'contains' => array(
            'month' => array('default' => 1),
            'day' => array('default' => 1),
          ),
        ),
        'value' => array('default' => ''),
      ),
    );
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Set the values to relative if the add exception is available.
    if ($this->options['add_exception']) {
      $form['value']['value_group']['value_choose_input_type']['#default_value'] = 'relative';
      $form['value']['min_group']['min_choose_input_type']['#default_value'] = 'relative';
      $form['value']['max_group']['max_choose_input_type']['#default_value'] = 'relative';
    }

    // Show / Hide states for the exception options.
    $states = array(array(':input[name="options[add_exception]"]' => array('checked' => TRUE)));

    // Loop each one.
    foreach ($this->simpleOps as $op) {
      $op_states[] = array(':input[name="options[operator]"]' => array('value' => $op));
    }

    // Hide type selectors.
    $form['value']['value_group']['value_choose_input_type']['#states']['invisible'] = $this->splitStates($states);
    $form['value']['min_group']['min_choose_input_type']['#states']['invisible'] = $this->splitStates($states);
    $form['value']['max_group']['max_choose_input_type']['#states']['invisible'] = $this->splitStates($states);

    // Hide date select field.
    $form['value']['value_group']['value']['#states']['invisible'] = $this->splitStates($states);
    $form['value']['min_group']['min']['#states']['invisible'] = $this->splitStates($states);
    $form['value']['max_group']['max']['#states']['invisible'] = $this->splitStates($states);

    // Show the relative options.
    $form['value']['value_group']['default_date']['#states']['visible'] = array(
      array(':input.value-choose-input-type' => array('value' => 'relative')),
      array(':input[name="options[add_exception]"]' => array('checked' => TRUE)),
    );

    $form['value']['min_group']['default_date']['#states']['visible'] = array(
      array(':input.min-choose-input-type' => array('value' => 'relative')),
      array(':input[name="options[add_exception]"]' => array('checked' => TRUE)),
    );

    $form['value']['max_group']['default_to_date']['#states']['visible'] = array(
      array(':input.max-choose-input-type' => array('value' => 'relative')),
      array(':input[name="options[add_exception]"]' => array('checked' => TRUE)),
    );

    $form['add_exception'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add Exception Timeframe'),
      '#description' => t('Only works with relative dates & non-exposed filters.'),
      '#default_value' => $this->options['add_exception'],
      '#states' => array(
        'visible' => $this->splitStates($op_states),
      ),
    );

    $form['exception'] = array(
      '#type' => 'fieldset',
      '#title' => t('Exception'),
      '#states' => array(
        'visible' => $this->splitStates($states),
      ),
    );

    $cal = cal_info(0);
    $days = range(0, 31);
    unset($days[0]);

    $form['exception']['from'] = array(
      '#type' => 'fieldset',
      '#title' => t('From'),
      '#attributes' => array(
        'class' => array('views-left-50', 'clearfix'),
      ),
    );
    $form['exception']['from']['month'] = array(
      '#type' => 'select',
      '#title' => t('Month'),
      '#options' => $cal['months'],
      '#default_value' => $this->options['exception']['from']['month'],
      '#prefix' => '<div class="views-left-50">',
      '#suffix' => '</div>',
    );
    $form['exception']['from']['day'] = array(
      '#type' => 'select',
      '#title' => t('Day'),
      '#options' => $days,
      '#default_value' => $this->options['exception']['from']['day'],
      '#prefix' => '<div class="views-left-50">',
      '#suffix' => '</div>',
    );

    $form['exception']['to'] = array(
      '#type' => 'fieldset',
      '#title' => t('To'),
      '#attributes' => array(
        'class' => array('views-left-50', 'clearfix'),
      ),
    );
    $form['exception']['to']['month'] = array(
      '#type' => 'select',
      '#title' => t('Month'),
      '#options' => $cal['months'],
      '#default_value' => $this->options['exception']['to']['month'],
      '#prefix' => '<div class="views-left-50">',
      '#suffix' => '</div>',
    );
    $form['exception']['to']['day'] = array(
      '#type' => 'select',
      '#title' => t('Day'),
      '#options' => $days,
      '#default_value' => $this->options['exception']['to']['day'],
      '#prefix' => '<div class="views-left-50">',
      '#suffix' => '</div>',
    );

    $form['exception']['value'] = array(
      '#type' => 'textfield',
      '#title' => t('Relative Date during exception'),
      '#default_value' => $this->options['exception']['value'],
    );

  }

  /**
   * Validate provided configuration options.
   *
   * @param array $form
   *   The form array.
   * @param array $form_state
   *   The form_state array.
   *
   * @return array
   *   The options array.
   */
  public function options_validate(&$form, &$form_state) {
    if ($form_state['values']['options']['add_exception']) {
      $exception = $form_state['values']['options']['exception'];
      if ($exception['from']['month'] == $exception['to']['month'] && $exception['from']['day'] == $exception['to']['day']) {
        form_error($form['exception'], t('Invalid timeframe.'));
      }

      if (empty($form_state['values']['options']['value']['value_group']['default_date'])) {
        form_error($form['value']['value_group']['default_date'], t('Invalid relative time.'));
      }
    }

    // TODO: Change the autogenerated stub.
    return parent::options_validate($form, $form_state);
  }

  /**
   * Splits array of jQuery states with or between them.
   *
   * @param array $states
   *   Associative array of jQuery states.
   *
   * @return array
   *   Associative array of jQuery states split with or between them
   */
  private function splitStates($states) {
    $new_states = array();
    foreach ($states as $state) {
      if ($new_states) {
        $new_states[] = 'or';
      }
      $new_states[] = $state;
    }
    return $new_states;
  }

  /**
   * {@inheritdoc}
   */
  public function op_simple($field) {
    if ($this->addException()) {
      $this->exception();
    }
    parent::op_simple($field);
  }

  /**
   * Helper function to determine if the current date is within the exception.
   *
   * @return bool
   *   Not in exception timeframe.
   */
  private function exception() {
    $exception = $this->options['exception'];
    if (!$exception['value'] || !$this->parseDate($exception['value'])) {
      return FALSE;
    }
    $from = $exception['from']['month'] . '/' . $exception['from']['day'];
    $to = $exception['to']['month'] . '/' . $exception['to']['day'];

    // Spans over January 1st so add one year.
    if ($this->parseDate($to) - $this->parseDate($from) < 0) {
      $to += 60 * 60 * 24 * 365;
    }

    if ($this->parseDate(date('n/j')) <= $this->parseDate($to) &&
      $this->parseDate(date('n/j')) >= $this->parseDate($from)
    ) {
      $this->options['default_date'] = $exception['value'];
    }
  }

  /**
   * Helper function to attempt to parse a string as a date.
   *
   * @param string $date
   *   Date string.
   *
   * @return int
   *   Timestamp of the given date. 0 if it is unable to parse.
   */
  private function parseDate($date) {
    try {
      $d = new DateTime($date);
      return $d->getTimestamp();
    }
    catch (Exception $e) {
      return 0;
    }
  }

  /**
   * {@inheritdoc}
   */
  public function is_exposed() {
    if ($this->addException()) {
      return FALSE;
    }
    return parent::is_exposed();
  }

  /**
   * Checks if exception time is given.
   *
   * @return bool
   *   If filter is configured to have an exception time period.
   */
  private function addException() {
    if (in_array($this->options['operator'], $this->simpleOps) &&
      isset($this->options['add_exception']) &&
      $this->options['add_exception']
    ) {
      return TRUE;
    }
    return FALSE;
  }

}
