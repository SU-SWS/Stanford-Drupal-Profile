#!/bin/bash


# Log failed backups.
#
# @param $1 Site URI
# @param $2 Timestamp
bak_log_fail() {
SITE=$1
STAMP=$2
echo "$SITE Failed to backup on $STAMP"
}

# Log successful backup.
#
# @param $1 Site URI
# @param $2 Timestamp
bak_log_success() {
SITE=$1
STAMP=$2
echo "$SITE successfully backed up on $STAMP"
}
