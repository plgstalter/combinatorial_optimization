#pragma once
#include <math.h>

int array_sum(int* array);

class std_graph {
	private:
		int big_integer = 10000;
	public:
		int size_graph;
		std_graph(int Size, int* Arcs, int* Weights);
		int* arcs;
		int* weights;
		int* predecessors;
		int* distances;
		void Dijkstra(int start);
		int min_dist();
		void update_distances(int k, int l);
};
