#!/bin/bash
read -p "Enter a number: " num
rev=0
temp=$num
while [ $temp -ne 0 ]; do
    rev=$((rev * 10 + temp % 10))
    temp=$((temp / 10))
done
if [ $num -eq $rev ]; then
    echo "Palindrome"
else
    echo "Not Palindrome"
fi
