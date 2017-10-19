<?php
/**
 * @file
 * Abstract Task Class.
 */

use Stanford\DrupalCamp\Install\Content\Importer\ImporterFieldProcessorCustomBody as ImporterFieldProcessorCustomBody;
use Stanford\DrupalCamp\Install\Content\Importer\ImporterFieldProcessorFieldSDestinationPublish as ImporterFieldProcessorFieldSDestinationPublish;

namespace Stanford\DrupalCamp\Install\Content;
/**
 *
 */
class ImportDrupalCampBeans extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // @todo: Make this an option on the install form.
    $endpoint = variable_get("stanford_content_server", "https://sites.stanford.edu/jsa-content/jsainstall");

    // BEANS.
    $uuids = array(
      '6435a4e6-2f53-4236-8f1b-06d12c3ffa25', // News and Updates homepage
      '22db72c1-b06a-4ae3-aed5-a4f4078b3763', // Twitter Widget
      '038c1749-e7a2-4e0e-ad9d-8eef4ed7e2fc', // Sign up for DrupalCamp
      '2a84eda4-b6fc-4eed-97b7-d0040f7e2a8c', // DrupalCamp Banner
      '10535876-06b1-421b-8b00-56d741e1ea70', // DrupalCamp Propose A Session Button
    );
    $importer = new \SitesContentImporter();
    $importer->set_endpoint($endpoint);
    $importer->set_bean_uuids($uuids);
    $importer->import_content_beans();

  }

  /**
   * [requirements description]
   * @return [type] [description]
   */
  public function requirements() {
    return array(
      'bean',
      'bean_admin_ui',
    );
  }

}







