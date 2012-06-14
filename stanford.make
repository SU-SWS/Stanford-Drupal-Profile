core = 7.x

api = 2
projects[drupal][version] = "7.12"

; Contributed modules
projects[admin_menu][version] = "3.0-rc1"
projects[auto_nodetitle][version] = "1.0"
projects[biblio][version] = "1.0-rc4"
projects[calendar][version] = "3.2"
projects[content_access][version] = "1.2-beta1"
projects[css_injector][version] = "1.7"
projects[ctools][version] = "1.0"
projects[custom_breadcrumbs][version] = "1.0-alpha1"
projects[date][version] = "2.5"
projects[email][version] = "1.0"
projects[entity][version] = "1.0-rc1"
projects[features][version] = "1.0-rc2"
projects[feeds][version] = "2.0-alpha4"
projects[feeds_tamper][version] = "1.0-beta3"
projects[feeds_xpathparser][version] = "1.0-beta3"
projects[filefield_paths][version] = "1.0-beta3"
projects[globalredirect][version] = "1.4"
projects[google_analytics][version] = "1.2"
projects[insert][version] = "1.1"
projects[job_scheduler][version] = "2.0-alpha2"
projects[libraries][version] = "2.0-alpha2"
projects[link][version] = "1.0"
projects[metatag][version] = "1.0-alpha5"
projects[mollom][version] = "2.0"
projects[node_clone][version] = "1.0-beta1"
projects[nodeformcols][version] = "1.x-dev"
projects[pathauto][version] = "1.0"
projects[pathologic][version] = "1.4"
projects[redirect][version] = "1.0-beta4"
projects[semanticviews][version] = "1.x-dev"
projects[taxonomy_manager][version] = "1.0-beta2"
projects[token][version] = "1.0"
projects[views][version] = "3.3"
projects[views_bulk_operations][version] = "3.0-rc1"
projects[views_slideshow][version] = "3.0"
projects[wysiwyg][version] = "2.1"

; Contributed themes
projects[rubik][version] = "4.0-beta7"
projects[tao][version] = "3.0-beta4"

; Custom modules, github
projects[stanford_sites_systemtools][type] = "module"
projects[stanford_sites_systemtools][download][type] = "git"
projects[stanford_sites_systemtools][download][url] = "git@github.com:SU-SWS/SU-IT-Services.git"
; projects[stanford_sites_systemtools][download][url] = "file:///home/quickstart/Documents/stanford_sites_systemtools"
projects[stanford_sites_systemtools][download][tag] = "7.x-1.0-alpha3"
projects[stanford_sites_helper][type] = "module"
projects[stanford_sites_helper][download][type] = "git"
projects[stanford_sites_helper][download][url] = "git@github.com:SU-SWS/stanford_sites_helper.git"
; projects[stanford_sites_helper][download][url] = "file:///home/quickstart/Documents/stanford_sites_helper"
projects[stanford_sites_helper][download][tag] = "7.x-1.0-alpha2"

; Custom themes, github
projects[stanfordmodern][type] = theme
projects[stanfordmodern][download][type] = git
projects[stanfordmodern][download][url] = git@github.com:su-ddd/stanfordmodern.git
projects[stanfordmodern][download][branch] = "7.x-1.x"
projects[stanford_basic][type] = theme
projects[stanford_basic][download][type] = git
projects[stanford_basic][download][url] = git@github.com:su-ddd/stanford_basic.git
projects[stanford_basic][download][branch] = "7.x-1.x"

; Custom themes, github
; disabled until D7 versions released
;projects[stanford_framework][type] = theme
;projects[stanford_framework][version] = "6.x-1.01"
;projects[stanford_framework][download][type] = git
;projects[stanford_framework][download][url] = git@github.com:SU-SWS/stanford_framework.git

; Custom modules, Stanford features server
projects[webauth][location] = "http://drupalfeatures.stanford.edu/fserver"
projects[webauth][version] = "3.0"

; Libraries
; ---------
libraries[ckeditor][type] = "libraries"
libraries[ckeditor][download][type] = "file"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.3/ckeditor_3.6.3.tar.gz"

; Profile

projects[stanford][type] = "profile"
projects[stanford][download][type] = "git"
projects[stanford][download][url] = "git@github.com:SU-SWS/Stanford-Drupal-Profile.git"
; projects[stanford][download][url] = "file:///home/quickstart/Documents/D7/Stanford-Drupal-Profile"
projects[stanford][download][tag] = 7.x-1.0-alpha10
; projects[stanford][download][branch] = 7.x-1.x
