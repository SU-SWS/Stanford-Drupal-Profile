<?php
/**
 * @file
 * stanford_courses.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function stanford_courses_default_rules_configuration() {
  $items = array();
  $items['rules_courses_academic_year'] = entity_import('rules_config', '{ "rules_courses_academic_year" : {
      "LABEL" : "Courses Academic Year",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Courses" ],
      "REQUIRES" : [ "rules", "stanford_courses", "field_collection" ],
      "ON" : { "field_collection_item_presave" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "field-collection-item" ],
            "type" : "field_collection_item",
            "bundle" : { "value" : { "field_s_course_section_info" : "field_s_course_section_info" } }
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : {
              "type" : "text",
              "value" : [ "field-collection-item:field-s-course-section-year" ]
            },
            "PROVIDE" : { "variable_added" : { "date_string" : "Date String" } }
          }
        },
        { "data_convert" : {
            "USING" : { "type" : "integer", "value" : [ "date-string" ] },
            "PROVIDE" : { "conversion_result" : { "date_int" : "Date Integer" } }
          }
        },
        { "data_calc" : {
            "USING" : { "input_1" : [ "date-int" ], "op" : "+", "input_2" : "1" },
            "PROVIDE" : { "result" : { "academic_year" : "Academic Year" } }
          }
        },
        { "stanford_courses_string_to_time" : {
            "USING" : {
              "input" : [ "academic-year" ],
              "padding_string" : "Jan 1 ",
              "padding_side" : "left"
            },
            "PROVIDE" : { "parsed_date" : { "parsed_date" : "Date Stamp" } }
          }
        },
        { "data_set" : {
            "data" : [ "field-collection-item:field-s-course-year-computed" ],
            "value" : [ "parsed-date" ]
          }
        },
        { "entity_save" : { "data" : [ "field-collection-item" ] } }
      ]
    }
  }');
  return $items;
}
