Authors: Marco Wise, John Bickar
URL: http://sites.stanford.edu

A drush make and Drupal install profile for new sites on the Drupal Hosting Service at Stanford ("Stanford Sites").

Leading-edge development occurs on this branch, 7.x-1.x-dev. This branch may or may not reflect what is installed on sites.stanford.edu.

The -installed branches (6.x-1.x-installed, 7.x-1.x-installed) track what is installed on sites.stanford.edu. Check out the latest tag on one of those branches to match what is currently installed on sites.stanford.edu.

If drush make fails because you do not have access to some of the github repositories referenced in the .make file, run drush make with the --force-complete flag.

Install using drush like so:

drush si stanford --account-mail="sunetid@stanford.edu" --site-mail="sunetid@stanford.edu" --site-name="Stanford Sites Install" --account-name="admin" --account-pass="admin" install_configure_form.stanford_sites_org_type="group" install_configure_form.stanford_sites_tmpdir="sites/default/files/tmp" install_configure_form.stanford_sites_requester_email="sunetid@stanford.edu" install_configure_form.stanford_sites_requester_name="Leland Stanford, Jr." install_configure_form.stanford_sites_requester_sunetid="sunetid" -y
