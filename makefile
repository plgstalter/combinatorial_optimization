CC = g++
CFLAGS = -g -Wall -std=c++17

main: main.o Graph.o
	$(CC) -o main *.o

main.o: main.cpp Graph.h BinaryHeap.h test_graphs.hpp
	$(CC) $(CFLAGS) -c main.cpp

Graph.o: Graph.cpp
	$(CC) $(CFLAGS) -c Graph.cpp

BinaryHeap.o: BinaryHeap.cpp
	$(CC) $(CFLAGS) -c BinaryHeap.cpp

clean: main.o Graph.o BinaryHeap.o
	rm *.o
