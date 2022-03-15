#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct edge {
	int left;
	int right;
};

struct Graph {
	int vertices;
	int number_of_edges;
	struct edge* edges;
	struct edge* covering_tree;
};

void create_set(int vertex) {
	printf("%s", "aha");
}

int* sort_vertices(struct Graph graph) {
	int* p;
	return p;
}

void unite(int* left, int* right) {
	printf("%s", "ehe");
}

int find(int* vertex) {
	return 0;
}

void kruskal(struct Graph graph) {
	int count = 0;
	for (int i=0; i<graph.vertices; i++) {
		create_set(i);
	}
	int* sorted_vertices = sort_vertices(graph);
	for (int i=0; i<graph.number_of_edges; i++) {
		if (find(&graph.edges[i].left) != find(&graph.edges[i].right)) {
			graph.covering_tree[count] = graph.edges[i];
			count++;
			unite(&(&graph.edges[i])->left, &(&graph.edges[i])->right);
		}
	}
}

int main(int argc, char const *argv[]) { 
 return 0; 
 }
