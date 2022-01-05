CC = g++
CFLAGS = -g -Wall -std=c++17

main: main.o Graph.o
	$(CC) -o main *.o

main.o: main.cpp Graph.h test_graphs.hpp
	$(CC) $(CFLAGS) -c main.cpp

Graph.o: Graph.h
