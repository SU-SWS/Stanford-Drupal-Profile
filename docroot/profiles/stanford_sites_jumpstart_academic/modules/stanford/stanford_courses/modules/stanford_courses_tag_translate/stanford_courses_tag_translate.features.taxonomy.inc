<?php
/**
 * @file
 * stanford_courses_tag_translate.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function stanford_courses_tag_translate_taxonomy_default_vocabularies() {
  return array(
    'course_tags_human' => array(
      'name' => 'Human-Readable Course Tags',
      'machine_name' => 'course_tags_human',
      'description' => 'For the human-readable tags',
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
