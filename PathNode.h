#ifndef PATHNODE_H
#define PATHNODE_H

class PathNode {   
    public:
	    int vert;
	    PathNode *next;
        int p_len;
        int p_cost;
        bool seen;

        PathNode(int );
        PathNode(int ,int ,PathNode *);
	void fillPath(int *, int);
        bool is_lexicographic(PathNode *);
	void printPath();

        
};

#endif

