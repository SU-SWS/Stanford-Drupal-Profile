<?php
/**
 * @file
 *
 */

class context_reaction_view_mode extends context_reaction {

  /**
   * Override of options form.
   *
   * @param  array $context
   *  The context object we are working on.
   */
  function options_form($context) {
    // Get parent class form.
    $form = parent::options_form($context);
    // Get the options the have been saved.
    $options = $this->fetch_from_context($context);
    // Get all entity information. We are going to need it.
    $entity_info = entity_get_info();

    // Do not support these.
    unset($entity_info['comment']);
    unset($entity_info['taxonomy_vocabulary']);

    // Create a VT group for supported entity types.
    $form['entity_types'] = array(
      '#type' => 'vertical_tabs',
    );

    // For each entity type create a settings group.
    foreach ($entity_info as $entity_type => $info) {

      // Fieldset wrapper.
      $form['entity_types'][$entity_type] = array(
        '#title' => check_plain($info['label']),
        '#description' => t('View mode selection for ') . $info['label'],
        '#type' => 'fieldset',
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
        '#group' => 'entity_types',
        '#tree' => TRUE,
      );

      // Create drop down options for entity type view modes.
      $modes = array("none" => t("Not set"));
      foreach ($info['view modes'] as $mode_key => $mode_info) {
        $modes[$mode_key] = $mode_info['label'];
      }

      foreach ($info['bundles'] as $machine_name => $bundle_info) {
        $default = isset($options['entity_types'][$entity_type][$machine_name]) ? $options['entity_types'][$entity_type][$machine_name] : 'none';
        $form['entity_types'][$entity_type][$machine_name] = array(
          '#title' => $bundle_info['label'] . " " . t("view mode"),
          '#description' => t("Select the view mode for this entity bundle type when this context is active"),
          '#type' => 'select',
          '#options' => $modes,
          '#default_value' => $default,
        );
      }

    }

    return $form;
  }


  /**
   * Execute and return the type of entity view mode that should be used.
   *
   * @param string $type
   *   The type of entity we are working on.
   * @param object $entity
   *   The entity object to be evaluated.
   *
   *
   * @return mixed
   *   False if no match or a string of the view mode if matched.
   */
  function execute(&$entity, $type) {

    // Be safe, wrap it up.
    $wrapped = entity_metadata_wrapper($type, $entity);
    // Get the bundle type.
    $bundle = $wrapped->getBundle();
    // Get the available active contexts
    $contexts = $this->get_contexts();

    // Loop through each active context and assert the view mode settings.
    foreach ($contexts as $context) {
      // The configuration options for the context.
      $options = $this->fetch_from_context($context);
      // If no setting found keep moving along.
      if (!isset($options['entity_types'][$type][$bundle])) {
        continue;
      }
      // If we find a match then return the view mode string.
      if ($options['entity_types'][$type][$bundle] !== "none") {
        return $options['entity_types'][$type][$bundle];
      }
    }

    // Nothing matched. Return false.
    return FALSE;
  }

}
