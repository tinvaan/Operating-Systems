#! /bin/bash

echo "You are currently in : "; pwd
read -p "Enter name of new directory : " dirname
echo "Name of the new directory to be created $dirname "
echo "Creating new directory in ~/Desktop "
cd ~/Desktop
mkdir "$dirname"
echo "DONE ! Successfully created new directory"
read -p "Do you want to delete the directory ? " answer

if test "$answer" == "yes"
then
  echo "Deleting $dirname ... "
  rm -r $dirname
fi
echo "Successfully deleted $dirname"
echo

