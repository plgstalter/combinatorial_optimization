CC = g++
CFLAGS = -g -Wall -std=c++17

main: main.o Graph.o
	$(CC) -o main main.o Graph.o

main.o: main.cpp Graph.h
	$(CC) $(CFLAGS) -c main.cpp

Graph.o: Graph.h
