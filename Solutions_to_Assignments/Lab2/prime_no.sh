#
# Shell script to print the no. of prime numbers from 1 to a n
#

#! /bin/bash

read -p "Enter the upper bound : " max

potential_prime=2
prime_set=($potential_prime)

while [ $potential_prime -le $max ]
do
  potential_prime=$((potential_prime + 1))
  for i in $max
    if [ "$((potential_prime % i))" == "0" ]
    then
      break
    else 
      prime_set+=($i)
    fi
done

echo "The list of prime numbers within $max are "
echo "${prime_set[*]}"
