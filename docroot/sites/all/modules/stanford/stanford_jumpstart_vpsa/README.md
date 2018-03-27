#Jumpstart VPSA
Version 7.x-4.6+8-dev

[![Code Climate](https://codeclimate.com/github/SU-SWS/stanford_jumpstart_vpsa/badges/gpa.svg)](https://codeclimate.com/github/SU-SWS/stanford_jumpstart_vpsa)

This module contains code for the JSVPSA product. Current it is a container for other sub modules but will be the place for future additions outside of the installation profile.

## Modules in this module:

**[Stanford Jumpstart VPSA Basic Page Import](modules/stanford_jumpstart_vpsa_basic_page_import)**
A feeds importer specifically tuned to import basic page content from pre-existing SA websites. This is to expedite  the migration process.

**[Stanford Jumpstart VPSA Events Import](modules/stanford_jumpstart_vpsa_events_import)**
A feeds importer specifically tuned to import events content from pre-existing SA websites. This is to expedite the migration process.

**[Stanford Jumpstart VPSA Layouts](modules/stanford_jumpstart_vpsa_layouts)**
A feature module containing a number of context layouts and css specific to this product.

**[Stanford Jumpstart VPSA Permissions](modules/stanford_jumpstart_vpsa_permissios)**
A feature module containing the base permissions for this product. This module is dependant on the VPSA roles module.

**[Stanford Jumpstart VPSA Roles](modules/stanford_jumpstart_site_vpsa_roles)**
A feature module contining additional roles on top of Stanford Jumpstart Roles. Contains the student assistant role.

**[Stanford Jumpstart VPSA Shortcuts](modules/stanford_jumpstart_vpsa_shortcuts)**
A jumpstart shortcuts module that orders the shortcuts for VPSA specific weights.

**[Stanford Jumpstart VPSA Workflows](modules/stanford_jumpstart_vpsa_workflows)**
A feature module that contains the workbench workflows for this product.

**[VPSA Content Access](modules/vpsa_content_access)**
A feature module that contains the content_access configuration settings for the content types in this product.

**[VPSA Landing Page](modules/vpsa_landing_page)**
A feature module that contains landing page content type that has a special layout.
