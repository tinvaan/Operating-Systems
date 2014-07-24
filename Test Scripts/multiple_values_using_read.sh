#
# Handling multiple values using read.
#

#! /bin/bash

nameservers="ns1.nixcraft.net ns2.nixcraft.net ns3.nixcraft.net"
read -r ns1 ns2 ns3 <<< "$nameservers"
echo "$ns1 and $ns2 and $ns3\n"
