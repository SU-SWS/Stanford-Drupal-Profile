#!/bin/bash
# Run `bash daily.sh`
set -Ee
source includes/common.inc

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
DOCROOT="/var/www/html/$STACK.$AH_SITE_ENVIRONMENT/docroot"
SITELISTPATH="/mnt/files/$STACK$AH_SITE_ENVIRONMENT/files-private/sites.json"
TODAYSDATE=$(date +%Y%m%d)
NUMBEROFBACKUPSTOKEEP=7

# $SITELISTPATH holds information about all the sites. We manipulate it with
# grep to get a list of all *.stanford.edu sites.
SITES=`grep -o -P "[\w_-]*(\.$STACKDOMAIN)?.stanford.edu" $SITELISTPATH`

# ###################################################
# FUNCTIONS
# ###################################################

# Validate domain path for duplicate domain.
# eg: foo.cardinalsites.stanford.edu/foo.stanford.edu
# foo.cardinalsites.stanford.edu
#
# @param $1 Site uri
# @return string
#   "true" for valid.
validate_uri() {
  SITE=$1
  SPLIT=(${SITE//\//})

  # If a string can be split by "/" assume not a good url.
  if [ ${#SPLIT[@]} -gt 1 ]
  then
    echo "false"
  else
    echo "true"
  fi
}

# Rotate the backup logs.
#
# @param $1 Number of backups to keep
# @param $2 Backup directory path
# @param $3 Site directory name
bak_rotate() {

  NUMBEROFBACKUPSTOKEEP=$1
  BACKUPDIR=$2
  SITEDIRNAME=$3

  i=$1
  while [ $i -gt -1 ]
  do
    OLDER=$i
    NEWER=$[$i-1]
    NEWERPATHDB=$BACKUPDIR/$SITEDIRNAME-dbdump.$NEWER.sql
    OLDERPATHDB=$BACKUPDIR/$SITEDIRNAME-dbdump.$OLDER.sql
    NEWERPATHFL=$BACKUPDIR/$SITEDIRNAME-files.$NEWER.tar.gz
    OLDERPATHFL=$BACKUPDIR/$SITEDIRNAME-files.$OLDER.tar.gz

    # DB.
    if [ -f $NEWERPATHDB ]
    then
      mv $NEWERPATHDB $OLDERPATHDB
    fi

    # Files.
    if [ -f $NEWERPATHFL ]
    then
      mv $NEWERPATHFL $OLDERPATHFL
    fi

    # Iterate.
    i=$[$i-1]
  done

  # Remove the oldest backup. We start counting at 0 so we can use the total.
  rm -f $BACKUPDIR/$SITEDIRNAME-dbdump.$NUMBEROFBACKUPSTOKEEP.sql
  rm -f $BACKUPDIR/$SITEDIRNAME-files.$NUMBEROFBACKUPSTOKEEP.tar.gz
}

# Create a new backup of files and db.
#
# @param $1 Backup directory path
# @param $2 Site directory name
# @param $3 Docroot path
# @param $4 drupal public file path
# @param $5 Site URI
bak_make() {

  BACKUPDIR=$1
  SITEDIRNAME=$2
  DOCROOT=$3
  FILEPUBLICPATH=$4
  SITE=$5

  # Tar the files up
  if [ -d $DOCROOT/$FILEPUBLICPATH ]
  then
    cd $DOCROOT/$FILEPUBLICPATH
    # TODO: tar -cfz
    tar -cf $SITEDIRNAME-files.0.tar ./*
    mv $SITEDIRNAME-files.0.tar $BACKUPDIR/$SITEDIRNAME-files.0.tar
    gzip $BACKUPDIR/$SITEDIRNAME-files.0.tar
  fi

  # Back up the database.
  drush --uri=https://$SITE --root=$DOCROOT sql-dump > $BACKUPDIR/$SITEDIRNAME-dbdump.0.sql
}

# ###################################################
# INIT • EXEC • START • GO
# ###################################################

# Loop through each site and perform backup operations.
for SITE in ${SITES[@]}
do

  # Validate URL string first.
  VALID=$(validate_uri $SITE)
  if [ $VALID == "false" ]
  then
    continue
  fi

  # The directory name that houses the site in operation.
  SITEDIRNAME=$(echo $SITE | sed -e 's/\./_/g')

  # The path to the files directory relative to the webserver docroot. D7 ONLY!
  FILEPUBLICPATH=$(drush --uri=https://$SITE --root=$DOCROOT --format=list vget file_public_path)

  { # try
    bak_rotate $NUMBEROFBACKUPSTOKEEP $BACKUPDIR $SITEDIRNAME &&
    bak_make $BACKUPDIR $SITEDIRNAME $DOCROOT $FILEPUBLICPATH $SITE &&
    bak_log_success $SITE $TODAYSDATE
  } || { # catch
    bak_log_fail $SITE $TODAYSDATE
  }

done
