<?php
/**
 * @file
 * This file contains slightly modified code from the delete_all module by
 * Khalid Baheyldin, Doug Green, Kevin O and Brian Gilbert.
 * see: http://www.drupal.org/project/delete_all
 */

function _stanford_courses_delete_all_normal($types) {
  $results = array();
  $deleted = 0;
  if (is_array($types) && count($types) > 0) {
    foreach ($types as $type) {
      $results[] = db_query(
        'SELECT nid FROM {node} WHERE type = :type',
        array(':type' => $type)
      );
    }
  }
  else {
    $results[] = db_query(
      'SELECT nid FROM {node}'
    );
  }
  foreach ($results as $result) {
    if ($result) {
      foreach ($result as $data) {
        set_time_limit(30);
        node_delete($data->nid);
        $deleted ++;
      }
    }
  }
  return $deleted;
}

function _stanford_courses_delete_all_quick($types) {
  $deleted = 0;
  foreach ($types as $type) {
    // keep this alive
    set_time_limit(240);

    // determine how many items will be deleted
    $count = db_result(db_query("SELECT COUNT(*) FROM {node} WHERE type = '%s'", $type));
    if ($count) { // should always be positive
      /**
       * build a list of tables that need to be deleted from
       *
       * The tables array is of the format table_name => array('col1', 'col2', ...)
       * where "col1, col2" are using "nid, vid", but could simply be "nid".
       */

      $nid_vid = array('nid', 'vid');
      $nid = array('nid');
      $tables = array('node_revisions' => $nid_vid, 'comments' => $nid);
      $tables[_content_tablename($type, CONTENT_DB_STORAGE_PER_CONTENT_TYPE)] = $nid_vid;
      $content = content_types($type);
      if (count($content['fields'])) {
        foreach ($content['fields'] as $field) {
          $field_info = content_database_info($field);
          $tables[$field_info['table']] = $nid_vid;
        }
      }

      // find all other tables that might be related
      switch ($GLOBALS['db_type']) {
        case 'mysql':
        case 'mysqli':
          $result_tables = db_query("SHOW TABLES");
          while ($data = db_fetch_array($result_tables)) {
            $table = array_pop($data);
            if (isset($tables[$table]) || substr($table, 0, 8) == 'content_') {
              continue;
            }
            $result_cols = db_query("SHOW COLUMNS FROM %s", $table);
            $cols = array();
            while ($data = db_fetch_array($result_cols)) {
              $cols[$data['Field']] = $data;
            }
            if (isset($cols['nid'])) {
              $tables[$table] = isset($cols['vid']) ? $nid_vid : $nid;
            }
          }
          break;

        case 'pgsql':
          // @TODO: inspect the database and look for nid fields
          break;
      }

      // @todo: update all node related nid references
      // delete from all of the content tables in one sql statement
      $sql = array('delete' => array(), 'from' => array(), 'where' => array());
      $index = 0;
      foreach ($tables as $table => $cols) {
        $table = '{' . $table . '}';
        $sql['cols'][] = "t$index.*";
        // build the ON clause
        $on = array();
        foreach ($cols as $col) {
          $on[] = "t$index.$col = n.$col";
        }
        // now that we have the ON clause, build the join clause
        $sql['join'][] = " LEFT JOIN $table t$index ON " . implode(' AND ', $on);
        $index ++;
      }
      $delete_sql = "DELETE n.*, " . implode(', ', $sql['cols']) . " FROM {node} n " . implode(' ', $sql['join']);
      db_query($delete_sql . " WHERE n.type = '%s'", $type);

      $deleted += $count;
    }
  }
  return $deleted;
}
