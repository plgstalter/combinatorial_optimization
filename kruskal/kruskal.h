#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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

void create_set(struct vertex*);
struct vertex* find(struct vertex*);
void unite(struct vertex*, struct vertex*);
void quicksort_method(Graph, int, int);
int kruskal(Graph*);
