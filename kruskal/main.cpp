#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "kruskal.h"
#include "graphs.h"

int main(int argc, char const *argv[]) {
	struct Graph graphe = {
		.number_of_vertices = 7,
		.number_of_edges = 12,
		//.edges = e0[0]
	};
	graphe.edges = e0[0];
	//int j = kruskal(&graphe);
	return 0; 
}
