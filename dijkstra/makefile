CC=g++
CFLAGS= -std=c++17 -Wall -ggdb -Iinclude

src := $(wildcard src/*.cpp)
obj := $(subst src, build, $(src:.cpp=.o))

.PHONY: directories

all: directories project
	@echo $(obj)

project: main.o build
	$(CC) $(CFLAGS) -o project main.o build/*.o
 
main.o: main.cpp $(obj)
	$(CC) $(CFLAGS) -c main.cpp 

build/%.o: src/%.cpp include/%.h
	$(CC) $(CFLAGS) -o $@ -c $<

directories: build
build:
	mkdir -p $@

clean:
	rm -r build
	rm main.o
	rm include/*.gch
