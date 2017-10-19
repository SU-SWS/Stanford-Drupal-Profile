api: 2
core: 7.x

includes:
  - drupal-org-core.make
  - drupal-org.make

# see http://www.drush.org/en/master/make/#recursion the 'Use a distribution as core' section under recursion.
projects:
  lightning:
    type: core
    version: 7.x-1.0-beta14
