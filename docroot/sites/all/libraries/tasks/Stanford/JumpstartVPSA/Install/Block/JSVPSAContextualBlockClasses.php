<?php
/**
 * @file
 * Abstract Task Class.
 */

namespace Stanford\JumpstartVPSA\Install\Block;
/**
 *
 */
class JSVPSAContextualBlockClasses extends \ITasks\AbstractInstallTask {

  /**
   * Set Contextual Block Classes.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {

    // Insert contextual block classes.
    // -------------------------------------------------------------------------
    $cbc_layouts = array();
    // Large about block.
    $cbc_layouts['vpsa_homepage_dickinson']['bean-vpsa-large-about-block'][] = 'span8';
    $cbc_layouts['vpsa_homepage_dickinson']['bean-vpsa-large-about-block'][] = 'clear-row';
    $cbc_layouts['vpsa_homepage_dickinson']['bean-vpsa-large-about-block'][] = 'column';
    // Quick links.
    $cbc_layouts['vpsa_homepage_dickinson']['bean-vpsa-quick-links'][] = 'span4';
    $cbc_layouts['vpsa_homepage_dickinson']['bean-vpsa-quick-links'][] = 'well';
    $cbc_layouts['vpsa_homepage_dickinson']['bean-vpsa-quick-links'][] = 'column';
    $cbc_layouts['vpsa_homepage_ellison']['bean-vpsa-quick-links'][] = 'well';
    $cbc_layouts['vpsa_homepage_melville']['bean-vpsa-quick-links'][] = 'well';
    $cbc_layouts['vpsa_homepage_melville']['bean-vpsa-quick-links'][] = 'column';
    $cbc_layouts['vpsa_homepage_morrison']['bean-vpsa-quick-links'][] = 'span4';
    $cbc_layouts['vpsa_homepage_morrison']['bean-vpsa-quick-links'][] = 'well';
    $cbc_layouts['vpsa_homepage_morrison']['bean-vpsa-quick-links'][] = 'column';
    // Announcements & News block.
    $cbc_layouts['vpsa_homepage_dickinson']['views-f73ff55b085ea49217d347de6630cd5a'][] = 'well';
    $cbc_layouts['vpsa_homepage_dickinson']['views-f73ff55b085ea49217d347de6630cd5a'][] = 'column';
    $cbc_layouts['vpsa_homepage_ellison']['views-f73ff55b085ea49217d347de6630cd5a'][] = 'well';
    $cbc_layouts['vpsa_homepage_melville']['views-f73ff55b085ea49217d347de6630cd5a'][] = 'well';
    $cbc_layouts['vpsa_homepage_melville']['views-f73ff55b085ea49217d347de6630cd5a'][] = 'column';
    $cbc_layouts['vpsa_homepage_morrison']['views-f73ff55b085ea49217d347de6630cd5a'][] = 'well';
    // Upcoming events block. Date stacked.
    $cbc_layouts['vpsa_homepage_dickinson']['views-stanford_events_views-block'][] = 'well';
    $cbc_layouts['vpsa_homepage_dickinson']['views-stanford_events_views-block'][] = 'column';
    $cbc_layouts['vpsa_homepage_morrison']['views-stanford_events_views-block'][] = 'well';
    // Custom content block.
    $cbc_layouts['vpsa_homepage_dickinson']['bean-vpsa-custom-block-'][] = 'well';
    $cbc_layouts['vpsa_homepage_dickinson']['bean-vpsa-custom-block-'][] = 'column';
    $cbc_layouts['vpsa_homepage_melville']['bean-vpsa-custom-block-'][] = 'well';
    $cbc_layouts['vpsa_homepage_melville']['bean-vpsa-custom-block-'][] = 'column';
    $cbc_layouts['vpsa_homepage_morrison']['bean-vpsa-custom-block-'][] = 'well';
    $cbc_layouts['vpsa_homepage_morrison']['bean-vpsa-custom-block-'][] = 'column';
    $cbc_layouts['vpsa_homepage_morrison']['bean-vpsa-custom-block-'][] = 'span4';
    // Custom content block #2.
    $cbc_layouts['vpsa_homepage_morrison']['bean-vpsa-custom-block-2'][] = 'well';
    $cbc_layouts['vpsa_homepage_morrison']['bean-vpsa-custom-block-2'][] = 'column';
    $cbc_layouts['vpsa_homepage_morrison']['bean-vpsa-custom-block-2'][] = 'span4';
    // Social media connect block.
    $cbc_layouts['vpsa_homepage_dickinson']['bean-jumpstart-footer-social-media--0'][] = 'span12';
    $cbc_layouts['vpsa_homepage_ellison']['bean-jumpstart-footer-social-media--0'][] = 'span12';
    $cbc_layouts['vpsa_homepage_ellison']['bean-jumpstart-footer-social-media--0'][] = 'clear-row';
    $cbc_layouts['vpsa_homepage_melville']['bean-jumpstart-footer-social-media--0'][] = 'span12';
    // Full width banner short. full-width-banner-short
    // $cbc_layouts['vpsa_homepage_dickinson'][''][] = '';
    // Upcoming Event 5 Item List block.
    $cbc_layouts['vpsa_homepage_ellison']['views-stanford_events_views-block_1'][] = 'span12';
    $cbc_layouts['vpsa_homepage_ellison']['views-stanford_events_views-block_1'][] = 'clear-row';
    // Storytelling block.
    $cbc_layouts['vpsa_homepage_melville']['bean-vpsa-story-telling-block'][] = 'span12';
    $cbc_layouts['vpsa_homepage_melville']['bean-vpsa-story-telling-block'][] = 'clear-row';
    $cbc_layouts['vpsa_homepage_morrison']['bean-vpsa-story-telling-block'][] = 'span12';
    $cbc_layouts['vpsa_homepage_morrison']['bean-vpsa-story-telling-block'][] = 'clear-row';
    // OK DONE!
    variable_set('contextual_block_class', $cbc_layouts);
  }

}
