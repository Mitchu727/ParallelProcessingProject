#!/bin/bash
fileName=../output/tabu_2_100.txt

echo "Running experiments for open MP" 
touch $fileName
cat /dev/null > $fileName


for threadsNumber in 1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192
    do
    export OMP_NUM_THREADS=$threadsNumber
    echo "OMP_NUM_THREADS=$threadsNumber" >> $fileName
    for i in {1..5}
    do
        { time ../build/mainOpenMp tabu 2 2 100 ; } 2> >(tee -a $fileName >&2)
    done
done