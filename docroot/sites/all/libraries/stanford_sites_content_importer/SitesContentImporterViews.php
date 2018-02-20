<?php
/**
 * @file
 * Content Import by Views Resource.
 *
 * Contains a class file that allows for fetching and receiving content from
 * the view based services resource.
 *
 * @author Shea McKinney <sheamck@stanford.edu>
 */

/**
 * Sites content importer class that can import by the view endpoint.
 */
class SitesContentImporterViews extends SitesContentImporter {

  protected $filters;
  protected $resource;

  /**
   * Imports Nodes by the filtered view endpoint.
   */
  public function importContentByViewsAndFilters() {

    $endpoint = $this->getEndpoint();
    $filters = $this->getFilters();
    $resource = $this->getResource();
    $ids = array();

    $filters = $this->prepareFilters();

    try {
      $response = drupal_http_request($endpoint . "/" . $resource . ".json?" . $filters);
    }
    catch (Exception $e) {
      watchdog('SitesContentImporterViews', 'Could not fetch: %s', array("%s" => $resource), WATCHDOG_NOTICE);
      if (function_exists('drush_log')) {
        drush_log('Could not fetch: ' . $resource, 'error');
      }
      return;
    }

    if ($response->code !== "200") {
      watchdog('SitesContentImporterViews', '%code | Could not fetch: %resource', array("%code" => $resource->code, "%resource" => $resource), WATCHDOG_NOTICE);
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

    $this->importerProcessNodesByUuids($ids);

  }

  /**
   * Set the filter parameters for the request to the service endpoint.
   *
   * @param array $filters
   *   A key -> value array of filters to use as request parameters.
   */
  public function setFilters($filters = array()) {
    $this->filters = $filters;
  }

  /**
   * Return the array of key value filters.
   *
   * The filters are sent along with the request to the service endpoint so that
   * the response only contains the content that the user is looking for.
   *
   * @return array
   *   An array of key -> values.
   */
  public function getFilters() {
    return $this->filters;
  }

  /**
   * Changes the filter array in to a url string.
   *
   * @return string
   *   A url stafe string of query parameters.
   */
  public function prepareFilters() {
    $filters = $this->getFilters();
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
   * Set the endpoint resource for the request.
   */
  public function setResource($resource) {
    $this->resource = $resource;
  }

  /**
   * Get the endpoint resource for the request.
   *
   * @return string
   *   The name of the services endpoint resource.
   */
  public function getResource() {
    return $this->resource;
  }

}
