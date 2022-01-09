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
	int m = 1;
	if (n == 1) {
		if (m == 1 && argc > 1) {
			test_graphs teste;
			Graph test(*teste.arcs[0], *teste.weights[0]);
			int argv1 = atoi(argv[1]);
			for (int i=0; i<80; i++) {
				test  = Graph(*teste.arcs[i], *teste.weights[i]);
				for (int j=0; j<10; j++)
				test.Dijkstra(10 * j + argv1);
				vector_printer(test.predecessors);
				std::cout << "\n";
			}
		} else if (argc > 2) {
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
		BinaryHeap Test(5);
	} else if (n == 3) {
		int Size = 5;
		std::vector<int> Arcs = {
		0, 0, 1, 1, 0,
		0, 0, 0, 0, 1,
		1, 0, 0, 1, 0,
		1, 0, 1, 0, 0,
		0, 1, 0, 0, 0
		};
		std::vector<int> Weights = {
		0, 0, 20, 100, 0,
		0, 0, 0, 0, 50,
		20, 0, 0, 230, 0,
		100, 0, 230, 0, 0,
		0, 50, 0, 0, 0
		};
		std_graph TestGraph(Size, Arcs, Weights);
		TestGraph.Dijkstra(0);
		for (int i=0; i<Size*Size; i++) {
			if (i%Size == 0) {
				std::cout << "\n";
			}
			std::cout << TestGraph.weights[i] << " ";
		}
		std::cout << "\n";
	}
	return 0;
};
