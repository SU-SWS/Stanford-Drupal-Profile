<?php

/**
 * @file
 * Set contextual block classes.
 */

namespace Stanford\JumpstartEngineering\Install\Block;
use \ITasks\AbstractInstallTask;

/**
 * Contextual Block Classes configuration for JSE sites class.
 */
class JSEContextualBlockClasses extends AbstractInstallTask {

  /**
   * Set Contextual Block Classes.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Install contextual block classes.
    $cbc_layouts = variable_get("contextual_block_class", array());
    $cbc_layouts['stanford_jumpstart_home_gibbons']['bean-homepage-about-block'][] = 'span8 well column';
    $cbc_layouts['stanford_jumpstart_home_hoover']['bean-homepage-about-block'][] = 'span4 well column';
    $cbc_layouts['stanford_jumpstart_home_morris']['bean-homepage-about-block'][] = 'span4 well column';
    $cbc_layouts['stanford_jumpstart_home_pettit']['bean-homepage-about-block'][] = 'span8 well column';
    $cbc_layouts['stanford_jumpstart_home_terman']['bean-jumpstart-about-block'][] = 'span4 well column';

    $cbc_layouts['sitewide_jse']['bean-jse-linked-logo-block'][] = 'span4';
    $cbc_layouts['sitewide_jse']['bean-jumpstart-footer-contact-block'][] = 'span2';
    $cbc_layouts['sitewide_jse']['bean-jumpstart-footer-social-media--0'][] = 'span2';
    $cbc_layouts['sitewide_jse']['bean-jumpstart-custom-footer-block'][] = 'span2';
    $cbc_layouts['sitewide_jse']['stanford_private_page-stanford_internal_login'][] = 'span2';
    variable_set('contextual_block_class', $cbc_layouts);
  }

}
