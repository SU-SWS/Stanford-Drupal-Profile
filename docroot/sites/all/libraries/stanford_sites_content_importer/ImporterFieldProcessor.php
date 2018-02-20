<?php
/**
 * @file
 * Field Processor class.
 */

/**
 * Importer Field Procecessor Abstract Class.
 *
 * To extend all of the field processor classes.
 */
abstract class ImporterFieldProcessor {

  // Configuration array.
  protected $config = array();

  // Endpoint.
  protected $endpoint;

  /**
   * A storage variable for saveing arbitrary data.
   *
   * @var array
   */
  static protected $processStorage = array();

  /**
   * Instantiate the class with configuration.
   *
   * @param array $config
   *   An array of configuration options.
   */
  public function __construct($config = array()) {
    $this->setConfiguration($config);
  }

  /**
   * Process a field.
   *
   * @param object $entity
   *   The entity object that is being worked on.
   * @param string $entity_type
   *   The type of entity that is passed in.
   * @param string $field_name
   *   The name of the field to be processed on the $entity.
   */
  abstract public function process(&$entity, $entity_type, $field_name);

  /**
   * Sets the services endpoint.
   *
   * @param string $endpoint
   *   A URL to the services endpoint where all of the information being
   *   processed is coming from.
   *   eg: https://sites.stanford.edu/jsa-content/jsa-install/.
   */
  public function setEndpoint($endpoint) {
    $this->endpoint = $endpoint;
  }

  /**
   * Returns the endpoint configuration setting.
   *
   * @return string
   *   A url endpoint that was set in setEndpoint().
   */
  public function getEndpoint() {
    return $this->endpoint;
  }

  /**
   * Set the configuration options for this field processor.
   *
   * @param array $params
   *   An array of configuration options in key => value format.
   */
  protected function setConfiguration($params = array()) {

    $this->config = array_merge($this->config, $params);

    // Set endpoint if passed in params.
    if (isset($params['endpoint'])) {
      $this->setEndpoint($params['endpoint']);
    }

  }

  /**
   * Save information in a key => value array for later.
   *
   * @param mixed $key
   *   The associative array key for the stored value.
   * @param mixed $value
   *   The value for the $key.
   */
  protected function setStorage($key, $value) {
    self::$processStorage[$key] = $value;
  }

  /**
   * Fetch the stored information.
   *
   * @param mixed $key
   *   The key of the associative array for the value you wish to have returned.
   *   If "all" is passed in the whole array will be returned back.
   *
   * @return mixed
   *   The value of key or the whole array if "all" is passed in as a parameter.
   */
  public function getStorage($key) {

    if ($key == "all") {
      return self::$processStorage;
    }

    if (isset(self::$processStorage[$key])) {
      return self::$processStorage[$key];
    }

    return array();
  }

}
