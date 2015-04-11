#ifndef GROUP_H
#define GROUP_H

#include <stdlib.h>
#include <stdio.h>

class Group {
    private:
 	int *verts;
        bool visited;
	    int size_;
        int iterator_;
        int current_insert_pos;
	public:
        Group(int );
	    ~Group();
        void insertVertex(int );
        void resetIterator();
        bool isIteratorFinished();
        int advanceIterator();
        int getGroupSize();
        bool isReached();
        void setReached();
	    bool contains(int );
};
#endif
