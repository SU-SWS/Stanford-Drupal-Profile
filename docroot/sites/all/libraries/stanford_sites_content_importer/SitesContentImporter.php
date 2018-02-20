<?php
/**
 * @file
 * Sites Content Importer.
 *
 * Saves content from a Drupal services REST server.
 *
 * @author Shea McKinney <sheamck@stanford.edu>
 */

// Field processors.
require_once "ImporterFieldProcessor.php";
require_once "ImporterFieldProcessorDatetime.php";
require_once "ImporterFieldProcessorEmail.php";
require_once "ImporterFieldProcessorFieldCollection.php";
require_once "ImporterFieldProcessorFile.php";
require_once "ImporterFieldProcessorImage.php";
require_once "ImporterFieldProcessorInterface.php";
require_once "ImporterFieldProcessorLinkField.php";
require_once "ImporterFieldProcessorListText.php";
require_once "ImporterFieldProcessorNumberInteger.php";
require_once "ImporterFieldProcessorTaxonomyTermReference.php";
require_once "ImporterFieldProcessorText.php";
require_once "ImporterFieldProcessorTextLong.php";
require_once "ImporterFieldProcessorTextWithSummary.php";
require_once "ImporterFieldProcessorEntityreference.php";

// Property Processors.
require_once "ImporterPropertyProcessorUid.php";

// Alternate importers.
include_once "SitesContentImporterViews.php";


/**
 * Content Importer class.
 */
class SitesContentImporter {

  protected $endpoint;
  protected $resource;
  protected $arguments;
  protected $method;
  protected $processStorage = array();
  protected $beanUuids = array();
  protected $contentTypes = array();
  protected $restrictions = array();
  protected $restrictedVocabularies = array();
  protected $responseFormatType = ".json";
  protected $registry = array('property' => array(), 'field' => array());

  /**
   * Constructor.
   *
   * Nothing fancy here.
   */
  public function __construct() {
    // Nothing to see here.
  }

  /**
   * Returns response format type.
   *
   * The type of format you wish to receive from the content server. This can
   * be .json or .xml typically.
   *
   * @return string
   *   The format type. eg: .json.
   */
  public function getResponseFormatType() {
    return $this->responseFormatType;
  }

  /**
   * Set the desired response format type from the content server.
   *
   * @param string $type
   *   The type of response document you wish to return.
   *
   * @return bool
   *   FALSE if not valid.
   */
  public function setResponseFormatType($type = ".json") {
    if (!is_string($type)) {
      return FALSE;
    }
    $this->responseFormatType = $type;
  }

  /**
   * Set the endpoint of the content server in which to interact with.
   *
   * @param string $endpoint
   *   A url for the endpoint of the content server.
   *   eg: https://sites.stanford.edu/jsa-content/jsa-install.
   */
  public function setEndpoint($endpoint) {
    $this->endpoint = $endpoint;
  }

  /**
   * Return the endpoint of the content server.
   *
   * @return string
   *   The url of the content server endpoint.
   */
  public function getEndpoint() {
    return $this->endpoint;
  }

  /**
   * Arbitrary data storage set method.
   *
   * @param string $key
   *   The associated key with the value store.
   * @param mixed $value
   *   The data to store at $key.
   */
  protected function setStorage($key, $value) {
    $this->processStorage[$key] = $value;
  }

  /**
   * Get data out of the arbitrary data store.
   *
   * @param string $key
   *   The index key for the data you wish to return.
   *
   * @return mixed
   *   The value of $key
   */
  public function getStorage($key) {

    if ($key == "all") {
      return $this->processStorage;
    }

    if (isset($this->processStorage[$key])) {
      return $this->processStorage[$key];
    }

    return array();
  }

  /**
   * Add a content type to the types that are going to be imported.
   *
   * When importing by content type you can add any number of types you wish to
   * import. The most recent 20 items of each type will be imported.
   *
   * @param string $type
   *   The content type bundle name.
   */
  public function addImportContentType($type = '') {

    if (is_array($type)) {
      $type = array_flip($type);
      $this->contentTypes = array_merge($this->contentTypes, $type);
    }
    else {
      $this->contentType[$type] = $type;
    }

  }

  /**
   * Remove a content type from being imported.
   *
   * @param string $type
   *   The bundle name of the content type.
   */
  public function removeImportContentType($type = '') {
    unset($this->contentTypes[$type]);
  }

  /**
   * Return all of the content types that are to be imported.
   *
   * Content types are set with setImportContentType.
   *
   * @return arrary
   *   An array of bundle names.
   */
  public function getImportContentTypes() {
    return $this->contentTypes;
  }

  /**
   * Add a restriction on an item by uuid.
   *
   * Setting a restriction will prevent an entity from being saved even if it
   * shows up in the service endpoint.
   *
   * @param array $uuids
   *   An array of uuids.
   */
  public function addUuidRestrictions($uuids = array()) {
    $restrictions = $this->getUuidRestrictions();

    if (!is_array($uuids)) {
      return FALSE;
    }

    $restrictions = array_merge($restrictions, $uuids);
    $this->setUuidRestrictions($restrictions);
    return $restrictions;
  }

  /**
   * Return an array of UUIDs.
   *
   * The restricted UUIDs are entities that should not be saved.
   *
   * @return array
   *   An array of uuid strings.
   */
  public function getUuidRestrictions() {
    return $this->restrictions;
  }

  /**
   * Set a restriction on items by uuid.
   *
   * Setting a restriction will prevent an entity from being saved even if it
   * shows up in the service endpoint.
   *
   * @param array $uuids
   *   An array of uuids.
   */
  protected function setUuidRestrictions($uuids) {
    $this->restrictions = $uuids;
  }

  /**
   * Returns a boolean value on wether a UUID is in the restricted list.
   *
   * @param string $uuid
   *   The UUID of the imported item to import.
   *
   * @return bool
   *   True if is a restricted entity.
   */
  protected function isRestrictedUuid($uuid) {
    $restrictions = $this->getUuidRestrictions();
    return in_array($uuid, $restrictions);
  }

  /**
   * Get a property out of the registry.
   *
   * @return string
   *   A property value.
   */
  protected function getPropertyRegistry() {
    return $this->registry['property'];
  }

  /**
   * Returns the field key from the registry.
   *
   * Not really sure what this is for.
   *
   * @return mixed
   *   Something from $this->registry['field'].
   */
  protected function getFieldRegistry() {
    return $this->registry['field'];
  }

  /**
   * Sets the processor registry.
   *
   * @param string $type
   *   Either a field or a property.
   * @param string $value
   *   The processor class.
   */
  protected function setRegistry($type, $value) {
    $this->registry[$type] = $value;
  }

  /**
   * Register a property processor class.
   *
   * @param array $values
   *   Array with 'key' => 'value' where key is the name of the property and
   *   value is the name of the php class to process it.
   *   eg: array(
   *     'status' => 'myPropertyProcessorStatus'
   *     'author' => 'myPropertyProcessorAuthor'
   *   );.
   */
  public function addPropertyProcessor($values = array()) {
    $prop_reg = $this->getPropertyRegistry();
    foreach ($values as $property => $processor) {
      $prop_reg[$property][] = $processor;
    }
    $this->setRegistry('property', $prop_reg);
  }

  /**
   * Register a field processor class.
   *
   * @param array $values
   *   Array with 'key' => 'value' where key is the name of the field and
   *   value is the name of the php class to process it.
   *   eg:
   *   array(
   *     'field_something_that' => 'myFieldProcessorThing'
   *     'field_other_field' => 'myOtherFieldProcessorThingy'
   *   );.
   */
  public function addFieldProcessor($values = array()) {
    $field_reg = $this->getFieldRegistry();
    foreach ($values as $field => $processor) {
      $field_reg[$field][] = $processor;
    }
    $this->setRegistry('field', $field_reg);
  }

  /**
   * The main process function.
   *
   * Go through all of the fields on the entity that is being saved and run
   * the field processors on them.
   *
   * @param object $entity
   *   The entity object to be saved.
   * @param string $entity_type
   *   The type of entity that is passed in $entity.
   */
  public function processFields(&$entity, $entity_type) {
    $fields = field_info_field_map();
    $field_reg = $this->getFieldRegistry();

    foreach ($fields as $field_name => $field_info) {
      if (isset($entity->{$field_name})) {
        $class_name = "ImporterFieldProcessor";
        $type_name = explode("_", $field_info['type']);
        foreach ($type_name as $index => $name) {
          $class_name .= ucfirst(strtolower($name));
        }
        if (class_exists($class_name)) {
          try {
            $field_processor = new $class_name();
            $field_processor->setEndpoint($this->getEndpoint());
            $field_processor->process($entity, $entity_type, $field_name);
          }
          catch (Exception $e) {
            // No worries. Just continue.
            continue;
          }
        }
        if (isset($field_reg[$field_name])) {
          // If there are registered field processors then loop through them.
          foreach ($field_reg[$field_name] as $processor_name) {

            if (!class_exists($processor_name)) {
              throw new Exception("Could not find PHP class " . $processor_name);
            }

            $field_processor = new $processor_name();
            $field_processor->setEndpoint($this->getEndpoint());
            $field_processor->process($entity, $entity_type, $field_name);

          }
        }
        else {
          $no_importer_class = "This is only here for my debugger to pick up :)";
        }
      }
    }
  }

  /**
   * Process all properties on an entity.
   *
   * This function processes properties of entities that
   * are not attached fields and are not picked up by the process_fields
   * methos. Example would be the uid field on node entities.
   *
   * @param object $entity
   *   The entity object to be saved.
   * @param string $entity_type
   *   The type of entity in $entity.
   */
  public function processProperties(&$entity, $entity_type) {
    $prop_reg = $this->getPropertyRegistry();

    foreach ($entity as $property => $value) {

      // Skip fields.
      if (strpos($property, 'field_') === 0) {
        continue;
      }

      $class_name = "ImporterPropertyProcessor" . ucfirst(strtolower($property));

      if (class_exists($class_name)) {
        try {
          $property_processor = new $class_name();
          $property_processor->setEndpoint($this->getEndpoint());
          $property_processor->process($entity, $entity_type, $property);
        }
        catch (Exception $e) {
          // No worries. Just carry on.
        }
      }
      elseif (isset($prop_reg[$property])) {
        // If there are registered field processors then loop through them.
        foreach ($prop_reg[$property] as $processor_name) {

          if (!class_exists($processor_name)) {
            throw new Exception("Could not find PHP class " . $processor_name);
          }

          $property_processor = new $processor_name();
          $property_processor->setEndpoint($this->getEndpoint());
          $property_processor->process($entity, $entity_type, $property);

        }
      }
      else {
        $no_importer_class = "This is only here for my debugger to pick up :)";
      }

    }
  }

  /**
   * Run all custom field processors.
   *
   * This function allows authors to declare custom field processors with the
   * pattern ImporterFieldProcessorCustom[FieldName]
   *
   * @param object $entity
   *   The entity object to be saved.
   * @param string $entity_type
   *   The type of entity in $entity.
   */
  public function processFieldsCustom(&$entity, $entity_type) {

    foreach ($entity as $field_name => $field_data) {

      // Skip properties.
      if (strpos($field_name, 'field_') !== 0 && $field_name !== "body") {
        continue;
      }

      if (isset($entity->{$field_name})) {
        $class_name = "ImporterFieldProcessorCustom";
        $type_name = explode("_", $field_name);
        foreach ($type_name as $index => $name) {
          $class_name .= ucfirst(strtolower($name));
        }
        if (class_exists($class_name)) {
          try {
            $field_processor = new $class_name();
            $field_processor->setEndpoint($this->getEndpoint());
            $field_processor->process($entity, $entity_type, $field_name);
          }
          catch (Exception $e) {
            // No worries. Just continue.
            continue;
          }
        }
        else {
          $no_importer_class = "This is only here for my debugger to pick up :)";
        }
      }
    }
  }

  /**
   * Run all custom property processors.
   *
   * This function processes properties of entities that
   * are not attached fields and are not picked up by the process_fields
   * methos. Example would be the uid field on node entities.
   *
   * @param object $entity
   *   The entity object to be saved.
   * @param string $entity_type
   *   The entity_type in $entity.
   */
  public function processPropertiesCustom(&$entity, $entity_type) {
    foreach ($entity as $property => $value) {

      // Skip fields.
      if (strpos($property, 'field_') === 0 || $property == "body") {
        continue;
      }

      $class_name = "ImporterPropertyProcessorCustom" . ucfirst(strtolower($property));

      if (class_exists($class_name)) {
        try {
          $property_processor = new $class_name();
          $property_processor->setEndpoint($this->getEndpoint());
          $property_processor->process($entity, $entity_type, $property);
        }
        catch (Exception $e) {
          // No worries. Just carry on.
        }
      }
      else {
        $no_importer_class = "This is only here for my debugger to pick up :)";
      }

    }
  }

  /**
   * Saves field collection entities.
   *
   * This function should be called just before the host entity is saved and
   * no sooner or there will be errors on the host entity as it gets saved
   * with the field collection entity.
   *
   * @return array
   *   A key -> value map of field collection uuids and entity objects.
   */
  protected function saveFieldCollections() {
    $field_collections = &drupal_static('ImporterFieldProcessorFieldCollection', array());
    $uuid_map = array();
    foreach ($field_collections as $k => $fc) {

      if (!is_object($fc)) {
        continue;
      }

      $fc->save();
      $uuid_map[$fc->uuid] = $fc;
      unset($field_collections[$k]);
    }
    return $uuid_map;
  }

  /**
   * Set the UUIDs of the beans to be imported.
   *
   * @param array $uuids
   *   An array of UUIDs.
   */
  public function setBeanUuids($uuids) {
    $this->beanUuids = $uuids;
  }

  /**
   * Get the array of BEAN UUIDs to import.
   *
   * @return array
   *   An array of UUID strings.
   */
  public function getBeanUuids() {
    return $this->beanUuids;
  }

  /**
   * Imports and processess beans.
   *
   * @return array
   *   An array of imported beans.
   */
  public function importContentBeans() {

    // Endpoint will almost always be the hardcoded one.
    $endpoint = $this->getEndpoint();
    $bean_uuids = $this->getBeanUuids();
    $response_format_type = $this->getResponseFormatType();

    // Get and save beans.
    $beans = array();
    $bean_types = array();
    $module_implements = module_implements('bean_types');
    foreach ($module_implements as $module) {
      $bean_types += module_invoke($module, 'bean_types');
    }

    foreach ($bean_uuids as $uuid) {
      $bean_result = drupal_http_request($endpoint . "/bean/" . $uuid . $response_format_type);
      $bean = ($bean_result->code == "200") ? drupal_json_decode($bean_result->data) : FALSE;

      if (!$bean) {
        watchdog('SitesContentImporter', 'Could not fetch BEAN: %s', array("%s" => $uuid), WATCHDOG_NOTICE);
        if (function_exists('drush_log')) {
          drush_log('Could not fetch BEAN: ' . $uuid, 'error');
        }
        continue;
      }

      // Ensure we don't already have this bean.
      $old_bean = bean_load_delta($bean['delta']);
      if ($old_bean) {
        $old_bean->delete();
      }

      // Add the plugin and remove the bid.
      $plugin_settings = bean_fetch_plugin_info($bean['type']);
      $bean['plugin'] = new $bean_types[$bean['type']]['handler']['class']($plugin_settings);
      unset($bean['bid']);
      unset($bean['vid']);

      // Instantiate the bean and process all of the fields.
      $bean = new Bean($bean);

      $this->processFields($bean, 'bean');
      $this->processFieldsCustom($bean, 'bean');

      // Process non field properties.
      $this->processProperties($bean, 'bean');
      $this->processPropertiesCustom($bean, 'bean');

      // Field Collections are awful things and can only be saved right before the entity that they are attached to is
      // saved. We stored them for later saving and must do that now.
      $this->saveFieldCollections();

      // Now we can save Mr. Bean.
      $bean->save();
      $beans[] = $bean;
    }

    return $beans;
  }

  /**
   * Add restrictions to the vocabulary import.
   *
   * Even though some vocabularies are available on the content server we may
   * not want to save them locally. Use this function to set which ones you
   * wish to skip saving.
   *
   * @param array $restrictions
   *   An array of taxonomy vocabulary machine names.
   */
  public function addRestrictedVocabularies($restrictions = array()) {
    if (!is_array($restrictions)) {
      throw new Exception("Restriction parameter is not an array");
    }
    $this->restrictedVocabularies = array_merge($this->restrictedVocabularies, $restrictions);
  }

  /**
   * Returns the array of restricted vocabulary machine names.
   *
   * @return array
   *   An array of vocabulary machine names.
   */
  public function getRestrictedVocabularies() {
    return $this->restrictedVocabularies;
  }

  /**
   * Tests to see if a machine name is in the restricted vocabularies.
   *
   * @param string $machine_name
   *   The machine name to test against.
   *
   * @return bool
   *   True if restricted
   */
  public function isRestrictedVocabulary($machine_name) {
    $restrictions = $this->getRestrictedVocabularies();
    return in_array($machine_name, $restrictions);
  }

  /**
   * Import all of the taxonomy terms from a vocabulary.
   *
   * Fetches and saves the terms from a taxonomy vocabulary on the content
   * server.
   *
   * @return bool
   *   True if successful.
   */
  public function importVocabularyTrees() {
    $endpoint = $this->getEndpoint();
    $response_format_type = $this->getResponseFormatType();

    // Vocabularies.
    try {
      $vocabularies_result = drupal_http_request($endpoint . "/taxonomy_vocabulary" . $response_format_type);
    }
    catch (Exception $e) {
      watchdog('SitesContentImporter', 'Could Not Fetch Vocabularies', array(), WATCHDOG_ERROR);
      if (function_exists('drush_log')) {
        drush_log('Could Not Fetch Vocabularies', 'error');
      }
      return FALSE;
    }

    $vocabularies = drupal_json_decode($vocabularies_result->data);

    if (empty($vocabularies)) {
      watchdog('SitesContentImporter', 'Vocabularies Data Was Empty. Did not import.', array(), WATCHDOG_ERROR);
      if (function_exists('drush_log')) {
        drush_log('Vocabularies Data Was Empty. Did not import', 'error');
      }
      return FALSE;
    }

    // Loop through each vocab and do two things.
    // One save the vocab.
    // Two get the terms.
    foreach ($vocabularies as $index => $vocab) {
      $vocab = (object) $vocab;

      if ($this->isRestrictedVocabulary($vocab->machine_name)) {
        watchdog('SitesContentImporter', 'Did not import restricted vocabulary: %s', array("%s" => $vocab->machine_name), WATCHDOG_NOTICE);
        if (function_exists('drush_log')) {
          drush_log('Did not import restricted vocabulary: ' . $vocab->machine_name, 'ok');
        }
        continue;
      }

      // Get terms.
      $data = "vid=" . $vocab->vid;
      // Fetch tree.
      try {
        $tree_result = drupal_http_request($endpoint . "/taxonomy_vocabulary/getTree" . $response_format_type, array('method' => "POST", "data" => $data));
        $tree = ($tree_result->code == "200") ? drupal_json_decode($tree_result->data) : FALSE;
      }
      catch (Exception $e) {
        watchdog('SitesContentImporter', 'Tree was either empty or returned error: %s', array("%s" => $vocab->machine_name), WATCHDOG_NOTICE);
        if (function_exists('drush_log')) {
          drush_log('Tree was either empty or returned error: ' . $vocab->machine_name, 'error');
        }
        continue;
      }

      unset($vocab->vid);

      // Save vocab if no already present.
      $load_vocab = taxonomy_vocabulary_machine_name_load($vocab->machine_name);
      $vocab = ($load_vocab) ? $load_vocab : $vocab;

      if (!isset($vocab->vid)) {
        taxonomy_vocabulary_save($vocab);
      }

      // Save the trees! heh heh had to.
      if (!empty($tree)) {
        foreach ($tree as $k => $term) {
          $term = (object) $term;
          $term->vid = $vocab->vid;
          $term->vocabulary_machine_name = $vocab->machine_name;
          unset($term->tid);
          taxonomy_term_save($term);
        }
      }
    }

    return TRUE;
  }

  /**
   * Fetch and save content by content type.
   *
   * Requests and saves the most recent content by content type. Due to a bug
   * in the services module only the last 20 items can be fetched.
   */
  public function importerContentNodesRecentByType() {
    $endpoint = $this->getEndpoint();
    $types = $this->getImportContentTypes();
    $response_format_type = $this->getResponseFormatType();
    $requests = array();
    $ids = array();

    foreach ($types as $machine_name => $value) {
      try {
        // Can't seem to get the pagesize variable to work. So for now we only get 20 of each.
        // Because of this we will want two pages of stanford_page types. The page param works so we can use that to get more.
        if ($machine_name == "stanford_page") {
          $requests[$machine_name]        = drupal_http_request($endpoint . "/node" . $response_format_type . "?page=0&pagesize=20&fields=nid,uuid&parameters[type]=" . $machine_name);
          $requests[$machine_name . "_2"] = drupal_http_request($endpoint . "/node" . $response_format_type . "?page=1&pagesize=20&fields=nid,uuid&parameters[type]=" . $machine_name);
          $requests[$machine_name . "_3"] = drupal_http_request($endpoint . "/node" . $response_format_type . "?page=2&pagesize=20&fields=nid,uuid&parameters[type]=" . $machine_name);
        }
        else {
          $requests[$machine_name] = drupal_http_request($endpoint . "/node" . $response_format_type . "?pagesize=50&fields=nid,uuid&parameters[type]=" . $machine_name);
        }

      }
      catch (Exception $e) {
        watchdog('SitesContentImporter', 'Could not fetch content type: %s', array("%s" => $machine_name), WATCHDOG_NOTICE);
        if (function_exists('drush_log')) {
          drush_log('Could not fetch content type: ' . $machine_name, 'error');
        }
      }
    }

    // Store all the ids from all the responses!
    foreach ($requests as $key => $response) {
      if ($response->code == 200) {
        $data = drupal_json_decode($response->data);
        foreach ($data as $k => $id_array) {
          $ids[$id_array['uuid']] = $id_array;
        }
      }
    }

    $this->importerProcessNodesByUuids($ids);
  }

  /**
   * Process the nodes fetched from the content server.
   *
   * Loop through all of the nodes fetched from importerContentNodesRecentByType
   * and process them.
   *
   * @param array $ids
   *   Array in the form of: $ids[uuid] = $id_array;.
   */
  public function importerProcessNodesByUuids($ids) {

    // Now we get all the node information.
    // @todo: Stop hammering the server with requests and make this better.

    $endpoint = $this->getEndpoint();
    $types = $this->getImportContentTypes();
    $response_format_type = $this->getResponseFormatType();

    foreach ($ids as $uuid => $other_ids) {

      if ($this->isRestrictedUuid($uuid)) {
        watchdog('SitesContentImporter', 'Did not import restricted UUID: %s', array("%s" => $uuid), WATCHDOG_NOTICE);
        if (function_exists('drush_log')) {
          drush_log('Did not import restricted UUID: ' . $uuid, 'ok');
        }
        continue;
      }

      try {
        $node_request = drupal_http_request($endpoint . "/node/" . $uuid . $response_format_type);
      }
      catch (Exception $e) {
        watchdog('SitesContentImporter', 'Could not fetch node information for: %s', array("%s" => $uuid), WATCHDOG_NOTICE);
        if (function_exists('drush_log')) {
          drush_log('Could not fetch node information for: ' . $uuid, 'error');
        }
        continue;
      }

      if ($node_request->code !== "200") {
        watchdog('SitesContentImporter', 'Could not fetch node information for: %s', array("%s" => $uuid), WATCHDOG_NOTICE);
        if (function_exists('drush_log')) {
          drush_log('Could not fetch node information for: ' . $uuid, 'error');
        }
        continue;
      }

      $node = drupal_json_decode($node_request->data);
      unset($node['nid']);
      unset($node['vid']);
      $node = (object) $node;

      // Process the fields.
      $this->processFields($node, 'node');
      $this->processFieldsCustom($node, 'node');

      // Process non field properties.
      $this->processProperties($node, 'node');
      $this->processPropertiesCustom($node, 'node');

      // Alter node to save the alias.
      $alias = FALSE;
      if (isset($node->url_alias[0])) {
        $alias = $node->url_alias[0]['alias'];
        unset($node->url_alias);
        $node->path['pathauto'] = FALSE;
      }

      // Save the node.
      node_save($node);

      // Save new pathauto string.
      if ($alias) {
        $path = array(
          'source' => 'node/' . $node->nid,
          'alias' => $alias,
        );
        path_save($path);
      }

    }
  }

}
