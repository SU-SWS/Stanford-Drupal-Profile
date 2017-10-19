-- SUMMARY --

The JW Player module adds a new field for displaying video files in a JW Player.

For a full description visit the project page:
  http://drupal.org/project/jw_player
Bug reports, feature suggestions and latest developments:
  http://drupal.org/project/issues/jw_player


-- REQUIREMENTS --

* This module depends on the File module, which is part of Drupal core, Chaos
  Tools (http://drupal.org/project/ctools) and the Libraries module
  (http://drupal.org/project/libraries).


-- INSTALLATION --

* Download either the latest commercial or the latest non-commercial JW
  Player at http://www.longtailvideo.com/players/jw-flv-player/.

* Extract the zip file and put the contents of the extracted folder in
  libraries/jwplayer. 
  E.g.: sites/all/libraries/jwplayer or sites/<sitename>/libraries/jwplayer
	
* Install this module as described at http://drupal.org/node/895232.

* Go to Administration > Reports > Status reports (admin/reports/status) to
  check your configuration.


-- BASIC USAGE --

In that majority of cases JW Player is used as a field formatter on a file
field. Before enabling JW Player on a field visit /admin/config/media/jw_player
to configure one or more presets. A preset is a group of JW Player settings,
such as dimentions and skin, that can be re-used multiple times.

Once a preset has been defined visit /admin/structure/types and select "manage
display" for the content type you'd like to configure and select "JW player" as
the formatter on the relevant file field. At this point you will also need to
click on the cog beside the field to select the preset you'd like to apply to
the file. That's it - vidoes uploaded to this field should now be displayed
using JW Player!