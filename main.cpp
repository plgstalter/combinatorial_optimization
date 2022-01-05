#include <iostream>
#include <vector>

#include "Graph.h"
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
	if (argc > 2) {
		test_graphs teste;
		Graph test_graph(teste.arcs1, teste.weights1);
		test_graph.Dijkstra(2);
			//std::cerr << "Please indicate a number smaller than the amount of graphs.\n Same for the starting vertex.\n";
	} else {
		std::cerr << "Please which graph you want to run Dijkstra on, and the starting vertex.\n";
	};
	return 0;
}
