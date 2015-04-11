#include <stdio.h>
#include <stdlib.h>
#include "PathNode.h"

PathNode::PathNode(int vertex){
    vert = vertex;   
    next = NULL;
    seen = false;
    p_len = 0;
    p_cost = 0;
}

PathNode::PathNode(int vertex, int edge_cost, PathNode *vPtr){
    vert = vertex;
    next = vPtr;
    seen = false;
    if(next == NULL){
        p_cost = 0;
        p_len = 0;
    }
    else{
        p_cost = next->p_cost + edge_cost;
        p_len = next->p_len + 1;
    }
}



bool PathNode::is_lexicographic(PathNode *node2){
    
    PathNode *n1 = this;
    PathNode *n2 = node2;

    while(n1 != NULL && n2 != NULL)
    {
        if(n1->vert < n2->vert)
            return true;
        else if (n1->vert == n2->vert)
        {
                n1 = n1->next;
                n2 = n2->next;
        }
        else if(n1->vert > n2->vert)
            return false;
    }

    if(n1 == NULL && n2 == NULL)
        return false;
    else if(n1 != NULL)
        return false;
    else if(n2 != NULL)
        return true;
}
void PathNode::printPath()
{
    printf("PathCost: %d Path_Len: %d\n",p_cost,p_len);
    PathNode *n = this;
    while (n != NULL)
    {
	printf("%d -> ",n->vert);
	n = n->next;
    }
    printf("\n");
}
