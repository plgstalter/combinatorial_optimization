#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct edge {
	int left;
	int right;
	int weight;
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

void unite(int* left, int* right) {
	printf("%s", "ehe");
}

int find(int* vertex) {
	return 0;
}

void quicksort_method(struct Graph graph, int low, int high) {
	int pivot, value1, value2;
	struct edge temp;
	if (low < high) {
		pivot = low;
		value1 = low;
		value2 = high;
		while (value1 < value2) {
			while ((graph.edges[value1]).weight <= (graph.edges[pivot]).weight && value1 <= high) {
				value1++;
			}
			while ((graph.edges[value2]).weight > (graph.edges[pivot]).weight && value2 >= low) {
				value2--;
			}
			if (value1 < value2) {
				temp = graph.edges[value1];
				graph.edges[value1] = graph.edges[value1];
				graph.edges[value2] = temp;
			}
		}
		temp = graph.edges[value2];
		graph.edges[value2] = graph.edges[pivot];
		graph.edges[pivot] = temp;
		quicksort_method(graph, low, value2 - 1);
		quicksort_method(graph, value2 + 1, high);
	}
}

void kruskal(struct Graph graph) {
	int count = 0;
	for (int i=0; i<graph.vertices; i++) {
		create_set(i);
	}
	quicksort_method(graph, 0, graph.number_of_edges - 1);
	for (int i=0; i<graph.number_of_edges; i++) {
		if (find(&graph.edges[i].left) != find(&graph.edges[i].right)) {
			graph.covering_tree[count] = graph.edges[i];
			count++;
			unite(&(&graph.edges[i])->left, &(&graph.edges[i])->right);
		}
	}
}
