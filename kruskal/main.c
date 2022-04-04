#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "kruskal.h"

int main(int argc, char const *argv[]) {
	struct Graph* graphe;
	graphe = createGraph(graphe, 2, 1);
	struct vertex v0, v1;
	struct edge e0;
	e0.left = &v0;
	e0.right = &v1;
	e0.weight = 10;
	graphe->edges[0] = e0;
	graphe->edges[1] = e0;
	kruskal(graphe);
	free(graphe);
	return 0; 
}
