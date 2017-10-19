#Import

The **Import tab** is where you can overview existing impoters on your site, perform actions, and create new importers.

###Action to perform on orphaned profiles

Orphan profiles are profiles that are removed from the CAP API or from the importer configuration. You can choose to leave orphans unchanged or to delete them.

##Add Groups and Individuals

Each grouping is additive. You can combine any and all of the options that are available. You can add more than one organization, workgroup, and SUNet ID by using a comma to separate each.

**Note:** If a person or profile exists in more than one of the options their profile will not be duplicated. Only one profile per person per importer can exist. However, duplicate profiles may occur if the same person or profile is associated with more than one importer.

##Actions Column

Clicking the **Update profiles now** link will update all of the profiles attached to the importer. The importer will run regardless of any setting on the cron setting for that importer. This action does not check for orphans.

Clicking the **Check for orphans** link will execute a process that will identify and mark profiles as orphans from an importer. Orphan profiles are profiles that no longer exist in the CAP API or the importer settings. Any new orphan will have an action applied to them based on the settings in the importer configuration.

**Note:** Orphans can be found on the **Profiles** tab.
