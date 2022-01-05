import numpy as np
from sys import argv

def random_graph(number_of_graphs, size_nodes, density=.3, max_weight=500):

    res = []
    bis_size = int(density * size_nodes **2)
    arcs_array = np.arange(size_nodes**2)
    weights = (max_weight * np.random.rand(number_of_graphs * bis_size)).astype(int).reshape(number_of_graphs, bis_size)
    
    for i in range(number_of_graphs):
        np.random.shuffle(arcs_array)
        arcs = arcs_array[:int(np.floor(density * size_nodes**2))]
        res.append(arcs)
    return [res, weights]

def decode_graph(Arcs, Weights, size_nodes):
    '''
    put graph in proper arcs form
    '''
    print('#include <vector>\nclass test_graphs {\npublic:')
    for j in range(len(Arcs)):
        start = Arcs[j]//size_nodes
        end = Arcs[j]%size_nodes
        print(f"std::vector< std::vector<int> > arcs{j}=",end='{')
        print()
        for i in range(size_nodes):
            print(list(start[(end == i) & (start != end)]), end=',')
            print()
        print('};')
        print()
        print(f"std::vector< std::vector<int> > weights{j}=",end='{')
        print()
        for i in range(size_nodes):
            print(list(Weights[j][(end == i) & (start != end)]), end=',')
            print()
        print('};')
        print()
        print()
    print("};")

if  len(argv) > 2:
    Arcs, Weights = random_graph(int(argv[1]), int(argv[2]))
    decode_graph(Arcs, Weights, int(argv[2]))
