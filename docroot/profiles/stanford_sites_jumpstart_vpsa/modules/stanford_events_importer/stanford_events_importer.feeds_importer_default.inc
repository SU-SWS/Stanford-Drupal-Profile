<?php
/**
 * @file
 * stanford_events_importer.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function stanford_events_importer_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'stanford_event_importer';
  $feeds_importer->config = array(
    'name' => 'Stanford Event Importer',
    'description' => 'Import from events.stanford.edu',
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
          'xpathparser:1' => 'guid',
          'xpathparser:2' => 'description',
          'xpathparser:3' => 'isoEventDate',
          'xpathparser:4' => 'status',
          'xpathparser:5' => 'Audience/audienceName',
          'xpathparser:7' => 'contactPhone',
          'xpathparser:8' => 'imageUrl',
          'xpathparser:9' => 'sponsor',
          'xpathparser:10' => 'url',
          'xpathparser:11' => 'locationText',
          'xpathparser:12' => 'admissionDescription',
          'xpathparser:13' => 'Category/categoryName',
          'xpathparser:14' => 'contactEmail',
          'xpathparser:15' => 'isoEventEndDate',
          'xpathparser:16' => 'concat(\'http://events.stanford.edu/ical/download.php?id=\',eventID)',
          'xpathparser:17' => 'mapUrl',
          'xpathparser:18' => 'eventStatus',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
          'xpathparser:13' => 0,
          'xpathparser:14' => 0,
          'xpathparser:15' => 0,
          'xpathparser:16' => 0,
          'xpathparser:17' => 0,
          'xpathparser:18' => 0,
        ),
        'context' => '//EventList/Event',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:4' => 0,
            'xpathparser:3' => 0,
            'xpathparser:5' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
            'xpathparser:13' => 0,
            'xpathparser:14' => 0,
            'xpathparser:15' => 0,
            'xpathparser:16' => 0,
            'xpathparser:17' => 0,
            'xpathparser:18' => 0,
          ),
        ),
        'allow_override' => 0,
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
            'unique' => FALSE,
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
            'source' => 'xpathparser:5',
            'target' => 'field_stanford_event_audience',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_stanford_event_phone',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_stanford_event_image',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_stanford_event_sponsor',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_stanford_event_url:url',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_stanford_event_location',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_stanford_event_admission',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_stanford_event_categories',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'xpathparser:14',
            'target' => 'field_stanford_event_email',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'xpathparser:15',
            'target' => 'field_stanford_event_datetime:end',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'xpathparser:16',
            'target' => 'field_stanford_event_add_to_cal:url',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'xpathparser:17',
            'target' => 'field_s_event_map_link:url',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'xpathparser:18',
            'target' => 'field_s_event_feed_type',
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
    'content_type' => 'stanford_event_importer',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['stanford_event_importer'] = $feeds_importer;

  return $export;
}
