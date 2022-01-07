#include <iostream>
#include <vector>

#include "Graph.h"
#include "BinaryHeap.h"
#include "std_graph.h"
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
	int n = 1;
	if (n == 1) {
		if (argc > 2) {
			test_graphs teste;
			int argv1 = atoi(argv[1]);
			int argv2 = atoi(argv[2]);
			if (argv1 < size(teste.arcs) && argv2 < size(*teste.arcs[0])) {
				Graph test_graph(*teste.arcs[argv1], *teste.weights[argv1]);
				test_graph.Dijkstra(argv2);
				vector_printer(test_graph.predecessors);
			} else {
				std::cerr << "Please indicate a number smaller than the amount of graphs.\n Same for the starting vertex.\n";
		}
		       
		}	else {
			std::cerr << "Please which graph you want to run Dijkstra on, and the starting vertex.\n";
		}
	} else if (n == 2) {
		BinaryHeap Test(3);
		std::cout <<  Test.size << std::endl;
	}
	return 0;
}
