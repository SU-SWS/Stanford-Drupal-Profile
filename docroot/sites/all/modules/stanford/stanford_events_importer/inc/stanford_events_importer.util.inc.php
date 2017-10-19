<?php
/**
 * @file
 * Helper function and utilities for the events importer. :)
 * @author Shea McKinney <sheamck@stanford.edu>
 */

/**
 * Fetches and returns a multidimensional array of keys from the events xml.
 * This function will make live calls to the feed.php stream as well as cache
 * the data into the variables array for later usage. :
 * @return array
 *   an array of keys arranged as such:
 *   [importer node nid] => array
 *        [guid] (url) => [guid2] (integer-integer)
 *        [guid] => [guid2]
 *   [importer node nid] => array
 *        [guid] => [guid2]
 *        [guid] => [guid2]
 */
function stanford_events_importer_update_7200_get_xml_keys() {

  // An array of urls to fetch.
  $urls = stanford_events_importer_update_7200_get_xml_urls();

  // Get the xml contents.
  $data = stanford_events_importer_update_7200_process_xml_feeds($urls);

  // Generate guid mapping keys.
  $keys = array();
  foreach ($data as $importer_node_id => $xml) {
    $these_keys = stanford_events_importer_update_7200_process_xml_to_guids($xml);
    $keys[$importer_node_id] = $these_keys;
  }

  return $keys;
}

/**
 * Gets and returns an array of xml feeds that are being consumed.
 * @return array
 *   An array of urls
 */
function stanford_events_importer_update_7200_get_xml_urls() {
  $query = db_select('feeds_source', 'fs')
              ->fields('fs', array('source', 'feed_nid'))
              ->condition('id', 'stanford_event_importer')
              ->execute();

  $nids = $query->fetchAllAssoc('feed_nid');

  if (!is_array($nids)) {
    return FALSE;
  }

  $results = array();
  foreach ($nids as $nid => $data) {
    $results[$nid] = $data->source;
  }

  return $results;
}

/**
 * Gets and returns a nested array of XML data
 * @param  array  $feeds an array of feed urls keyed with the feed_nid
 * @return array
 *   An array of arrays of arrays of xml data as arrays
 */
function stanford_events_importer_update_7200_process_xml_feeds($feeds = array()) {

  // Some quick validation.
  if (!is_array($feeds) || empty($feeds)) {
    return FALSE;
  }

  $return_data = array();

  foreach ($feeds as $nid => $url) {

    // No guarantees this will work.
    try {
      $response = drupal_http_request($url);
    }
    catch(Exception $e) {
      watchdog('stanford_events_importer', 'http request timed out for: ' . $url, array(), WATCHDOG_ERROR);
      continue;
    }

    // Bad response.
    if ($response->code !== "200" || empty($response->data)) {
      watchdog('stanford_events_importer', 'http request failed with error code: ' . $response->code . '. URL: ' . $url, array(), WATCHDOG_ERROR);
      continue;
    }

    // Turn data into something usable.
    $xml = new SimpleXMLElement($response->data);
    $return_data[$nid] = $xml;
  }

  return $return_data;
}


/**
 * Processes an array of xml event objects into a guid mapping table
 * @param  array  $xml_events an array of xml event objects created by simplexml
 * @return array
 *   an array of guid mappings: guid => guid2
 */
function stanford_events_importer_update_7200_process_xml_to_guids($xml = array()) {
  $mappings = array();
  $i = 0;
  while ($event = $xml->Event[$i]) {
    $guid = (string) $event->guid;
    $guid2 = (string) $event->guid2;
    if (empty($guid2)) {
      $i++;
      continue;
    }
    $mappings[$guid] = $guid2;
    $i++;
  }
  return $mappings;
}

