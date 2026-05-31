#!/bin/bash
# 2x2 matrix multiplication
A=(1 2 3 4)
B=(5 6 7 8)
for ((i=0; i<2; i++)); do
    for ((j=0; j<2; j++)); do
        sum=0
        for ((k=0; k<2; k++)); do
            sum=$((sum + A[i*2+k] * B[k*2+j]))
        done
        echo -n "$sum "
    done
    echo
done
