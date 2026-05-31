#!/bin/bash
sum=0
for i in 1 2 3 4 5; do
    read -p "Enter number $i: " n
    sum=$((sum + n))
done
echo "Average = $(echo "scale=2; $sum/5" | bc)"
