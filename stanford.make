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

projects[] = admin_menu
projects[] = auto_nodetitle
projects[] = biblio
projects[] = calendar
projects[] = cck
projects[] = content_access
projects[] = css_injector
projects[] = date
projects[] = email
projects[] = features
projects[] = filefield
projects[] = globalredirect
projects[] = google_analytics
projects[] = insert
projects[] = jquery_ui
projects[] = link
projects[] = mollom
projects[] = nodeformcols
projects[] = pathauto
projects[] = pathologic
projects[] = path_redirect
projects[] = semanticviews
projects[] = token
projects[] = vertical_tabs
projects[] = views
projects[] = wysiwyg

; Stanford Modules

;projects[] = webauth

; Themes

projects[] = tao
projects[] = rubik

; Libraries

libraries[jquery_ui][download][type] = "get"
libraries[jquery_ui][download][url] = "http://jquery-ui.googlecode.com/files/jquery.ui-1.6.zip"
libraries[jquery_ui][directory_name] = "jquery.ui"
libraries[jquery_ui][destination] = "modules/jquery_ui"

libraries[ckeditor][download][type] = "get"
libraries[ckeditor][download][url]  = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.5.3/ckeditor_3.5.3.zip"
libraries[ckeditor][directory_name] = "ckeditor"
libraries[ckeditor][destination] = "libraries"

; Profile

projects[stanford][type] = "profile"
projects[stanford][download][type] = "git"
projects[stanford][download][url] = "git@github.com:mistermarco/Stanford-Drupal-Profile.git"

