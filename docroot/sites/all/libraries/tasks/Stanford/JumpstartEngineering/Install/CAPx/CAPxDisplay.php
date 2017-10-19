<?php
/**
 * @file
 * Define the context for the CAP display view mode for person pages.
 */

namespace Stanford\JumpstartEngineering\Install\CAPx;
/**
 *
 */
class CAPxDisplay extends \ITasks\AbstractInstallTask {

  /**
   * Define the context for the CAP display view mode for person pages.
   *
   * @param array $args
   *   Installation arguments.
   */
  public function execute(&$args = array()) {
    $context = new \stdClass();
    $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
    $context->api_version = 3;
    $context->name = 'stanford_people_cap_pages';
    $context->description = 'Context for people pages using CAP fields';
    $context->tag = 'People';
    $context->conditions = array(
      'path' => array(
        'values' => array(
          'people/*' => 'people/*',
        ),
      ),
    );
    $context->reactions = array(
      'context_reaction_view_mode' => array(
        'entity_types' => array(
          'node' => array(
            'stanford_person' => 'stanford_cap',
          ),
          'reactions__plugins__context_reaction_view_mode__entity_types__active_tab' => 'edit-reactions-plugins-context-reaction-view-mode-entity-types-node',
        ),
      ),
    );
    $context->condition_mode = 0;

    // Translatables
    // Included for use with string extractors like potx.
    t('Context for people pages using CAP fields');
    t('People');

    context_save($context);
  }

  /**
   * Define module requirements.
   * @return array An array of required modules.
   */
  public function requirements() {
    return array(
      'context',
      'contextual_view_modes',
      'stanford_capx',
    );
  }

}
