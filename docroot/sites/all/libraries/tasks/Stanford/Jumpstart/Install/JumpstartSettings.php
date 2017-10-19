<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\Jumpstart\Install;
/**
 *
 */
class JumpstartSettings extends \ITasks\AbstractInstallTask {

  /**
   * Set the site name.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Set the home page.
    $home = drupal_lookup_path('source', 'home');
    variable_set('site_frontpage', $home);

    // Install contextual block class for Panama layout.
    $cbc_layouts = array();
    $cbc_layouts['stanford_jumpstart_home_lomita']['bean-jumpstart-lead-text-with-body'][] = 'span6';
    $cbc_layouts['stanford_jumpstart_home_mayfield']['bean-jumpstart-lead-text-with-body'][] = 'span6';
    $cbc_layouts['stanford_jumpstart_home_mayfield_news_events']['bean-jumpstart-lead-text-with-body'][] = 'span6';
    $cbc_layouts['stanford_jumpstart_home_palm']['bean-jumpstart-lead-text-with-body'][] = 'span6';
    $cbc_layouts['stanford_jumpstart_home_palm_news_events']['bean-jumpstart-lead-text-with-body'][] = 'span6';
    $cbc_layouts['stanford_jumpstart_home_panama']['bean-jumpstart-lead-text-with-body'][] = 'span4';
    $cbc_layouts['stanford_jumpstart_home_panama_news_events']['bean-jumpstart-lead-text-with-body'][] = 'span4';
    $cbc_layouts['stanford_jumpstart_home_serra']['bean-jumpstart-lead-text-with-body'][] = 'span6';
    $cbc_layouts['stanford_jumpstart_home_serra_news_events']['bean-jumpstart-lead-text-with-body'][] = 'span6';
    variable_set('contextual_block_class', $cbc_layouts);

    // Install block classes.
    // $fields = array('module', 'delta', 'css_class');
    $values = array(
      array("bean", "social-media", "span4"),
      array("bean", "contact-block", "span4"),
      array("bean", "optional-footer-block", "span3"),
      array("bean", "homepage-about-block", "well"),
      array("bean", "flexi-block-for-the-home-page", "well"),
      array("bean", "jumpstart-footer-social-media-co", "span4"),
      array("bean", "jumpstart-footer-contact-block", "span3"),
      array("bean", "jumpstart-footer-social-media--0", "span3"),
      array("bean", "jumpstart-homepage-announcements", "well"),
      // Lomita.
      array("bean", "jumpstart-postcard-with-video", "span6"),
      // Mayfield.
      array("bean", "jumpstart-homepage-testimonial-b", "span6"),
      // Palm.
      array("bean", "jumpstart-homepage-tall-banner", "span12"),
      // Panama.
      array("bean", "homepage-banner-image", "span8"),
      // Serra.
      array("bean", "jumpstart-info-text-block", "span3"),
      array("bean", "jumpstart-homepage-mission-block", "mission-block"),
      array("bean", "jumpstart-homepage-mission-blo-0", "mission-block"),
      array("menu", "menu-admin-shortcuts-home", "shortcuts-home"),
      array("menu", "menu-admin-shortcuts-site-action", "shortcuts-actions shortcuts-dropdown"),
      array("menu", "menu-admin-shortcuts-add-feature", "shortcuts-features"),
      array("menu", "menu-admin-shortcuts-get-help", "shortcuts-help"),
      array("menu", "menu-admin-shortcuts-ready-to-la", "shortcuts-launch"),
      array("menu", "menu-admin-shortcuts-logout-link", "shortcuts-logout"),
      array("menu", 'menu-related-links', 'span3'),
      array("stanford_jumpstart_layouts", "jumpstart-launch", "shortcuts-launch-block"),
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
      'cbc',
      'stanford_jumpstart',
      'stanford_jumpstart_home',
      'block_class',
    );
  }

}
