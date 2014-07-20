#
# Shell script to build the Plasma Media Center
#

#! bin/bash

# Move to the home directory
cd

# Get the source
git clone git://anongit.kde.org/plasma-mediacenter

# Move inside the cloned folder
cd plasma-mediacenter

# Start the building process
mkdir build
cmake -DCMAKE_INSTALL_PREFIX=`kde4-config --prefix`
make install
kbuildsyscoca4

# Run Plasma Media Center
plasma-mediacenter
