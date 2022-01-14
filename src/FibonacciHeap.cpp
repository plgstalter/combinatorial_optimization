#include <math.h>
#include <iostream>

struct node {
	int n;
	int degree;
	node* parent;
	node* child;
	node* left;
	node* right;
	char mark;
	char C;
};

class FibonacciHeap {
	
	private:
		int number;
		node* HH;
		void consolidate(node*);
	public:
		FibonacciHeap();
		void link(node*, node*, node*);
		node* createNode(int);
		node* insert(node*, node *);
		node* extractMin(node *);
		int decreaseKey(node *, int, int);
		node* find(node*, int);
		int deleteKey(node*, int);
		void cut(node*, node*, node*);
		void cascade_cut(node*, node*);
};

FibonacciHeap::FibonacciHeap() {
	HH = NULL;
}

node* FibonacciHeap::createNode(int value) {
	node* x = new node;
	x->n = value;
	return x;
}

node* FibonacciHeap::insert(node* a, node* b) {
	b->degree = 0;
	b->parent = NULL;
	b->child = NULL;
	b->left  = b;
	b-> right = b;
	b->mark = 'F';
	b->C = 'N';
	if (a != NULL) {
		(a->left)->right = b;
		b->right = a;
		b-> left = a->left;
		a->left = b;
		if (b->n < a->n) {
			a = b;
		}
	} else {
		a = b;
	}
	number++;
	return a;
}

node* FibonacciHeap::extractMin(node* H) {
	if (H == NULL) {
		return H;
	}
	node* p;
	node* ptr;
	node* z = H;
	p = z;
	ptr = z;
	node* x = z->child;
	node* np;
	if (x != NULL) {
		ptr = x;
		while (np != ptr) {
			np = x->right;
			(H->left)->right = x;
			x->right = H;
			x->left = H->left;
			H->left = x;
			if (x-> n < H->n) {
				H = x;
			}
			x->parent = NULL;
			x = np;
		}		
	}
	(z->left)->right = z->right;
	(z->right)->left = z->left;
	H = z->right;
	if (z == z->right && z->child == NULL) {
		H = NULL;
	} else {
		H = z-> right;
		consolidate(H);
	}
	number++;
	return p;
}

void FibonacciHeap::consolidate(node* H) {
	int d, i;
	float f = (log(number)) / log(2);
	int D = f;
	node* A[D];
	for (i=0; i<=D; i++) {
		A[i] = NULL;
	}
	node* x = H;
	node* y;
	node* np;
	node* pt = x;
	while (x != H) {
		pt = pt->right;
		d = x->degree;
		while (A[d] != NULL) {
			y = A[d];
			if (x-> n > y->n) {
				np = x;
				x = y;
				y = np;
			}
			if (y == H) {
				H = x;
			}
			link(H, y, x);
			if (x-> right == x) {
				H = x;
				A[d] = NULL;
			}
			d++;
		}
		A[d] = x;
		x = x->right;
	}
	HH = NULL;
	for (int i=0; i<=D; i++) {
		if (A[i] != NULL) {
			A[i]->left = A[i];
			A[i]->right = A[i];
				if (HH != NULL) {
					(HH->left)->right = A[i];
					A[i]->right = HH;
					A[i]->left = HH->left;
					HH->left = A[i];
					if (A[i]->n < H->n) {
						HH = A[i];
					}
				} else {
					HH = A[i];
				}
				if (HH == NULL || (A[i]->n < HH->n)) {
					HH = A[i];
				}
		}
	}
}

int FibonacciHeap::decreaseKey(node* H, int x, int k) {
	node* y;
	if (H == NULL) {
		return 0;
	}
	node* ptr = find(H, x);
	if (ptr == NULL) {
		return 1;
	}
	if (ptr->n < k) {
		return 0;
	}
	ptr->n = k;
	y = ptr->parent;
	if (y != NULL && ptr->n < y->n) {
		cut(H, ptr, y);
		cascade_cut(H, y);
	}
	if (ptr->n < HH->n) {
		HH = ptr;
	}
	return 0;
}

void FibonacciHeap::cut(node* H, node* x, node* y) {
	if (x == x->right) {
		y->child = NULL;
	}
	(x->left)->right = x->right;
	(x->right)->left = x->left;
	if (x == y->child) {
		y->child = x->right;
	}
	(y->degree)--;
	x->right = x;
	x->left = x;
	(H->left)->right = x;
	x->right = H;
	x->left = H->left;
	H->left = x;
	x->parent = NULL;
	x->mark = 'F';
}

void FibonacciHeap::cascade_cut(node* a, node* b) {
	node* z = b->parent;
	if (z != NULL) {
		if (b->mark == 'F') {
			b->mark = 'T';
		} else {
			cut(a, b, z);
			cascade_cut(a, z);
		}
	}
}

node* FibonacciHeap::find(node* H, int k) {
	node* x = H;
	x->C = 'Y';
	node* p = NULL;
	if (x->n == k) {
		p = x;
		x->C = 'N';
		return p;
	}
	if (p == NULL && (x->child != NULL || (x->right)->C != 'Y')) {
		p = find(x->right, k);
	}
	x->C = 'N';
	return p;
}

void FibonacciHeap::link(node* a, node* b, node* c) {
	(b->left)->right = b->right;
	(b->right)->left = b->left;
	if (c->right == c) {
		a = c;
	}
	b->left = b;
	b->right = b;
	b->parent = c;
	if (c->child == NULL) {
		c->child = b;
	}
	b->right = c->right;
	b->left = (c->child)->left;
	((c->child)->left)->right = b;
	(c->child)->left = b;
	if (b->n < (c->child)->n) {
		c->child = b;
	}
	(c->degree)++;
}


int FibonacciHeap::deleteKey(node* H, int k) {
	node* np = NULL;
	int t;
	t = decreaseKey(H, k, -5000);
	if (!t) {
		np = extractMin(HH);
	}
	return 0;
}
