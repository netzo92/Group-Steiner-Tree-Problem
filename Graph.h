#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <stdio.h>

#include "EdgeNode.h"

class Graph {
    private:
        EdgeNode **edgeList;
        int listSize;
    
        
	public:
        Graph();
        Graph(int );
	~Graph();
        bool insertEdge(int ,int , int);
        bool deleteEdge(int ,int);
        int getEdgeCost(int, int);
        int getSize();
        EdgeNode* getAdjList(int );
  
};
#endif
