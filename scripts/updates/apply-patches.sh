#!/bin/bash
patch --no-backup-if-mismatch -p1 < patches/saml.htaccess.patch
