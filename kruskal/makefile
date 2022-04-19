.PHONY: directories

all: project

project: main.o kruskal.o
	g++ -o project main.o kruskal.o

main.o: main.cpp kruskal.h
	g++ -c main.cpp

kruskal.o: kruskal.cpp
	g++ -c kruskal.cpp

clean:
	rm *.o
	rm project
