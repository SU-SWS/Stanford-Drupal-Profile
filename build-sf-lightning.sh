#!/usr/bin/env bash
set -o xtrace
set -e

# Builds some version of d8 with acsf initialized
DRUSH_PATH="./vendor/bin"
DRUSH_VERSION='8.1.3'

CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)

check_drush_version () {
DRUSH_VERSION=`$DRUSH_PATH/drush --version --pipe`
if ! [[ $DRUSH_VERSION =~ ^[8]\.[0-9].+$ ]]; then
 echo "You must be running drush 8 for d8 to work"
 exit 1
fi
}

install_composer () {
  echo "Installing composer"
  mkdir -p bin
  curl -sS https://getcomposer.org/installer | php -- --install-dir=bin --filename=composer
}

install_drush () {
  echo "Installing drush"
  php bin/composer require drush/drush:${DRUSH_VERSION:=8.1.0}
}

build_drupal () {
  echo "Building drupal"
# Clean out docroot
  rm -rf docroot
  $DRUSH_PATH/drush make --no-cache --overwrite --working-copy build-sf-lightning.make docroot
}

init_acsf () {
  echo "Initializing acsf"
  ./vendor/bin/drush --root=$(pwd)/docroot --include=$(pwd)/docroot/sites/all/modules/contrib/acsf/acsf_init -y acsf-init
}

commit_changes () {
  echo "Committing changes"
  DATE=$(date)
  git add -A && git commit -m "Committing build for $DATE"
  git push origin
}

install_composer
install_drush
check_drush_version
build_drupal
init_acsf
if [[ -n $COMMIT_CHANGES ]]; then
  commit_changes
else
  echo "Any changes are not being committed please check the git status output"
  git status
fi

