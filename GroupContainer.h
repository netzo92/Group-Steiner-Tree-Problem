#ifndef GROUP_CONTAINER_H
#define GROUP_CONTAINER_H

#include <stdlib.h>
#include <stdio.h>
#include "Group.h"
#include "PathNode.h"

class GroupContainer {
    private:
	Group **container;
	int next_insert;
        int size_;
	int num_touched_;
	bool *reached;
    public:
        GroupContainer(int );
	~GroupContainer();
	void insertGroup(int , int);
	void insertGroup(int, Group*);
	int getSize();
	Group * getGroup(int );
	bool allReached();
	int setGroupReached(int );
	int num_groups_touched(PathNode *);
	void printReached();
	void updateReached(int );
	void updateReached(PathNode *);

};
#endif
