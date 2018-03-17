<?php
/**
 * @file
 * stanford_events_importer.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function stanford_events_importer_taxonomy_default_vocabularies() {
  return array(
    'stanford_event_audience' => array(
      'name' => 'Stanford Event Audience',
      'machine_name' => 'stanford_event_audience',
      'description' => 'Audience as used on events.stanford.edu (e.g., "Faculty/Staff", "Students", etc.)',
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
    'stanford_event_categories' => array(
      'name' => 'Stanford Event Categories',
      'machine_name' => 'stanford_event_categories',
      'description' => 'Category names as used on events.stanford.edu',
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
    'stanford_event_type' => array(
      'name' => 'Event Type',
      'machine_name' => 'stanford_event_type',
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
