<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Importer\Orphans;
use CAPx\Drupal\Util\CAPxImporter;
/**
 * A static class for handling Batch/Queue API callbacks.
 */
class EntityImporterOrphansBatch {

  /**
   * Callback for batch import functionality.
  *
   * @param string $importerMachineName
   *   The machine name of the importer configuration entity.
   * @param int $profiles
   *   An array of profile ids.
   * @param array $context
   *   Batch context information passed by reference.
   */
  public static function batch($importerMachineName, $profiles, &$context) {
    $orphanator = CAPxImporter::getEntityOrphanator($importerMachineName, $profiles);
    $orphanator->execute();
  }



}
