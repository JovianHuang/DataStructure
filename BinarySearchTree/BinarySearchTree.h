#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE

typedef int ItemType;
typedef int SizeType;
typedef bool Status;

typedef struct node {
  ItemType item;
  struct node * left;   // pointer to right branch
  struct node * right;  // pointer to left branch
} Node, * ptNode;

static const SizeType ITEMSMAXNUM = 100;  // MaxSize of the tree
typedef struct tree{
    ptNode root;  // pointer to root of tree
    SizeType size;  // number of items in tree
} Tree, * BSTree;

/* operation: create a new tree and initialize to empty */
/* postconditions:  return a pointer points to the new empty tree */
BSTree CreateNewBSTree(void);

/* operation: determine if tree is empty */
/* preconditions: tree points to a tree */
/* postconditions: function returns true if tree is empty and returns false otherwise */
Status TreeIsEmpty(const BSTree tree);

/* operation: determine if tree is full */
/* preconditions: tree points to a tree */
/* postconditions: function returns true if tree is full and returns false otherwise */
Status TreeIsFull(const BSTree tree);

/* operation: determine number of items in tree */
/* preconditions: tree points to a tree */
/* postconditions: function returns number of items in tree */
SizeType TreeItemCount(const BSTree tree);

/* operation: add an item to a tree */
/* preconditions: item is an item to be added, and tree points to an initialized tree */
/* postconditions: if possible, function adds item to tree and returns true; otherwise, the function returns false */
Status AddItem(const ItemType item, BSTree tree);

/* operation: find an item in a tree */
/* preconditions: item is an item to be added, and tree points to an initialized tree */
/* postconditions: function returns true if item is in tree and returns false otherwise */
Status InTree(const ItemType item, const BSTree tree);

/* operation: delete an item from a tree */
/* preconditions: item is the item to be deleted, and tree points to an initialized tree */
/* postconditions: if possible, function deletes item from tree and return true; otherwise the function returns false */
Status DeleteItem(const ItemType item, BSTree tree);

/* operation: delete everything from a tree */
/* preconditions: tree points to an initialied tree */
/* postconditions: tree is empty */
void DeleteAll(BSTree tree);

/* operation: apply a function to each item in the tree */
/* precondtions: */
/* postcondtions: the function pointed to by */

#endif // !BINARYSEARCHTREE


