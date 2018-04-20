#!/bin/bash
# Run `bash monthly.sh`
set -Ee
source /var/www/html/${AH_SITE_NAME}/scripts/backups/includes/common.inc

# ###################################################
# VARIABLES
# ###################################################

# Available environment var examples:
#
# [HOME] => /home/cardinalsites
# [AH_SITE_GROUP] => cardinalsites
# [AH_SITE_NAME] => cardinalsites01live
# [AH_SITE_ENVIRONMENT] => 01live
# [AH_NON_PRODUCTION] => 1

STACK="cardinald7"
STACKDOMAIN="cardinalsites"
BACKUPDIR="/mnt/gfs/home/$STACK/$AH_SITE_ENVIRONMENT/backups/on-demand"
DAILYBACKUPDIR="$BACKUPDIR/daily"
WEEKLYBACKUPDIR="$BACKUPDIR/weekly"
MONTHLYBACKUPDIR="$BACKUPDIR/monthly"
DOCROOT="/var/www/html/$STACK.$AH_SITE_ENVIRONMENT/docroot"
SITELISTPATH="/mnt/files/$STACK$AH_SITE_ENVIRONMENT/files-private/sites.json"
TODAYSDATE=$(date +%Y%m%d)
NUMBEROFBACKUPSTOKEEP=12

# Rotate the backup logs.
#
# @param $1 Number of backups to keep
# @param $2 Backup directory path
bak_rotate() {

  # Rotate out the old
  NUMBEROFBACKUPSTOKEEP=$1
  MONTHLYBACKUPDIR=$2

  i=$1
  while [ $i -gt -1 ]
  do
    OLDER=$i
    NEWER=$[$i-1]
    NEWERPATH=$MONTHLYBACKUPDIR/monthly-archive.$NEWER.tar.gz
    OLDERPATH=$MONTHLYBACKUPDIR/monthly-archive.$OLDER.tar.gz

    # DB.
    if [ -f $NEWERPATH ]
    then
      mv $NEWERPATH $OLDERPATH
    fi

    # Iterate.
    i=$[$i-1]
  done

  # Remove the oldest backup. We start counting at 0 therefore we can just use the total.
  rm -f $MONTHLYBACKUPDIR/monthly-archive.$NUMBEROFBACKUPSTOKEEP.tar.gz

  # Copy the most recent weekly backup into the monthly directory.
  cp $WEEKLYBACKUPDIR/weekly-archive.0.tar.gz $MONTHLYBACKUPDIR/monthly-archive.0.tar.gz

}

# ###################################################
# INIT • EXEC • START • GO
# ###################################################

# Create a YYYYMMDD directory. This also ensures that our weekly backup directory exists.
mkdir -p $MONTHLYBACKUPDIR/$TODAYSDATE

{ # try
  bak_rotate $NUMBEROFBACKUPSTOKEEP $MONTHLYBACKUPDIR &&
  bak_log_success "Monthly archive" $TODAYSDATE
} || { # catch
  bak_log_fail "Monthly archive" $TODAYSDATE
}

# Clean up.
if [ ! -z $TODAYSDATE ] && [ -d $MONTHLYBACKUPDIR/$TODAYSDATE ]
then
  rm -fr $MONTHLYBACKUPDIR/$TODAYSDATE
  rotate_cleanup_success "Monthly archive" $TODAYSDATE
else
  NOW=$(date +%Y%m%d)
  rotate_cleanup_fail "Monthly archive" $NOW
fi
