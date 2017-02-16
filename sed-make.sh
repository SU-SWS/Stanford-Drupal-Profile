#!/bin/bash

# Usage: ./sed-make <module> <oldversion> <newversion>
# E.g., "./sed-make block_class 1.3 2.3"
# E.g., "./sed-make.sh stanford_events_importer 7.x-3.2 7.x-3.3
# Assumes data source will be called modules_to_upgrade.csv
# And be located in the same directory as sed-make.sh

while IFS=, read module_name current_version new_version
do
  # skip headers in data source
  if [[ $module_name == "module_name" ]]; then
    continue
  fi
  if [[ $module_name == *"stanford"* ]]; then
    find . -name "*.make" -exec sed -i '' 's/'$module_name'\]\[download\]\[tag\] \= \"'$current_version'\"/'$module_name'\]\[download\]\[tag\] \= \"'$new_version'\"/g' "{}" \;
  fi
  if [[ $module_name == *"open_framework"* ]]; then
    find . -name "*.make" -exec sed -i '' 's/'$module_name'\]\[download\]\[tag\] \= \"'$current_version'\"/'$module_name'\]\[download\]\[tag\] \= \"'$new_version'\"/g' "{}" \;
  fi
  find . -name "*.make" -exec sed -i '' 's/'$module_name'\]\[version\] \= \"'$current_version'\"/'$module_name'\]\[version\] \= \"'$new_version'\"/g' "{}" \;
done < modules_to_upgrade.csv
