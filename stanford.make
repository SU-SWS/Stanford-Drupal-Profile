; This file was auto-generated by drush_make
core = 7.x

api = 2
projects[drupal][version] = "7.12"

; Contributed modules
projects[admin_menu][version] = "3.0-rc1"
projects[auto_nodetitle][version] = "1.0"
projects[ctools][version] = "1.0-rc1"
projects[calendar][version] = "3.0-alpha2"
projects[css_injector][version] = "1.7"
projects[date][version] = "2.0-rc1"
projects[email][version] = "1.0"
projects[features][version] = "1.0-beta6"
projects[globalredirect][version] = "1.4"
projects[insert][version] = "1.1"
projects[link][version] = "1.0"
projects[nodeformcols][version] = "1.x-dev"
projects[pathauto][version] = "1.0"
projects[pathologic][version] = "1.4"
projects[semanticviews][version] = "1.x-dev"
projects[token][version] = "1.0-beta7"
projects[views][version] = "3.0"
projects[wysiwyg][version] = "2.1"

; Contributed themes
projects[rubik][version] = "4.0-beta7"
projects[tao][version] = "3.0-beta4"

; Custom modules, github
; disabled until D7 version released
; projects[su_it_services][type] = "module"
; projects[su_it_services][version] = "6.x-1.2"
; projects[su_it_services][download][type] = "git"
; projects[su_it_services][download][url] = "git@github.com:SU-SWS/SU-IT-Services.git"

; Custom themes, github
projects[stanfordmodern_d7][type] = theme
projects[stanfordmodern_d7][version] = "7.x-1.0"
projects[stanfordmodern_d7][download][type] = git
projects[stanfordmodern_d7][download][url] = git@github.com:su-ddd/stanfordmodern_d7.git

; Custom themes, github
; disabled until D7 versions released
;projects[stanford_framework][type] = theme
;projects[stanford_framework][version] = "6.x-1.01"
;projects[stanford_framework][download][type] = git
;projects[stanford_framework][download][url] = git@github.com:SU-SWS/stanford_framework.git
;projects[stanford_basic][type] = theme
;projects[stanford_basic][version] = "v.1.3.1"
;projects[stanford_basic][download][type] = git
;projects[stanford_basic][download][url] = git@github.com:su-ddd/stanford_basic.git

; Custom modules, Stanford features server
projects[webauth][location] = "http://drupalfeatures.stanford.edu/fserver"
projects[webauth][version] = "3.0"


; Profile

projects[stanford][type] = "profile"
projects[stanford][download][type] = "git"
projects[stanford][download][url] = "git@github.com:jbickar/Stanford-Drupal-Profile.git"
; projects[stanford][download][url] = "file:///home/quickstart/Documents/D7/Stanford-Drupal-Profile"
projects[stanford][download][tag] = 7.x-1.0-alpha3
