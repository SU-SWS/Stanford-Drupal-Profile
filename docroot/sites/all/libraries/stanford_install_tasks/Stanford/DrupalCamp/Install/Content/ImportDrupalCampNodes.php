<?php
/**
 * @file
 * Abstract Task Class.
 */


namespace Stanford\DrupalCamp\Install\Content;
use Stanford\DrupalCamp\Install\Content\Importer\ImporterFieldProcessorCustomBody as ImporterFieldProcessorCustomBody;
use Stanford\DrupalCamp\Install\Content\Importer\ImporterFieldProcessorFieldSDestinationPublish as ImporterFieldProcessorFieldSDestinationPublish;
use \ITasks\AbstractInstallTask;

/**
 *
 */
class ImportDrupalCampNodes extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // @todo: Make this an option on the install form.
    $endpoint = variable_get("stanford_content_server", "https://sites.stanford.edu/jsa-content/jsainstall");

    // JSV ONLY CONTENT - Tid 35 = JSV.
    $filters = array('tid_raw' => array('111'));
    $view_importer = new \SitesContentImporterViews();
    $view_importer->setEndpoint($endpoint);
    $view_importer->setResource('content');
    $view_importer->setFilters($filters);
    $view_importer->addFieldProcessor(array("body" => "\Stanford\DrupalCamp\Install\Content\Importer\ImporterFieldProcessorCustomBody"));
    $view_importer->addFieldProcessor(array("field_s_destination_publish" => "\Stanford\DrupalCamp\Install\Content\Importer\ImporterFieldProcessorCustomFieldSDestinationPublish"));
    $view_importer->importContentByViewsAndFilters();

  }

}
