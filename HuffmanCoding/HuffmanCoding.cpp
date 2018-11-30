#include <stdio.h>
#include <stdlib.h>
#include "HuffmanCoding.h"

/* local data type */


/* prototype for local functions */
static Trnode * MakeNode(const ItemType * pitem);
static void DeleteAllNode(Trnode * root);

/* function definition */
void InitializeTree(Tree * ptree) {
  ptree->root = NULL;
  ptree->size = 0;
}

Status TreeIsEmpty(const Tree * ptree) {
  if (ptree->root == NULL) {
    return TRUE;
  } else {
    return FALSE;
  }
}

Status TreeIsFull(const Tree * ptree) {
  if (ptree->size == MAXITEMS) {
    return TRUE;
  } else {
    return FALSE;
  }
}

SizeType TreeItemCount(const Tree * ptree) {
  return ptree->size;
}

Status AddItem(const ItemType * pitem, Tree * ptree) {
  Trnode * new_node;
  if (TreeIsFull(ptree)) {
    fprintf(stderr, "Tree is full.\n");
    return FALSE;
  }
  
  new_node = MakeNode(pitem);
  if (new_node == NULL) {
    fprintf(stderr, "Couldn't create node.\n");
    return FALSE;
  }
  // succeeded in creating a new node
  ptree->size++;
  if (ptree->root == NULL) { // case 1: tree is empty
    ptree->root = new_node; // new node is tree root
  } else {  // case 2: not empty
    // AddNode(); // add node to tree
  }
  return TRUE;
}


/* local functions */

static Trnode * MakeNode(const ItemType * pitem) {
  Trnode * new_node;
  new_node = (Trnode *)malloc(sizeof(Trnode));
  if (new_node != NULL) {
    new_node->item = *pitem;
    new_node->left = NULL;
    new_node->right = NULL;
  }
  return new_node;
}

static void DeleteAllNode(Trnode * root) {
  Trnode * pright;
  if (root != NULL) {
    pright = root->right;
    DeleteAllNode(root->left);
    free(root);
    DeleteAllNode(pright);
  }
}



//static void InOrder(const Trnode * root) {
//  if (root) {
//    InOrder(root->left);
//    
//  }
//}
