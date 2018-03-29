#!/bin/bash
drush make --no-core ../../patches/patches.make ../../docroot/
cd ../../
patch --no-backup-if-mismatch -p1 < patches/enforce-paranoia.patch