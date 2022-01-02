#pragma once

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
