#!/bin/bash

backupdir="/mnt/gfs/home/cardinald7/02live/backups"
todaysdate=$(date +%Y%m%d)

# /mnt/files/cardinald702live/files-private/sites.json holds information about all the sites.
# We manipulate it with grep to get a list of all *.stanford.edu sites
# TODO: deal with duplicate foo.cardinalsites.stanford.edu/foo.stanford.edu sites

sites=($(grep -o -P "[\w_-]*(\.cardinalsites)?.stanford.edu" /mnt/files/cardinald702live/files-private/sites.json))
#printf '%s\n' ${sites[@]}
for site in ${sites[@]}
do
#  echo $site
  sitedirname=$(echo $site | sed -e 's/\./_/g')
#  echo $sitedirname
  ##########################
  # Rotate out old backups #
  ##########################
  mv $backupdir/$sitedirname-dbdump.4.sql $backupdir/$sitedirname-dbdump.5.sql
  mv $backupdir/$sitedirname-dbdump.3.sql $backupdir/$sitedirname-dbdump.4.sql
  mv $backupdir/$sitedirname-dbdump.2.sql $backupdir/$sitedirname-dbdump.3.sql
  mv $backupdir/$sitedirname-dbdump.1.sql $backupdir/$sitedirname-dbdump.2.sql
  mv $backupdir/$sitedirname-dbdump.0.sql $backupdir/$sitedirname-dbdump.1.sql
  rm -f $backupdir/$sitedirname-dbdump.5.sql
  mv $backupdir/$sitedirname-files.4.tar.gz $backupdir/$sitedirname-files.5.tar.gz
  mv $backupdir/$sitedirname-files.3.tar.gz $backupdir/$sitedirname-files.4.tar.gz
  mv $backupdir/$sitedirname-files.2.tar.gz $backupdir/$sitedirname-files.3.tar.gz
  mv $backupdir/$sitedirname-files.1.tar.gz $backupdir/$sitedirname-files.2.tar.gz
  mv $backupdir/$sitedirname-files.0.tar.gz $backupdir/$sitedirname-files.1.tar.gz
  rm -f $backupdir/$sitedirname-files.5.tar.gz


  ################
  # Make backups #
  ################

  # Find the path to the files directory.
  file_public_path=$(drush --uri=$site --format=list vget file_public_path)
  # Make a new directory to hold the site files
  mkdir -p $backupdir/$sitedirname-files.0
  # Copy the files into the backup directory.
  cp -a /var/www/html/cardinald7.02live/docroot/$file_public_path/* $backupdir/$sitedirname-files.0
  # Tar it up
  tar -cfz  $backupdir/$sitedirname-files.0.tar.gz $backupdir/$sitedirname-files.0
  # Back up the database
  drush --uri=$site sql-dump > $backupdir/$sitedirname-dbdump.0.sql
done