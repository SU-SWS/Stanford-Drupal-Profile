<?php

namespace Stanford\JumpstartLab\Install\Content;

use \ITasks\AbstractInstallTask;

/**
 * Class ImportJSLabBeans.
 *
 * @package Stanford\JumpstartLab\Install\Content.
 */
class ImportJSLabBeans extends AbstractInstallTask {

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
      // Jumpstart Home Page Banner Image.
      'e813c236-7400-4f43-ad18-736617ceb28e',
      // Publications Something to Add.
      '806b3a6e-4225-4ff7-8b8f-d96fd054280a',
      // Jumpstart Location Map Block.
      '178acfee-6423-4817-af05-5533d2e95e3f',
      // Jumpstart Home Page About Block.
      'b66a5774-d0d1-44eb-abda-7aa8ea4eea0e',
      // Academic Programs.
      '27620187-f60a-4f85-b1d1-8c03e1eab40c',
      // Affiliated Programs.
      '8dc5934a-ee22-4c48-a125-d78ce3293ffa',
      // Home Page Announcements.
      'a4b63a55-2626-4591-a952-6db9c3c270fc',
      // Connect.
      '2066e872-9547-40be-9342-dbfb81248589',
      // Contact Us Postcard.
      '60ecdc50-e649-4433-b936-0228aa32fc55',
      // Featured Course.
      '080e08c1-0ef7-4102-8d2e-ebb1a6444513',
      // Footer contact block.
      '864a97ac-ecd9-43b8-94be-da553c1e0426',
      // Featured Event.
      'b7334d9f-b4d4-48ba-b1b5-e3ec7b9bb100',
      // In the spotlight homepage block.
      'ba352284-7aec-4044-a6dc-7e60441c2ccf',
      // Jumpstart Footer Optional Block.
      '67045bcc-06fc-4db8-9ef4-dd0ebb4e6d72',
      // Jumpstart Our Graduate Students.
      '61b6f7f7-5b94-4112-b69c-07240da330f8',
      // Jumpstart Graduate Student Sidebar Block.
      '05f729cf-a05c-446a-96ce-324237e2a5db',
      // Jumpstart Twitter Block.
      '5ee82af2-bfac-4584-a006-a0fb0661af34',
      // Why I teach block.
      '44f527d1-08ab-4ade-b3f6-a57a97987b40',
      // For Home Page Layouts -------------------------------------------------
      // Jumpstart Homepage Tall Banner.
      '8c4ed672-debf-45a5-8dfc-ef42794b975b',
      // Jumpstart Postcard with Video.
      'b880d372-ef1c-4c85-93e8-6a47726d98c2',
      // Jumpstart Lab Homepage Research Projects Block.
      '59556eee-18e4-42c0-be6d-28545c18bbb0',
      // Jumpstart Lab Footer Logo Block.
      'a3648d6a-486b-4bf2-a2ff-a5ff9099c771',
      // Jumpstart Info Text Block.
      'd643d114-c4bc-47b0-b0df-dbf1dc673a1a',
      // Jumpstart Homepage Mission Block 2 (this should be 1, I think).
      'f00c9906-971f-4d9d-b75c-23db1499318c',
      // Jumpstart Homepage Mission Block 2.
      '008d2300-a00d-4de9-bdce-39f7bc9f312d',
      // Jumpstart Homepage Testimonial Block.
      '7c1bdc2c-cd07-4404-8403-8bdbe7ebc9bb',
      // Jumpstart Lead Text With Body.
      '68d11514-1a52-4716-94b4-3ef0110e75b2',
      // Announcements.
      'b7a04511-fcdb-49c4-a0c0-d4340cb35746',
    );

    $importer = new \SitesContentImporter();
    $importer->setEndpoint($endpoint);
    $importer->setBeanUuids($uuids);
    $importer->importContentBeans();

  }

  /**
   * Module requirements.
   *
   * @return array
   *   Array of module requirements.
   */
  public function requirements() {
    return array(
      'bean',
      'bean_admin_ui',
    );
  }

}
