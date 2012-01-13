; Stanford makefile
; ------------

; Core version
; ------------
; Each makefile should begin by declaring the core version of Drupal that all
; projects should be compatible with.

core = 7.x

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

projects[admin_menu] = 3.0-rc1
projects[auto_nodetitle] = 1.0
projects[biblio] = 1.0-rc3
projects[calendar] = 3.0-alpha2
; dev version only of cck
projects[] = cck
projects[content_access] = 1.2-beta1
projects[css_injector] = 1.7
projects[ctools] = 1.0-rc1
projects[date] = 2.0-rc1
projects[email] = 1.0
projects[features] = 1.0-beta6
projects[feeds] = 2.0-alpha4
projects[feeds_xpathparser] = 1.0-beta3
projects[globalredirect] = 1.4
projects[google_analytics] = 1.2
projects[insert] = 1.1
projects[job_scheduler] = 2.0-alpha2
; dev version only of jquery_ui
; projects[] = jquery_ui
projects[link] = 1.0
projects[mollom] = 1.1
; dev version only of nodeformcols
projects[] = nodeformcols
projects[pathauto] = 1.0
projects[pathologic] = 1.4
projects[redirect] = 1.0-beta4
; dev version only of semanticviews
projects[] = semanticviews
projects[token] = 1.0-beta7
projects[views] = 3.0
projects[views_slideshow] = 3.0
projects[wysiwyg] = 2.1

; Stanford Modules
; projects[stanford_events_importer][type] = module
; projects[stanford_events_importer][download][type] = file
; projects[stanford_events_importer][download][url] = 'https://techcommons.stanford.edu/files/stanford_events_importer-6.x-1.0-beta6.tar.gz'
; projects[webauth][type] = module
; projects[webauth][download][type] = file
; projects[webauth][download][url] = 'http://drupalfeatures.stanford.edu/sites/default/files/fserver/webauth-6.x-3.0.tar.gz'

; Themes

projects[] = tao
projects[] = rubik

; Libraries

; libraries[jquery_ui][download][type] = "get"
; libraries[jquery_ui][download][url] = "http://jquery-ui.googlecode.com/files/jquery.ui-1.6.zip"
; libraries[jquery_ui][directory_name] = "jquery.ui"
; libraries[jquery_ui][destination] = "libraries"

; libraries[ckeditor][download][type] = "get"
; libraries[ckeditor][download][url]  = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.5.3/ckeditor_3.5.3.zip"
; libraries[ckeditor][directory_name] = "ckeditor"
; libraries[ckeditor][destination] = "libraries"

; Profile

projects[stanford][type] = "profile"
projects[stanford][download][type] = "git"
projects[stanford][download][url] = "git@github.com:SU-SWS/Stanford-Drupal-Profile.git"
projects[stanford][download][branch] = 7.x-1.0-dev
; projects[stanford][type] = "profile"
; projects[stanford][download][type] = "file"
; projects[stanford][download][url] = "file:///home/quickstart/Documents/Stanford-Drupal-Profile/stanford.profile"
