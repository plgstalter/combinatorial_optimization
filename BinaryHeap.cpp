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

BinaryHeap::BinaryHeap(int n){ 
	size = n;
	int* Heap[size];
}

int* BinaryHeap::left(int i){
	return Heap[0];
}

int* BinaryHeap::right(int i){
	return Heap[0];
}

int* BinaryHeap::parent(int i){
	return Heap[0];
}

void BinaryHeap::insert(int i, int j){
	// todo
}

int* BinaryHeap::extract_min(int i, int j){
	return Heap[0];
}

void BinaryHeap::decrease_key(int i, int j) {
	// todo
}

void BinaryHeap::move_up(int i, int j) {
	// todo
}

void BinaryHeap::move_down(int i, int j) {
	// todo
}

void BinaryHeap::swap(int p, int q) {
	// todo
}
