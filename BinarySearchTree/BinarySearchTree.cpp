#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BinarySearchTree.h"

/* local data type */
typedef struct pair {
  ptNode parent;
  ptNode child;
} Pair;

/* prototype for local functions */
static ptNode MakeNode(const ItemType item);
static Status ToLeft(const ItemType item1, const ItemType item2);
static Status ToRight(const ItemType item1, const ItemType item2);
static void AddNode(ptNode new_node, ptNode root);
static Pair SeekItem(const ItemType item, const BSTree tree);
static void DeleteNode(ptNode * ptr);
static void DeleteAllNode(ptNode root);

/* function definition */

BSTree CreateNewBSTree(void) {
  Tree * tree = (Tree *)malloc(sizeof(Tree));
  tree->root = NULL;
  tree->size = 0;
  return tree;
}

Status TreeIsEmpty(const BSTree tree) {
  if (tree->root == NULL) {
    return true;
  } else {
    return false;
  }
}

Status TreeIsFull(const BSTree tree) {
  if (tree->size == ITEMSMAXNUM) {
    return true;
  } else {
    return false;
  }
}

SizeType TreeItemCount(const BSTree tree) {
  return tree->size;
}

Status AddItem(const ItemType item, BSTree tree) {
  if (TreeIsFull(tree)) {
    fprintf(stderr, "Tree is full!\n");
    return false;
  }
  if (SeekItem(item, tree).child !=NULL) {
    fprintf(stderr, "Attempted to add duplicate item!\n");
    return false;
  }
  ptNode new_node = MakeNode(item);
  if (new_node == NULL) {
    fprintf(stderr, "Couldn't create node!\n");
    return false;
  }
  // succeeded in creating a new node
  tree->size++;
  if (tree->root == NULL) { // case 1: tree is empty
    tree->root = new_node;  // new node is tree root
  } else {  // case 2: not empty
    AddNode(new_node, tree->root);  // add node to tree
  }
  return true;
}

Status InTree(const ItemType item, const BSTree tree) {
  return (SeekItem(item, tree).child == NULL) ? false : true;
}

Status DeleteItem(const ItemType item, BSTree tree) {
  Pair look = SeekItem(item, tree);
  if (look.child == NULL) {
    return false;
  }
  if (look.parent == NULL) {  // delete root item
    DeleteNode(&tree->root);
  } else if (look.parent->left == look.child) {
    DeleteNode(&look.parent->left);
  } else {
    DeleteNode(&look.parent->right);
  }
  tree->size--;
  return true;
}

void DeleteAll(BSTree tree) {
  if (tree != NULL) {
    DeleteAllNode(tree->root);
  }
  tree->root = NULL;
  tree->size = 0;
}


/* local functions */

static ptNode MakeNode(const ItemType item) {
  ptNode node = (ptNode)malloc(sizeof(Node));
  if (node != NULL) {
    node->item = item;
    node->left = NULL;
    node->right = NULL;
  }
  return node;
}

static Status ToLeft(const ItemType item1, const ItemType item2) {
  if (item1 < item2) {
    return true;
  } else {
    return false;
  }
}

static Status ToRight(const ItemType item1, const ItemType item2) {
  if (item1 > item2) {
    return true;
  } else {
    return false;
  }
}

static void AddNode(ptNode new_node, ptNode root) {
  if (ToLeft(new_node->item, root->item)) {
    if (root->left = NULL) {  // empty subtree
      root->left = new_node;  // so add node here
    } else {
      AddNode(new_node, root->right); // else process subtree
    }
  } else if (ToRight(new_node->item, root->item)) {
    if (root->right = NULL) {  // empty subtree
      root->right = new_node;  // so add node here
    } else {
      AddNode(new_node, root->right); // else process subtree
    }
  } else {
    fprintf(stderr, "location error in AddNode()\n");
    exit(0);
  }
}

static Pair SeekItem(const ItemType item, const BSTree tree) {
  Pair look;
  look.parent = NULL;
  look.child = tree->root;
  if (look.child == NULL) {
    return look;
  }
  while (look.child != NULL) {
    if (ToLeft(item, look.child->item)) {
      look.parent = look.child;
      look.child = look.child->left;
    } else if (ToRight(item, look.child->item)) {
      look.parent = look.child;
      look.child = look.child->right;
    } else {  // must be same if not to left or right
      break;  // look.child is address of node with item
    }
  }
  return look;
}

static void DeleteNode(ptNode * ptr) {
  // ptr is address of parent member pointing to target node
  ptNode temp;
  if ((*ptr)->left == NULL) {
    temp = *ptr;
    *ptr = (*ptr)->right;
    free(temp);
  } else if ((*ptr)->right == NULL) {
    temp = *ptr;
    *ptr = (*ptr)->left;
    free(temp);
  } else {
    // deleted node has two children
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

static void DeleteAllNode(ptNode root) {
  if (root != NULL) {
    ptNode rightSub = root->right;
    DeleteAllNode(root->left);
    free(root);
    DeleteAllNode(rightSub);
  }
}

