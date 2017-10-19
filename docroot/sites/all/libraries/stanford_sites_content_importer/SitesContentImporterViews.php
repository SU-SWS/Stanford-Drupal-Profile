<?php
/**
 * @file
 * @author  Shea McKinney <sheamck@stanford.edu>
 */
class SitesContentImporterViews extends SitesContentImporter {

  protected $filters;
  protected $resource;

  /**
   * [__construct description]
   */
  public function __construct() {

  }

  /**
   * Imports Nodes by the filter
   */
  public function import_content_by_views_and_filters() {

    $endpoint = $this->get_endpoint();
    $filters = $this->get_filters();
    $resource = $this->get_resource();
    $ids = array();

    $filters = $this->prepare_filters();

    try {
      $response = drupal_http_request($endpoint . "/" . $resource . ".json?" . $filters);
    }
    catch(Exception $e) {
      watchdog('SitesContentImporterViews', 'Could not fetch: ' . $resource, array(), WATCHDOG_NOTICE);
      if (function_exists('drush_log')) {
        drush_log('Could not fetch: ' . $resource, 'error');
      }
      return;
    }

    if ($response->code !== "200") {
      watchdog('SitesContentImporterViews', $resource->code . ' | Could not fetch: ' . $resource, array(), WATCHDOG_NOTICE);
      if (function_exists('drush_log')) {
        drush_log($resource->code . ' | Could not fetch: ' . $resource, 'error');
      }
    }

    $data = drupal_json_decode($response->data);

    if (!array($data) || count($data) < 1) {
       watchdog('SitesContentImporterViews', 'No content available', array(), WATCHDOG_NOTICE);
      if (function_exists('drush_log')) {
        drush_log('No content available for import by views.', 'warning');
      }
      return;
    }

    foreach ($data as $k => $id_array) {
      $ids[$id_array['node_uuid']] = $id_array;
    }

    $this->importer_process_nodes_by_uuids($ids);

  }

  /**
   * [set_filters description]
   * @param array $filters [description]
   */
  public function set_filters($filters = array()) {
    $this->filters = $filters;
  }

  /**
   * [get_filters description]
   * @return [type] [description]
   */
  public function get_filters() {
    return $this->filters;
  }

  /**
   * [prepare_filters description]
   * @return [type] [description]
   */
  public function prepare_filters() {
    $filters = $this->get_filters();
    $filter_string = '';

    foreach ($filters as $field_name => $values) {
      if (is_array($values)) {
        $filter_string .= $field_name . '=' . implode(',', $values);
      }
      else {
        $filter_string .= $field_name . '=' . $values;
      }

      $filter_string .= "&";
    }

    return rtrim($filter_string, '&');
  }

  /**
   * [set_resource description]
   */
  public function set_resource($resource) {
    $this->resource = $resource;
  }

  /**
   * [get_resource description]
   * @return [type] [description]
   */
  public function get_resource() {
    return $this->resource;
  }

}
