core = 7.x
api = 2

; https://www.drupal.org/node/550428 No empty tags patch.
projects[wysiwyg][patch][] = "https://drupal.org/files/wysiwyg-non-empty-tags.550428.79.patch"

; https://drupal.org/node/1267966 - entity tokens bugs
projects[pathauto][patch][] = "https://drupal.org/files/pathauto_admin.patch"

; https://drupal.org/node/1326998 - PHP notice
projects[context_useragent][patch][] = "https://drupal.org/files/issues/context_useragent-undefined_offset_error-1326998-3.patch"

; https://drupal.org/node/927566 & https://drupal.org/node/860974 | Menu Links will not import/revert
projects[features][patch][] = "https://drupal.org/files/issues/features-parent_identifier-927566-79.patch"

; https://www.drupal.org/node/1036962 | Edit link destination incorrect when using AJAX-enabled views
projects[views][patch][] = "https://www.drupal.org/files/views-fix-destination-link-for-ajax-1036962-29.patch"

; https://www.drupal.org/node/1819538 | More link disappears when time-based views cache is enabled
projects[views][patch][] = "https://www.drupal.org/files/issues/views-more_link_disappears_with_caching-1819538-6.patch"

; https://www.drupal.org/node/1687794 | WYSIWYG Filter - Validation occurs on disabled filter
projects[wysiwyg_filter][patch][] = "https://www.drupal.org/files/wysiwyg_filter-1687794-1-skip-validation-if-filter-disabled.patch"

; https://www.drupal.org/node/2332181 | Add update hook for date_views variables
; Patch commited to 2.9-beta2
projects[date][patch][] = https://www.drupal.org/files/issues/date-date_views_update_hook-2332181-8.patch

; https://www.drupal.org/node/2471911 Form validation fails with "the directory is not writable" when public file system is remote
projects[css_injector][patch][] = "https://www.drupal.org/files/issues/css_injector-remove_drupal_realpath-2471911-2.patch"