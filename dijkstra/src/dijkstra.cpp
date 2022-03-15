#include <iostream>
#include <vector>

#include "../include/Graph.h"
#include "../include/FibonacciHeap.h"


class Dijkstra {
	public:
		Dijkstra(int, Graph);
		FibonacciHeap priorityQueue;
};

void Dijkstra(int start, Graph Instance) {
	if (start > Instance.size_nodes) {
		std::cerr << "The start node must be part of the graph.\n";
	}
	FibonacciHeap priorityQueue;
	node* tmp = priorityQueue.createNode(10000);
	priorityQueue.insert(priorityQueue.HH, tmp);
	node* bis = tmp;
	for (int i=1; i<Instance.size_nodes; i++) {
		tmp = priorityQueue.createNode(10000);
		priorityQueue.insert(bis, tmp);
		bis = tmp;
	}
	Instance.predecessors[start] = -1;
	while ( priorityQueue.number > 0) {
		//node* u = priorityQueue.extractMin();
	}
}
