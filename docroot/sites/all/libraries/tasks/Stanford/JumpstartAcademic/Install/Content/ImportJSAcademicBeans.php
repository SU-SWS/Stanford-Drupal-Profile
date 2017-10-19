<?php
/**
 * @file
 * Abstract Task Class.
 */

use Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomBody as ImporterFieldProcessorCustomBody;
use Stanford\Jumpstart\Install\Content\Importer\ImporterFieldProcessorCustomFieldSDestinationPublish as ImporterFieldProcessorFieldSDestinationPublish;

namespace Stanford\JumpstartAcademic\Install\Content;
/**
 *
 */
class ImportJSAcademicBeans extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // @todo: Make this an option on the install form.
    $endpoint = variable_get("stanford_content_server", "https://sites.stanford.edu/jsa-content/jsainstall");

   // BEANS
    $uuids = array(
      'e813c236-7400-4f43-ad18-736617ceb28e', // Jumpstart Home Page Banner Image
      '806b3a6e-4225-4ff7-8b8f-d96fd054280a', // Publications Something to Add
      '178acfee-6423-4817-af05-5533d2e95e3f', // Jumpstart Location Map Block
      'b66a5774-d0d1-44eb-abda-7aa8ea4eea0e', // Jumpstart Home Page About Block
      '27620187-f60a-4f85-b1d1-8c03e1eab40c', // Academic Programs
      '8dc5934a-ee22-4c48-a125-d78ce3293ffa', // Affiliated Programs
      'a4b63a55-2626-4591-a952-6db9c3c270fc', // Home Page Announcements
      '2066e872-9547-40be-9342-dbfb81248589', // Connect
      '60ecdc50-e649-4433-b936-0228aa32fc55', // Contact Us Postcard
      '080e08c1-0ef7-4102-8d2e-ebb1a6444513', // Featured Course
      '864a97ac-ecd9-43b8-94be-da553c1e0426', // footer contact block
      'b7334d9f-b4d4-48ba-b1b5-e3ec7b9bb100', // Featured Event
      'ba352284-7aec-4044-a6dc-7e60441c2ccf', // In the spotlight homepage block
      '67045bcc-06fc-4db8-9ef4-dd0ebb4e6d72', // Jumpstart Footer Optional Block
      '61b6f7f7-5b94-4112-b69c-07240da330f8', // Jumpstart Our Graduate Students
      '05f729cf-a05c-446a-96ce-324237e2a5db', // Jumpstart Graduate Student Sidebar Block
      '5ee82af2-bfac-4584-a006-a0fb0661af34', // Jumpstart Twitter Block
      '44f527d1-08ab-4ade-b3f6-a57a97987b40',  // Why I teach block.
      // For Home Page Layouts -------------------------------------------------
      '8c4ed672-debf-45a5-8dfc-ef42794b975b', // Jumpstart Homepage Tall Banner
      'b880d372-ef1c-4c85-93e8-6a47726d98c2', // Jumpstart Postcard with Video
      'd643d114-c4bc-47b0-b0df-dbf1dc673a1a', // Jumpstart Info Text Block
      'f00c9906-971f-4d9d-b75c-23db1499318c', // Jumpstart Homepage Mission Block 2 (this should be 1, I think)
      '008d2300-a00d-4de9-bdce-39f7bc9f312d', // Jumpstart Homepage Mission Block 2
      '7c1bdc2c-cd07-4404-8403-8bdbe7ebc9bb', // Jumpstart Homepage Testimonial Block
      '68d11514-1a52-4716-94b4-3ef0110e75b2', // Jumpstart Lead Text With Body
      'b7a04511-fcdb-49c4-a0c0-d4340cb35746', // Announcements
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







