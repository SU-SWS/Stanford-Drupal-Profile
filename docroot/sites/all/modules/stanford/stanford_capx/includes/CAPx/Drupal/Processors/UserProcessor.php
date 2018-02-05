<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Processors;
use CAPx\Drupal\Mapper\EntityMapper;
use CAPx\Drupal\Util\CAPx;

class UserProcessor extends EntityProcessor {

  /**
   * newEntity method override.
   * @see  parent:newEntity();
   * User entities have some special needs around their default values.
   * return Entity the saved user entity.
   */
  public function newEntity($entityType, $bundleType, $data, $mapper) {

    require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');

    $properties = array(
      'type' => $bundleType,
      'status' => 1, // @TODO - allow this to change
      'timezone' => variable_get("date_default_timezone", "America/Los_Angeles"),
      'pass' => user_hash_password(user_password(20)),
    );

    $values = array(
      'properties' =>  $properties,
      'entity_type' => $entityType,
      'bundle_type' => $bundleType,
      'mapper' => $mapper,
      'data' => $data,
    );

    drupal_alter('capx_pre_entity_create', $values);

    // Create an empty entity.
    $entity = entity_create($entityType, $properties);

    // Wrap it up baby!
    $entity = entity_metadata_wrapper($entityType, $entity);
    $entity = $mapper->execute($entity, $data);

    // Allow altering again.
    drupal_alter('capx_entity_presave', $entity, $mapper);

    // Special validation to ensure that the user has an email. If not, cheat
    // and create one through the sunet id.
    if ($entity && !valid_email_address($entity->mail->value())) {
      $entity->mail = $data['uid'] . "@stanford.edu";
    }

    // Now all the values should be set. Lets save.
    if ($entity) {
      $entity->save();
    }
    else {
      $this->setStatus(0, 'Skipped user entity with sunet id: ' . $data['uid']);
    }

    // Because this is a new user and the init value is not available to be
    // mapped to look in the entity and see if we can clone the mail value to
    // init.
    if (isset($entity->mail) && !empty($entity->mail->value())) {
      db_update("users")
        ->fields(array(
          "init" => $entity->mail->value()
          )
        )
        ->condition("mail", $entity->mail->value())
        ->execute();
    }

    drupal_alter('capx_post_entity_create', $entity, $data);

    // Write a new record.
    $entityImporter = $this->getEntityImporter();
    $importerMachineName = $entityImporter->getMachineName();
    CAPx::insertNewProfileRecord($entity, $data['profileId'], $data['meta']['etag'], $importerMachineName);

    return $entity;
  }

}
