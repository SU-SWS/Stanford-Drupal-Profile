; Stanford makefile
; ------------

; Core version
; ------------
; Each makefile should begin by declaring the core version of Drupal that all
; projects should be compatible with.

core = 6.x

; API version
; ------------
; Every makefile needs to declare it's Drush Make API version. This version of
; drush make uses API version `2`.

api = 2

; Core project
; ------------
projects[drupal][type] = core

; Projects
; --------

projects[admin_menu] = 1.6
projects[auto_nodetitle] = 1.2
projects[biblio] = 1.15
projects[calendar] = 2.4
projects[cck] = 2.9
projects[content_access] = 1.2
projects[css_injector] = 1.4
projects[ctools] = 1.8
projects[date] = 2.7
projects[email] = 1.2
projects[features] = 1.0
projects[feeds] = 1.0-beta11
projects[feeds_xpathparser] = 1.11
projects[filefield] = 3.10
projects[globalredirect] = 1.2
projects[google_analytics] = 3.3
projects[imageapi] = 1.10
projects[imagecache] = 2.0-beta12
projects[imagefield] = 3.10
projects[insert] = 1.1
projects[job_scheduler] = 1.0-beta3
projects[jquery_ui] = 1.4
projects[link] = 2.9
projects[mollom] = 1.15
projects[nodeformcols] = 1.6
projects[pathauto] = 1.5
projects[pathologic] = 3.4
projects[path_redirect] = 1.0-rc2
projects[semanticviews] = 1.1
projects[token] = 1.15
projects[vertical_tabs] = 1.0-rc1
projects[views] = 2.12
projects[views_slideshow] = 2.3
projects[wysiwyg] = 2.3

; Stanford Modules
projects[stanford_events_importer][type] = module
projects[stanford_events_importer][download][type] = file
projects[stanford_events_importer][download][url] = 'https://techcommons.stanford.edu/files/stanford_events_importer-6.x-1.0-beta6.tar.gz'

; need URLs
;projects[] = webauth

; Themes

projects[] = tao
projects[] = rubik

; Libraries

libraries[jquery_ui][download][type] = "get"
libraries[jquery_ui][download][url] = "http://jquery-ui.googlecode.com/files/jquery.ui-1.6.zip"
libraries[jquery_ui][directory_name] = "jquery.ui"
libraries[jquery_ui][destination] = "libraries"

libraries[ckeditor][download][type] = "get"
libraries[ckeditor][download][url]  = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.5.3/ckeditor_3.5.3.zip"
libraries[ckeditor][directory_name] = "ckeditor"
libraries[ckeditor][destination] = "libraries"

; Profile

projects[stanford][type] = "profile"
projects[stanford][download][type] = "git"
projects[stanford][download][url] = "git@github.com:mistermarco/Stanford-Drupal-Profile.git"