<?php
/**
 * @file
 * Import JSE nodes.
 */

namespace Stanford\JumpstartEngineering\Install\Content;

use ITasks\AbstractInstallTask;
use Stanford\Jumpstart\Install\Content\Importer\LoadImporterLibrary;
use Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomBody;
use Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomFieldSDestinationPublish;

/**
 * Import JSE Nodes class.
 */
class ImportJSENodes extends AbstractInstallTask {

  /**
   * Import JSE Nodes.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Load the importer library.
    $loader = new LoadImporterLibrary();
    $loader->execute();

    // This could take a while.
    drupal_set_time_limit(600);

    // @todo: Make this an option on the install form.
    $endpoint = variable_get("stanford_content_server", "https://sites.stanford.edu/jsa-content/jsainstall");
    $filters = array('tid_raw' => array('55'));

    $view_importer = new \SitesContentImporterViews();
    $view_importer->setEndpoint($endpoint);
    $view_importer->setResource('content');
    $view_importer->setFilters($filters);
    $view_importer->addFieldProcessor(array("body" => "\Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomBody"));
    $view_importer->addFieldProcessor(array("field_s_destination_publish" => "\Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomFieldSDestinationPublish"));
    $view_importer->importContentByViewsAndFilters();

  }

}
