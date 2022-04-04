#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct vertex {
	struct vertex* parent;
};

struct edge {
	struct vertex* left;
	struct vertex* right;
	int weight;
};

struct Graph {
	int number_of_vertices;
	int number_of_edges;
	struct edge* covering_tree;
	struct edge edges[];
};

struct Graph* createGraph(struct Graph*, int, int);
void create_set(struct vertex*);
struct vertex* find(struct vertex*);
void unite(struct vertex*, struct vertex*);
int* quicksort_method(struct Graph, int, int);
int kruskal(struct Graph*);
