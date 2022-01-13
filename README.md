# combinatorial_optimization

School project for the class "Combinatorial Optimization" at the University of Milan.

## Goal

Implementing Dijkstra's algorithm on different data structures so as to compare experimental complexity. Thus, it will be compared to theoretical complexity.

### Random Graphs generator

To best test the algorithm's implementation, it will run on lots of graphs, randomly generated. Speed doesn't matter as much for these graphs, so they'll be computed in `Python`, using `numpy`.

On Unix: To compute `n` graphs of `m` nodes, type:

	python fast_generators n m graph

	python fast_generators n m std

The graphs will be stored in the file `include/test_graphs.hpp` and `include/test_std_graphs.hpp`, directly readable `C++` code. 

For now, the algorithm runs on these two data structures. Fibonacci heap support is in the books.

### Running Dijkstra

Once random graphs are generated, run:

	make

And finally

	./project a b

Will output the result of running Dijkstra on graph n°`a` starting from vertex `b`. Make sure that `a<n` and `b<m`.

Here is an example of graph generator use:

![timing python](ressources/capture.png)

Less than 2 seconds for creating a file with 50 instances of graphs composed of 200 nodes.

## ToDo

Implement other algorithms as well as dijkstra's to enrich the project.

### Results

Here is the evolution of computational time for Dijkstra's on the structure "Graph":

![dijkstra_graph](ressources/dijkstra_res_graph.png)

Run on graphs of 10 to 400 nodes, at a given density.

And with different densities of arcs:

![variable_density](ressources/dijkstra_res_graph_density.png)
