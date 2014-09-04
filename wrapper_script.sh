#!/bin/bash

for (( j = 1; j <= 10; j++ )); do
sleep 2
sbatch submit.sh $j
done

