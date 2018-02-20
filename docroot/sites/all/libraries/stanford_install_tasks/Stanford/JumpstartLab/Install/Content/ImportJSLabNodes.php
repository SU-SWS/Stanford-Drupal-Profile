<?php

namespace Stanford\JumpstartLab\Install\Content;

use \ITasks\AbstractInstallTask;

/**
 * Class ImportJSLabNodes.
 */
class ImportJSLabNodes extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // @todo: Make this an option on the install form.
    $endpoint = variable_get("stanford_content_server", "https://sites.stanford.edu/jsa-content/jsainstall");

    // NODES.
    // Import types.
    $content_types = array(
      'stanford_event_series',
      'stanford_event',
      'stanford_event_importer',
      'article',
      'stanford_person',
      'stanford_publication',
      'stanford_news_item',
      'stanford_course',
    );

    // Restrictions.
    // These entities we do not want even if they appear in the feed.
    $restrict = array(
      // Recent News Page.
      '2efac412-06d7-42b4-bf75-74067879836c',
      // Courses Page.
      '6d48181f-7387-40e8-81ba-199de7ede938',
      // Past events Page. (Delete after 4.5)
      'b10b8889-73b1-4842-8e1b-b8a21120e2d9',

      // Undesired Private Pages.
      'ac30fcb2-63fc-4e2d-9278-a2780626ce49',
      '0f2878c0-813a-42ca-8f7f-c01630d25c28',
      '355c6ddc-5c24-4cd4-bb3d-b8a66894f9e2',
      '8cac43b8-8953-4936-b857-53f4b68e1724',
      'cbcae411-e5ba-4dcf-8d2f-7e18db8439ec',

      // Haley Jackson Profile.
      'b8e7f735-93e3-4717-8208-e9b0baff5dc4',

      // Other "Research Overview" page we dont want.
      '00d94894-0d54-4a4f-bc41-985da4a05778'
    );

    $importer = new \SitesContentImporter();
    $importer->setEndpoint($endpoint);
    $importer->addImportContentType($content_types);
    $importer->addUuidRestrictions($restrict);
    $importer->importerContentNodesRecentByType();

    // Prevent duplicated content.
    $query = db_select('node', 'n')
      ->fields('n', array('uuid'))
      ->execute();
    while ($uuid = $query->fetchAssoc()) {
      $restrict[] = $uuid;
    }

    // JSL ONLY CONTENT.
    $filters = array('tid_raw' => array('112'));
    $view_importer = new \SitesContentImporterViews();
    $view_importer->setEndpoint($endpoint);
    $view_importer->setResource('content');
    $view_importer->setFilters($filters);
    $importer->addUuidRestrictions($restrict);
    $view_importer->importContentByViewsAndFilters();

    if ($term = reset(taxonomy_get_term_by_name('Students', 'stanford_affiliation'))) {
      taxonomy_term_delete($term->tid);
    }
  }

}







