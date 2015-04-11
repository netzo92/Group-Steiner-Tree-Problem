#include <stdio.h>
#include <stdlib.h>
#include "Group.h"
#include "GroupContainer.h"



//constructor
GroupContainer::GroupContainer(int number_of_groups)
{
    container = new Group*[number_of_groups];
    size_ = number_of_groups;
    num_touched_ = 0;
    next_insert = 0;
    reached = NULL;
    
}

GroupContainer::~GroupContainer()
{
    if(container != NULL)
    {
	for(int i = 0; i < size_; i++)
	{
	    if(container[i] != NULL){
		delete container[i];
		container[i] = NULL;
	    }
	}
	delete [] container;
	container = NULL;
    }
    
}

void GroupContainer::insertGroup(int group_num, int group_size)
{
    container[group_num] = new Group(group_size);
}

void GroupContainer::insertGroup(int group_num, Group *group){
    container[group_num] = group;
}

int GroupContainer::getSize()
{
    return size_;
}

Group * GroupContainer::getGroup(int group_num)
{
    return container[group_num];
    
}

bool GroupContainer::allReached()
{
    for(int i = 0; i < size_; i++)
    {
	if(container[i]->isReached() == false)
	    return false;
    }
    return true;
}


int GroupContainer::setGroupReached(int group_num)
{
    container[group_num]->setReached();
}

int GroupContainer::num_groups_touched(PathNode* path)
{
    int numberGroupsReached = 0;
    PathNode *n = path;
    bool *GroupArray = new bool[size_];
    int num_initially_touched = 0;
    for(int i = 0; i < size_;i++){
	if(container[i]->isReached() == false)
	    GroupArray[i] = false;
	else{
	    num_initially_touched += 1;
	    GroupArray[i] = true;
	}
    }
    int num_finally_touched = num_initially_touched;
    while(n != NULL){
	for(int i = 0; i < size_; i++){
	    if(GroupArray[i] == false)
		if(container[i]->contains(n->vert))
		{
		    num_finally_touched += 1;
		    GroupArray[i] = true;
		}
	}
	n = n->next;
    }
    delete GroupArray;
    
    return num_finally_touched-num_initially_touched;
}
void GroupContainer::printReached()
{
    if(reached != NULL)
    {
	for(int z = 0; z < size_; z++)
	    if(reached[z] == true)
		printf("%d\n",z);
    }
    else return
	
    delete reached;
    reached = NULL;
}

void GroupContainer::updateReached(int vertex)
{	
    reached = new bool[size_];
    for(int y = 0; y <size_; y++)
	reached[y] = false;
    
    for(int i = 0; i < size_; i++)
    {	
	if(container[i]->isReached() == false)
	    if(container[i]->contains(vertex)){
		container[i]->setReached();
		num_touched_ = num_touched_+1;
		reached[i] = true;
	    }
    }
}

void GroupContainer::updateReached(PathNode *path)
{   
    reached = new bool[size_];
    for(int y = 0; y <size_; y++)
	reached[y] = false;
    PathNode *n = path;
    while( n != NULL)
    {
	for(int i = 0; i < size_; i++){	
	    if(container[i]->isReached() == false)
		if(container[i]->contains(n->vert)){
		    container[i]->setReached();
		    num_touched_ = num_touched_+1;
		    reached[i] = true;
		}
	}
	n = n->next;
    }
}











