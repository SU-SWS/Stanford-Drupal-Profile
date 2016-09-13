#!/bin/bash

# Usage: ./sed-make <module> <oldversion> <newversion>
# E.g., "./sed-make block_class 1.3 2.3"

find . -name "*.make" -exec sed -i '' 's/'$1'\]\[version\] \= \"'$2'\"/'$1'\]\[version\] \= \"'$3'\"/g' "{}" \;

