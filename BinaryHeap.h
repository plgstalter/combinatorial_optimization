#pragma once

class BinaryHeap {
	public:
		int size;
		BinaryHeap(int n);
		int* Heap[];
		int* left(int i);
		int* right(int i);
		int* parent(int i);
		void insert(int i, int j);
		int* extract_min(int i, int j);
		void decrease_key(int i, int j);
		void move_up(int p);
		void move_down(int p);
		void swap(int p, int q);
};
