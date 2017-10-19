# Stanford Sites Content Importer
-------------------------------------------

7.x-1.1 2015-03-19
--------------------------
- Added entityreference field processor to handle UUID badness from server
- UUID support for entity reference fields
- Fixed undefined variable name for bean import where plugin settings was an empty array instead of the bean plugin information

7.x-1.0 2014-11-27
-------------------------
- BASIC-1088 | Changed alt default to empty instead of filename

7.x-1.0-alpha3 2014-10-23
-------------------------
- $field_collection->save() protection for field collection items that fail to be imported
- Fixed bug where file was not in root of the files directory
- Added alt and title to images
- Preserve the alt and title information

7.x-1.0-alpha2 2014-05-16
-------------------------------------------
- Added field and property processor registration system
- Added vocabulary restriction functionality
- Added check for array to avoid php warning on import content by view
- Small bug fixes
- Updated documenation


7.x-1.0-alpha1  2014-03-11
-------------------------------------------
- Initial release
