<?php
/**
 * @file
 * API hooks
 */

/**
 * Register a condition display class
 * @return array
 *   An array of display PHP classes that are used to display conditions
 */
function hook_context_list_register_condition_display() {
  return array(
    'all' => 'ContextListConditionDisplay',
    'defaultcontent' => 'ContextListConditionDisplay_defaultcontent',
    'path' => 'ContextListConditionDisplay_path',
  );
}

/**
 * Register a reaction display class
 * @return array
 *   An array of display PHP classes that are used to display conditions
 */
function hook_context_list_register_reaction_display() {
  return array(
    'all' => 'ContextListReactionDisplay',
    'block' => 'ContextListReactionDisplay_block',
  );
}

/**
 * Alter a block name
 */
function hook_context_list_reaction_block_name(&$block_name, &$details) {
}

/**
 * Alter the list of blocks available to the context display plugin
 */
function hook_context_list_reaction_blocks(&$blocks) {
}

/**
 * Alter a theme name
 */
function hook_context_list_reaction_theme_name(&$theme_name, &$regions) {
}
