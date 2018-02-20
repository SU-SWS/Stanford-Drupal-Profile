<?php

namespace Stanford\JumpstartLab\Install\Block;

use \ITasks\AbstractInstallTask;

/**
 * Class BlockSettings.
 */
class BlockSettings extends AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Install contextual block class for Panama layout.
    $cbc_layouts = array();
    $cbc_layouts['stanford_jumpstart_home_lomita']['bean-jumpstart-lead-text-with-body'][] = 'span6';
    $cbc_layouts['stanford_jumpstart_home_mayfield']['bean-jumpstart-lead-text-with-body'][] = 'span12';
    $cbc_layouts['stanford_jumpstart_home_mayfield_news_events']['bean-jumpstart-lead-text-with-body'][] = 'span6';
    $cbc_layouts['stanford_jumpstart_home_palm']['bean-jumpstart-lead-text-with-body'][] = 'span6';
    $cbc_layouts['stanford_jumpstart_home_palm_news_events']['bean-jumpstart-lead-text-with-body'][] = 'span6';
    $cbc_layouts['stanford_jumpstart_home_panama']['bean-jumpstart-lead-text-with-body'][] = 'span4';
    $cbc_layouts['stanford_jumpstart_home_panama_news_events']['bean-jumpstart-lead-text-with-body'][] = 'span4';
    $cbc_layouts['stanford_jumpstart_home_serra']['bean-jumpstart-lead-text-with-body'][] = 'span6';
    $cbc_layouts['stanford_jumpstart_home_serra_news_events']['bean-jumpstart-lead-text-with-body'][] = 'span6';
    variable_set('contextual_block_class', $cbc_layouts);

    // Block classes.
    $values = array(
      array("bean", "jumpstart-home-page-about", "well"),
      array("bean", "homepage-about-block", 'well'),
      array("bean", "jumpstart-home-page-information-", 'well'),
      array("bean", "jumpstart-affiliated-programs", "well"),

      // Home Page Columns.
      array("bean", "jumpstart-lab-homepage-research-", "well column"),
      array("views", "publications_common-block_4", "well column"),
      array("views", "f73ff55b085ea49217d347de6630cd5a", "well column"),

      array("bean", "jumpstart-contact-us-postcard", "well"),
      array("bean", "jumpstart-degree-programs-info-f", "well"),
      array("bean", "jumpstart-featured-course", "well"),
      array("bean", "jumpstart-featured-event", "well"),
      array("bean", "jumpstart-featured-event-block", "well"),
      array("bean", "jumpstart-footer-social-media-co", "span4"),
      array("bean", "jumpstart-graduate-student-sideb", "well"),
      array("bean", "jumpstart-home-page-academics", "well"),
      array("bean", "jumpstart-info-for-current-gra-0", "span4 well"),
      array("bean", "jumpstart-info-for-current-gra-1", "span4 well"),
      array("bean", "jumpstart-info-for-current-gradu", "span4 well"),
      array("bean", "jumpstart-info-for-current-und-0", "span4 well"),
      array("bean", "jumpstart-info-for-current-und-1", "span4 well"),
      array("bean", "jumpstart-info-for-current-under", "span4 well"),
      array("bean", "jumpstart-info-for-prospective-0", "span4 well"),
      array("bean", "jumpstart-info-for-prospective-1", "span4 well"),
      array("bean", "jumpstart-info-for-prospective-g", "span4 well"),
      array("bean", "jumpstart-twitter-block", "well"),
      array("bean", "jumpstart-why-i-teach", "well"),
      array("bean", "jumpstart-why-i-teach-block", "well"),
      array("bean", "optional-footer-block", "span4"),
      array("bean", "social-media", "span4"),
      array("ds_extras", "contact", "well"),
      array("ds_extras", "office_hours", "well"),
      array("menu", "menu-admin-shortcuts-add-feature", "shortcuts-features"),
      array("menu", "menu-admin-shortcuts-get-help", "shortcuts-help"),
      array("menu", "menu-admin-shortcuts-home", "shortcuts-home"),
      array("menu", "menu-admin-shortcuts-logout-link", "shortcuts-logout"),
      array("menu", "menu-admin-shortcuts-ready-to-la", "shortcuts-launch"),
      array(
        "menu",
        "menu-admin-shortcuts-site-action",
        "shortcuts-actions shortcuts-dropdown",
      ),
      array("menu", "menu-footer-news-events-menu", "span2"),
      array("menu", "menu-footer-people-menu", "span2"),
      array("menu", "menu-footer-academics-menu", "span2"),

      array("bean", "jumpstart-footer-contact-block", "span3"),
      array("bean", "jumpstart-footer-social-media--0", "span3"),
      array("bean", "jumpstart-lab-footer-logo-block", "span3"),
      array("menu", "menu-footer-about-menu", "span3"),

      array(
        "stanford_jumpstart_layouts",
        "jumpstart-launch",
        "shortcuts-launch-block",
      ),
      array("views", "-exp-publications-page", "well"),
      array("views", "jumpstart_current_user-block", "shortcuts-user"),
      array("views", "stanford_news-block", "well"),
      array("views", "stanford_events_views-block", "well"),
      array("views", "-exp-stanford_person_staff-page", "well"),
      array("views", "-exp-stanford_news-page_1", "well"),
      array("views", "-exp-courses-search_page", "well"),
      array("views", "442e92af913370af5bffd333a036ceaa", "well"),
      array("views", "b38da907588eed2d09c10bdb381e5aaf", "well"),
      array("views", "4066d038591af2b511f66557e5ac41e8", "well"),
      array("views", "2d9147be40cd77d32915a554bf315858", "well"),
      array("views", "85c57f65aa0dee37d8aa5a5031e564bc", "well"),
      array("views", "5c84bdc5ea8289bceed723799d38940f", "well"),
      array("views", "ad215e0528148b386833fa3db1f3b7dc", "well"),
      array("views", "-exp-stanford_events_views-page", "well"),
      array("views", "-exp-stanford_person_grid-page", "well"),

      // Person Grid.
      array("views", "99107f9408b38333b7b9429d6f180b75", "well"),
      // Person list.
      array("views", "84a0a512b3e0ccb8042a7d3b418168d7", "well"),
      // Person Directory.
      array("views", "385e44d327c496fd55fac99bf18f15d9", "well"),
      // Person Grouped Directory.
      array("views", "e37f035f29edbe11736c3500a7ea43a7", "well"),
      // Person Profile.
      // Panama.
      array("bean", "homepage-banner-image", "span8"),

      // Lomita.
      array("bean", "jumpstart-postcard-with-video", "span6"),

      // Mayfield.
      array("bean", "jumpstart-homepage-testimonial-b", "span6"),

      // Palm.
      array("bean", "jumpstart-homepage-tall-banner", "span12"),

      // Serra.
      array("bean", "jumpstart-info-text-block", "span3"),
      array("bean", "jumpstart-homepage-mission-block", "mission-block"),
      array("bean", "jumpstart-homepage-mission-blo-0", "mission-block"),
    );

    foreach ($values as $k => $value) {
      // UPDATE block SET (module="bean",delta="social-media",css_class="span4") WHERE module="bean" AND delta="social-media"
      $update = db_update('block')->fields(array('css_class' => $value[2]));
      $update->condition('module', $value[0]);
      $update->condition('delta', $value[1]);
      $update->execute();
    }

    db_update('block')
      ->fields(array('status' => 0))
      ->condition('module', 'webauth')
      ->condition('delta', 'webauth_login_block')
      ->execute();
  }

  /**
   * Returns an array of module requirements.
   *
   * @return array
   *   Module requirements
   */
  public function requirements() {
    return array(
      'system',
      'search',
      'user',
      'block_class',
    );
  }

}
