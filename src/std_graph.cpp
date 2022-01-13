#include <math.h>
#include <array>
#include <numeric>
#include <iostream>
#include <vector>

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
};

std_graph::std_graph(std::vector<int> Arcs, std::vector<int> Weights) {
	size_graph = sqrt(size(Arcs));
	arcs       = Arcs;
	weights    = Weights;
	for (int i=0; i<size_graph*size_graph; i++) {
		if (weights[i] == 0) {
			weights[i] = big_integer/2;
		}
	}
	predecessors.assign(size_graph, 0);
	P.assign(size_graph, 1);
	distances.assign(size_graph, big_integer);
	}

void std_graph::display_graph() {
	for (int i=0; i<size(arcs); i++) {
		if (i%size_graph == 0) {
			std::cout << "\n";
		}
		std::cout << arcs[i] << " ";
	}
	std::cout << "\n\n";
}

void std_graph::Dijkstra(int start) {
	if (start > size_graph) {
		std::cerr << "The start node must be part of the graph.\n";
	}
	distances[start] = 0;
	predecessors[start] = -1;
	while (std::accumulate(P.begin(), P.end(), 0) != 0) {
		int a = min_dist();
		P[a] = 0;
		for (int i=0; i<size_graph; i++) {
			if (arcs[a * size_graph + i] == 1 ) {
				update_distances(a, i);
			}
		}
	}
}

int std_graph::min_dist() {
	int mini = 2 * big_integer;
	int node = -1;
	for (int i=0; i<size_graph; i++) {
		if (P[i] == 1 && distances[i] < mini) {
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
