<?php

/**
 * @file
 * Views integration for Workbench Access.
 *
 * Field to display the active section.
 *
 * @TODO: support multiple sections.
 */

class workbench_access_handler_field_section extends views_handler_field_prerender_list {
  function init(&$view, &$options) {
    parent::init($view, $options);
    if ($view->base_table == 'node_revision') {
      $this->additional_fields['nid'] = array('table' => 'node_revision', 'field' => 'nid');
    }
    else {
      $this->additional_fields['nid'] = array('table' => 'node', 'field' => 'nid');
    }
  }
  // Add the additional fields.
  function query() {
    $this->add_additional_fields();
  }

  function click_sort($order) {
    $active = workbench_access_get_active_tree();
    if (empty($active['access_scheme']['sort'])) {
      return;
    }
    foreach ($active['access_scheme']['sort'] as $sort) {
      $table = $this->query->ensure_table($sort['table']);
      if (!empty($table)) {
        $this->query->add_orderby($table, $sort['field'], (isset($sort['order'])) ? $sort['order'] : $order);
      }
    }
    // Logic to remove JOIN to the default table, which can cause duplicate results.
    $base_table = $this->view->base_table;
    if ($base_table == 'node' && isset($active['access_scheme']['adjust_join'])) {
      foreach ($active['access_scheme']['adjust_join'] as $table => $replace) {
        $join = $this->query->get_join_data($table, $base_table);
        if (isset($join->left_table) && $join->left_table == $replace['original_table']) {
          $this->query->table_queue[$table]['join']->left_table = $replace['new_table'];
          $this->query->table_queue[$table]['join']->left_field = $replace['new_field'];
          unset($this->query->tables['node'][$replace['original_table']]);
          unset($this->query->table_queue[$replace['original_table']]);
        }
      }
    }
  }

  function pre_render(&$values) {
    // We have to find the sections assigned to each node.
    // Load node data.
    $nids = array();
    foreach ($values as $result) {
      if (!empty($result->{$this->aliases['nid']})) {
        $nids[] = $result->{$this->aliases['nid']};
      }
    }
    $nodes = node_load_multiple($nids, array());

    // Now match the data to the active tree.
    $active = workbench_access_get_active_tree();
    foreach ($values as $value) {
      if (isset($value->{$this->aliases['nid']}) && isset($nodes[$value->{$this->aliases['nid']}]->workbench_access)) {
        foreach ($nodes[$value->{$this->aliases['nid']}]->workbench_access as $access_id) {
          $value->workbench_access[] = check_plain($active['tree'][$access_id]['name']);
          $this->items[$value->{$this->aliases['nid']}][$access_id]['value'] = check_plain($active['tree'][$access_id]['name']);
        }
      }
      else {
        $value->workbench_access = array();
      }
    }
  }

  // Only render() seems to work. What gives, Views?
  function render($values) {
    if (!isset($values->workbench_access)) {
      $values->workbench_access = array();
    }
    if ($this->options['type'] == 'separator') {
      return implode($this->sanitize_value($this->options['separator']), $values->workbench_access);
    }
    $variables['items'] = $values->workbench_access;
    $variables['type'] = $this->options['type'];
    return theme('item_list', $variables);
  }
}
