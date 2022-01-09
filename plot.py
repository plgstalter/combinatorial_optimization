import numpy as np
import matplotlib.pyplot as plt

def generate_plot(graph):
    size_graph = len(graph)
    positions = 150 * np.random.rand(size_graph*2).reshape(2, size_graph)
    return positions

def plot(positions, dijkstra_res):
    for i in range(len(dijkstra_res)):
        plt.plot([positions[0][i], positions[0][dijkstra_res[i]]], [positions[1][i], positions[1][dijkstra_res[i]]], 'b')

def graph_reader(filename):
    file = open(filename, 'r')
    lines = file.readlines()
    file.close()
    res = []
    for line in lines:
        bis = line.split(' ')[:-1]
        bis = np.array(bis, dtype=int)
        res.append(bis)
    return res 

result = graph_reader('res.txt')
positions = generate_plot(np.ones(100))
plt.figure();
plt.scatter(positions[0], positions[1])
plot(positions, result[0]) 
plt.show()
