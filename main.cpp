// standard libraries
#include <iostream>
#include <vector>

// external files
#include "Graph.h"
#include "BinaryHeap.h"
#include "std_graph.h"
#include "FibonacciHeap.h"
#include "dijkstra.h"

// example files to test dijkstra
#include "test_graphs.hpp"
#include "test_std_graphs.hpp"

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
	// Graph implementation testing
	//std::cout << "This is the testing of the implementation with data structure 'Graph'.\n\n";
	//if (argc == 2) {
		//test_graphs teste;
		//Graph test(*teste.arcs[0], *teste.weights[0]);
		//int argv1 = atoi(argv[1]);
		//test  = Graph(*teste.arcs[0], *teste.weights[0]);
		//for (int j=0; j<10; j++)
		//test.Dijkstra(j + argv1);
		//vector_printer(test.predecessors);
		//std::cout << "\n";
	//} else if (argc > 2) {
		//test_graphs teste;
		//int argv1 = atoi(argv[1]);
		//int argv2 = atoi(argv[2]);
		//if (argv1 < size(teste.arcs) && argv2 < size(*teste.arcs[0])) {
			//Graph test_graph(*teste.arcs[argv1], *teste.weights[argv1]);
			//test_graph.Dijkstra(argv2);
			//vector_printer(test_graph.predecessors);
		//} else {
			//std::cerr << "Please indicate a number smaller than the amount of graphs.\n Same for the starting vertex.\n";
	//}
		       
	//} else {
		//std::cerr << "Please which graph you want to run Dijkstra on, and the starting vertex.\n";
	//}
	//std::cout << "\n\n\n";
	//std_graph implementation testing
	//std::cout << "This is the testing of the implementation with data structure 'std_graph'.\n\n";
	//if (argc == 2) {
		//test_std_graphs teste2;
		//std_graph TestGraph(*teste2.arcs[0], *teste2.weights[0]);
		//int argv1 = atoi(argv[1]);
		//for (int j=0; j<10; j++)
		//TestGraph.Dijkstra(j + argv1);
		//vector_printer(TestGraph.predecessors);
		//std::cout << "\n";
	//} else if (argc > 2) {
		//test_std_graphs teste2;
		//int argv1 = atoi(argv[1]);
		//int argv2 = atoi(argv[2]);
		//if (argv1 < size(teste2.arcs) && argv2 < size(*teste2.arcs[0])) {
			//std_graph test_std_graph(*teste2.arcs[argv1], *teste2.weights[argv1]);
			//test_std_graph.Dijkstra(argv2);
			//vector_printer(test_std_graph.predecessors);
		//} else {
			//std::cerr << "Please indicate a number smaller than the amount of graphs.\n Same for the starting vertex.\n";
	//}
		       //
	//} else {
		//std::cerr << "Please which graph you want to run Dijkstra on, and the starting vertex.\n";
	//}
 	//fibonacci heaps implementation testing
	std::cout << "This is the testing of the implementation with data structure 'FibonacciHeap'.\n\n";
	FibonacciHeap fibo_test;
	return 0;
}
