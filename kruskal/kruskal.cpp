#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

struct vertex {
	struct vertex* parent;
};

typedef struct edge {
	struct vertex* left;
	struct vertex* right;
	int weight;
} edge;

typedef struct Graph {
	int number_of_vertices;
	int number_of_edges;
	struct edge* edges;
	struct edge* covering_tree;	
} Graph;

//class Graph {
	//public:
		//int number_of_vertices;
		//int number_of_edges;
		//std::vector<struct edge> covering_tree;
		//std::vector<struct edge> edges;
		//Graph(int, int);
//};

//Graph::Graph(int number_1, int number_2) {
	//struct edge e0;
	//number_of_vertices = number_1;
	//number_of_edges = number_2;
	//edges.assign(number_of_edges, e0);
	//covering_tree.assign(number_of_edges, e0);
//}

void create_set(struct vertex* x) {
	x->parent = NULL;
}

struct vertex* find(struct vertex* x) {
	if (x->parent == NULL) {
		return x;
	}
	return find(x->parent);
}

void unite(struct vertex* x, struct vertex* y) {
	struct vertex* x_root = find(x);
	struct vertex* y_root = find(y);
	if (x_root != y_root) {
		x_root->parent = y_root;
	}
}

void quicksort_method(Graph graph, int low, int high) {
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

int kruskal(Graph *graph) {
	int count = 0;
	struct vertex* vertices[graph->number_of_vertices];
	for (int i=0; i<graph->number_of_vertices; i++) {
		create_set(vertices[i]);
	}
	quicksort_method(*graph, 0, graph->number_of_edges - 1);
	for (int i=0; i<graph->number_of_edges; i++) {
		if (find(graph->edges[i].left) != find(graph->edges[i].right)) {
			graph->covering_tree[count] = graph->edges[i];
			count++;
			unite((graph->edges[i]).left, (graph->edges[i]).right);
		}
	}
	return count;
}
