#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

extern int montecarlo(int);

int main(int argc, char **argv) 
{
  int size, rank;
  MPI_Init(NULL, NULL);
//  MPI_Init(&argc,&argv);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  MPI_Comm_size(MPI_COMM_WORLD,&size);
  srand(time(NULL));


  int *send_buf;
  int *recv_buf;

    send_buf = (int*) malloc (sizeof(int) * size);
    recv_buf = (int*) malloc(sizeof(int) );	


    for (int i = 0; i< size; i++)
	send_buf[i] = i; // Set the seed array here

  MPI_Scatter(send_buf,1,MPI_INT,recv_buf,1,MPI_INT,0,MPI_COMM_WORLD);


	montecarlo(*recv_buf);
/*
 *
 *  Your code goes here ...
 *  Each thread will have it's own seed given by recv_buf
 */

	free(send_buf);
	free(recv_buf);

  MPI_Finalize();

  return 0;
}


    
