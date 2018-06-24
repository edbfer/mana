CC = g++
CFLAGS = -g -fopenmp
RM = rm

all: main.o population.o util.o path.o iteration.o
	$(CC) $(CFLAGS) -o teste main.o population.o util.o path.o iteration.o
	export OMP_NUM_THREADS=4

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

population.o: population.cpp population.h
	$(CC) $(CFLAGS) -c population.cpp -o population.o

util.o: util.cpp util.h
	$(CC) $(CFLAGS) -c util.cpp -o util.o

path.o: path.cpp path.h
	$(CC) $(CFLAGS) -c path.cpp -o path.o

iteration.o: iteration.cpp iteration.h
	$(CC) $(CFLAGS) -c iteration.cpp -o iteration.o

clean:
	$(RM) -rf *.o teste

del-data:
	$(RM) -rf iteration_*
