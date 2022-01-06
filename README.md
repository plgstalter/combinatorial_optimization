# combinatorial_optimization

School project for the class "Combinatorial Optimization" at the University of Milan.

## Goal

Implementing Dijkstra's algorithm on different data structures so as to compare experimental complexity. Thus, it will be compared to theoretical complexity.

### Random Graphs generator

To best test the algorithm's implementation, it will run on lots of graphs, randomly generated. Speed doesn't matter as much for these graphs, so they'll be computed in `Python`, using `numpy`.

On Unix: To compute `n` graphs of `m` nodes, type:

	python random_graphs.py n m | tr '[' '{' | tr ']' '}' | tr '@' '[' | tr '%' ']' > test_graphs.hpp

On Windows (or if you don't like pipes) run that instead:

	python no_unix.py n m

The graphs will be stored in the file `test_graphs.hpp`, directly readable `C++` code. Then, run

### Running Dijkstra

Once random graphs are generated, run:

	make

And finally

	./main a b

Will output the result of running Dijkstra on graph n°`a` starting from vertex `b`. Make sure that `a<n` and `b<m`.

Here is an example of graph generator use:

![timing python](ressources/capture.png)

So generating 100 graphs of 400 nodes (and 48K edges) took about 25s using full `Python` and 40s with `Python` and `bash` (that needs be optimized...).
