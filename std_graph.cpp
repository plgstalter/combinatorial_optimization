#include <math.h>
#include <iostream>

int array_sum(int* array) {
 	int res = 0;
	for (int i = 0; i < (sizeof array)/(sizeof array[0]); i++) {
		res = res + array[i];
	}
	return res;
}

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
		int* P;
		void Dijkstra(int start);
		int min_dist();
		void update_distances(int k, int l);
};

std_graph::std_graph(int Size, int* Arcs, int* Weights) {
	size_graph = Size;
	int* arcs = Arcs;
	int* weights = Weights;
	int* predecessors[size_graph];
	int* distances[size_graph];
	int* P[size_graph];
	for (int i=0; i<size_graph; i++) {
		*distances[i] = big_integer;
		*P[i] = 1;
	}
}

void std_graph::Dijkstra(int start) {
	if (start > size_graph) {
		std::cerr << "The start node must be part of the graph.\n";
	}
	distances[start] = 0;
	predecessors[start] = -1;
	while (array_sum(P) != 0) {
		int a = min_dist();
		P[a] = 0;
		for (int i=0; i<floor(size_graph/2); i++) {
			if (arcs[a * size_graph + i] == 1 and P[i] == 0) {
				update_distances(a, i);
			}
		}
	}
}

int std_graph::min_dist() {
	int mini = big_integer;
	int node = -1;
	for (int i=0; i<size_graph; i++) {
		if ( P[i] == 1 && distances[i] < mini) {
			mini = distances[i];
			node = i;
		}
	}
	return node;
}

void std_graph::update_distances(int k, int l) {
	if (distances[l] > distances[k] + weights[k * size_graph + l]) {
		distances[l] = distances[k] + weights[k * size_graph + l];
		predecessors[l] = k;
	}
}
