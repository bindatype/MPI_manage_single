#!/bin/bash

#SBATCH -o testing%j.out
#SBATCH -e testing%j.err 
#SBATCH -N 3
#SBATCH -p short
#SBATCH -t 00:30:00
#SBATCH -D /home/maclach/Codes/HPC_Examples/MPI/MPI_manage_single 

#echo $1
module load openmpi/1.8/gcc/4.7/cpu
mpirun -n 8 ./scatter_seed $1

