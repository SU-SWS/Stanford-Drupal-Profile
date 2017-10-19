<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Importer\Orphans\Comparisons;

class CompareOrgCodesSunet implements ComparisonInterface {

  /**
   * Check to see if any of the missing organization profiles are in the sunet
   * option.
   *
   * @param EntityImporterOrphans $orphaner
   *   The orphan processor object.
   *
   * @return array
   *   The remaining orphans
   */
  public function execute($orphaner) {
    $orphans = $orphaner->getOrphans();
    $options = $orphaner->getImporterOptions();
    $results = $orphaner->getResults();

    // If we are missing one of these we cannot run.
    if (empty($orphans['orgCodes']) || empty($options['sunet_id'])) {
      return $orphans;
    }

    $sunetIds = array();
    foreach ($results as $index => $profile) {
      $sunetIds[$profile['profileId']] = $profile['uid'];
    }

    $sunetOptions = explode(",", $options['sunet_id']);
    $sunetOptions = array_map('trim', $sunetOptions);

    foreach ($orphans['orgCodes'] as $index => $profileId) {
      if (in_array($sunetIds[$profileId], $sunetOptions)) {
        // If the sunet code is found in the sunet id list option then the
        // profile is not an orphan and we need to unset it from the orphans.
        unset($orphans["orgCodes"][$index]);
      }
    }

    return $orphans;
  }

}
