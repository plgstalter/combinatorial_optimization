#pragma once
#include <math.h>
#include <numeric>
#include <vector>
#include <iostream>

int array_sum(int* array);

class std_graph {
	private:
		int big_integer = 10000;
		std::vector<int> P;
		std::vector<int> distances;
		int min_dist();
		void update_distances(int k, int l);
	public:
		int size_graph;
		std_graph(std::vector<int> Arcs, std::vector<int> Weights);	
		std::vector<int> arcs;
		std::vector<int> weights;
		std::vector<int> predecessors;
		void display_graph();
		void Dijkstra(int start);
		void Kruskal();
};
