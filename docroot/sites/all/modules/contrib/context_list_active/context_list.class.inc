<?php

/**
 * @file
 * Contains ContextListReactionDisplay_blockWithName class
 */

/**
 * The reaction display class for blocks
 *
 * Nearly a duplicate of the class it extends, except we fetch the human readable block name
 */
class ContextListReactionDisplay_blockWithName extends ContextListReactionDisplay_block {
  function display() {
    $reaction_details = array();

    foreach ($this->settings['blocks'] as $block => $details) {
      // Grab the human readable block name
      // @todo - Probably a more efficient way then recalling the hook_block_info function multiple times, but
      // performance impact is probably negligible, especially for a dev module
      $info = call_user_func($details['module'] . '_block_info');
      if (!empty($info[$details['delta']]['info'])) {
        $block_name = $info[$details['delta']]['info'];
      }
      else {
        $block_name = '';
      }

      $block_link = $details['module'] . ': ' .
        l($block_name . " ($block)", 'admin/structure/block/manage/' . $details['module'] . '/' . $details['delta'] . '/configure');

      // Original function follows:

      switch ($details['module']) {
        case 'menu':
          $block_link .= ' (' . l(t('Edit'), 'admin/structure/menu/manage/' . $details['delta']) . ')';
          break;
        case 'views':
          $view = str_replace('-', '/', $details['delta']);
          $block_link .= ' (' . l(t('Edit'), 'admin/structure/views/view/' . $view) . ')';
          break;
      }

      array_push(
        $reaction_details,
        $block_link
      );
    }
    $list = array(
      '#theme' => 'item_list',
      '#items' => $reaction_details,
    );
    $rendered_list = '<p>Blocks:</p>' . drupal_render($list);
    return $rendered_list;
  }
}