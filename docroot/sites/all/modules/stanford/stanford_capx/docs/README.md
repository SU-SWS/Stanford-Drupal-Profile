#CAPx Documentation

##Install the Stanford CAPx module on your Drupal 7 site

The [Stanford CAPx module can be downloaded from GitHub »] (https://github.com/SU-SWS/stanford_capx)

If you do not have an existing content type, it is recommend that you use the Stanford Person content type. You can [download the Stanford Person module from GitHub »] (https://github.com/SU-SWS/stanford_person)

**Important Note:** This documentation will use the Stanford Person content type as an example. If you are not using the Stanford Person content type, disregard the references to it.

##Enable Stanford CAPx and Stanford Person modules using Drush

Run the following Drush command: % drush en stanford_person stanford_capx -y

**Note:** Dependencies should be automagically handled.

##Enable Stanford CAPx and Stanford Person modules from the user interface

1. Click **Modules** and locate the Stanford Person and the Stanford CAPx modules
2. Check the box next to each of the modules to enable them
3. Click **Save configuration**

##Configure Stanford CAPx module

1. From the administration menu, hover over **Configuration**
2. Click **CAPx**

###Connect

1. Click the **Connect** tab
2. In the **Authorization** field, enter your authentication information
3. In the **Advanced** field, accept the default values unless it becomes necessary to change them
4. Click **Save connection settings**
 
[Learn more about the Connect tab »] (connect.md)

###Settings

1. Click the **Settings** tab
2. In the **Organization** field, click **Sync Now**
3. In the **Synchronization settings** field, accept the default values unless it becomes necessary to change them
4. Click **Save configuration**

[Learn more about the Settings tab »] (settings.md)

###Map

####Create new mapping

1. Click the **Map** tab
2. Click **Create new mapping**
3. Give the new mapping a title
4. Select which entity type and bundle you would like to map the CAP data into. Select the entity type first. The bundle type will appear automatically.
5. Complete the field mapping for the entity type and bundle you selected

**Note:** The following table highlights some commonly used settings for the Stanford Person content type (**Entity type:** Node **Bundle:** Person):

Label | CAPx API Path
--- | ---
Display Name |	$.displayName
First name |	$.names.legal.firstName
Middle name |	$.displayName
Last Name |	$.names.legal.lastName
Display Name |	$.names.legal.middleName
Profile Picture |	$.profilePhotos.bigger
Type |	$.titles.*.type
Profile / Bio |	$.bio.html
Title and Department | $.longTitle.title
Degrees / Education |	$.education.*.label.text
File |	$.documents.cv
Email |	$.primaryContact.email
Phone |	$.primaryContact.phoneNumbers.*
Fax |	$.primaryContact.fax
Office Hours |	
Office | $.primaryContact.officeName
Mailing Address | $.primaryContact.address
Mail Code |	
Personal Info Links Title | $.internetLinks.*.label.text
Personal Info Links URL | $.internetLinks.*.url
Faculty Status | 
Student Type | $.titles.*.type
Cohort |$.maintainers.*.title
Field of Study | $.education.*.fieldOfStudy
Dissertation Title | 
Graduation Year | $.education.*.yearIssued
Staff Type | $.titles.*.type

####Edit exisiting mapping

1. Click the **Map** tab
2. Click **Edit** in the **Operations** column next to the mapper you wish to edit
3. Edit the necessary items in the **Field Mapping** field. The Mapper Title and Entity Mapping fields cannot be changed
4. Click **Save mapper**

####Delete mapping

1. Click the **Map** tab
2. Click **Delete** in the **Operations** column next to the mapper you wish to delete
3. If you are sure that you want to delete the mapper, click **Yes, please delete**

[Learn more about the Map tab »] (map.md)

###Import

####Create new importer

1. Click the **Import** tab
2. Click **Create new importer**
3. In the **Importer name** field, enter a unique name for the Importer
4. In the **Mapping** field, select the mapping from the dropdown that you would like to import this profile data
5. Configure the **Sync Options** as desired
6. Configure **Add Groups** as desired. The **Organizations** field, will autocomplete as you begin typing the name of the organization you wish to import, whereas you will need to enter the full workgroup name by hand
7. Configure  **Add Individuals** as desried. You may enter the SUNet IDs for the profiles you wish to import. Multiple SUNet IDs may be entered by separating them with a comma
8. To save the importer, but **not import** now, click **Save**. To save and **import** now, click **Save & Import Now**

####Edit existing importer

1. Click the **Import** tab
2. Click **Edit** in the **Operations** column next to the importer you wish to edit
3. Edit all necessary items. All fields except for the Importer name can be updated
4. To save the chamges to the importer, but **not import** now, click **Save**. To save the changes to the importer and **import** now, click **Save & Import Now**

####Delete importer

1. Click the **Import** tab
2. Click **Delete** in the **Operations** column next to the importer you wish to delete
3. Select what you would like to do with the items that are associated with the selected importer from the dropdown
3. If you are sure that you want to delete the importer, click **Yes, please delete the importer**

####Update profiles

1. Click the **Import** tab
2. Click **Update profiles now** in the **Operations** column next to the importer you wish to update the profiles for

####Check for orphans

1. Click the **Import** tab
2. Click **Check for orphans** in the **Operations** column next to the importer you wish to check for orphans

####View profiles via the Import tab

1. Click the **Import** tab
2. Click on the importer you wish to view the profiles for in the **Title** column
3. Click **View all imported profiles**

**Note:** When viewing proifles via the Import tab, you can only view profiles for importers that are currently in use.

[Learn more about the Import tab »] (import.md)

###Profiles

####View profiles

1. Click the **Profiles** page
2. The title of the profile and what importer it is being populated from can be viewed in the table

**Note:** The profiles displayed on this page are only profiles imported from the CAPx module.

[Learn more about the Profiles tab »] (profiles.md)

###Help

Use the Help tab for quick information and helpful tips on using and setting up the CAPx module.
