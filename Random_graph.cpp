#include <vector>
#include <random>

#include "Graph.h"

class Random_graph {
	public:
		int number_of_graphs;
		std::vector<Graph*> generated_graphs;

		Random_graph(int number);
		void generate_graphs();
		std::vector<int> test_random();
};

Random_graph::Random_graph(int number) {
	number_of_graphs = number;
}

void Random_graph::generate_graphs() {
	std::vector< std::vector<int> > tmp_nodes;
	std::vector< std::vector<int> > tmp_weights;
	Graph tmp_graph(tmp_nodes, tmp_weights);
	generated_graphs.assign(number_of_graphs, &tmp_graph);
	for (int i=0; i<number_of_graphs; i++) {
		//tmp_graph.nodes = ?;
		//tmp_graph.weights = ?;
		generated_graphs[i] = &tmp_graph;
	}
}

std::vector<int> Random_graph::test_random() {
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1,50);
	auto dice = std::bind ( distribution, generator );
	std::vector<int> rand_vec;
	for (int i=0; i<10; i++) {
		rand_vec.push_back(dice());
	}
	return rand_vec;
}
