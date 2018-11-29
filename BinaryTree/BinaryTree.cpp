#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

/* local data type */
typedef struct pair {
  Trnode * parent;
  Trnode * child;
} Pair;

/* prototype for local functions*/
static Trnode * MakeNode(const ItemType * pi);
static Status ToLeft(const ItemType * i1, const ItemType * i2);
static Status ToRight(const ItemType * i1, const ItemType * i2);
static void AddNode(Trnode * new_node, Trnode * root);
static void InOrder(const Trnode * root, void (* pfun)(ItemType item));
static Pair SeekItem(const ItemType * pi, const Tree * ptree);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNode(Trnode * ptr);

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

Status AddItem(const ItemType *pi, Tree * ptree) {
  Trnode * new_node;
  if (TreeIsFull(ptree)) {
    fprintf(stderr, "Tree is full\n");
    return FALSE;
  }
  if (SeekItem(pi, ptree).child != NULL) {
    fprintf(stderr, "Attempted to add duplicate item\n");
    return FALSE;
  }
  new_node = MakeNode(pi);
  if (new_node == NULL) {
    fprintf(stderr, "Couldn't create node\n");
    return FALSE;
  }
  // succeeded in creating a new node
  ptree->size++;
  if (ptree->root == NULL) {  // case 1: tree is empty
    ptree->root = new_node;   // new node is tree root
  } else {  // case 2: not empty
    AddNode(new_node, ptree->root); // add node to tree
  }
  return TRUE;
}

Status InTree(const ItemType * pi, const Tree * ptree) {
  return (SeekItem(pi, ptree).child == NULL) ? FALSE : TRUE;
}

Status DeleteItem(const ItemType * pi, Tree * ptree) {
  Pair look;
  look = SeekItem(pi, ptree);
  if (look.child == NULL) {
    return FALSE;
  }
  if (look.parent == NULL) {  // delete root item
    DeleteNode(&ptree->root);
  } else if (look.parent->left == look.child) {
    DeleteNode(&look.parent->left);
  } else {
    DeleteNode(&look.parent->right);
  }
  ptree->size--;
  return TRUE;
}

void Traverse(const Tree * ptree, void(*pfun)(ItemType item)) {
  if (ptree != NULL) {
    InOrder(ptree->root, pfun);
  }
}

void DeleteAll(Tree * ptree) {
  if (ptree != NULL) {
    DeleteAllNode(ptree->root);
  }
  ptree->root = NULL;
  ptree->size = 0;
}

/* local functions */
static Trnode * MakeNode(const ItemType * pi) {
  Trnode * new_node;
  new_node = (Trnode *)malloc(sizeof(Trnode));
  if (new_node != NULL) {
    new_node->item = *pi;
    new_node->left = NULL;
    new_node->right = NULL;
  }
  return new_node;
}

static Status ToLeft(const ItemType * i1, const ItemType * i2) {
  if (i1 < i2) {
    return TRUE;
  } else {
    return FALSE;
  }
}

static Status ToRight(const ItemType * i1, const ItemType * i2) {
  if (i1 > i2) {
    return TRUE;
  } else {
    return FALSE;
  }
}

static void AddNode(Trnode * new_node, Trnode * root) {
  if (ToLeft(&new_node->item, &root->item)) {
    if (root->left == NULL) { // empty subtree
      root->left = new_node;  // so add node here
    } else {
      AddNode(new_node, root->right); // else process subtree
    }
  } else if (ToRight(&new_node->item, &root->item)) {
    if (root->right == NULL) {
      root->right = new_node;
    } else {
      AddNode(new_node, root->right);
    }
  } else {  // should be no duplicates
    fprintf(stderr, "location error in AddNode()\n");
    exit(1);
  }
}

static void InOrder(const Trnode * root, void(*pfun)(ItemType item)) {
  if (root != NULL) {
    InOrder(root->left, pfun);
    (*pfun)(root->item);
    InOrder(root->right, pfun);
  }
}

static Pair SeekItem(const ItemType * pi, const Tree * ptree) {
  Pair look;
  look.parent = NULL;
  look.child = ptree->root;
  if (look.child == NULL) {
    return look;
  }
  while (look.child != NULL) {
    if (ToLeft(pi, &(look.child->item))) {
      look.parent = look.child;
      look.child = look.child ->left;
    } else if (ToRight(pi, &(look.child->item))) {
      look.parent = look.child;
      look.child = look.child->right;
    } else {  // must be same if not to left or right
      break;  // look.child is address of node with item
    }
  }
  return look;
}

static void DeleteNode(Trnode **ptr) {
  // ptr is addres of parent member pointing to target node
  Trnode * temp;
  if ((*ptr)->left == NULL) {
    temp = *ptr;
    *ptr = (*ptr)->right;
    free(temp);
  } else if ((*ptr)->right == NULL) {
    temp = *ptr;
    *ptr = (*ptr)->left;
    free(temp);
  } else {  // deleted node has two children
    // fund where to reattach right subtree
    for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right) {
      continue;
    }
    temp->right = (*ptr)->right;
    temp = *ptr;
    *ptr = (*ptr)->left;
    free(temp);
  }
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

//void InorderTraversal(Tree BT) {
//  if (BT) {
//    InorderTraversal(BT->LChild);
//    printf("%d ", BT->info.item); 
//    InorderTraversal(BT->RChild);
//  }
//}
//
//void PreorderTraversal(Tree BT) {
//  if (BT) {
//    printf("%d ", BT->info.item);
//    PreorderTraversal(BT->LChild);
//    PreorderTraversal(BT->RChild);
//  }
//}
//
//void PostorderTraversal(Tree BT) {
//  if (BT) {
//    PostorderTraversal(BT->LChild);
//    PostorderTraversal(BT->RChild);
//    printf("%d ", BT->info.item);
//  }
//}
//
//void LevelorderTraversal(Tree BT) {
//  Queue Q;
//  Tree T;
//
//  if (!BT) return;
//
//  Q = CreateQueue();
//  //AddQ(BT, Q);
//  while (!IsEmpty(Q)) {
//    //T = Front(Q);
//    DeleteQ(Q);
//    printf("%d ", T->info.item); 
//    //if (T->LChild)   AddQ(T->LChild, Q);
//    //if (T->RChild)  AddQ(T->RChild, Q);
//  }
//}


