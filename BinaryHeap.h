#pragma once
#include <vector>
#include <math.h>

class BinaryHeap {
	public:
		int size;
		int L = 0;
		BinaryHeap(int n);
		void Heap_builder(int* V[]);
		int left(int i);
		int right(int i);
		int parent(int i);
		void insert(int i, int v);
		int* extract_min();
		void decrease_key(int i, int v);
		void move_up(int p);
		void move_down(int p);
		void swap(int p, int q);
		int* Heap[];
};
