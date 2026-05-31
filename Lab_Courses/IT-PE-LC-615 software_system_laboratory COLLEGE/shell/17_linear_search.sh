#!/bin/bash
arr=(10 20 30 40 50)
read -p "Search: " key
found=0
for ((i=0; i<${#arr[@]}; i++)); do
    if [ ${arr[$i]} -eq $key ]; then
        echo "Found at index $i"
        found=1
        break
    fi
done
[ $found -eq 0 ] && echo "Not found"
