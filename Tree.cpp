#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
#include "PathNode.h"
#include <cmath>

Tree::Tree(int i_root,int max_size)
{
	array = new int[max_size];
    tree_max_size = max_size;
    cost = 0;
    root = i_root;
	for(int i = 0; i < tree_max_size; i++)
		array[i] = -1;
    array[root] = 1;
    tree_current_size = 1;
    //Last index of iterator
    iterator = -1;
    last_ = root;
}

Tree::~Tree()
{
    delete [] array;
}
	
void Tree::insertEdge(int v1, int v2, int edge_cost)
{
        int max_edge;
        if( v1 > v2)
            max_edge = v1;
        else
            max_edge = v2;

        if(max_edge > last_)
            last_ = max_edge;
        
        if(array[v1] < 0){
            array[v1] = 1;
            tree_current_size += 1;        
        }
        if(array[v2] < 0){
            array[v2] = 1;
            tree_current_size += 1;
        }
        cost = cost + edge_cost;
}

void Tree::printVertices()
{
    
    for(int i = 0; i <= last_; i++)
    {
        if(array[i] > 0)
            printf("%d\n",i);
    }
}

void Tree::reset_iter()
{
    iterator = -1;
}

int Tree::next_vertex()
{
    while(iterator < tree_max_size - 1 )
    {    
        iterator = iterator + 1;
        if(array[iterator] > 0)
            return iterator;
    }
    return -1;
}

bool Tree::iter_not_finished()
{
    if(iterator < tree_max_size - 1 && iterator < last_)
        return true;
    else
        return false;

}
void Tree::printCost()
{
    printf("%d\n",cost);

}
int Tree::getCost()
{
    return cost;
}

void Tree::incrementCost(int inc_val)
{
   
    cost = cost + inc_val;
}

void Tree::addPath(PathNode *path)
{

	PathNode *n = path;
	int path_cost = path->p_cost;
	incrementCost(path_cost);
	
	while(n->next!= NULL){
		insertEdge(n->vert, n->next->vert, 0);
		n = n->next;
	}
}
