#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"


Graph::Graph()
{
    edgeList = NULL;
    listSize = 0;
}

Graph::Graph(int initial_size)
{
    edgeList = new EdgeNode*[initial_size];
    listSize = initial_size;
    for(int i; i < initial_size; i++)
    {
        edgeList[i] = NULL;
    }
}

Graph::~Graph()
{
    if(edgeList != NULL){
	EdgeNode *n = NULL;
	EdgeNode *ln1 = NULL;
	for(int i = 0; i < listSize; i++)
	{
	    n = edgeList[i];
	    while(n != NULL)
	    {
		ln1 = n;
		n = n->next;
		delete ln1;
	    }
	}
	delete [] edgeList;
    }

}

bool Graph::insertEdge(int vert1, int vert2, int edgeWeight)
{
    int tmpNode;
    EdgeNode *n1 = edgeList[vert1];
    EdgeNode *n2 = edgeList[vert2];
    EdgeNode *ln1 = NULL , *ln2 = NULL;

    if(n1 == NULL)
        edgeList[vert1] = new EdgeNode(vert2, edgeWeight);
    else{
        EdgeNode *ln1 = NULL;
        while (n1 != NULL){
            if(n1->dest_vert == vert2)
                return false;
            ln1 = n1;
            n1 = n1->next;     
        }
        ln1->next = new EdgeNode(vert2, edgeWeight);
    }
    
    if(n2 == NULL)
        edgeList[vert2] = new EdgeNode(vert1, edgeWeight);
    else{
        EdgeNode *ln2 = NULL;
        while(n2 != NULL){
            if(n2->dest_vert == vert1)
                return false;
            ln2 = n2;
            n2 = n2->next;        
        }
        ln2->next = new EdgeNode(vert1, edgeWeight);
    }
    return true;
}

int Graph::getEdgeCost(int vert1, int vert2){
    EdgeNode *n = edgeList[vert1];
    if(n != NULL){
        while(n != NULL){
            if(n->dest_vert == vert2)
                return n->weight;
            n = n->next;        
        }
    }
    return -1;
}

bool Graph::deleteEdge(int vert1, int vert2){
    
    EdgeNode *n = edgeList[vert1];
    EdgeNode *lagging_pntr = NULL;
    bool firstEdgeFound = false;
    while(n != NULL)
    {   
        if(n->dest_vert == vert2)
        {
            if(lagging_pntr == NULL)
                edgeList[vert1] = n->next;
            else
                lagging_pntr->next = n->next;
            delete n;
            firstEdgeFound = true;
            break;
        }
        lagging_pntr = n;
        n = n->next;
    }
    if(firstEdgeFound == true)
    {
        n = edgeList[vert2];
        lagging_pntr = NULL;
        while(n != NULL)
        {
            if(n->dest_vert == vert1)
            {
                if(lagging_pntr == NULL)
                    edgeList[vert2] = n->next;
                else 
                    lagging_pntr->next = n->next;
                delete n;
                return true;
            }
            lagging_pntr = n;
            n = n->next;
        }
    }
    return false;
}

int Graph::getSize()
{
    return listSize;
}

EdgeNode* Graph::getAdjList(int vertex)
{
    return edgeList[vertex]; 
}
