#include <stdlib.h>
#include <iostream>
#include "Dijkstra.h"

Dijkstra::Dijkstra()
{
    p_array = NULL;
    
}
Dijkstra::Dijkstra(int starting_vert, int number_nodes){
    p_array = new PathNode*[number_nodes];
    num_nodes = number_nodes;
    start_node = starting_vert;
    for(int i = 0; i < num_nodes; i++){
	    p_array[i] = NULL;
    }
    
}

Dijkstra::~Dijkstra(){
    if(p_array != NULL)
    {
	for(int i = 0; i < num_nodes; i++)
	{
		delete p_array[i];
	}
	delete [] p_array;
    }
}


void Dijkstra::checkResult()
{
    PathNode *tmp = NULL;
    for(int i = 0; i < num_nodes; i++)
    {
        tmp = p_array[i];
        printf("Node: %d p_len: %d p_cost: %d\n",tmp->vert, tmp->p_len, tmp->p_cost);
    }
}
PathNode * Dijkstra::getPathToVertex(int destination_vertex)
{
    return p_array[destination_vertex];
}

void Dijkstra::runOpenShortestPath(Graph *myGraph)
{
    int current_node = start_node;
    int unseen_nodes = num_nodes;
    int *seenArray = new int[num_nodes];
    int seenIncrementor = 0;  
    
    do{
	if(p_array[current_node] == NULL){
	    p_array[current_node] = new PathNode(start_node);
	    p_array[current_node]->seen = true;
	}
	else
	    p_array[current_node]->seen = true;
	
	seenArray[seenIncrementor] = current_node;
	seenIncrementor += 1;
	int minEdgeCost, minVert1, minVert2;
	minEdgeCost = 10000;
	//Find minimum adjacent edge to all seen edges
	for(int i = 0; i < seenIncrementor; i++){
	    int seenVertex = seenArray[i];
	    EdgeNode *n = myGraph->getAdjList(seenVertex);
	    while(n != NULL){
		if(p_array[n->dest_vert] == NULL)
		    p_array[n->dest_vert] = new PathNode(n->dest_vert, n->weight,p_array[seenVertex]);
		else if(p_array[seenVertex]->p_cost + n->weight < p_array[n->dest_vert]->p_cost){
		    p_array[n->dest_vert]->next = p_array[seenVertex];
		    p_array[n->dest_vert]->p_cost = p_array[seenVertex]->p_cost + n->weight;
		    p_array[n->dest_vert]->p_len = p_array[seenVertex]->p_len + 1;
		}
		else if((p_array[seenVertex]->p_cost + n->weight) == (p_array[n->dest_vert]->p_cost)){
		    if(p_array[seenVertex]->is_lexicographic(p_array[n->dest_vert]->next)){
			    p_array[n->dest_vert]->next = p_array[seenVertex];
			    p_array[n->dest_vert]->p_len = p_array[seenVertex]->p_len + 1;
		    }	
		}
		
		if(p_array[n->dest_vert]->seen == false && n->weight < minEdgeCost){
		    minEdgeCost = n->weight;
		    minVert1 = seenVertex;
		    minVert2 = n->dest_vert;
		}
		n = n->next;
	    }
	}
	current_node = minVert2;	
    }while(seenIncrementor < num_nodes);

    delete [] seenArray;
    
}
