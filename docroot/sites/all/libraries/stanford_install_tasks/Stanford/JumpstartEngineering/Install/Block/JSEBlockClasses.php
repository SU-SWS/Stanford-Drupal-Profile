<?php

namespace Stanford\JumpstartEngineering\Install\Block;

use \ITasks\AbstractInstallTask;

/**
 * Default block class configuration for JSE sites class.
 */
class JSEBlockClasses extends AbstractInstallTask {

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
      array("views", "-exp-courses-search_page", "well"),

      // Affiliates two-stacked.
      array("views", "46f3a22e00be75cb8fe3bc16de17162a", "well span4"),

      // Events.
      array("views", "stanford_events_views-block", "well span4 column"),

      // News and News Extras.
      // News: 2 Item Recent News List Block.
      array("views", "f73ff55b085ea49217d347de6630cd5a", "well span4 column"),
      // News Extras: 2 Item Recent News List Block.
      array("views", "9bf4ec9695a5b13242ba5a4898a6b635", "well span4 column"),
      // News with teaser: 2 Item Recent News List Block.
      array("views", "bf4ec9695a5b13242ba5a4898a6b635", "well span4 column"),
      // Exposed filter for News Extras view.
      array("views", "b9c01c6eb8df3ae2f662a9d4a0e35311", "well"),

      // Related content blocks.
      // Events: Stanford Events List: Filtered Upcoming Block.
      array("views", "b0b97e4fb54df88f280eb220fef1829e", "well"),
      // News with image and title: 2 Item filtered.
      array("views", "2822b14d3cd0fffa732b52003beba914", "well"),
      // News with image and title: 3 Item filtered.
      array("views", "d6a08df010339ebc8df9db319eb2052c", "well"),
      // Person grid filtered.
      array("views", "e94fb0374cf38241b08947ca4e210563", "well"),
      // Person grid five filtered.
      array("views", "7c6a569773ec75eec1ddc08609e9c4cf", "well"),
      // Person grid six filtered.
      array("views", "88cc9b459c80892d71732a8f342e7db0", "well"),
      // Filtered News view.
      array("views", "e1db4622d5599968122994300d2a6f47", "well"),
    );

    foreach ($values as $k => $value) {
      $update = db_update('block')->fields(array('css_class' => $value[2]));
      $update->condition('module', $value[0]);
      $update->condition('delta', $value[1]);
      $update->execute();
    }
  }

  /**
   * Class requirements.
   */
  public function requirements() {
    return array(
      'block_class',
    );
  }

}
