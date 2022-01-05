#include <iostream>
#include <vector>
#include <fstream>

#include "Graph.h"
#include "Random_graph.h"
#include "test_graphs.hpp"

template <typename T>
void vector_debug(std::vector<T> vec) {
	int j = 0;
	for (int i=0; i<size(vec); i++) {
		std::cout << j << std::endl;
		j++;
	}
}

void vector_printer(std::vector<int> vec) {
	for (int i=0; i<size(vec); i++) {
		std::cout <<  vec[i];
		std::cout << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char const *argv[]) { 
	test_graphs teste;
	Graph instance(teste.arcs0, teste.weights0);
	instance.Dijkstra(1);
	vector_printer(instance.predecessors);
	return 0;
}
