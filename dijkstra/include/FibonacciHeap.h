#pragma once
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
                void consolidate(node*);
                int link(node*, node*, node*);
        public:
                int number;
                FibonacciHeap();
                node* HH; 
                node* createNode(int);
                node* insert(node*, node *); 
                node* extractMin(node *); 
                int decreaseKey(node *, int, int);
                node* find(node*, int);
                int deleteKey(node*, int);
                void cut(node*, node*, node*);
                int cascade_cut(node*, node*);
};
