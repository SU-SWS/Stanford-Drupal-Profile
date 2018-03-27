<?php
/**
 * @file
 * stanford_jumpstart_vpsa_events_import.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function stanford_jumpstart_vpsa_events_import_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'student_affairs_events_import';
  $feeds_importer->config = array(
    'name' => 'Student Affairs Events Import',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'title',
          'xpathparser:1' => 'Nid',
          'xpathparser:2' => 'body',
          'xpathparser:3' => 'date-and-time',
          'xpathparser:4' => 'status',
          'xpathparser:11' => 'location',
          'xpathparser:12' => 'RSVP',
          'xpathparser:13' => '',
          'xpathparser:15' => '',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
          'xpathparser:13' => 0,
          'xpathparser:15' => 0,
        ),
        'context' => '//nodes/node',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
            'xpathparser:13' => 0,
            'xpathparser:15' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'body',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_stanford_event_datetime:start',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'status',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_stanford_event_location',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_stanford_event_admission',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_stanford_event_categories',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:15',
            'target' => 'field_stanford_event_datetime:end',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'filtered_html',
        'authorize' => 1,
        'skip_hash_check' => 0,
        'bundle' => 'stanford_event',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['student_affairs_events_import'] = $feeds_importer;

  return $export;
}
