<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Mapper;

use \Peekmo\JsonPath\JsonStore as JsonParser;
use CAPx\Drupal\Entities\CFEntity;

abstract class MapperAbstract implements MapperInterface {

  // Configuration settings.
  protected $config = array();

  // The entity that is being mapped.
  protected $entity;

  // The mapper configuration entity (CFEntity).
  protected $mapper;

  // Importer machine name this mapper is attached to.
  protected $importer;

  // Error storage so they can be fetched after everything has run.
  protected $errors = array();

  /**
   * Merges default configuration options with the passed in set.
   *
   * @param CFEntity $mapper
   *   [description]
   */
  public function __construct(CFEntity $mapper) {
    $this->setMapper($mapper);
    $this->addConfig($mapper->settings);
  }

  /**
   * Uses a JSONPath library and notation to find data in a parsed json array.
   * Documentation on JSON path: http://goessner.net/articles/JsonPath/
   *
   * @param  array $data the JSON array of data from the API
   * @param  string $path The JSONPath
   * @return array       an array of data sliced from the $data by $path.
   */
  public function getRemoteDataByJsonPath($data, $path) {

    if (empty($path)) {
      throw new \Exception("Path cannot be empty", 1);
    }

    // Wildcard paths need to have index association maintained. JSONPath does
    // not provide much help in this and we need to do funny things.
    if (strpos($path, "*")) {
      $parsed = $this->getRemoteDataWithWildcard($data, $path);
    }
    // No wildcard, just get stuff.
    else {
      $parsed = $this->getRemoteDataRegular($data, $path);
    }

    return $parsed;

  }

  /**
   * Returns an array of data that matched the given path.
   *
   * @param $data
   * @param $path
   * @return array
   */
  protected function getRemoteDataRegular($data, $path) {
    $jsonParser = new JsonParser($data);
    $parsed = $jsonParser->get($path);
    return $parsed;
  }

  /**
   * Returns an array of data that matched the given path with empty strings
   * for missing leaf items.
   * @param $data
   * @param $path
   */
  protected function getRemoteDataWithWildcard($data, $path) {

    // To maintain index association over wildcards we need to return an empty
    // result on a missing leaf. JSONPATH does not provide a nice way of doing
    // this out of the box at this point in time so we are going to have to
    // break up the requests in to parts.

    $pathParts = explode("*", $path);
    $lastPart = array_pop($pathParts);
    $countQuery = implode("*", $pathParts);
    $countQuery .= "*";

    $jsonParser = new JsonParser($data);
    $results = $jsonParser->get($path);
    $wildResults = $jsonParser->get($countQuery);

    // If the number of results matches the number of wildcards then we have no
    // Missing items. Just return the results.
    if (count($results) == count($wildResults)) {
      return $results;
    }

    // Darn, we have a mismatch in wildcards and leafs. Find out who is missing
    // and add an empty value for them in the return array.
    $parsed = array();
    $tmpData = $data;

    // Iterate over each of the wild card queries and evaluate the expression.
    foreach ($pathParts as $i => $part) {

      // Tack on the wildcard character to the end of the first expression.
      if ($i == 0) {
        $part .= "*";
      }
      else {
        $part = "$.*" . $part . "*";
      }

      $jsonParser = new JsonParser($tmpData);
      $tmpData = $jsonParser->get($part);
    }

    foreach ($tmpData as $values) {
      $jsonParser = new JsonParser($values);
      $result = $jsonParser->get("$" . $lastPart);
      if ($result) {
        $parsed[] = array_pop($result);
      }
      else {
        $parsed[] = "";
      }
    }

    return $parsed;
  }

  /**
   * Getter function
   * @return string the entity type
   */
  public function getEntityType() {
    return $this->getConfigSetting('entity_type');
  }

  /**
   * Getter function
   * @return string the bundle type
   */
  public function getBundleType() {
    return $this->getConfigSetting('bundle_type');
  }

  /**
   * Setter function
   * @param array the configuration array
   */
  protected function setConfig($config) {
    $this->config = $config;
  }

  /**
   * Getter function
   * @return array the configuration array
   */
  public function getConfig() {
    return $this->config;
  }

  /**
   * [addConfig description]
   * @param [type] $settings [description]
   */
  public function addConfig($settings) {

    $config = $this->getConfig();
    $settings['fieldCollections'] = array();

    if (isset($settings['collections'])) {
      foreach ($settings['collections'] as $fieldName => $fields) {

        $mapper = new \stdClass();
        $mapper->settings = array();
        $mapper->settings['entity_type'] = "field_collection_item";
        $mapper->settings['bundle_type'] = $fieldName;
        $mapper->settings['fields'] = $fields;
        $mapper->settings['properties'] = array();
        $mapper->settings['collections'] = array();
        $mapper->settings['multiple'] = FALSE;
        $mapper->settings['subquery'] = '';
        $mapper->settings['guuidquery'] = '';

        $settings['fieldCollections'][$fieldName] = new FieldCollectionMapper($mapper);
        $settings['fieldCollections'][$fieldName]->addConfig($mapper->settings);
      }
    }

    unset($settings['collections']);

    $config = array_merge($config, $settings);
    $this->setConfig($config);
  }

  /**
   * Getter function for a key in the config array
   * @param string $name the index key for an item in the config array.
   * @return mixed the value for a key in an associative array.
   */
  public function getConfigSetting($name) {
    if (isset($this->config[$name])) {
      return $this->config[$name];
    }
    else {
      throw new \Exception("No config setting by that name: " . $name);
    }
  }

  /**
   * Setter function
   * @param Entity $entity The entity to be worked on.
   */
  public function setEntity($entity) {
    $this->entity = $entity;
  }

  /**
   * Getter function
   * @return Entity the entity being worked on.
   */
  public function getEntity() {
    return $this->entity;
  }

  /**
   * [setMapper description]
   * @param [type] $mapper [description]
   */
  public function setMapper($mapper) {
    $this->mapper = $mapper;
  }

  /**
   * [getMapper description]
   * @return [type] [description]
   */
  public function getMapper() {
    return $this->mapper;
  }

  /**
   * Checks mapper status.
   *
   * @param string $importer
   *   Importer machine name.
   *
   * @return bool
   *  Mapper status.
   *
   * @todo finish this.
   */
  public function valid($importer) {
    return TRUE;
  }

  /**
   * Get importer machine name.
   *
   * @return string
   */
  public function getImporter() {
    return $this->importer;
  }

  /**
   * Set importer machine name.
   *
   * @param string $importer
   */
  public function setImporter($importer) {
    $this->importer = $importer;
  }

  /**
   * Adds an error to the storage array.
   * @param mixed $error
   *   Could be anything really. Most likely an exception object.
   */
  protected function setError($error) {
    $this->errors[] = $error;
  }

  /**
   * Returns and array of error or false if none.
   * @return [type] [description]
   */
  public function getErrors() {
    if (!empty($this->errors)) {
      return $this->errors;
    }
    return FALSE;
  }

  /**
   * [getMultipleEntityCount description]
   * @return [type] [description]
   */
  public function getMultipleEntityCountBySubquery($data) {
    $result = $this->getRemoteDataByJsonPath($data, $this->getConfigSetting("subquery"));
    return count($result);
  }

  /**
   * [getGUUID description]
   * @param  [type] $index [description]
   * @return [type]        [description]
   */
  public function getGUUID($data, $index) {
    $path = $this->getConfigSetting("guuidquery");
    if (empty($path)) {
      return '';
    }
    $guuids = $this->getRemoteDataByJsonPath($data, $path);
    return $guuids[$index];
  }

}
