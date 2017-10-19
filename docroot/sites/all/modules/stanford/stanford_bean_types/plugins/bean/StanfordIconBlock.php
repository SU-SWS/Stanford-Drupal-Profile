<?php
/**
 * @file
 * StanfordIconBlock
 */

class StanfordIconBlock extends BeanDefault {

  /**
   * Return the block content.
   *
   * @param $bean
   *   The bean object being viewed.
   * @param $content
   *   The default content array created by Entity API.  This will include any
   *   fields attached to the entity.
   * @param $view_mode
   *   The view mode passed into $entity->view().
   * @return
   *   Return a renderable content array.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {

    if (!isset($content['bean'][$bean->delta]['field_s_icon_icon'])) {
      drupal_set_message("Could not find field_s_icon_icon on icon block", "error", TRUE);
      return $content;
    }

    // Get the rendered text from the output.
    $text = $content['bean'][$bean->delta]['field_s_icon_icon'][0]["#markup"];

    // Create the markup and get the css class from the field.
    $markup = "<div>";
    $markup .= "<i class=\"icon-3x " . drupal_clean_css_identifier($bean->field_s_icon_icon[LANGUAGE_NONE][0]['value']) . "\"><span class=\"icon-text\">" . t($text) . "</span></i>";
    $markup .= "</div>";

    // Re-set the field content.
    $content['bean'][$bean->delta]['field_s_icon_icon'][0]["#markup"] = $markup;

    // Return it.
    return $content;
  }

}
