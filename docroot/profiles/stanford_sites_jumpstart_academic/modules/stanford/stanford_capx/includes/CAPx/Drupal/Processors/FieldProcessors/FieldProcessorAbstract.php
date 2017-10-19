<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Processors\FieldProcessors;

abstract class FieldProcessorAbstract implements FieldProcessorInterface {

  // Entity.
  protected $entity;

  // Field Name.
  protected $fieldName;

  // Type of field or widget.
  protected $type;

  /**
   * Construction method
   * @param [type] $entity    [description]
   * @param [type] $fieldName [description]
   */
  public function __construct($entity, $fieldName, $type = NULL) {
    $this->setEntity($entity);
    $this->setFieldName($fieldName);

    if (!is_null($type)) {
      $this->setType($type);
    }

  }

  /**
   * Default implementation of put.
   *
   * Puts the information from the CAP API
   * In to the field via entity_metadata_wrapper. Tries to handle information
   * being provided to it for most field types. Specific FieldProcessors may
   * override this function to provide their own custom processing.
   *
   * @param array $data
   *   An array of data from the CAP API.
   */
  public function put($data) {

    $entity = $this->getEntity();
    $fieldName = $this->getFieldName();
    $fieldInfo = field_info_field($fieldName);

    // Reformat the jsonpath return data so it works with Drupal.
    $data = $this->repackageJsonDataForDrupal($data, $fieldInfo);

    // Allow others to alter the data before it is set to the field.
    drupal_alter('capx_field_processor_pre_set', $entity, $data, $fieldName);

    $field = $entity->{$fieldName};
    $fieldWrapperInfo = $field->info();

    // If there's no data, do nothing.
    if (empty($data)) {
      if (empty($fieldWrapperInfo['required'])) {
        $field->set(NULL);
      }
      else {
        // Setting NULL for required fields
        // will trigger EntityMetadataWrapperException.
        $this->logIssue(new \Exception(t("CAP profile didn't provide any data for required field.")));
      }

      return;
    }

    try {
      if ($fieldInfo['cardinality'] === "1") {
        // Only want the first value for one cardinality field.
        $data = array_shift($data);
        // Metadata wrapper is smarter then plain field info.
        switch (get_class($field)) {
          // Structure wrapper assumes we providing multiple columns.
          case 'EntityStructureWrapper':
            $field->set($data);
            break;

          // Value wrapper assumes we providing single value.
          case 'EntityDrupalWrapper':
          case 'EntityValueWrapper':

            // Only Shift if it is an array.
            if (is_array($data)) {
              $data = array_shift($data);
            }

            $field->set($data);
            break;
        }
      }
      else {
        // For everything else give it all.
        $field->set($data);
      }
    }
    catch (\EntityMetadataWrapperException $e) {
      // Log the problem.
      $this->logIssue($e);
    }

  }

  /**
   * Takes the data from the CAP API and turns it into an array that can be
   * used by entity_metadata_wrapper's set function.
   * @param  array $data CAP API data
   * @return array       an array of data suitable for saving to a field.
   */
  public function repackageJsonDataForDrupal($data, $fieldInfo) {
    $return = array();
    $columns = array_keys($fieldInfo['columns']);

    // If the configuration passed doesn't specify a field column to insert the
    // data into assume the first key in the field info columns array
    $columnKey = $columns[0];

    // For when data is passed in with column keys.
    foreach ($columns as $key) {
      if (isset($data[$key])) {
        foreach ($data[$key] as $index => $value) {
          $return[$index][$key] = $value;
        }
      }
    }

    // If no key value was specified then assume the column key.
    if (isset($data[0][0]) && is_array(($data[0][0]))) {
      foreach ($data[0] as $int => $value) {
        $return[$int][$columnKey] = $value;
      }
    }

    return $return;
  }

  /**
   * Logs an issue to watchdog.
   * @param  \Exception|null $e [description]
   * @return [type]             [description]
   */
  public function logIssue(\Exception $e = NULL) {
    $entity = $this->getEntity();

    // BEAN is returning its delta when using this.
    // $entityId = $entity->getIdentifier();

    $entityType = $entity->type();
    $entityRaw = $entity->raw();
    list($entityId, $vid, $bundle) = entity_extract_ids($entityType, $entityRaw);


    $logText = 'Could not save the field data for %field on %type id: %profileId.';

    if (isset($e)) {
      $logText .= ' ';
      $logText .= get_class($e);
      $logText .= ': ' . check_plain($e->getMessage());
    }

    watchdog(
      'stanford_capx_field',
      $logText,
      array(
        '%field' => $this->getFieldName(),
        '%type' => $entity->getBundle(),
        '%profileId' => $entityId ? $entityId : 'unknown',
      ),
      WATCHDOG_ERROR
    );

    // Now throw $e so that the mapper knows something went wrong.
    if (isset($e)) {
      throw $e;
    }

  }


  // Getters and Setters
  // ---------------------------------------------------------------------------
  //

  /**
   * Returns current entity.
   *
   * @return \EntityDrupalWrapper
   *   The entity being worked on, wrapped.
   */
  public function getEntity() {
    return $this->entity;
  }

  /**
   * Setter function
   * @param Entity $entity the entity to be worked on.
   */
  public function setEntity($entity) {
    $this->entity = $entity;
  }

  /**
   * Getter function
   * @return string the field name being processed.
   */
  public function getFieldName() {
    return $this->fieldName;
  }

  /**
   * Setter function
   * @param string $name the field name to be processed.
   */
  public function setFieldName($name) {
    $this->fieldName = $name;
  }

  /**
   * Setter function
   * @param string $type The field type.
   */
  public function setType($type) {
    $this->type = $type;
  }

  /**
   * Getter function
   * @return string the field type.
   */
  public function getType() {
    return $this->type;
  }


}
