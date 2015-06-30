#[Stanford Drupal Profile](https://github.com/SU-SWS/Stanford-Drupal-Profile)
##### Version: 7.x-2.x-dev
Maintainers: [Marco Wise](https://github.com/mistermarco), [John Bickar](https://github.com/jbickar), [Shea McKinney](https://github.com/sherakama)

URL: [http://sites.stanford.edu](http://sites.stanford.edu)

A drush make and Drupal install profile for new sites on the Drupal Hosting Service at Stanford ("Stanford Sites").

Leading-edge development occurs on this branch, 7.x-2.x. This branch may or may not reflect what is installed on sites.stanford.edu.

The -installed branches (6.x-1.x-installed, 7.x-1.x-installed) track what is installed on sites.stanford.edu. Check out the latest tag on one of those branches to match what is currently installed on sites.stanford.edu.

## Drush Make

* Run `drush make make/group.make` to create a group or personal site.
* Run `drush make make/group.make` to create a department site (includes Stanford-specific themes; `drush make` will fail if you do not have access to the private theme repositories).
* Run `drush make make/anchorage.make` to create a department site for the Anchorage hosting environment (includes Stanford-specific themes; `drush make` will fail if you do not have access to the private theme repositories).

## Drupal Site Installation
Install using drush like so:

`drush si stanford --account-mail="sunetid@stanford.edu" --site-mail="sunetid@stanford.edu" --site-name="Stanford Sites Install" --account-name="admin" --account-pass="admin" install_configure_form.stanford_sites_org_type="group" install_configure_form.stanford_sites_tmpdir="sites/default/files/tmp" install_configure_form.stanford_sites_requester_email="sunetid@stanford.edu" install_configure_form.stanford_sites_requester_name="Leland Stanford, Jr." install_configure_form.stanford_sites_requester_sunetid="sunetid" -y`

Additional flags for "drush si":

To use SimpleSAMLphp instead of webauth:
`install_configure_form.stanford_authentication=simplesamlphp`

To use Amazon S3 as the file system instead of local file system:
`install_configure_form.enable_s3fs=1 install_configure_form.awssdk2_access_key="INSERT_KEY_HERE" install_configure_form.awssdk2_secret_key="INSERT_SECRET_KEY_HERE" install_configure_form.s3fs_bucket="BUCKET_NAME_HERE"  install_configure_form.s3fs_bucket_region="us-west-2"`
