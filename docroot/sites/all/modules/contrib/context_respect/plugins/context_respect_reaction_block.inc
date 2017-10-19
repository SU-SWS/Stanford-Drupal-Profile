<?php
// $Id$

/**
 * @file
 * Context Respect reaction plugin file.
 */

/**
 * Expose permissions as context reactions.
 */
class context_respect_reaction_block extends context_reaction_block {
  /**
  * Override of block_list().
  * An alternative version of block_list() that provides any context enabled blocks.
  */
  function block_list($region) {
    module_load_include('module', 'block', 'block');

    $context_blocks = &drupal_static('context_reaction_block_list');
    $contexts = context_active_contexts();
    if (!isset($context_blocks)) {
      $info = $this->get_blocks();
      $context_blocks = array();
      foreach ($contexts as $context) {
        $options = $this->fetch_from_context($context);
        if (!empty($options['blocks'])) {
          foreach ($options['blocks'] as $block) {
            $bid = $block['module'] . '-' . $block['delta'];
            if (!isset($info[$bid])) {
              continue;
            }
            // Copy general block settings.
            $block = (object) array_merge((array) $info[$bid], $block);
            // Set context name and others.
            $block->context = $context->name;
            $block->title = isset($info[$block->bid]->title) ? $info[$block->bid]->title : NULL;
            $block->cache = isset($info[$block->bid]->cache) ? $info[$block->bid]->cache : DRUPAL_NO_CACHE;

            // Check role access
            $role_match = $this->check_role_match($block);

            // Check path access
            $page_match = $this->check_page_match($block);

            if ($page_match && $role_match) {
              $context_blocks[$block->region][$block->bid] = $block;
            }
          }
        }
      }

      $this->is_editable_check($context_blocks);
      foreach ($context_blocks as $r => $blocks) {
        $context_blocks[$r] = _block_render_blocks($blocks);

        // Make blocks editable if allowed.
        if ($this->is_editable_region($r)) {
          foreach ($context_blocks[$r] as $key => $block) {
            $context_blocks[$r][$key] = $this->editable_block($block);
          }
        }

        // Sort blocks.
        uasort($context_blocks[$r], array('context_reaction_block', 'block_sort'));
      }
    }
    return isset($context_blocks[$region]) ? $context_blocks[$region] : array();
  }

  /**
   * Helper function for determining if authenticated user has access
   * to a block.
   *
   * @param $block
   *  A block object.
   *
   * @return $role_match
   *   Boolean determining if logged in user has block access
   */
  protected function check_role_match($block) {
    global $user;
    $role_match = FALSE;

    // Check for overriden variables
    $overrides = variable_get('context_respect_override_role', false);
    if ($overrides) {
      foreach ($overrides as $or_bid => $or_val) {
        if ($or_bid == $block->bid) {
          return $or_val;
        }
      }
    }

    $rids = array_keys($user->roles);
    $result = db_query("SELECT rid FROM {block_role} b WHERE b.delta = :delta and b.module = :module", array(':delta' => $block->delta, ':module' => $block->module));

    // if the block has no roles, return TRUE until they choose to use visibility settings
    if (!$result->rowCount()) {
      return TRUE;
    }

    foreach($result as $b) {
      if(in_array($b->rid, $rids)) {
        $role_match = TRUE;
      }
    }

    return $role_match;
  }

  /**
   * Helper function for determining if page level access is granted to current
   * block.
   *
   * @param $block
   *  A block object.
   *
   * @return $page_match
   *   Boolean determining if page access is granted to block
   */
  protected function check_page_match($block) {
    // Check for overriden variables
    $overrides = variable_get('context_respect_override_page', false);
    if($overrides) {
      foreach($overrides as $or_bid => $or_val) {
        if($or_bid == $block->bid) {
          return $or_val;
        }
      }
    }

    $block_data = db_query("SELECT pages, visibility FROM {block} b where b.delta = :delta and b.module = :module", array(':delta' => $block->delta, ':module' => $block->module))->fetch();
    $page_match = TRUE;

    // Bypass check if there are no pages set for a block
    if (!empty($block_data) && !$block_data->pages || drupal_match_path($_GET['q'], 'admin/structure/context*') || !$block_data) {
      return TRUE;
    }
    if(!empty($block_data) && $block_data->visibility < 2) {
      $path = drupal_get_path_alias($_GET['q']);
      $page_match = drupal_match_path($path, $block_data->pages);
      if ($path != $_GET['q']) {
        $page_match = $page_match || drupal_match_path($_GET['q'], $block_data->pages);
      }
      // When $block_data->visibility has a value of 0, the block is displayed on
      // all pages except those listed in $block_data->pages. When set to 1, it
      // is displayed only on those pages listed in $block_data->pages.
      $page_match = !($block_data->visibility xor $page_match);
    }
    elseif (!empty($block_data) && module_exists('php')) {
      $page_match = php_eval($block_data->pages);
    }
    return $page_match;
  }
}
