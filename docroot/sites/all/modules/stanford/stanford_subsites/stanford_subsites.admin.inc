<?php
/**
 * @file
 * Stanford Subsites administrative functions
 */

/**
 * Subsite configuration form.
 *
 * The configuration form options for subsite tasks. Ie: menu and content types.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form_state array.
 *
 * @return array
 *   A form array for the setting form.
 */
function stanford_subsites_admin_config_form($form, &$form_state) {

  // Set the validate hook.
  $form["#validate"][] = "stanford_subsites_admin_config_form_process_validate";

  // If the gotoconf variable is set then show the user the conf variable.
  if (isset($form_state['values']['gotoconf']) && $form_state['values']['gotoconf'] == "true") {
    $form_state['rebuild'] = TRUE;
    return confirm_form(
      $form,
      t("Are you sure you want to do this?"),
      'admin/config/subsites',
      t("You have marked a content type to be disabled. Any previously checked and now unchecked content types will have their subsite fields removed from them. This will destroy their subsite data and cannot be recovered. Click yes to confirm that you know the consequences and wish to proceed."),
      t('Yes, Proceed')
    );
  }

  // Trigger for going to confirmation form.
  $form['gotoconf'] = array(
    '#type' => 'hidden',
    '#value' => "false"
  );

  // Content Types.
  // ---------------------------------------------------------------------------

  $form['sws'] = array(
    '#type' => "fieldset",
    '#title' => t('Content Types'),
    '#description' => t("Enabled content types that can be used within a subsite."),
    '#collapsed' => FALSE,
    '#collapsible' => FALSE,
  );

  $type_names = node_type_get_names();
  $enabled_types = variable_get('stanford_subsite_content_types', array());

  // Remove subsite as option.
  unset($type_names[SUBSITE_CONTENT_TYPE]);

  $form['sws']['stanford_subsite_content_types'] = array(
    '#title' => t("Check To Enable Content Type"),
    '#type' => 'checkboxes',
    '#options' => $type_names,
    '#default_value' => $enabled_types,
  );

  // Menu Block Placement.
  // ---------------------------------------------------------------------------

  $form['sws_menu'] = array(
    '#type' => "fieldset",
    '#title' => t('Subsite Menu Placement'),
    '#description' => t("Enable/Disable and configure menu creation and block placement."),
    '#collapsed' => FALSE,
    '#collapsible' => FALSE,
  );

  $form['sws_menu']['stanford_subsite_menu_block_enabled'] = array(
    '#title' => t("Check To Enable Menu and Menu Block Creation"),
    '#description' => t("Checking this box will enable menu and menu block creation and placement on the creation of new subsites only."),
    '#type' => 'checkbox',
    '#default_value' => variable_get('stanford_subsite_enabled_menus', FALSE),
  );

  // Taken right from menu_block module...
  $form['sws_menu']['stanford_subsite_menu_block_level'] = array(
    '#title' => t("Menu block menu starting level"),
    '#default_value' => variable_get('stanford_subsite_menu_block_level', "1"),
    '#type' => 'select',
    '#options' => array(
      '1'  => t('1st level (primary)'),
      '2'  => t('2nd level (secondary)'),
      '3'  => t('3rd level (tertiary)'),
      '4'  => t('4th level'),
      '5'  => t('5th level'),
      '6'  => t('6th level'),
      '7'  => t('7th level'),
      '8'  => t('8th level'),
      '9'  => t('9th level'),
    ),
    '#description' => t('Blocks that start with the 1st level will always be visible. Blocks that start with the 2nd level or deeper will only be visible when the trail to the active menu item passes though the block’s starting level.'),
  );

  // Taken right from menu_block module...
  $form['sws_menu']['stanford_subsite_menu_block_depth'] = array(
    '#type' => 'select',
    '#title' => t('Maximum depth'),
    '#options' => array(
      '1'  => '1',
      '2'  => '2',
      '3'  => '3',
      '4'  => '4',
      '5'  => '5',
      '6'  => '6',
      '7'  => '7',
      '8'  => '8',
      '9'  => '9',
      '0'  => t('Unlimited'),
    ),
    '#description' => t('From the starting level, specify the maximum depth of the menu tree.'),
    '#default_value' => variable_get('stanford_subsite_menu_block_depth', "1"),
  );

  $mbtr = variable_get('stanford_subsite_mbtr', array());

  // We want to list out all enabled themes and provide their regions as options.
  $themes = list_themes();
  foreach ($themes as $k => $theme) {
    if (!$theme->status) {
      continue;
    }

    $regions = $theme->info['regions'];
    $regions['stanford_subsites_dnp'] = "- " . t("Do Not Place") . " -";

    $form["sws_menu"]['stanford_subsite_mbtr_' . $k] = array(
      '#title' => $theme->info['name'],
      '#type' => 'select',
      '#options' => $regions,
      '#default_value' => isset($mbtr[$k]) ? $mbtr[$k] : 'stanford_subsites_dnp',
    );

  }

  // Final bits.
  // ---------------------------------------------------------------------------

  drupal_set_message(t("WARNING: Any unchecked content types will have their Subsite fields removed from them. This will delete all subsite data for that content type."), 'warning', FALSE);
  return system_settings_form($form);
}

/**
 * Settings form custom validate actions.
 *
 * Handles redirecting the users to
 * confirmation forms, and setting up additional submit handlers
 *
 * @param array $form
 *   The form array
 * @param array $form_state
 *   The form state array.
 */
function stanford_subsites_admin_config_form_process_validate(&$form, &$form_state) {

  // Store the values of the submission for later submit hooks.
  foreach ($form_state['values'] as $k => $v) {
    $form_state['storage'][$k] = $v;
  }

  // Compare enabled content types to the form submission.
  $disabled = _has_disabled_types($form_state);

  // There are disabled types and the form hasnt been confirmed
  // Boot the user over to a confirm form.
  if ($disabled
    && !isset($form_state['values']['confirm'])) {
    form_set_value($form['gotoconf'], "true", $form_state);
    $form_state['rebuild'] = TRUE;
    return;
    // We are going to a cofirm form. End here so that additional submit handles
    // do not get added.
  }

  // There are disabled types but the user has confirmed they want to process.
  if ($disabled && !empty($form_state['values']['confirm'])) {
    $form["#submit"][] = "stanford_subsites_admin_config_form_process_submit";
  }

  // No disabled types lets process and save.
  if (!$disabled) {
    $form["#submit"][] = "stanford_subsites_admin_config_form_process_submit";
  }


  // All is good with the content types. Add in the submit hanlder for the menu
  // and block stuff.
  $form["#submit"][] = "stanford_subsites_admin_config_form_process_menu_submit";

}


/**
 * Settings form custom submit actions for processing the content types.
 *
 * @param array $form
 *   The form array
 * @param array $form_state
 *   The form state array.
 */
function stanford_subsites_admin_config_form_process_submit($form, &$form_state) {

  $original = variable_get("stanford_subsite_content_types", array());
  $values = array_merge($form_state['values'], $form_state['storage']);
  $disabled_types = array_filter($values['stanford_subsite_content_types'], '_give_zero_values');
  $filtered = array_filter($values['stanford_subsite_content_types'], '_remove_zero_values');

  // Loop through the disabled content types and remove their field instances.
  foreach ($disabled_types as $type => $nothing) {

    $tax_instance = field_read_instance('node', SUBSITE_TAGS_FIELD, $type);

    if ($tax_instance) {
      $instance = _get_tax_field_instance($type);
      field_delete_instance($instance, FALSE);
    }
  }

  // Remove content types from the list that arent enabled and then
  // store the values of the form
  $keys = array_keys($filtered);
  variable_set('stanford_subsite_content_types', $keys);

  // We now have a list of content types (bundles) that we need to attach an
  // instance of the fields to. Loop through them and attach them.
  foreach ($keys as $k => $v) {

    $tax_instance = field_read_instance('node', SUBSITE_TAGS_FIELD, $v);

    if (!$tax_instance) {
      // Create it.
      $instance = _get_tax_field_instance($v);
      field_create_instance($instance);
    }

  }

  // Last but not least. Update the path aliases for all newly added and removed
  // content types
  $added = array_diff($keys, $original);
  $removed = array_diff($original, $keys);
  $the_diff = array_merge($added , $removed);

  if (count($the_diff)) {
    foreach ($the_diff as $type) {
      // Get all the nids of the disabled content type and update the alias
      $q = db_select('node', "n")
        ->fields("n", array('nid'))
        ->condition("type", $type)
        ->execute();

      $nids = array();
      while($result = $q->fetchAssoc()) {
        $nids[] = $result['nid'];
      }

      // Save current action for new aliases and change it to update and
      // preserve old one.
      $alias_action = variable_get('pathauto_update_action', 0);
      variable_set('pathauto_update_action', 1);

      // add a bulk update operation
      pathauto_node_update_alias_multiple($nids, 'bulkupdate');

      // Restore original setting
      variable_set('pathauto_update_action', $alias_action);
    }
  }

  // Clear all the caches
  drupal_flush_all_caches();
}

/**
 * Submit handler for the configuration page menu and menu block options.
 *
 * @param array $form
 *   The form array
 * @param array $form_state
 *   The form state array
 */
function stanford_subsites_admin_config_form_process_menu_submit($form, &$form_state) {

  $values = array_merge($form_state['values'], $form_state['storage']);

  // Enable / Disable checkbox.
  variable_set('stanford_subsite_enabled_menus', $values['stanford_subsite_menu_block_enabled']);


  // Save the theme/region configuration.
  $mbtr = array();
  $themes = list_themes();
  foreach ($themes as $k => $theme) {
    if (!$theme->status) {
      continue;
    }
    $mbtr[$k] = $values['stanford_subsite_mbtr_' . $k];
  }

  variable_set('stanford_subsite_mbtr', $mbtr);

}


// HELPER FUNCTIONS
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/**
 * Revove zero values from an array callback.
 *
 * Helper function to remove items from an assoc array with value == 0
 *
 * @param array $input
 *   The input array
 *
 * @return bool
 *   True if value is valid | false if value is 0
 */
function _remove_zero_values($input) {
  if ($input === 0 ||
     $input === FALSE ||
     strlen($input) == 0 ||
     $input === "0")
  {
    return FALSE;
  }
  return TRUE;
}


/**
 * Return the values that are == 0 callback function.
 *
 * Helper function to remove items from an assoc array with value == 0
 *
 * @param array $input
 *   The input array
 * @return bool
 *   True if value is valid | false if value is 0
 */
function _give_zero_values($input) {
  if ($input === 0 ||
     $input === FALSE ||
     strlen($input) == 0 ||
     $input === "0")
  {
    return TRUE;
  }
  return FALSE;
}


/**
 * Checks the form_state array.
 *
 * Checks the form_state array against the saved enabled content types
 * for disabled types.
 *
 * @param array $form_state
 *   The form state_array
 *
 * @return bool
 *   False if there are no disabled types
 */
function _has_disabled_types($form_state) {

  $enabled_types = variable_get('stanford_subsite_content_types', array());
  $values = array_merge($form_state['values'], $form_state['storage']);
  $filtered = array_filter($values['stanford_subsite_content_types'], '_remove_zero_values');
  $keys = array_keys($filtered);

  // Loop through current enabled types and check for it being enabled in the
  // submitted values.
  foreach ($enabled_types as $k => $name) {
    if (!in_array($name, $keys)) {
      return TRUE;
    }
  }

  // Nothing disabled :)
  return FALSE;
}
