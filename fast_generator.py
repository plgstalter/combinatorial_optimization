from sys import argv
import numpy as np

class Graph_gen():

    def __init__(self, nb_graphs, size_graphs, max_weight=500, density=.3):
        self.nb_graphs = nb_graphs
        self.size_graphs = size_graphs
        self.max_weight = max_weight
        self.density = density

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
        Arcs = []
        bis_size = int(self.density * self.size_graphs **2)
        arcs_array = np.arange(self.size_graphs**2)
        Weights = (self.max_weight * np.random.rand(self.nb_graphs * bis_size)).astype(int).reshape(self.nb_graphs, bis_size)
        
        for i in range(self.nb_graphs):
            np.random.shuffle(arcs_array)
            arcs = arcs_array[:int(np.floor(self.density * self.size_graphs**2))]
            Arcs.append(arcs)

        file = open(file_name, 'w')

        file.write('//This file was compiled by fast_generator.py.\n//It contains randomly generated graphs.\n\n#include <vector>\n\nclass test_graphs {\npublic:\n')
        for j in range(len(Arcs)):
            start = Arcs[j]//self.size_graphs
            end = Arcs[j]%self.size_graphs
            string = f"std::vector< std::vector<int> > arcs{j}=" 
            file.write(string + "{\n")
            for i in range(self.size_graphs):
                string2 = str(list(start[(end == i) & (start != end)])).replace('[', '{').replace(']', '}')
                file.write(string2 + ",\n")
            string3 = f"std::vector< std::vector<int> > weights{j}="
            file.write("};\n" + string3 + "{\n")
            for i in range(self.size_graphs):
                string4 = str(list(Weights[j][(end == i) & (start != end)])).replace('[', '{').replace(']', '}')
                file.write(string4 + ",\n")
            file.write("};\n")
        string5 = f"std::vector< std::vector<int> >* arcs[{self.nb_graphs}]="
        file.write(string5 + "{\n")
        for i in range(len(Arcs)):
            string6 = f"&arcs{i},\n"
            file.write(string6)
        string7 = f"std::vector< std::vector<int> >* weights[{self.nb_graphs}]="
        file.write("};\n" + string7 + "{\n")
        for i in range(len(Arcs)):
            string8 = f"&weights{i},\n"
            file.write(string8)
        file.write('};\n};\n')
        file.close()

    def fibo_heap_printer(self, file_name="include/test_fibo.hpp"):
        pass

    def std_graph_printer(self, file_name="include/test_std_graphs.hpp"):
        file = open(file_name, 'w')

        file.write('//This file was compiled by fast_generator.py.\n//It contains randomly generated graphs.\n\n#include <vector>\n\nclass test_std_graphs {\npublic:\n')
        for j in range(len(self.arcs)):
            string = f"std::vector<int> arcs{j}=" 
            file.write(string + "{\n")
            for i in range(self.size_graphs):
                string2 = str(list(self.arcs[j][i])).replace('[', '').replace(']', '')
                file.write(string2 + ",\n")
            string3 = f"std::vector<int> weights{j}="
            file.write("};\n" + string3 + "{\n")
            for i in range(self.size_graphs):
                string4 = str(list(self.weights[j][i])).replace('[', '').replace(']', '')
                file.write(string4 + ",\n")
            file.write("};\n")
        string5 = f"std::vector<int>* arcs[{self.nb_graphs}]="
        file.write(string5 + "{\n")
        for i in range(len(self.arcs)):
            string6 = f"&arcs{i},\n"
            file.write(string6)
        string7 = f"std::vector<int>* weights[{self.nb_graphs}]="
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
