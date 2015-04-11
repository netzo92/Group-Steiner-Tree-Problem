#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>
#include "PathNode.h"


class Tree {
	private:
	    int *array;
        int tree_max_size;
	    int cost;
        int root;
	    int tree_size;
	    int iterator;
        int tree_current_size;
        int last_;
	public:
	    Tree(int ,int);
        ~Tree();
        void insertEdge(int ,int ,int);
        void printVertices();
        void reset_iter();
        int next_vertex();
        bool iter_not_finished();
        void printCost();
        int getCost();
        void incrementCost(int );
	void addPath(PathNode *);
	
	
};
#endif
