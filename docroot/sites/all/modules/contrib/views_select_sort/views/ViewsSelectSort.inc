<?php

/**
 * @file
 * Academic Term Sort handler.
 *
 * This filter allows views to Sort by academic term chronologically.
 */

/**
 * Class ViewsSelectSort.
 */
class ViewsSelectSort extends views_handler_sort {

  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $definitions = parent::option_definition();
    $values = $this->getValues();
    $i = 0;
    foreach ($values as $value) {
      $definitions['item_order'][$value] = array('default' => $i);
      $i++;
    }
    return $definitions;
  }

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    foreach ($this->getSortedValues() as $weight => $value) {
      $form['item_order'][$value]['label'] = array(
        '#markup' => $value,
      );
      $form['item_order'][$value]['weight'] = array(
        '#type' => 'weight',
        '#title' => t('Weight'),
        '#title_display' => 'invisible',
        '#default_value' => $weight,
      );
    }
    $form['#theme'] = 'views_select_sort_form';
        $form['#attached']['css'][] = drupal_get_path('module', 'views_select_sort') . '/css/views_select_sort.admin.css';
  }

  public function options_submit(&$form, &$form_state) {
    foreach ($form_state['values']['options']['item_order'] as &$weight) {
      $weight = $weight['weight'];
    }
    asort($form_state['values']['options']['item_order']);
    parent::options_submit($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function query() {
    $this->ensure_my_table();
    $order = $this->getSortedValues();

    $replace_string = '';
    foreach ($order as $weight => $value) {
      $weight = str_pad((string) $weight, strlen($weight), '0', STR_PAD_LEFT);
      if (!(int) $weight) {
        $replace_string = "replace(`{$this->real_field}`, '$value', '$weight-$value')";
      }
      else {
        $replace_string = "replace($replace_string, '$value', '$weight-$value')";
      }
    }

    if ($replace_string) {
      $this->query->add_orderby(NULL, $replace_string, $this->options['order'], $this->table_alias);
    }
  }

  /**
   * Get the values that can be used in the field.
   *
   * @return array
   *   Possible values of the field.
   */
  public function getValues() {
    $field = field_info_field($this->definition['field_name']);
    $items = array_keys($field['settings']['allowed_values']);
    asort($items);
    return $items;
  }

  /**
   * Get the values in a sorted order based on weight.
   *
   * @return array
   *   Ordered values.
   */
  public function getSortedValues() {
    $items = $this->options['item_order'];

    // If item weights haven't been set yet, use the initial definition.
    if (empty($items) || is_null($items)) {
      $definition = $this->option_definition();
      $items = $definition['item_order'];
    }
    asort($items);
    return array_keys($items);
  }

}
