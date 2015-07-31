Authors: Marco Wise, John Bickar
URL: http://sites.stanford.edu

A drush make and Drupal install profile for new sites on the Drupal Hosting Service at Stanford ("Stanford Sites").

This branch, 7.x-1.x-installed, has been superseded by 7.x-2.x-installed.

Leading-edge development occurs on the -dev branch for each Drupal core version (6.x-1.x-dev, 7.x-2.x). Those branches may or may not reflect what is installed on sites.stanford.edu.

If drush make fails because you do not have access to some of the github repositories referenced in the .make file, run drush make with the --force-complete flag.

Install using drush like so:

drush si stanford --account-mail="sunetid@stanford.edu" --site-mail="sunetid@stanford.edu" --site-name="Stanford Sites Install" --account-name="admin" --account-pass="admin" install_configure_form.stanford_sites_org_type="group" install_configure_form.stanford_sites_tmpdir="sites/default/files/tmp" install_configure_form.stanford_sites_requester_email="sunetid@stanford.edu" install_configure_form.stanford_sites_requester_name="Leland Stanford, Jr." install_configure_form.stanford_sites_requester_sunetid="sunetid" -y
