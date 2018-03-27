<?php
/**
 * @file
 * stanford_subsites_vocabularies_and_terms.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function stanford_subsites_vocabularies_and_terms_taxonomy_default_vocabularies() {
  return array(
    'stanford_subsites_sites' => array(
      'name' => 'Subsites',
      'machine_name' => 'stanford_subsites_sites',
      'description' => 'Subsites Vocabulary',
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
