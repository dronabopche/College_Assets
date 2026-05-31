#!/bin/bash
read -p "Enter a: " a
read -p "Enter b: " b
if [ $a -gt $b ]; then
    echo "$a is greater"
else
    echo "$b is greater"
fi
