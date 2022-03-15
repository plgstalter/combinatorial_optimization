#pragma once
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

void create_set(int);
void unite(int*, int*);
int find(int*);
int* quicksort_method(struct Graph, int, int);
void kruskal(struct Graph);
