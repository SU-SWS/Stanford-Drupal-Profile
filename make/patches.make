core = 7.x
api = 2

; https://drupal.org/node/1326998 - PHP notice
; Still on RTBC as of 9.19.2016 - jbickar
projects[context_useragent][patch][] = "https://drupal.org/files/issues/context_useragent-undefined_offset_error-1326998-3.patch"

; https://www.drupal.org/node/2471911 Form validation fails with "the directory is not writable" when public file system is remote
; Committed to 7.x-1.x-dev but no new point release as of 9.19.2016 - jbickar
projects[css_injector][patch][] = "https://www.drupal.org/files/issues/css_injector-remove_drupal_realpath-2471911-2.patch"

; https://www.drupal.org/node/2160385 - PHP notices after clicking "Edit rule"
; Committed to 7.x-1.x-dev but no new point release as of 9.19.2016 - jbickar
projects[css_injector][patch][] = "https://www.drupal.org/files/issues/css_injector-bad_crid_protection-2160385-10.patch"

; https://www.drupal.org/node/2375235 Calendar block Next/Prev navigation broken
; Committed to 7.x-2.x and in 7.x-2.10-rc1, but not in 7.x-2.9, as of 9.19.2016 - jbickar
projects[date][patch][] = "https://www.drupal.org/files/issues/calendar_pager_broken-2375235-35.patch"

; https://drupal.org/node/927566 & https://drupal.org/node/860974 | Menu Links will not import/revert
; Has not been committed as of 9.19.2016; there is an updated patch in comment #82 on https://drupal.org/node/927566 - jbickar.
projects[features][patch][] = "https://drupal.org/files/issues/features-parent_identifier-927566-79.patch"

; https://drupal.org/node/1267966 - entity tokens bugs
; Has not been committed as of 9.19.2016 - jbickar
projects[pathauto][patch][] = "https://drupal.org/files/pathauto_admin.patch"

; Fixed as of 7.x-3.12 - jbickar, 9.19.2016
; https://www.drupal.org/node/1036962 | Edit link destination incorrect when using AJAX-enabled views
; projects[views][patch][] = "https://www.drupal.org/files/views-fix-destination-link-for-ajax-1036962-29.patch"

; Fixed as of 7.x-3.12 - jbickar
; https://www.drupal.org/node/1819538 | More link disappears when time-based views cache is enabled
; projects[views][patch][] = "https://www.drupal.org/files/issues/views-more_link_disappears_with_caching-1819538-6.patch"

; https://www.drupal.org/node/550428 No empty tags patch.
; Has not been committed as of 9.19.2016 - jbickar
projects[wysiwyg][patch][] = "https://drupal.org/files/wysiwyg-non-empty-tags.550428.79.patch"

; Fixed as of 7.x-1.6-rc3 - jbickar, 9.19.2016
; https://www.drupal.org/node/1687794 | WYSIWYG Filter - Validation occurs on disabled filter
; projects[wysiwyg_filter][patch][] = "https://www.drupal.org/files/wysiwyg_filter-1687794-1-skip-validation-if-filter-disabled.patch"

; https://www.drupal.org/node/2221307 | Deleting host entity causes save during deletion and triggers pathauto
; Has not been committed as of 9.19.2016 - jbickar
projects[field_collection][patch][] = "https://www.drupal.org/files/issues/field_collection-2385985-29.patch"
