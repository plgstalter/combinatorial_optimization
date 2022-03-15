.PHONY: directories

all: project

project: main.o kruskal.o
	gcc -o project main.o kruskal.o

main.o: main.c kruskal.h
	gcc -c main.c

kruskal.o: kruskal.c
	gcc -c kruskal.c

clean:
	rm *.o
	rm project
