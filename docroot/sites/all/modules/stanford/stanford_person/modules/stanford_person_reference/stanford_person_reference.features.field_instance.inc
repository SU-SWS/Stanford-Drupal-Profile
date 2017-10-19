<?php
/**
 * @file
 * stanford_person_reference.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function stanford_person_reference_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-stanford_publication-field_s_person_link'
  $field_instances['node-stanford_publication-field_s_person_link'] = array(
    'bundle' => 'stanford_publication',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Link to authors who have their profile pages on this site. Begin typing the person\'s name and it will autocomplete. Enter one author per line.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_person_link',
    'label' => 'Author link',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Author link');
  t('Link to authors who have their profile pages on this site. Begin typing the person\'s name and it will autocomplete. Enter one author per line.');

  return $field_instances;
}
