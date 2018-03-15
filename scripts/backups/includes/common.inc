#!/bin/bash


# Log failed backups.
#
# @param $1 Site URI
# @param $2 Timestamp
bak_log_fail() {
SITE=$1
STAMP=$2
echo "$SITE failed to backup on $STAMP"
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

# Log failed backup rotations.
#
# @param $1 Backup scheme (daily, weekly, monthly)
# @param $2 Timestamp
rotate_log_fail() {
SCHEME=$1
STAMP=$2
echo "$SCHEME failed to rotate backup assets on $STAMP"
}

# Log successful backup.
#
# @param $1 Backup scheme (daily, weekly, monthly)
# @param $2 Timestamp
rotate_log_success() {
SCHEME=$1
STAMP=$2
echo "$SCHEME successfully rotated backup assets on $STAMP"
}

# Log when backup rotation fails to clean up working directories or assets.
#
# @param $1 Backup scheme (daily, weekly, monthly)
# @param $2 Timestamp
rotate_cleanup_fail() {
SCHEME=$1
STAMP=$2
echo "$SCHEME failed to clean up backup assets on $STAMP"
}

# Log when backup rotation succeeds in cleaning up working directories and/or assets.
#
# @param $1 Backup scheme (daily, weekly, monthly)
# @param $2 Timestamp
rotate_cleanup_success() {
SCHEME=$1
STAMP=$2
echo "$SCHEME successfully cleaned up backup assets on $STAMP"
}
