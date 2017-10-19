<?php
/**
 * @file
 * stanford_jumpstart_home.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_jumpstart_home_context_default_contexts() {
  $export = stanford_jumpstart_home_get_contexts();

  if (empty($export)) {
    return array();
  }

  return $export;
}

/**
 * Loads up and returns all contexts that are in the layouts folder.
 * @return [type] [description]
 */
function stanford_jumpstart_home_get_contexts($clear_cache = FALSE) {

  // cache_set($cid, $data, $bin = 'cache', $expire = CACHE_PERMANENT);
  // cache_get($cid, $bin = 'cache');
  // cache_clear_all($cid = NULL, $bin = NULL, $wildcard = FALSE)

  $cache = cache_get('jumpstart_home_context');
  $contexts = array();

  if (!$clear_cache && is_object($cache) && !isset($cache->data['']) && count($cache->data)) {
    $contexts = $cache->data;
  }
  else {
    $dir = drupal_get_path('module', 'stanford_jumpstart_home') . '/layouts';
    $mask = "/.*\.inc$/";
    $options['key'] = 'name';
    $files = file_scan_directory($dir, $mask, $options);

    foreach ($files as $name => $data) {
      include DRUPAL_ROOT . "/" . $data->uri;
      $contexts[$context->name] = $context;
    }

  }

  cache_set('jumpstart_home_context', $contexts);

  return $contexts;
}
