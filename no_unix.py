import numpy as np
from sys import argv

from random_graphs import random_graph

def file_writer(number_of_graphs, size_nodes, density=.3, max_weight=500, file_name="test_graphs.hpp"):
    Arcs, Weights = random_graph(number_of_graphs, size_nodes, density=density, max_weight=max_weight)
    file = open(file_name, 'w')

    file.write('//This file was compiled by no_unix.py.\n//It contains randomly generated graphs.\n\n#include <vector>\n\nclass test_graphs {\npublic:')
    for j in range(len(Arcs)):
        start = Arcs[j]//size_nodes
        end = Arcs[j]%size_nodes
        string = f"std::vector< std::vector<int> > arcs{j}=" 
        file.write(string + "{\n")
        for i in range(size_nodes):
            string2 = str(list(start[(end == i) & (start != end)])).replace('[', '{').replace(']', '}')
            file.write(string2 + ",\n")
        string3 = f"std::vector< std::vector<int> > weights{j}="
        file.write("};\n" + string3 + "{\n")
        for i in range(size_nodes):
            string4 = str(list(Weights[j][(end == i) & (start != end)])).replace('[', '{').replace(']', '}')
            file.write(string4 + ",\n")
    string5 = f"std::vector< std::vector<int> >* arcs[{number_of_graphs}]="
    file.write("};\n" + string5 + "{\n")
    for i in range(len(Arcs)):
        string6 = f"&arcs{i},\n"
        file.write(string6)
    string7 = f"std::vector< std::vector<int> >* weights[{number_of_graphs}]="
    file.write("};\n" + string7 + "{\n")
    for i in range(len(Arcs)):
        string8 = f"&weights{i},\n"
        file.write(string8)
    file.write('};\n};\n')
    file.close()

if  len(argv) == 3:
    file_writer(int(argv[1]), int(argv[2]))
elif len(argv) > 3:
    file_writer(int(argv[1]), int(argv[2]), file_name=argv[3])
else:
    raise AttributeError("please add file name, size of the graph and how many graphs you want.")
