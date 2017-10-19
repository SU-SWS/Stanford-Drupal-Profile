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
      'webform',
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
    );

    $importer = new \SitesContentImporter();
    $importer->setEndpoint($endpoint);
    $importer->addImportContentType($content_types);
    $importer->addUuidRestrictions($restrict);
    $importer->importerContentNodesRecentByType();

    // JSL ONLY CONTENT.
    $filters = array('tid_raw' => array('112'));
    $view_importer = new \SitesContentImporterViews();
    $view_importer->setEndpoint($endpoint);
    $view_importer->setResource('content');
    $view_importer->setFilters($filters);
    $importer->addUuidRestrictions($restrict);
    $view_importer->importContentByViewsAndFilters();

  }

}







