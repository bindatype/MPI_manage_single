CC=mpicc
CFLAGS=-Wall -g -std=c99 

all: monte_carlo
	$(CC) $(CFLAGS) montecarlo.o scatter_seed.c -o scatter_seed

monte_carlo: 
	$(CC) -c montecarlo.c


clean:
	rm montecarlo.o scatter_seed
