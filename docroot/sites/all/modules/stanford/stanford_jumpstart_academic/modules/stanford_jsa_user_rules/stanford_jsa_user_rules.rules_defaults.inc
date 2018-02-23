<?php

/**
 * @file
 * stanford_jsa_user_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function stanford_jsa_user_rules_default_rules_configuration() {
  $items = [];
  $roles = user_roles();
  $site_owner_rid = array_search('site owner', $roles);
  if (!$site_owner_rid) {
    return;
  }

  $items['rules_deleted_site_owner'] = entity_import('rules_config', '{ "rules_deleted_site_owner" : {
      "LABEL" : "Deleted Site Owner",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Site Owner" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_delete" : [] },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : { "' . $site_owner_rid . '" : "' . $site_owner_rid . '" } },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "dhliang@stanford.edu, alexbw@stanford.edu",
            "subject" : "A site owner user has been deleted [site:name]",
            "message" : "A user has been deleted on [site:url]. User that was changed has email address of [account:mail]. ",
            "from" : "[site:mail]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_new_site_owner'] = entity_import('rules_config', '{ "rules_new_site_owner" : {
      "LABEL" : "New Site Owner",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Site Owner" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "IF" : [
        { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "' . $site_owner_rid . '" : "' . $site_owner_rid . '" } } } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "dhliang@stanford.edu, alexbw@stanford.edu",
            "subject" : "A user has been granted the site owner role for [site:name]",
            "message" : "A user has been changed on [site:url]. User that was changed has email address of [account:mail]. ",
            "from" : "[site:mail]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_removed_site_owner'] = entity_import('rules_config', '{ "rules_removed_site_owner" : {
      "LABEL" : "Removed Site Owner",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Site Owner" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_update" : [] },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "account-unchanged" ],
            "roles" : { "value" : { "' . $site_owner_rid . '" : "' . $site_owner_rid . '" } },
            "operation" : "OR"
          }
        },
        { "NOT user_has_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : { "' . $site_owner_rid . '" : "' . $site_owner_rid . '" } },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "dhliang@stanford.edu, alexbw@stanford.edu",
            "subject" : "A user has lost the site owner role for [site:name]",
            "message" : "A user has been changed on [site:url]. User that was changed has email address of [account:mail]. ",
            "from" : "[site:mail]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_user_changed'] = entity_import('rules_config', '{ "rules_user_changed" : {
      "LABEL" : "User Changed",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Site Owner" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_update" : [] },
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "account-unchanged" ],
            "roles" : { "value" : { "' . $site_owner_rid . '" : "' . $site_owner_rid . '" } },
            "operation" : "OR"
          }
        },
        { "user_has_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : { "' . $site_owner_rid . '" : "' . $site_owner_rid . '" } },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "dhliang@stanford.edu, alexbw@stanford.edu",
            "subject" : "A user has been granted the site owner role for [site:name]",
            "message" : "A user has been changed on [site:url]. User that was changed has email address of [account:mail]. ",
            "from" : "[site:mail]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
