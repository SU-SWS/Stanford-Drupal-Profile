<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Importer\Orphans\Comparisons;

class CompareMissingFromAPI implements ComparisonInterface {

  /**
   * Any profile that has been marked as no longer in the API needs to be
   * processed immediately as an orphan.
   * @param  EntityImporterOrphans $orphaner
   *  The orphanator object.
   * @return array
   *   The remaining orphans.
   */
  public function execute($orphaner) {
    $orphans = $orphaner->getOrphans();
    $importer = $orphaner->getImporter();

    if (empty($orphans['missing'])) {
      return $orphans;
    }

    // No need to compare to anything. They are missing from the API.
    $orphaner->processOrphans($orphans['missing']);
    // unset($orphans['missing']);
    return $orphans;
  }

}
