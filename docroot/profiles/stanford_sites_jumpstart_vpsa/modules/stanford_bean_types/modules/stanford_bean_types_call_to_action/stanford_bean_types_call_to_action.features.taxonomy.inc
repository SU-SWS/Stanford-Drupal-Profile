<?php
/**
 * @file
 * stanford_bean_types_call_to_action.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function stanford_bean_types_call_to_action_taxonomy_default_vocabularies() {
  return array(
    'stanford_cta_color' => array(
      'name' => 'Call to Action Color',
      'machine_name' => 'stanford_cta_color',
      'description' => 'Color for call-to-action highlighting',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
