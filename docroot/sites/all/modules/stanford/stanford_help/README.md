# Stanford Help
#### Version 7.x-1.1-dev

Maintainers: [cjwest](https://github.com/cjwest), [boznik](https://github.com/boznik)
[Changelog.txt](CHANGELOG.txt)

Drupal Features module for providing site specific help and maintenance information. When used with the Content Access module, this help content type allows the site administrator to use permissions to select who can view and edit the help pages. This is designed to keep the help information available only to selected roles and away from search bots. 

## Configuration for Stanford Help
After installing and enabling the Stanford Help feature, install and enable the Content Access module (https://www.drupal.org/project/content_access). Then navigate to admin/structure/types/manage/stanford_help_page/access, and select your desired access control settings.

**Current implementation of Stanford Help is intended to be a singular page with access limited by content-access.**

### Steps to install:
Unless the site help is installed with the product, an administrator will need to configure the help section.

1. Install / Enable stanford_help module.
2. Create new Help page. For consistency it is recommended to create the page with the following path: `https://<site url>/site-help`
3. Verify that the _Content Access_ module is enabled
4. Set permissions to Stanford Help content type. *See table below*.
5. Add a block to the top of the `admin/stanford-jumpstart` page with the following content:
`Documentation specific to your site can be found at the following URL:
https://<site url>/site-help`

**Permissions for Stanford Help Content Type:**

| |Site Admin|Site Owner|Editor|Anon/Other|
|---|---|---|---|---|
|Create Stanford Help page|YES|NO|NO|NO|
|Edit Stanford Help page|YES|YES|NO|NO|
|View Stanford Help page|YES|YES|YES|NO|
|Delete Stanford Help page|YES|NO|NO|NO|

### Create Help block on Get Help page

1. Create a stanford_postcard block named `Jumpstart Site Specific Help Link`
2. In the block add the text:
`Documentation specific to your site can be found at the following URL:
https://<site_url>/site-help`
*Substitute the current site URL for `<site_url>` in the text*.
3. Navigate to the Context page at (structures > context) `admin/structure/context` and click on **+Add**
4. In the Add a new context form, add values:

|Field|Value|
|---|---|
|Name|jumpstart_help_page|
|Tag|Help|
|Description|Place blocks on the "Get help" page|
|Conditions|Path|
|Reation|blocks|
|Help (region)|Jumpstart Site Specific Help Link|

Navigate to `admin/stanford-jumpstart` to verify your block placement and click on your new link on the top help page.

