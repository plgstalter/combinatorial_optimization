from sys import argv
import numpy as np

class Graph_gen():

    def __init__(self, nb_graphs, size_graphs, max_weight=500):
        self.nb_graphs = nb_graphs
        self.size_graphs = size_graphs
        self.max_weight = max_weight

    def generator(self):
        tmp = (2 * np.random.rand(self.size_graphs**2 * self.nb_graphs)).reshape((self.nb_graphs, self.size_graphs, self.size_graphs)).astype(int)
        arcs = tmp
        for i in range(self.nb_graphs):
           arcs[i] += tmp[i].transpose() 
        self.arcs = arcs//2 # so as to make a symetric matrix
        weights = (self.max_weight* np.random.rand(self.size_graphs**2 * self.nb_graphs)).reshape((self.nb_graphs, self.size_graphs, self.size_graphs)).astype(int)
        self.weights = weights * arcs

    def printer_switch(self, choice):
        if  choice == "graph":
            self.graph_printer()
        elif  choice == "fibo":
            self.fibo_heap_printer()
        elif  choice == "std":
            self.std_graph_printer()

    def graph_printer(self, file_name="include/test_graphs.hpp"):
        file = open(file_name, 'w')

        file.write('//This file was compiled by no_unix.py.\n//It contains randomly generated graphs.\n\n#include <vector>\n\nclass test_graphs {\npublic:')
        for j in range(len(self.arcs)):
            string = f"std::vector< std::vector<int> > arcs{j}=" 
            file.write(string + "{\n")
            for i in range(self.size_graphs):
                string2 = str(list(start[(end == i) & (start != end)])).replace('[', '{').replace(']', '}')
                file.write(string2 + ",\n")
            string3 = f"std::vector< std::vector<int> > weights{j}="
            file.write("};\n" + string3 + "{\n")
            for i in range(self.size_graphs):
                string4 = str(list(self.weights[j][(end == i) & (start != end)])).replace('[', '{').replace(']', '}')
                file.write(string4 + ",\n")
        string5 = f"std::vector< std::vector<int> >* arcs[{self.nb_graphs}]="
        file.write("};\n" + string5 + "{\n")
        for i in range(len(self.arcs)):
            string6 = f"&arcs{i},\n"
            file.write(string6)
        string7 = f"std::vector< std::vector<int> >* weights[{self.nb_graphs}]="
        file.write("};\n" + string7 + "{\n")
        for i in range(len(self.arcs)):
            string8 = f"&weights{i},\n"
            file.write(string8)
        file.write('};\n};\n')
        file.close()

    def fibo_heap_printer(self, file_name="include/test_fibo.hpp"):
        pass

    def std_graph_printer(self, file_name="include/test_std_graph.hpp"):
        file = open(file_name, 'w')

        file.write('//This file was compiled by no_unix.py.\n//It contains randomly generated graphs.\n\n#include <vector>\n\nclass test_graphs {\npublic:\n')
        for j in range(len(self.arcs)):
            string = f"int arcs{j}[{self.size_graphs**2}]=" 
            file.write(string + "{\n")
            for i in range(self.size_graphs):
                string2 = str(list(self.arcs[j][i])).replace('[', '').replace(']', '')
                file.write(string2 + ",\n")
            string3 = f"int weights{j}[{self.size_graphs**2}]="
            file.write("};\n" + string3 + "{\n")
            for i in range(self.size_graphs):
                string4 = str(list(self.weights[j][i])).replace('[', '').replace(']', '')
                file.write(string4 + ",\n")
        string5 = f"int[{self.size_graphs**2}]* arcs[{self.nb_graphs}]="
        file.write("};\n" + string5 + "{\n")
        for i in range(len(self.arcs)):
            string6 = f"&arcs{i},\n"
            file.write(string6)
        string7 = f"int[{self.size_graphs**2}]* weights[{self.nb_graphs}]="
        file.write("};\n" + string7 + "{\n")
        for i in range(len(self.arcs)):
            string8 = f"&weights{i},\n"
            file.write(string8)
        file.write('};\n};\n')
        file.close()

if  len(argv) > 3:
    Instance = Graph_gen(int(argv[1]), int(argv[2]))
    Instance.generator()
    Instance.printer_switch(argv[3])
