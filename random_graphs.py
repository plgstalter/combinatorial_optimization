import numpy as np
from sys import argv

def random_graph(number_of_graphs, graph_max_nodes=100, density=.6):

    choice_array = np.arange(graph_max_nodes**2)
    for i in range(number_of_graphs):
        np.random.shuffle(choice_array)
        arcs = choice_array[:int(np.floor(density * graph_max_nodes))]
        print(arcs)        

if  len(argv) > 1:
    random_graph(int(argv[1]))
