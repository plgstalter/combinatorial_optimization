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
                int number;
                node* HH; 
                void consolidate(node*);
        public:
                FibonacciHeap();
                int link(node*, node*, node*);
                node* createNode(int);
                node* insert(node*, node *); 
                node* extractMin(node *); 
                int decreaseKey(node *, int, int);
                node* find(node*, int);
                int deleteKey(node*, int);
                void cut(node*, node*, node*);
                int cascade_cut(node*, node*);
};
