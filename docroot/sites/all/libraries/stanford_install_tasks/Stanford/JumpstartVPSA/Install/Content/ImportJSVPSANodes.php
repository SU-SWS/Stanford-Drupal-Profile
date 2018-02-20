<?php
/**
 * @file
 * Abstract Task Class.
 */


namespace Stanford\JumpstartVPSA\Install\Content;
use Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomBody as ImporterFieldProcessorCustomBody;
use Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorFieldSDestinationPublish as ImporterFieldProcessorFieldSDestinationPublish;
use \ITasks\AbstractInstallTask;

/**
 *
 */
class ImportJSVPSANodes extends AbstractInstallTask {

  /**
   * Import JSVPSA Nodes.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // @todo: Make this an option on the install form.
    $endpoint = variable_get("stanford_content_server", "https://sites.stanford.edu/jsa-content/jsainstall");

    // All RECENT CONTENT.
    $content_types = array(
      // 'stanford_event', removed in order to allow for specific tagging.
      'stanford_news_item',
      'stanford_slide',
      'stanford_person',
    );

    $importer = new \SitesContentImporter();
    $importer->setEndpoint($endpoint);
    $importer->addFieldProcessor(array("body" => "\Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomBody"));
    $importer->addFieldProcessor(array("field_s_destination_publish" => "\Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomFieldSDestinationPublish"));

    // Tell the importer what is what.
    $importer->addImportContentType($content_types);

    // Calling this imports the 20 most recent of each content type.
    $importer->importerContentNodesRecentByType();

    // JSVPSA ONLY CONTENT: tid 39 = JSVPSA.
    $filters = array('tid_raw' => array('39'));
    $view_importer = new \SitesContentImporterViews();
    $view_importer->setEndpoint($endpoint);
    $view_importer->setResource('content');
    $view_importer->setFilters($filters);
    $view_importer->addFieldProcessor(array("body" => "\Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomBody"));
    $view_importer->addFieldProcessor(array("field_s_destination_publish" => "\Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomFieldSDestinationPublish"));
    $view_importer->importContentByViewsAndFilters();

  }

}
