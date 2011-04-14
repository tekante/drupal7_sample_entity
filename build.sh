#!/bin/sh

# this has numerous assumptions about the location of a preconfigured settings.php and files directory
# it is not intended for direct use
drush make se.make ../html
cd ../html/profiles
if [ $? != 0 ]; then
  echo "Error changing directory"
  exit;
fi
ln -s ../../se se
cd ../sites/default
if [ $? != 0 ]; then
  echo "Error changing directory"
  exit;
fi
ln -s ../../../../settings.php
ln -s ../../../../files
