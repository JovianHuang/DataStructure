#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include "status.h"
#include "Stack.h"
#include "Queue.h"

typedef int ItemType;
typedef int DepthType;
typedef int SignType;

typedef struct BTNode{
  union {
    DepthType depth;
    ItemType item;
  } info;
  SignType sign;
  struct BTNode * LChild;
  struct BTNode * RChild;
} * BiTree;

/* Operation: Create an empty node */
/* Preconditions: None */
/* Postconditions: Create a node that has been allocated memory space and the
    node has been initialized. */
BiTree NewNode(void);

/* Operation: Output the item in the node */
/* Preconditions: Node exists */
/* Postconditions: Output the item and do not change the node */
Status PrintNode(BiTree node);

/* Operation: To judge if this tree/node is existing */
/* Preconditions: None */
/* Postconditions:  If the tree/node does not exist, return FALSE */
Status IsExisting(BiTree BT);







#endif // !BINARYTREE_H
