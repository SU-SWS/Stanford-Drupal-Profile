<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\JumpstartVPSA\Install\Block;
use \ITasks\AbstractInstallTask;

/**
 *
 */
class JSVPSABlockClasses extends AbstractInstallTask {

  /**
   * Set Block Classes.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {


    // Install block classes:
    $values = array(
      array("bean", "flexi-block-for-the-home-page", "well span4 clear-row"),
      array("bean", "homepage-about-block", "well"),
      array("bean", "vpsa-resources-block", "span4"),
      array("bean", "vpsa-student-affairs-block", "span4"),
      array('bean', "vpsa-helpful-links-footer-block", "span4"),
      array("bean", "social-media", "span4"),
      array("bean", "contact-block", "span4"),
      array("bean", "optional-footer-block", "span4"),
      array("bean", "jumpstart-footer-contact-block", "span4"),
      array("bean", "vpsa-story-telling-block", "storytelling"),
      // Menus.
      array("menu", "menu-admin-shortcuts-home", "shortcuts-home"),
      array(
        "menu",
        "menu-admin-shortcuts-site-action",
        "shortcuts-actions shortcuts-dropdown"
      ),
      array("menu", "menu-admin-shortcuts-add-feature", "shortcuts-features"),
      array("menu", "menu-admin-shortcuts-get-help", "shortcuts-help"),
      array("menu", "menu-admin-shortcuts-ready-to-la", "shortcuts-launch"),
      array("menu", "menu-admin-shortcuts-logout-link", "shortcuts-logout"),
      // Views.
      array("views", "stanford_events_views-block_1", "span12 clear-row"),
      // Upcoming Events Block
      // array('views', "3b9ba5dd07e9aa559cbe7d1ced47f7b7", "span12 clear-row"), // 5 Item News List Block
      array("views", "f73ff55b085ea49217d347de6630cd5a", "well"),
      //News: 2 Item Recent News List Block
      // Other.
      array(
        "stanford_jumpstart_layouts",
        "jumpstart-launch",
        "shortcuts-launch-block"
      ),
    );
    foreach ($values as $k => $value) {
      // UPDATE block SET (module="bean",delta="social-media",css_class="span4") WHERE module="bean" AND delta="social-media"
      $update = db_update('block')->fields(array('css_class' => $value[2]));
      $update->condition('module',$value[0]);
      $update->condition('delta',$value[1]);
      $update->execute();
    }
  }

  /**
   *
   */
  public function requirements() {
    return array(
      'block_class',
    );
  }

}
