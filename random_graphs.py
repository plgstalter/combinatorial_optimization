import numpy as np
from sys import argv

def random_graph(number_of_graphs, size_nodes, density=.3):

    res = []
    choice_array = np.arange(size_nodes**2)
    for i in range(number_of_graphs):
        np.random.shuffle(choice_array)
        arcs = choice_array[:int(np.floor(density * size_nodes**2))]
        res.append(arcs)
    return res

def decode_graph(Arcs, size_nodes):
    '''
    put graph in proper arcs form
    '''
    for arcs in Arcs:
        start = arcs//size_nodes
        end = arcs%size_nodes
        print('{')
        for i in range(size_nodes):
            print(start[(end == i) & (start != end)], end=',')
            print()
        print('}')
        print()

if  len(argv) > 2:
    Arcs = random_graph(int(argv[1]), int(argv[2]))
    decode_graph(Arcs, int(argv[2]))
