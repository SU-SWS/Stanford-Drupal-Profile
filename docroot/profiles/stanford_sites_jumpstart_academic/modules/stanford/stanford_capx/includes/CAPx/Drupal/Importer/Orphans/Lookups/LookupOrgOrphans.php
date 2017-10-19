<?php
/**
 * @file
 * @author [author] <[email]>
 */

namespace CAPx\Drupal\Importer\Orphans\Lookups;

use CAPx\Drupal\Organizations\Orgs;

class LookupOrgOrphans implements LookupInterface {

  /**
   * Find orphans from an Organization.
   *
   * Loop through a number of profileIds and look up their Organization relation
   * to see if they are still in the Org or Org tree if children are also being
   * imported. Org code aliases should also be included in this lookup.
   *
   * @param EntityImporterOrphans $orphaner
   *   The orphan processor object.
   *
   * @return array
   *   The remaining orphans
   */
  public function execute($orphaner) {

    $options = $orphaner->getImporterOptions();
    $orphans = $orphaner->getOrphans();

    // Check to see if there is something to run on.
    if (!in_array("orgCodes", $options['types'])) {
      return $orphans;
    }

    // Get the results from the server.
    $results = $orphaner->getResults();

    // Lets make sure we have some results from the server to run on.
    if (empty($results)) {
      return $orphans;
    }

    $profiles = $orphaner->getProfiles();
    $myOrphans = array();
    $orphans['orgCodes'] = array();

    $keyTids = array();
    $codes = explode(",", $options['organization']);
    $aliases = Orgs::getAliasesByCode($codes);
    $codes = array_merge($codes, $aliases);

    // Allow those to alter the codes.
    drupal_alter("capx_find_org_orphans_codes", $codes);

    // Load up the tids of the orgs that the importer is importing.
    foreach ($codes as $code) {
      $terms = taxonomy_get_term_by_name($code, Orgs::getVocabularyMachineName());
      $term = array_pop($terms);
      $keyTids[] = $term->tid;
    }

    // Look through the org codes attached to each profile.
    foreach ($results as $k => $profile) {
      $found = FALSE;

      // If there are no titles for the profile then they cannot be in an org.
      if (!isset($profile['titles'])) {
        $myOrphans[$profile['uid']] = $profile['profileId'];
        continue;
      }

      foreach ($profile['titles'] as $title) {

        $orgCode = $title['organization']['orgCode'];
        $orgTerms = taxonomy_get_term_by_name($orgCode, Orgs::getVocabularyMachineName());
        $org = array_pop($orgTerms);

        if (!isset($org->tid)) {
          continue;
        }

        // If the org code itself is in the list.
        if (in_array($org->tid, $keyTids)) {
          $found = TRUE;
          break;
        }

        // Check if any of the parents orgs codes match one in the keyTids.
        // If there is a match then this org code is a child of one of the key
        // importer codes.
        $parents = taxonomy_get_parents_all($org->tid);

        if (!empty($parents) && !$found) {
          foreach ($parents as $parentTerm) {
            if (in_array($parentTerm->tid, $keyTids)) {
              $found = TRUE;
              break;
            }
          }
        }

      }

      // If we did not find an organization that matches we have an orphan.
      if (!$found) {
        $myOrphans[$profile['uid']] = $profile['profileId'];
      }

    }

    // Allow those to alter this set.
    drupal_alter("capx_find_org_orphans", $orphans);


    if (!empty($myOrphans)) {
      $orphans['orgCodes'] = $myOrphans;
    }

    return $orphans;
  }

}
