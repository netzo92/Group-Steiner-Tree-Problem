#include <stdio.h>
#include <stdlib.h>
#include "Group.h"



//constructor
Group::Group(int group_size)
{
    verts = new int[group_size];
    size_ = group_size;
    visited = false;
    iterator_ = -1;
    current_insert_pos = 0;
}


Group::~Group()
{
    if(verts != NULL){
	delete[] verts;
	verts = NULL;
    }
    
}
//used for inserting vertexs into groups
void Group::insertVertex(int new_vert)
{
    if(current_insert_pos < size_){
        verts[current_insert_pos] = new_vert;
        current_insert_pos = current_insert_pos + 1;
    }
}



//iterator functions
void Group::resetIterator(){
    iterator_ = -1;
}

bool Group::isIteratorFinished()
{
    if(iterator_ < current_insert_pos-1)
        return false;
    return true;
}

int Group::advanceIterator()
{
    if(iterator_ < (size_ - 1))
    { 
        iterator_ = iterator_ + 1;
        return verts[iterator_]; 
    }   
    return -1;
}
//end iterator functions

//accessor methods

int Group::getGroupSize()
{
    return size_;
}

bool Group::isReached()
{
    return visited;
}

void Group::setReached()
{
    visited = true;
}
//check whether a group contains a vertex
bool Group::contains(int vertex)
{
    for(int i = 0; i < size_; i++)
    {
	if(verts[i] == vertex)
	    return true;
    }
	return false;
}

















