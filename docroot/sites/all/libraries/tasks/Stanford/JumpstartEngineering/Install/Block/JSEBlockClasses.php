<?php
/**
 * @file
 * Add block classes
 */

namespace Stanford\JumpstartEngineering\Install\Block;
/**
 *
 */
class JSEBlockClasses extends \ITasks\AbstractInstallTask {

  /**
   * Set Block Classes.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Install default JSE block classes.
    $values = array(
      array("bean", "jumpstart-home-page-banner---no-", "span8"),
      array("bean", "jumpstart-home-page-full-width-b", "span12"),
      array("bean", "homepage-about-block", "well"),
      array("bean", "jumpstart-large-custom-block", "well span8"),
      array("bean", "jumpstart-small-custom-block", "well span4"),
      array("bean", "jumpstart-small-custom-block-2", "well span4"),
      array("bean", "jumpstart-small-custom-block-3", "well span4"),
      array("bean", "jumpstart-small-custom-block-4", "well span4"),
      array("bean", "jumpstart-small-custom-block-5", "well span4"),

      // Affiliates two-stacked
      array("views", "46f3a22e00be75cb8fe3bc16de17162a", "well span4"),
      array("views", "stanford_events_views-block", "well span4"),
      // Events: Stanford Events List: Filtered Upcoming Block
      array("views", "b0b97e4fb54df88f280eb220fef1829e", "well span4"),
      // News: 2 Item Recent News List Block
      array("views", "f73ff55b085ea49217d347de6630cd5a", "well span4"),
      // News with image and title: 3 Item filtered
      array("views", "d6a08df010339ebc8df9db319eb2052c", "well span4"),
      // Person grid filtered
      array("views", "e94fb0374cf38241b08947ca4e210563", "well"),
      //filtered News view
      array("views","e1db4622d5599968122994300d2a6f47","well"),
      //exposed filter for News Extras view
      array("views","b9c01c6eb8df3ae2f662a9d4a0e35311","well"),
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
