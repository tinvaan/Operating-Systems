#! /bin/zsh
# Simple Shell script to get the Linux network information
#

echo "Current Date : $(date) @ $(hostname)"
echo "Networking Configuration : "
/sbin/ifconfig

