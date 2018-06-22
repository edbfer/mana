CC = g++
CFLAGS = -g -fopenmp -O3
RM = rm

all: main.o population.o
	$(CC) $(CFLAGS) -o teste main.o population.o
	export OMP_NUM_THREADS=4

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

population.o: population.cpp population.h
	$(CC) $(CFLAGS) -c population.cpp -o population.o

clean:
	$(RM) -rf *.o teste
