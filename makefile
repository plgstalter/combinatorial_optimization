CC = g++
CFLAGS = -g -Wall -std=c++17

main: main.o Graph.o BinaryHeap.o std_graph.o
	$(CC) -o main *.o

main.o: main.cpp Graph.h BinaryHeap.h std_graph.h test_graphs.hpp
	$(CC) $(CFLAGS) -c main.cpp

Graph.o: Graph.cpp
	$(CC) $(CFLAGS) -c Graph.cpp

BinaryHeap.o: BinaryHeap.cpp
	$(CC) $(CFLAGS) -c BinaryHeap.cpp

std_graph.o: std_graph.cpp
	$(CC) $(CFLAGS) -c std_graph.cpp

clean: Graph.o BinaryHeap.o main.o std_graph.o 
	rm *.o
