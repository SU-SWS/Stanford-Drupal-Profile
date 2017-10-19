Date iCal

This module allows users to create iCal feeds in Views, and import iCal feeds
from other sites using the Feeds module. Any entity can act as the source of
events for an iCal feed, as long as that entity contains a Date field. Date 
iCal creates a new iCal "view mode" for all entities, which is used to format
the Description field of the events in the iCal feed.

For an easier-to-read HTML version of these instructions, please go to 
http://www.drupal.org/project/date_ical and click the "Read documentation" link
in the Resources section of the right sidebar.

INSTALLATION

Date iCal has several required dependencies, and an optional one: 
- The Views, Entity API, Libraries API (version 2.0), and Date modules are required.
- The iCalcreator library is required.
- PHP 5.3 is required by the iCalcreator library to properly handle timezone
    data. Date iCal *might* work with PHP 5.2, but that configuration is 
    untested and unsupported.
- The Feeds module is optional, but it's needed to enable import of iCal feeds
    from other sites.

To install the iCalcreator library, download it from http://github.com/iCalcreator/iCalcreator
using either git clone or the "Download Zip" button. Inside you'll find the file
iCalcreator.class.php. Copy that file to a folder in your Drupal site named
sites/all/libraries/iCalcreator.

Or, if you have drush, install iCalcreator by running this command from your 
site's root directory:
drush make sites/all/modules/date_ical/date_ical.make --no-core

Then clear the cache on your site, by using either "drush cc all"
or logging in to your site and going to Configuration -> Development -> 
Performance and click the "Clear all caches" button. This is necessary because
libraries are cached, and you may see confusing behavior from Date iCal if the
iCalcreator library gets cached at a bad time.


To confirm that iCalcreator is installed correctly, log in to your Drupal site
and navigate to the admin/reports/status page. If the row titled "Date iCal" is
green, Date iCal is ready to go. If it's red, the iCalcreator library is not
properly installed. If it's missing, you'll need to enable Date iCal and then 
come back to this page. 


HOW TO CREATE AN ICAL FEED (using the iCal Entities plugin)

1.  Go to the Manage Display page for the content type you want to export in an 
    iCal feed. On the "Default" tab, check the box for "iCal" in the section 
    titled "Use custom display settings for the following view modes", then click
    Save.
2.  Click the new "iCal" tab that now appears in the upper-right corner of the
    Manage Display page for this content type.
3.  Set up the iCal view mode to contain whatever should be exported as the
    'Description' field for the iCal feed. You can trim the text to the desired
    size, include additional information from other fields, etc.
4.  Do this for each of the content types that you wish to include in your 
    site's iCal feeds.
5.  Create a new View that displays the entities that you want to include in the
    iCal feed.
6.  Add a "Feed" to the view. Change the Format to 'iCal Feed'. When you click 
    Apply from that dialog, you'll be given the option to name the calendar. This
    name will appear in your users' calendar clients as the calendar's title.
7.  Change the Show setting to 'iCal Entity' (rather than 'Content' or 'Fields').
8.  In the settings for iCal Entity, select the date field that should be used 
    as the event date for the iCal feed. Make sure that you choose a field that
    is a part of every entity that your View displays. Otherwise, the entities
    which don't have that field will be left out of the iCal feed.
9.  You may optionally choose a field that will be used to populate the Location
    property of events in your iCal feed. This field can be either a text field
    or a Node Reference field, in which case the title of the node will be used.
10. Give the feed a path like 'calendar/%/export.ics', where you have a
    '/%/' for every contextual filter in the view.
11. Make sure the Pager options are set to "Display all items".
12. Add date filters or arguments that will constrain the view to the items you
    want to be included in the iCal feed.
13. Attach the feed to a another view (usually a Page view that is displaying 
    the same events). Be aware, though, that attaching the feed to a view with
    different output will not make the iCal feed include that output. It will
    always include the events which match the feed's filters.
14. Save the View.
15. Navigate to a page which displays the attached view. You should see the iCal
    icon at the bottom of the view's output. Clicking on the icon will subscribe
    your preferred calendar app the iCal feed. However, if you don't have a 
    calendar app set up on your computer, you'll want to go back to the View 
    settings page, click the Settings link next to "Format:iCal Feed", and check
    "Disable webcal://", then save your View. This will make the iCal icon 
    download a .ics file with the events, instead of loading the events directly 
    into a calendar app.

HOW TO CREATE AN ICAL FEED (using the iCal Fields plugin)
1-6.These steps are the same as above.
7.  Add views fields for each piece of information that you want to populate your
    iCal feed with. A Date field is required, and fields that will act as the 
    Title and Description of the events are reccomended. You can also include a
    Location field.
8.  Back in the FORMAT section, change the Show setting to 'iCal Fields'.
9.  In the settings for iCal Fields, choose which views fields you want to use
    for the Date, Title, Description, and Location.
10+ These steps are the same as above. 


HOW TO IMPORT AN ICAL FEED FROM ANOTHER SITE
- Install the Feeds module, which acts as the framework around Date iCal's 
  calendar import functionality.
- Login to your Drupal site and navigate to the admin/structure/feeds page.
- Click the "Add importer" link, and give it a name and description.
- Clicking "Create" will bring you to the general Feeds importer settings page.
  This page displays some general information about makign Feeds importers, 
  which you should familiarize yourself with.
- In the left sidebar, you'll see "Basic settings", "Fetcher", "Parser", and
  "Processor". The Parser and Processor settings are what we're interested in.
- In the Parser section, click "change". This will bring up the Parser 
  selection page, on which you should select the radio button for "iCal Parser"
  and then click Save.
- Now, under Processor, click the "Settings" link. Most of the time, you'll 
  want to use the "Update existing nodes (slower than replacing them)" setting.
  Then select the Content type of the nodes you'd like to create from iCal
  events. You can leave the other settings as their defeaults, or change them
  as you need. Click Save.
- Now click the "Mapping" link at the bottom of the left sidebar. This page is
  where you'll define how iCal event properties get mapped into your nodes'
  fields. Expand the "Legend" for a detailed description of each source and
  target field. Sources are the attributes available in iCal event objects.
  Targets are the fields in your nodes.
- Most of this setup is going to be dependant upon how your content type's 
  fields are configured, but there are some universal requirements:
  1) You must map the "UID" source to the "GUID" target. Then, after clicking
     "Add", click the gear-shaped button that appears in the new table row, 
     and check the "Unique" checkbox. Then click "Update", and then before
     you add any more mappings, click "Save" at the bottom of the page.
  2) If you're going to map both the "Date start" and "Date end" sources, you
     MUST ensure that the "Date start" mapping is above the "Date end" mapping
     in the table. This is because of an implementation detail in the parser. 
  3) It's a good idea to map the "Summary" source to the "Title" target, and
     the "Description" source to whatever field is the "body" of the node.
- Once you've completed all the mappings, click the "Save" button on the 
  bottom left side of the page.
- Now you can import the iCal feed into nodes by going to the /import page of
  your site (e.g. http://www.exmaple.com/import). Click the link for the 
  importer you just created, and enter the URL of the feed you'd like to 
  import into the "URL" field. Click the "Import" button, and observe the 
  progress.
- Once it's done, you should see a green message saying "Created X nodes." If
  you do, you've successfully set up your iCal importer. If you get some other
  message, you'll need to tweak the importer's settings. 



Additional Notes:
The Feeds plugin was originally written by ekes, for the "iCal feed parser"
module (http://www.drupal.org/project/parser_ical). It was modified and 
improved for Date iCal by coredumperror.

At this time, Date iCal supports outputting iCal calendars only through Views.
To put an "Add to calendar" button on individual event nodes, try the 
<a href="http://drupal.org/project/addtocal">Add to Cal</a> module, or follow
the instructions created by the estimable nmc at:
http://nmc-codes.blogspot.ca/2012/11/creating-ical-feed-for-single-node-in.html

Developers who wish to implement more powerful manipulation of event data can
read the date_ical.api.php file to learn about the various alter hooks that 
date_ical exposes.
