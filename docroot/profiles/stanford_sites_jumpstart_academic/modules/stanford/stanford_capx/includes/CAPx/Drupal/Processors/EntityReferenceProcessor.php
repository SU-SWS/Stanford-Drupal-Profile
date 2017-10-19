<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Processors;

use CAPx\Drupal\Mapper\EntityMapper;
use CAPx\Drupal\Util\CAPx;

/**
 * Entity references are a bit different than normal.
 */
class EntityReferenceProcessor {

  protected $entity;
  protected $importer;
  protected $target;

  /**
   * Creates an entityReferenceProcessor to handle entity reference fields.
   *
   * @param object $entity
   *   The entity we are currently working on to save.
   * @param object $importer
   *   The importer object and all its glory.
   * @param string $target
   *   The target importer where the relative entity lives.
   */
  public function __construct($entity, $importer, $target) {
    $this->entity = $entity;
    $this->importer = $importer;
    $this->target = $target;
  }

  /**
   * Returns a list of possible matches.
   *
   * @return mixed
   *   An empty array if no matches or a fully loaded entity.
   */
  public function execute() {

    // Get the profile ID of this entity as the profile id will be the same
    // for other importers and entity/bundle types.

    $profile_id = $this->entity->value()->capx['profileId'];

    // Did not find one. It could be that is hasn't been created yet and may
    // take another cycle or two to come up.
    if (!$profile_id) {
      throw new \Exception('Could not find profileId. Did something change in the API?');
    }

    $match = db_select("capx_profiles", 'capx')
      ->fields('capx')
      ->condition('profile_id', $profile_id)
      ->condition('importer', $this->target)
      ->orderBy('id', 'DESC')
      ->execute()
      ->fetchAssoc();

    if (empty($match)) {
      return array();
    }

    // Try to load it.
    $entity = entity_load_single($match['entity_type'], $match['entity_id']);

    // Return the result.
    return empty($entity) ? array() : $entity;
  }


}
