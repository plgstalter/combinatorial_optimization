#pragma once
#include <iostream>
#include "Graph.h"
#include "FibonacciHeap.h"

class Dijkstra {
	public:
		Dijkstra(int, Graph);
		FibonacciHeap priorityQueue;
};
