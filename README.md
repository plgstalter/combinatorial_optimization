# combinatorial_optimization

School project for the class "Combinatorial Optimization" at the University of Milan.

## Goal

Implementing Dijkstra's algorithm on different data structures so as to compare experimental complexity. Thus, it will be compared to theoretical complexity.

### Random Graphs generator

To best test the algorithm's implementation, it will run on lots of graphs, randomly generated. Speed doesn't matter as much for these graphs, so they'll be computed in `Python`, using `numpy`.

To compute `n` graphs of `m` nodes, type:

	python random_graphs.py n m | tr '[' '{' | tr ']' '}' > graphs.txt

The graphs will be stored in the file `graphs.txt` in such a form that is easily readable by `C++` code.

__Remark:__ The pipes after the python call require a Unix system. On Windows, find another way to change the '[]' into '{}'.
