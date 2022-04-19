from sys import argv
import numpy as np
import random
import itertools as it

class Graph_gen():

    def __init__(self, nb_graphs, number_of_nodes, number_of_edges, name_of_file='graphs.h', max_weight=500):
        self.nb_graphs = int(nb_graphs)
        self.nb_nodes = int(number_of_nodes)
        self.nb_edges = int(number_of_edges)
        self.max_weight = int(max_weight)
        self.name_of_file = name_of_file
    
    def generator(self):
        self.file = open(self.name_of_file, 'w')
        self.file.write('//This file was compiled by generator.py.\n//It contains randomly generated graphs.\n\n#include "kruskal.h"\n\n')
        vertices = list(range(self.nb_nodes))
        edges = list(it.product(vertices, vertices))
        for i in range(self.nb_graphs):
            tmp_edges = random.sample(edges, self.nb_edges)
            tmp_weights = (self.max_weight * np.random.rand(self.nb_edges)).astype(int)
            self.writer(tmp_edges, tmp_weights, i)
        self.file.close()

    def writer(self, edges, weights, graph_id):
        number = len(weights)
        str1 = f"struct vertex v{graph_id}[{self.nb_nodes}];\n"
        self.file.write(str1)
        trick = '{'
        trick2 = '}'
        bis = ""
        for i in range(len(weights)):
            tmp_str = f"struct edge e{graph_id}_{i} = {trick}\n   .left = &v{graph_id}[{edges[i][0]}],\n   .right = &v{graph_id}[{edges[i][1]}],\n   .weight = {weights[i]}\n{trick2};\n"
            self.file.write(tmp_str)
            bis += f"   &e{graph_id}_{i}"
            if  i < len(weights) - 1:
                bis += ",\n"
            else:
                bis += "\n"
        tmp_str = f"struct edge* e{graph_id}[{self.nb_edges}] = {trick}\n{bis}{trick2};\n"
        self.file.write(tmp_str)

if  __name__ == "__main__":
    if  len(argv) == 5:
        gen = Graph_gen(argv[1], argv[2], argv[3], argv[4])
        gen.generator()
    elif  len(argv) > 3:
        gen = Graph_gen(argv[1], argv[2], argv[3])
        gen.generator()
    else:
        print("error. Please indicate enough input")
