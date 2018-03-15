# Purpose
The scripts directory at the root of the repo is for scripts that are not meant to be publicly-accessible over the web.

# Contents
## Backups
- `backups/daily.sh`: Back up all sites on our ACSF instance. Rotate out the oldest, keeping 7.
- `backups/weekly.sh`: Create a selective archive of the most recent daily backups. Rotate out the oldest, keeping 5.
- `backups/monthly.sh`: Create a selective archive of the most recent weekly backup archive. Rotate out the oldest, keeping 12.

Backups are created using a [Grandfather-Father-Son](http://documentation.commvault.com/commvault/v10/article?p=features/storage_policy_copy/gfs_rotation.htm) backup rotation scheme.
