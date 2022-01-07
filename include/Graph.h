#pragma once
#include <vector>
#include <iostream>

class Graph {
	private:
		int big_integer;
	public:
		int size_nodes;
		std::vector< std::vector<int> > nodes;
		std::vector< std::vector<int> > weights;
		std::vector<int> P;
		std::vector<int> predecessors;
		std::vector<int> distances;

		Graph(std::vector< std::vector<int> > Nodes, std::vector< std::vector<int> > Weights);
		void Dijkstra(int start);
		int min_dist();
		void update_distances(int k, int l);
};
