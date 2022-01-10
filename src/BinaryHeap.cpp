#include <math.h>
#include <vector>

class BinaryHeap {
	public:
		int size;
		int L = 0;
		int res[2];
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

BinaryHeap::BinaryHeap(int n){ 
	size = n;
	int *Heap[2 * size]; // first size elements are Heap, next are Heaps
};

void BinaryHeap::Heap_builder(int* V[]) {
	for (int i = 0; i < size; i++) {
		*Heap[i] = i;
		*Heap[size + i] = *V[i];
	}
	for (int k = floor(size/2); k > 0; k--) {
		move_down(k);
	}
}

int BinaryHeap::left(int i){
	return 2 * i;
}

int BinaryHeap::right(int i){
	return 2 * i + 1;
}

int BinaryHeap::parent(int i){
	return i % 2;
}

void BinaryHeap::insert(int i, int v){
	L++;
	*Heap[L] = i;
	*Heap[size + L] = i;
	*Heap[i] = L;
	move_up(L);
}

int* BinaryHeap::extract_min() {
	res[0] = *Heap[0];
       	res[1] = *Heap[size + 0];
	int *pres = res;
	*Heap[ *pres ] = -1;
	L--;
	move_down(0);
	return pres;
}

void BinaryHeap::decrease_key(int i, int v) {
	int p = *Heap[i];
	*Heap[size + p] = v;
	move_up(p);
}

void BinaryHeap::move_up(int p) {
	bool stop = false;
	int q;
	while (p != 1 && !stop) {
		q = parent(p);
		if (*Heap[size + q] > *Heap[size + p]) {
			swap(p, q);
		} else {
			stop = true;
		}
	}
}

void BinaryHeap::move_down(int p) {
	bool stop = false;
	int q;
	while (left(p) <= L && !stop) {
		if (right(p) > L || *Heap[size + left(p)] < *Heap[size + right(p)]) {
			q = left(p);
		} else {
			q = right(p);
		}
		if (*Heap[size + p] > *Heap[size + q]) {
			swap(p, q);
		} else {
			stop = false;
		}
	}
}

void BinaryHeap::swap(int p, int q) {
	int r = *Heap[size + p];
	*Heap[size + p] = *Heap[size + q];
	*Heap[size + q] = r;
	int k = *Heap[p];
	*Heap[p] = *Heap[q];
	*Heap[q] = k;
}
