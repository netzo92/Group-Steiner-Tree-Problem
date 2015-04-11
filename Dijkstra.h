#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "PathNode.h"
#include "Graph.h"

class Dijkstra {
    private:
        PathNode **p_array;
        int num_nodes;
        int start_node;
    public:
	Dijkstra();
        Dijkstra(int ,int );
        ~Dijkstra();
	void runOpenShortestPath(Graph *);
	PathNode * getPathToVertex(int );
        void checkResult();

};
#endif

