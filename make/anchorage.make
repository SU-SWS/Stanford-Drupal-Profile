core = 7.x

api = 2

includes[stanford_profile] = "stanford.make"
includes[stanford_libraries] = "libraries.make"
includes[stanford_patches] = "patches.make"
includes[stanford_themes] = stanford-themes.make

; Contributed modules
projects[s3fs][subdir] = "contrib"
projects[s3fs][version] = "2.0"
projects[simplesamlphp_auth][subdir] = "contrib"
projects[simplesamlphp_auth][version] = "2.0-alpha2"
projects[smtp][subdir] = "contrib"
projects[smtp][version] = "1.2"

; Custom modules, github
projects[anchorage_helper][subdir] = "stanford"
projects[anchorage_helper][type] = "module"
projects[anchorage_helper][download][type] = "git"
projects[anchorage_helper][download][url] = "git@github.com:SU-SWS/anchorage_helper.git"
projects[anchorage_helper][download][tag] = "7.x-1.0-alpha4"

projects[stanford_ssp][subdir] = "stanford"
projects[stanford_ssp][type] = "module"
projects[stanford_ssp][download][type] = "git"
projects[stanford_ssp][download][url] = "git@github.com:SU-SWS/stanford_ssp.git"
projects[stanford_ssp][download][tag] = "7.x-1.0-alpha1"

; Libraries
; ---------
libraries[awssdk2][download][type] = "get"
libraries[awssdk2][download][url] = "https://github.com/aws/aws-sdk-php/releases/download/2.6.3/aws.zip"
libraries[awssdk2][directory_name] = "awssdk2"
libraries[awssdk2][destination] = "libraries"
