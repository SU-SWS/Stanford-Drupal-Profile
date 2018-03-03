<?php
/**
 * @file
 * stanford_affiliate_organization.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function stanford_affiliate_organization_taxonomy_default_vocabularies() {
  return array(
    'stanford_affiliate_organization_type' => array(
      'name' => 'Affiliate Organization Type',
      'machine_name' => 'stanford_affiliate_organization_type',
      'description' => '',
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
