#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "status.h"
#include "Stack.h"
#include "Queue.h"

#define MAXITEMS 100

typedef int ItemType;
typedef int SizeType;

typedef struct trnode {
  ItemType item;
  struct trnode *left;  // pointer to right branch
  struct trnode *right; // pointer to left branch
} Trnode;

typedef struct tree {
  Trnode * root;  // pointer to root of tree
  SizeType size;  // number of items in tree
} Tree;

//typedef enum status {
//  OVERFLOW = -1,
//  FALSE = 0,
//  ERROR = 0,
//  TRUE = 1,
//  SUCCESS = 1
//} Status;

/* function prototypes */

/* operation:       initialize a tree to empty        */
/* preconditions:   ptree points to a tree            */
/* postconditions:  the tree is initialized to empty  */
void InitializeTree(Tree * ptree);

/* operation:       determine if tree is empty        */
/* preconditions:   ptree points to a tree            */
/* postconditions:  function return true if tree is   */
/*                  empty and return false otherwise  */
Status TreeIsEmpty(const Tree * ptree);

/* operation:       determine if tree is full         */
/* preconditions:   ptree points to a tree            */
/* postconditions:  function return true if tree is   */
/*                  full and return false otherwise   */
Status TreeIsFull(const Tree * ptree);

/* operation:       determine number of items in tree */
/* preconditions:   ptree points to a tree            */
/* postconditions:  function return number of items in*/
/*                  tree                              */
SizeType TreeItemCount(const Tree * ptree);

/* operation:       determine if tree is empty        */
/* preconditions:   ptree points to a tree            */
/* postconditions:  function return true if tree is   */
/*                  empty and return false otherwise  */
Status AddItem(const ItemType *pi, Tree * ptree);

/* operation:       find an item in a tree              */
/* preconditions:   pi points to an item                */
/*                  ptree points to an initialized tree */             
/* postconditions:  function return true if item is in  */
/*                  tree and return false otherwise     */
Status InTree(const ItemType * pi, const Tree * ptree);

/* operation:       delete an item from a tree         */
/* preconditions:   pi is address of item to be deleted*/
/*                  ptree points to an initialied tree */
/* postconditions:  if possible, function deletes item */
/*                  from tree and return true;         */
/*                  otherwise the function return false*/
Status DeleteItem(const ItemType * pi, Tree * ptree);

/* operation:       apply a function to each item in    */
/*                  the tree                            */
/* preconditions:   ptree points to a tree              */
/*                  pfun points to a function that takes*/
/*                  an item argument and has no return  */
/*                  value                               */
/* postconditions:  the function pointed to by pfun is  */
/*                  excuted once for each item in tree  */
void Traverse(const Tree * ptree, void (*pfun)(ItemType item));

/* operation:       delete everything from a tree       */   
/* preconditions:   ptree points to an initialized tree */
/* postconditions:  tree is empty                       */
void DeleteAll(Tree * ptree);

#endif // !BINARYTREE_H
