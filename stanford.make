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
projects[drupal][version] = 6.25

; Projects
; --------

projects[admin_menu] = 3.0-alpha4
projects[advanced_help] = 1.2
projects[auto_nodetitle] = 1.2
projects[backup_migrate] = 2.6
projects[backup_migrate_files] = 1.x-dev
projects[better_formats] = 1.2
projects[biblio] = 1.17
projects[calendar] = 2.4
projects[cck] = 2.9
projects[node_clone] = 1.3
projects[content_access] = 1.2
projects[css_injector] = 1.4
projects[ctools] = 1.8
projects[custom_breadcrumbs] = 2.0-rc1
projects[date] = 2.7
projects[email] = 1.2
projects[features] = 1.2
projects[feeds] = 1.0-beta11
projects[feeds_tamper] = 1.0-beta4
projects[feeds_xpathparser] = 1.12
projects[filefield] = 3.10
projects[filefield_paths] = 1.4
projects[globalredirect] = 1.4
projects[google_analytics] = 3.3
projects[imageapi] = 1.10
projects[imagecache] = 2.0-beta12
projects[imagecache_actions] = 1.8
projects[imagefield] = 3.10
projects[insert] = 1.1
projects[job_scheduler] = 1.0-beta3
projects[jquery_ui] = 1.5
projects[libraries] = 1.0
projects[link] = 2.9
projects[mollom] = 1.16
projects[nodeformcols] = 1.6
projects[nodewords] = 1.13
projects[nodewords_nodetype] = 1.8
projects[pathauto] = 1.6
projects[pathologic] = 3.4
projects[path_redirect] = 1.0-rc2
projects[print] = 1.14
projects[semanticviews] = 1.1
projects[taxonomy_manager] = 2.2
projects[token] = 1.18
projects[vertical_tabs] = 1.0-rc2
projects[views] = 2.16
projects[views_bulk_operations] = 1.13
projects[views_slideshow] = 2.3
projects[webform] = 2.9
projects[wysiwyg] = 2.4

; Stanford Modules
projects[stanford_courses][type] = module
projects[stanford_courses][download][type] = git
projects[stanford_courses][download][url] = 'git://github.com/SU-SWS/stanford_courses.git'
projects[stanford_courses][download][tag] = 6.x-1.0-beta4
projects[stanford_video][type] = module
projects[stanford_video][download][type] = git
projects[stanford_video][download][url] = 'git://github.com/SU-SWS/stanford_video.git'
projects[stanford_video][download][tag] = 6.x-2.0-alpha4
projects[stanford_events_importer][type] = module
projects[stanford_events_importer][download][type] = git
projects[stanford_events_importer][download][url] = 'git://github.com/SU-SWS/stanford_events_importer.git'
projects[stanford_events_importer][download][tag] = 6.x-1.0-rc2
projects[stanford_sites_helper][type] = module
projects[stanford_sites_helper][download][type] = git
projects[stanford_sites_helper][download][url] = 'git://github.com/SU-SWS/stanford_sites_helper.git'
projects[stanford_sites_helper][download][tag] = 6.x-1.0-beta1
projects[su_it_services][type] = module
projects[su_it_services][download][type] = git
projects[su_it_services][download][url] = "git://github.com/SU-SWS/SU-IT-Services.git"
projects[su_it_services][download][tag] = 6.x-1.5
projects[webauth][type] = module
projects[webauth][download][type] = git
projects[webauth][download][url] = "git://github.com/Stanford/WMD.git"
projects[webauth][download][tag] = 6.x-3.3


; Themes

projects[tao] = 3.2
projects[rubik] = 3.0-beta2

projects[stanford_basic][type] = theme
projects[stanford_basic][download][type] = git
projects[stanford_basic][download][url] = "git@github.com:su-ddd/stanford_basic.git"
projects[stanford_basic][download][tag] = v.1.3.1

projects[stanfordmodern][type] = theme
projects[stanfordmodern][download][type] = git
projects[stanfordmodern][download][url] = "git@github.com:su-ddd/stanfordmodern.git"
projects[stanfordmodern][download][tag] = v.1.3.1

; Libraries

libraries[jquery_cycle][download][type] = "get"
libraries[jquery_cycle][download][url] = "http://malsup.github.com/jquery.cycle.all.js"
libraries[jquery_cycle][directory_name] = "jquery.cycle"
libraries[jquery_cycle][destination] = "../../sites/all/libraries"

libraries[jquery_ui][download][type] = "get"
libraries[jquery_ui][download][url] = "http://jquery-ui.googlecode.com/files/jquery.ui-1.6.zip"
libraries[jquery_ui][directory_name] = "jquery.ui"
libraries[jquery_ui][destination] = "../../sites/all/libraries"

libraries[ckeditor][download][type] = "get"
libraries[ckeditor][download][url]  = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.3.1/ckeditor_3.3.1.zip"
libraries[ckeditor][directory_name] = "ckeditor"
libraries[ckeditor][destination] = "../../sites/all/libraries"

; Profile

projects[stanford][type] = "profile"
projects[stanford][download][type] = "git"
projects[stanford][download][url] = "git://github.com/SU-SWS/Stanford-Drupal-Profile.git"
projects[stanford][download][branch] = 6.x-1.x-installed
