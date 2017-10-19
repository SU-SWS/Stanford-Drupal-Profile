<?php
/**
 * @file
 * Field Processor class
 */

/**
 *
 */
abstract class ImporterFieldProcessor {

  // Configuration array.
  protected $config = array();
  // Endpoint.
  protected $endpoint;
  // Processed items storage.
  static protected $process_storage = array();

  /**
   * [__construct description]
   */
  public function __construct($config = array()) {
    $this->set_configuration($config);
  }

  /**
   * [process description]
   * @return [type] [description]
   */
  abstract public function process(&$entity, $entity_type, $field_name);

  /**
   * [set_enpoint description]
   * @param [type] $endpoint [description]
   */
  public function set_endpoint($endpoint) {
    $this->endpoint = $endpoint;
  }

  /**
   * [get_endpoint description]
   * @return [type] [description]
   */
  public function get_endpoint() {
    return $this->endpoint;
  }

  /**
   * [set_configuration description]
   * @param array $params [description]
   */
  protected function set_configuration($params = array()) {

    $this->config = array_merge($this->config, $params);

    // Set endpoint if passed in params.
    if (isset($params['endpoint'])) {
      $this->set_endpoint($params['endpoint']);
    }

  }

    /**
   * [set_storage description]
   * @param [type] $key   [description]
   * @param [type] $value [description]
   */
  protected function set_storage($key, $value) {
    self::$process_storage[$key] = $value;
  }

  /**
   * [get_storage description]
   * @param  [type] $key [description]
   * @return [type]      [description]
   */
  public function get_storage($key) {

    if ($key == "all") {
      return self::$process_storage;
    }

    if (isset(self::$process_storage[$key])) {
      return self::$process_storage[$key];
    }

    return array();
  }



}
