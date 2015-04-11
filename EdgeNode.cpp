#include <stdio.h>
#include <stdlib.h>
#include "EdgeNode.h"

EdgeNode::EdgeNode(int d_vert, int edge_weight)
{
    dest_vert = d_vert;
    weight = edge_weight;
    next = NULL;
}
