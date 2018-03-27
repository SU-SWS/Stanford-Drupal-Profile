<?php
/**
 * @file
 * stanford_fellowship.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function stanford_fellowship_taxonomy_default_vocabularies() {
  return array(
    'fellowship_location' => array(
      'name' => 'Fellowship Location',
      'machine_name' => 'fellowship_location',
      'description' => 'Various types of Location of Fellowships',
      'hierarchy' => 1,
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
