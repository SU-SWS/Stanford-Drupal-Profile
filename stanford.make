core = 7.x

api = 2
projects[drupal][version] = "7.19"

; Contributed modules
projects[admin_menu][version] = "3.0-rc3"
projects[admin_views][version] = "1.0-alpha1"
projects[advanced_help][version] = "1.0"
projects[auto_nodetitle][version] = "1.0"
projects[backup_migrate][version] = "2.4"
projects[backup_migrate_files][version] = "1.x-dev"
projects[bean][version] = "1.1"
projects[better_formats][version] = "1.0-beta1"
projects[better_exposed_filters][version] = "3.0-beta3"
projects[biblio][version] = "1.0-rc4"
projects[block_class][version] = "1.2-beta1"
projects[block_titlelink][version] = "1.3"
projects[bundle_copy][version] = "1.1"
projects[calendar][version] = "3.4"
projects[computed_field][version] = "1.0-beta1"
projects[content_access][version] = "1.2-beta1"
projects[context][version] = "3.0-beta6"
projects[context_accordion][version] = "1.0"
projects[context_inline_editor][version] = "1.0-beta1"
projects[context_respect][version] = "1.1"
projects[css_injector][version] = "1.7"
projects[ctools][version] = "1.2"
projects[custom_breadcrumbs][version] = "1.0-alpha1"
projects[date][version] = "2.5"
projects[delta][version] = "3.0-beta11"
projects[diff][version] = "3.2"
projects[ds][version] = "2.2"
projects[email][version] = "1.2"
projects[entity][version] = "1.0-rc3"
projects[entityreference][version] = "1.0-rc3"
projects[features][version] = "1.0-rc3"
projects[feeds][version] = "2.0-alpha7"
projects[feeds_tamper][version] = "1.0-beta3"
projects[feeds_xpathparser][version] = "1.0-beta3"
projects[field_collection][version] = "1.0-beta4"
projects[field_group][version] = "1.1"
projects[filefield_paths][version] = "1.0-beta3"
projects[globalredirect][version] = "1.5"
projects[google_analytics][version] = "1.2"
projects[insert][version] = "1.1"
projects[job_scheduler][version] = "2.0-alpha3"
projects[js_injector][version] = "2.0"
projects[jw_player][version] = "1.0-alpha1"
projects[libraries][version] = "2.0-alpha2"
projects[link][version] = "1.0"
projects[menu_block][version] = "2.3"
projects[menu_position][version] = "1.1"
projects[metatag][version] = "1.0-alpha6"
projects[module_filter][version] = "1.7"
projects[mollom][version] = "2.1"
projects[node_clone][version] = "1.0-beta1"
projects[nodeformcols][version] = "1.x-dev"
projects[openlayers][version] = "2.0-beta3"
projects[pathauto][version] = "1.1"
projects[pathologic][version] = "1.4"
projects[redirect][version] = "1.0-beta4"
projects[relation][version] = "1.0-rc2"
projects[rules][version] = "2.1"
projects[services][version] = "3.3"
projects[site_verify][version] = "1.0"
projects[strongarm][version] = "2.0"
projects[taxonomy_manager][version] = "1.0-rc2"
projects[token][version] = "1.5"
projects[transliteration][version] = "3.1"
projects[views][version] = "3.3"
projects[views_bulk_operations][version] = "3.0-rc1"
projects[views_slideshow][version] = "3.0"
projects[webform][version] = "3.18"
projects[workbench][version] = "1.2"
projects[workbench_moderation][version] = "1.3"
projects[workbench_access][version] = "1.2"
projects[wysiwyg][version] = "2.2"
projects[wysiwyg_filter][version] = "1.6-rc2"

; Contributed themes
projects[cube][version] = "1.1"
projects[rubik][version] = "4.0-beta8"
projects[tao][version] = "3.0-beta4"

; Custom modules, github
projects[stanford_sites_systemtools][type] = "module"
projects[stanford_sites_systemtools][download][type] = "git"
projects[stanford_sites_systemtools][download][url] = "git@github.com:SU-SWS/SU-IT-Services.git"
projects[stanford_sites_systemtools][download][tag] = "7.x-1.1-beta1"
projects[stanford_sites_helper][type] = "module"
projects[stanford_sites_helper][download][type] = "git"
projects[stanford_sites_helper][download][url] = "git@github.com:SU-SWS/stanford_sites_helper.git"
projects[stanford_sites_helper][download][tag] = "7.x-1.0-beta5"

; Custom themes, github
projects[stanfordmodern][type] = theme
projects[stanfordmodern][download][type] = git
projects[stanfordmodern][download][url] = git@github.com:su-ddd/stanfordmodern.git
projects[stanfordmodern][download][tag] = "7.x-1.42"
projects[stanford_basic][type] = theme
projects[stanford_basic][download][type] = git
projects[stanford_basic][download][url] = git@github.com:su-ddd/stanford_basic.git
projects[stanford_basic][download][tag] = "7.x-1.4"
projects[open_framework][type] = theme
projects[open_framework][download][type] = git
projects[open_framework][download][url] = git@github.com:SU-SWS/open_framework.git
projects[open_framework][download][tag] = "7.x-2.04"
projects[stanford_framework][type] = theme
projects[stanford_framework][download][type] = git
projects[stanford_framework][download][url] = git@github.com:SU-SWS/stanford_framework.git
projects[stanford_framework][download][tag] = "7.x-2.0"
projects[stanford_jordan][type] = theme
projects[stanford_jordan][download][type] = git
projects[stanford_jordan][download][url] = git@github.com:SU-SWS/stanford_jordan.git
projects[stanford_jordan][download][tag] = "7.x-2.0"
projects[stanford_wilbur][type] = theme
projects[stanford_wilbur][download][type] = git
projects[stanford_wilbur][download][url] = git@github.com:SU-SWS/stanford_wilbur.git
projects[stanford_wilbur][download][tag] = "7.x-2.0"

; Custom modules, Stanford features server
projects[webauth][location] = "http://drupalfeatures.stanford.edu/fserver"
projects[webauth][version] = "3.1"
projects[stanford_courses][location] = "http://drupalfeatures.stanford.edu/fserver"
projects[stanford_courses][version] = "1.0-alpha6"
projects[stanford_events_importer][location] = "http://drupalfeatures.stanford.edu/fserver"
projects[stanford_events_importer][version] = "1.0-alpha2"
projects[stanford_video][location] = "http://drupalfeatures.stanford.edu/fserver"
projects[stanford_video][version] = "1.0-alpha7"
projects[stanford_wysiwyg][location] = "http://drupalfeatures.stanford.edu/fserver"
projects[stanford_wysiwyg][version] = "1.0-alpha7"

; Libraries
; ---------
libraries[ckeditor][download][type] = "get"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.6.1/ckeditor_3.6.6.1.zip"
libraries[ckeditor][directory_name] = "ckeditor"
libraries[ckeditor][destination] = "../../sites/all/libraries"

libraries[jquery_cycle][download][type] = "get"
libraries[jquery_cycle][download][url] = "http://malsup.github.com/jquery.cycle.all.js"
libraries[jquery_cycle][directory_name] = "jquery.cycle"
libraries[jquery_cycle][destination] = "../../sites/all/libraries"

libraries[jw_player][download][type] = "get"
libraries[jw_player][download][url] = "http://www.longtailvideo.com/jw/upload/mediaplayer-5.10.zip"
libraries[jw_player][directory_name] = "jwplayer"
libraries[jw_player][destination] = "../../sites/all/libraries"

libraries[openlayers][download][type] = "get"
libraries[openlayers][download][url] = "http://openlayers.org/download/OpenLayers-2.12.tar.gz"
libraries[openlayers][directory_name] = "openlayers"
libraries[openlayers][destination] = "../../sites/all/libraries"

; Profile

projects[stanford][type] = "profile"
projects[stanford][download][type] = "git"
projects[stanford][download][url] = "git@github.com:SU-SWS/Stanford-Drupal-Profile.git"
projects[stanford][download][branch] = 7.x-1.x-dev
