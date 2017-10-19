<?php
/**
 * @file
 * Plugins
 */

/**
 * Base class for displaying context conditions
 */
class ContextListConditionDisplay {

  /**
   * The condition key that is being displayed
   * @var string
   */
  public $condition = NULL;

  /**
   * The settings for this condition
   * @var array
   */
  public $settings = NULL;

  /**
   * The constructor for this class
   *
   * @param string $condition
   *   The condition identifier
   * @param array $settings
   *   Array of settings
   */
  public function __construct($condition = NULL, $settings = array()) {
    $this->condition = $condition;
    $this->settings = $settings;
  }

  /**
   * Display the condition
   *
   * @return string
   *   The condition
   */
  public function display() {
    return $this->condition;
  }
}

/**
 * A condition display class for displaying conditions that have a
 * values key in the settings.
 *
 * This class is used by a couple of different conditions.
 */
class ContextListConditionDisplayValues extends ContextListConditionDisplay {
  /**
   * Display the condition
   */
  public function display() {
    if (isset($this->settings['values']) && is_array($this->settings['values'])) {
      $values = $this->settings['values'];
      $values = array_map('htmlentities', $values);
      return $this->condition . ': ' . implode(', ', $values);
    }

    parent::display();
  }
}

/**
 * Condition display class for defaultcontent module
 */
class ContextListConditionDisplay_defaultcontent extends ContextListConditionDisplayValues {
}

/**
 * Condition display class for path conditions
 */
class ContextListConditionDisplay_path extends ContextListConditionDisplayValues {
}

/**
 * The base class for outputting context reactions
 */
class ContextListReactionDisplay {
  /**
   * The reaction key for this reaction
   * @var string
   */
  public $reaction = NULL;

  /**
   * The settings array for this reaction
   * @var array
   */
  public $settings = NULL;

  /**
   * The constructor for this reaction display
   *
   * @param string $reaction
   *   The context's reaction
   * @param array $settings
   *   The context reaction settings
   */
  public function __construct($reaction = NULL, $settings = array()) {
    $this->reaction = $reaction;
    $this->settings = $settings;
  }

  /**
   * Display the context reaction
   * @return string
   *   The reaction representation
   */
  public function display() {
    $d = $this->reaction . ": ";
    if (is_array($this->settings)) {
      $d .= $this->implodeSettings($this->settings);
    }
    else {
      $d .= htmlentities($this->settings);
    }
    return $d;
  }

  /**
   * Recursively implodes a context reaction settings array.
   * @param array $settings
   *   An array of context reactions.
   * @return string
   *   A human readable string.
   */
  function implodeSettings($settings) {
    $string = '';
    foreach ($settings as $key => $setting) {
      if (is_array($setting)) {
        $string .= $key . ': [' . $this->implodeSettings($setting) . ']';
      }
      else {
        return implode(', ', array_map('htmlentities', array_filter($settings)));
      }
    }
    return $string;
  }
}

/**
 * The reaction display class for blocks
 */
class ContextListReactionDisplay_block extends ContextListReactionDisplay {
  /**
   * Display reaction
   */
  public function display() {
    $reaction_details = array();

    // check if anything wants to modify the list of blocks
    drupal_alter('context_list_reaction_blocks', $this->settings['blocks']);

    foreach ($this->settings['blocks'] as $block => $details) {

      // see if anythings wants to modify the block name
      drupal_alter('context_list_reaction_block_name', $block, $details);

      $block_link = $details['module'] . ': ' .
        l($block, 'admin/structure/block/manage/' . $details['module'] . '/' . $details['delta'] . '/configure');

      // if we know the link structure for this block, link to the edit screen
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

/**
 * The reaction display class for regions
 */
class ContextListReactionDisplay_region extends ContextListReactionDisplay {
  /**
   * Display the context reaction
   */
  public function display() {
    $d = $this->reaction . ": ";
    if (is_array($this->settings)) {
      $d .= '<ul>';
      foreach ($this->settings as $theme => $regions) {
        drupal_alter('context_list_reaction_theme_name', $theme, $regions);
        $d .= '<li><strong>' . check_plain($theme) . '</strong>';

        // build a list of disabled regions
        if (isset($regions['disable'])) {
          $disabled_regions = array();
          foreach ($regions['disable'] as $region => $disabled) {
            if ($disabled) {
              array_push($disabled_regions, $region);
            }
          }
        }

        // display any disabled regions
        if (count($disabled_regions) > 0) {
          $d .= '<ul>';
          foreach ($disabled_regions as $disabled_region) {
            $d .= '<li>' . t('disabled:') . ' ' . check_plain($disabled_region) . '</li>';
          }
          $d .= '</ul>';
        }

        $d .= '</li>';
      }
      $d .= '</ul>';
    }
    else {
      return parent::display();
    }
    return $d;
  }
}

/**
 * Implements hook_context_list_register_condition_display().
 */
function context_list_context_list_register_condition_display() {
  return array(
    'all' => 'ContextListConditionDisplay',
    'defaultcontent' => 'ContextListConditionDisplay_defaultcontent',
    'path' => 'ContextListConditionDisplay_path',
  );
}

/**
 * Implements hook_context_list_register_reaction_display().
 */
function context_list_context_list_register_reaction_display() {
  return array(
    'all' => 'ContextListReactionDisplay',
    'block' => 'ContextListReactionDisplay_block',
    'region' => 'ContextListReactionDisplay_region',
  );
}
