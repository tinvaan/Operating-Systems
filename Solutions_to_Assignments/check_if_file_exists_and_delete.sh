#
# Simple shell script that verifies if a file exists in a given in the pwd
# if not, creates the file and then asks for the user's confirmation for deleting it
#

#! /bin/bash

echo "Looking for files in the PWD only ..."
read -p "Enter the filename : " filename
find $filename
return_value=$?
if test "$return_value"=="1"
then
  echo "Could not find $filename"
else 
  echo "Found $filename"
fi
