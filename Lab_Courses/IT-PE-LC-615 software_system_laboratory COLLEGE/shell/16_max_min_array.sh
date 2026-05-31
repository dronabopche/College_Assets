#!/bin/bash
arr=(3 1 7 2 9 4)
max=${arr[0]}
min=${arr[0]}
for x in "${arr[@]}"; do
    [ $x -gt $max ] && max=$x
    [ $x -lt $min ] && min=$x
done
echo "Max=$max  Min=$min"
