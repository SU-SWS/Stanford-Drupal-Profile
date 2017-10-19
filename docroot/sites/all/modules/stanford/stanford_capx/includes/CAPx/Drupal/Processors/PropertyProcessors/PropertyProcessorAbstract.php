<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Processors\PropertyProcessors;

abstract class PropertyProcessorAbstract implements PropertyProcessorInterface {

  // Entity
  protected $entity;

  // Property Name
  protected $propertyName;

  /**
   * Constructor Method
   * @param Entity $entity    The entity whose properties are being modified/set
   * @param string $propertyName the name of the property to modify/set
   */
  public function __construct($entity, $propertyName) {
    $this->setEntity($entity);
    $this->setPropertyName($propertyName);
  }

  /**
   * Default implementation of put
   * @param  array $data An array of CAP API data.
   */
  public function put($data) {
    $entity = $this->getEntity();
    $propertyName = $this->getPropertyName();

    $data = is_array($data) ? array_shift($data) : $data;

    if (empty($data)) {
      // @todo Do we really need to log this?
      $this->logIssue(new \Exception(t('Got empty property value.')));
      return;
    }

    // If autotruncating is enabled lets do that here. This is to help
    // avoid issues when trying to map data to the API.
    if (variable_get("stanford_capx_autotruncate_textfields", TRUE)) {
      $maxlength = 255; // Default.
      if (strlen($data) > $maxlength) {
        $data = substr($data, 0, $maxlength);
      }
    }

    try {
      $entity->{$propertyName}->set($data);
    }
    catch (\Exception $e) {
      $this->logIssue($e);
    }
  }


  // Getters and Setters
  // ---------------------------------------------------------------------------
  //

  /**
   * Getter function
   * @return Entity the entity being worked on.
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
   * @return string the name of the property being worked on.
   */
  public function getPropertyName() {
    return $this->PropertyName;
  }

  /**
   * Setter function
   * @param string $name the name of the property to be worked on.
   */
  public function setPropertyName($name) {
    $this->PropertyName = $name;
  }

  /**
   * Logs issues to DB.
   *
   * @param \Exception $e
   *   Optional.
   * @param  bool $invalidateEtag
   *   Optionally invalidate the eTag. Defaults to TRUE.
   */
  public function logIssue(\Exception $e = NULL, $invalidateETag = TRUE) {

    // BEAN is returning its delta when using this.
    // $entityId = $entity->getIdentifier();

    $entity = $this->getEntity();
    $entityType = $entity->type();
    $entityRaw = $entity->raw();
    list($entityId, $vid, $bundle) = entity_extract_ids($entityType, $entityRaw);

    $logText = 'There was an issue setting property value for %propery on %type id: %profileId.';

    if (isset($e)) {
      $logText .= ' ';
      $logText .= get_class($e);
      $logText .= ': ' . check_plain($e->getMessage());
    }

    watchdog(
      'stanford_capx_property',
      $logText,
      array(
        '%propery' => $this->getPropertyName(),
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


}
