<?php
/**
 * @file
 * Import JSE BEANs
 */

//use Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomBody as ImporterFieldProcessorCustomBody;
//use Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomFieldSDestinationPublish as ImporterFieldProcessorFieldSDestinationPublish;

namespace Stanford\JumpstartEngineering\Install\Content;
/**
 *
 */
class ImportJSECustomBeans extends \ITasks\AbstractInstallTask {

  /**
   * Import Custom BEANs.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    $endpoint = variable_get("stanford_content_server", "https://sites.stanford.edu/jsa-content/jsainstall");

    $uuids = array(
      // Jumpstart Small Custom Block.
      '7e510af6-c003-402d-91a4-7480dac1484a',
      // Jumpstart Small Custom Block 2.
      '27d46141-6f4f-4988-b054-ddb9797cfa6a',
      // Jumpstart Small Custom Block 3.
      '008e9fae-e2ca-4be7-a451-df0b794842d6',
      //Jumpstart Small Custom Block 4
      '6997adbe-96e6-43f9-b34c-03f6a23197c7',
      // Jumpstart Small Custom Block 5
      '7baae13f-7fc3-489c-bcd7-08698ab08d25',
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







