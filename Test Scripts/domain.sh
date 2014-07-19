#! /bin/bash
# Shell script to display the Internet domain name owner information.
#

# Read the user entered domain name.
# Wait 10 seconds for input, if no input is provided, abort.
# The above can be done using the -t option with "read".
read -t 10 -p "Enter the internet domain name (eg : arsenal.com): " domain_name
whois $domain_name
echo

