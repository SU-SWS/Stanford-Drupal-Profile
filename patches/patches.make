core = 7.x
api = 2

; https://www.drupal.org/node/2471911 Form validation fails with "the directory is not writable" when public file system is remote
; Committed to 7.x-1.x-dev but no new point release as of 9.19.2016 - jbickar
projects[css_injector][patch][] = "https://www.drupal.org/files/issues/css_injector-remove_drupal_realpath-2471911-2.patch"

; https://www.drupal.org/node/2160385 - PHP notices after clicking "Edit rule"
; Committed to 7.x-1.x-dev but no new point release as of 9.19.2016 - jbickar
projects[css_injector][patch][] = "https://www.drupal.org/files/issues/css_injector-bad_crid_protection-2160385-10.patch"

; https://www.drupal.org/node/2375235 Calendar block Next/Prev navigation broken
; Committed to 7.x-2.x and in 7.x-2.10-rc1, but not in 7.x-2.9, as of 9.19.2016 - jbickar
projects[date][patch][] = "https://www.drupal.org/files/issues/calendar_pager_broken-2375235-35.patch"

; https://www.drupal.org/node/2221307 | Patch allows for field groups to be rendered in ds custom block regions⏎
projects[ds][patch][] = "https://www.drupal.org/files/issues/ds_extras_field_group_not_rendered-2221307-18.patch"

; https://drupal.org/node/927566 & https://drupal.org/node/860974 | Menu Links will not import/revert
; Has not been committed as of 9.19.2016; there is an updated patch in comment #82 on https://drupal.org/node/927566 - jbickar.
projects[features][patch][] = "https://drupal.org/files/issues/features-parent_identifier-927566-79.patch"

; https://www.drupal.org/node/2713921 | Cannot install on mysql 5.7+
projects[jw_player][patch][] = "https://www.drupal.org/files/issues/jw-player-mysql57-2713921-8.patch"

; https://drupal.org/node/1267966 - entity tokens bugs
; Has not been committed as of 9.19.2016 - jbickar
projects[pathauto][patch][] = "https://drupal.org/files/pathauto_admin.patch"

; https://www.drupal.org/node/550428 No empty tags patch.
; Has not been committed as of 9.19.2016 - jbickar
projects[wysiwyg][patch][] = "https://drupal.org/files/wysiwyg-non-empty-tags.550428.79.patch"

; For ACSF

; https://www.drupal.org/project/features/issues/2957125 - Features replace eval().
projects[features][patch][] = "https://www.drupal.org/files/issues/2018-03-29/features-replace_eval_anonymous_functions.patch"

; Remove usage of deprecated create_function() calls for PHP 7.2+ future proofing
projects[context][patch][] = "https://www.drupal.org/files/issues/context-support_php_72-2946595-3.patch"

; https://www.drupal.org/project/paranoia/issues/2313945 - block some "import foo" boxes that use php arrays as a data structure
projects[paranoia][patch][] = "https://www.drupal.org/files/issues/2018-03-28/paranoia-block_additional_forms-2313945-33.patch"

; https://stanfordits.atlassian.net/browse/SITES-330 - Force Paranoia always to be enabled.
projects[drupal][patch][] = "https://raw.githubusercontent.com/SU-SWS/acsf-cardinald7/SITES-330-hack-core/patches/enforce-paranoia.patch?token=AAyHcutKMbOAId8FJkVOMasWuyZBD8rkks5axolywA%3D%3D"