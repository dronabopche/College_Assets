#!/bin/bash
arr=(64 34 25 12 22 11 90)
n=${#arr[@]}
for ((i=0; i<n-1; i++)); do
    for ((j=0; j<n-i-1; j++)); do
        if [ ${arr[$j]} -gt ${arr[$((j+1))]} ]; then
            tmp=${arr[$j]}
            arr[$j]=${arr[$((j+1))]}
            arr[$((j+1))]=$tmp
        fi
    done
done
echo "Sorted: ${arr[@]}"
