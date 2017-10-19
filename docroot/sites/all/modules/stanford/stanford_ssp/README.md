# [Stanford Simple SAML PHP](https://github.com/SU-SWS/stanford_ssp)
##### Version: 7.x-2.1-dev

Maintainers: [jbickar](https://github.com/jbickar),  [sherakama](https://github.com/sherakama)

[Changelog.txt](CHANGELOG.txt)

Simple SAML PHP authentication module for Drupal websites. This module is intended to replace the Webauth module and should be used independently of it. This module makes it possible for Drupal to communicate with SAML or Shibboleth identity providers (IdP) for authenticating users.

Sub Modules
---

**[Stanford SAML Block](https://github.com/SU-SWS/stanford_ssp/tree/7.x-2.x/modules/stanford_saml_block)**
Provides a login block and context for the sitewide header region. Also, alters the user login form to provide both local and SUNet login.

**[Stanford SimpleSAMLPHP Authentication](https://github.com/SU-SWS/stanford_ssp/tree/7.x-2.x/modules/stanford_simplesamlphp_auth)**
A complete re-write of the simplesamlphp_auth contrib module from Drupal.org. For more information on to why please see this thread: https://www.drupal.org/node/2745089

Installation
---

Install this module like any other module. [See Drupal Documentation](https://drupal.org/documentation/install/modules-themes/modules-7)

**DO NOT** install the simplesamlphp_auth contrib module from Drupal.org as it conflicts with this module.

**DO NOT** install the webauth module with this module as they conflict.

Prerequisites
---

SimpleSAMLphp - you must have SimpleSAMLphp version 1.6 or newer installed and configured to operate as a service provider (SP).

Please see [simplesamlphp_auth modules configuration for more](https://github.com/SU-SWS/stanford_ssp/tree/7.x-2.x/modules/stanford_simplesamlphp_auth#prerequisites).

Configuration
---

The main configuration page can be found at: `/admin/config/stanford/stanford_ssp`

**General Configuration:**  
In this section you can enable and disable authentication through SAML or local Drupal accounts. Be sure to have an authentication scheme planned and the appropriate permissions set before configuring this section as it is possible to lock yourself out of the Drupal website.

**User Account Configuration**  
In this section you can control the behaviour of users authenticating with SAML. You can choose wether to automatically create an account when a user successfully authenticates with the IDP, to automatically prompt the end user for SAML log in if they hit a 403 access denied page, and if they are allowed to create a Drupal password.

**SAML Configuration**  
These are the configuration options to let your Drupal website communicate with SimpleSAMLPHP. In here you tell Drupal where SimpleSAMLPHP is installed and which properties of the response describe the user.

#### Role Mappings
`/admin/config/stanford/stanford_ssp/role-mappings`

Role mappings allow for Drupal administrators to automatically assign roles to users who authenticate through SimpleSAMLPHP. This can be useful to assigning groups of people to specific roles. To do this select a Drupal role that already exists from the drop down menu, discover and copy and paste the workgroup you want to grant the Drupal role to and press the Add Mapping button. Be sure to copy and paste the workgroup name exactly as it needs to be an exact match.

Users that successfully authenticate will automatically receive one or more roles as everyone who authenticates will receive the `SSO User` role. Additional roles may be added if the user is a 'Student', 'Faculty', 'Staff', or some other type of account.

#### Login Block & Forms  
`/admin/config/stanford/stanford_ssp/login-block-forms`

In this section you can control the appearance of the login form found at `/user`

#### Authorizations
`/admin/config/stanford/stanford_ssp/authorizations`

In this section you can control who is allowed to authenticate using SAML. You may want to restrict this section to a specific set of SUNet ID's, a workgroup or two, or you may just want to leave it to the default setting of allowing anyone with a sunet id to be authenticated.

You may also modify the default behaviour of the Local Drupal accounts and prevent only specific roles or user ids to authenticate.

#### Add SSO User

Use this form to add user accounts that may authenticate with SAML. This is useful for adding users and granting them roles prior to their first log in.

Troubleshooting
---

Send a helpsu to Stanford Web Services or post an issue to the GitHub issue queue.

Contribution / Collaboration
---

You are welcome to contribute functionality, bug fixes, or documentation to this module. If you would like to suggest a fix or new functionality you may add a new issue to the GitHub issue queue or you may fork this repository and submit a pull request. For more help please see [GitHub's article on fork, branch, and pull requests](https://help.github.com/articles/using-pull-requests)
