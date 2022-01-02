CC = g++
CFLAGS = -g -Wall -std=c++17

main: main.o Graph.o Random_graph.o
	$(CC) -o main *.o

main.o: main.cpp Graph.h Random_graph.h
	$(CC) $(CFLAGS) -c main.cpp

Graph.o: Graph.h

Random_graph.o: Random_graph.h Graph.h
