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

BSTree CreateNewBSTree(void);

Status TreeIsEmpty(const BSTree ptree);

Status TreeIsFull(const BSTree ptree);

SizeType TreeItemCount(const BSTree tree);

Status AddItem(const ItemType item, BSTree tree);

Status InTree(const ItemType item, const BSTree tree);

Status DeleteItem(const ItemType item, BSTree tree);

void DeleteAll(BSTree tree);

#endif // !BINARYSEARCHTREE


