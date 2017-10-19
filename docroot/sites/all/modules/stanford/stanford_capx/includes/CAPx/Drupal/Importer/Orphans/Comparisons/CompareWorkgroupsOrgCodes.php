<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Importer\Orphans\Comparisons;

class CompareWorkgroupsOrgCodes implements ComparisonInterface {

  /**
   * Check to see if any of the orphans in the workgroups are in an
   * organization.
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

    // If both workgroup and organizations are selected we need to see that the
    // orphan is missing from both and the sunet is not in the ids.
    if (empty($orphans['privGroups'])) {
      return $orphans;
    }

    // Loopy loop.
    foreach ($orphans['privGroups'] as $index => $profileId) {
      // Scenario: Orphan in privGroups but not orgCodes.
      if (isset($orphans['orgCodes']) && !in_array($profileId, $orphans['orgCodes'])) {
        // Not an orphan. Remove it.
        unset($orphans['privGroups'][$index]);
      }
    }

    return $orphans;
  }

}
