#include <vector>
#include <numeric>
#include <iostream>

class Graph {
	private:
		int big_integer = 10000;
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

Graph::Graph(std::vector< std::vector<int> > Nodes, std::vector< std::vector<int> > Weights) {
	nodes = Nodes;
	weights = Weights;
	size_nodes = size(nodes);
	P.assign(size_nodes, 1);
	predecessors.assign(size_nodes, 0);
	distances.assign(size_nodes, big_integer);
}

void Graph::Dijkstra(int start) {
	distances[start] = 0;
	predecessors[start] = -1;
	while (std::accumulate(P.begin(), P.end(), 0) != 0) {
		int a = min_dist();
		P[a] = 0;
		for (std::vector<int>::iterator it = nodes[a].begin(); it != nodes[a].end(); it++){
			if ( P[*it] == 1) {
				update_distances(a, *it);
			}
		}
	}
}

int Graph::min_dist() {
	int mini = big_integer;
	int node = -1;
	for (int i=0; i<size_nodes; i++) {
		if ( P[i] == 1 && distances[i] < mini) {
			mini = distances[i];
			node = i;
		}
	}
	return node;
}

void Graph::update_distances(int k, int l) {
	if (distances[l] > distances[k] + weights[k][l]) {
		distances[l] = distances[k] + weights[k][l];
		predecessors[l] = k;
	}
}
