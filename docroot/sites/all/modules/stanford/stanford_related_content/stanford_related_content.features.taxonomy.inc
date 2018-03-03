<?php
/**
 * @file
 * stanford_related_content.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function stanford_related_content_taxonomy_default_vocabularies() {
  return array(
    'stanford_related_content' => array(
      'name' => 'Related Content',
      'machine_name' => 'stanford_related_content',
      'description' => 'Defines relationships for displaying aggregated content ',
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
