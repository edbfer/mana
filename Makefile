CC = g++
CFLAGS = -g

all: main.o population.o
	$(CC) $(CFLAGS) -o teste main.o population.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

population.o: population.cpp population.h
	$(CC) $(CFLAGS) -c population.o -o main.o
