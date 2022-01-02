#include <iostream>
#include <vector>

#include "Graph.h"
#include "Random_graph.h"

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
	std::vector< std::vector<int> > nodes = {
		{1, 2},
		{0, 4},
		{0, 3, 4},
		{2},
		{1, 2}
	};
	std::vector< std::vector<int> > weights = { 
		{10, 20},
		{10, 40},
		{20, 8, 500},
		{8},
		{40, 500}
	};
	Graph Instance(nodes, weights);
	if ( argc < 2) {
		Instance.Dijkstra(1);
	} else {
		Instance.Dijkstra(atoi(argv[1]));
	}
	vector_printer(Instance.predecessors);
	Random_graph random_graphs(12);
	random_graphs.generate_graphs();
	std::cout << random_graphs.generated_graphs[0] << std::endl;
	std::cout <<  "--- --- ---"<< std::endl;
	std::vector<int> rand_test = random_graphs.test_random();
	vector_printer(rand_test);
 return 0;
 }
