core = 7.x

api = 2

includes[stanford_profile] = "stanford.make"
includes[stanford_libraries] = "libraries.make"
includes[stanford_patches] = "patches.make"

; Custom theme, github
projects[stanford_basic][type] = theme
projects[stanford_basic][download][type] = "git"
projects[stanford_basic][download][url] = "git@github.com:su-ddd/stanford_basic.git"
projects[stanford_basic][download][tag] = "7.x-1.5"
