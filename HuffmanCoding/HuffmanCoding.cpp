#include <stdio.h>
#include <stdlib.h>
#include "HuffmanCoding.h"

/* local data type */
typedef const Trnode* ElementType;
typedef int Position;
typedef int CapType;

#define EMPTYTOS -1
#define MAXCAP_Stack 50
typedef struct SNode {
  ElementType *Data;    // Array of storage elements
  Position TopOfStack;  // Point to the top
  CapType Capacity;     // Maximum capacity of the stack
} *Stack;

#define MAXCAP_Queue 50
typedef struct QNode {
  ElementType *Data;  // Array of storage elements
  Position Front, Rear;  // Pointer to the front and the rear of the queue
  CapType Capacity;  // The maximum capacity of the queue
} *Queue;

/* prototype for local functions */
static Trnode * MakeNode(const ItemType * pitem);
static void DeleteAllNode(Trnode * root);
static void PrintItem(const ItemType item);
static void PreOrder(const Trnode * root);
static void InOrder(const Trnode * root);
static void PostOrder(const Trnode * root);
static Stack CreateStack(void);
static Status DisposeStack(Stack S);
static Status Push(ElementType x, Stack S);
static Status Pop(Stack S);
static void PreOrderByStack(const Trnode * root);
//static void InOrderByStack(const Trnode * root);
//static void PostOrderByStack(const Trnode * root);
static Queue CreateQueue(void);
static Status DisposeQueue(Queue Q);
static Status AddQ(ElementType x, Queue Q);
static Status DeleteQ(Queue Q);
static void LevelOrder(const Trnode * root);


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

void Traverse(const Tree * ptree, void(*pfun)(const Trnode * root)) {
  if (ptree != NULL) {
    (*pfun)(ptree->root);
  }
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

static void PrintItem(const ItemType item) {
  if (item.ch != '0') {
    printf("%c", item.ch);
  }
}

static void PreOrder(const Trnode * root) {
  if (root != NULL) {
    PrintItem(root->item);
    PreOrder(root->left);
    PreOrder(root->right);
  }
}

static void InOrder(const Trnode * root) {
  if (root != NULL) {
    InOrder(root->left);
    PrintItem(root->item);
    InOrder(root->right);
  }
}

static void PostOrder(const Trnode * root) {
  if (root != NULL) {
    PostOrder(root->left);
    PostOrder(root->right);
    PrintItem(root->item);
  }
}

static Stack CreateStack(void) {
  Stack S = (Stack)malloc(sizeof(SNode));
  S->Data = (ElementType *)malloc(sizeof(SNode));
  S->Capacity = MAXCAP_Stack;
  S->TopOfStack = EMPTYTOS;
  return S;
}

static Status DisposeStack(Stack S) {
  if (S != NULL) {
    free(S->Data);
    free(S);
    return SUCCESS;
  } else {
    return ERROR;
  }
}

static Status Push(ElementType x, Stack S) {
  if (S->TopOfStack == MAXCAP_Stack) {
    return OVERFLOW;
  } else {
    S->Data[++S->TopOfStack] = x;
    return SUCCESS;
  }
}

static Status Pop(Stack S) {
  if (S->TopOfStack == EMPTYTOS) {
    fprintf(stderr, "ERROR: Empty stack.\n");
    return ERROR;
  } else {
    S->TopOfStack--;
    return SUCCESS;
  }
}

static void PreOrderByStack(const Trnode * root) {
  Stack S = CreateStack();
  if (root != NULL) {
    Push(root, S);
  }
  ElementType temp;
  while (S->TopOfStack != EMPTYTOS) {
    temp = S->Data[S->TopOfStack];
    Pop(S);
    PrintItem(root->item);
    if (temp->right) {
      Push(temp->right, S);
    }
    if (temp->left) {
      Push(temp->left, S);
    }
  }
}

//static void InOrderByStack(const Trnode * root) {
//  Stack S = CreateStack();
//  if (root != NULL) {
//    Push(root, S);
//  }
//  ElementType temp = root;
//  while (temp != NULL || S->TopOfStack != EMPTYTOS) {
//    temp = S->Data[S->TopOfStack];
//    Pop(S);
//    PrintItem(root->item);
//    if (temp->right) {
//      Push(temp->right, S);
//    }
//    if (temp->left) {
//      Push(temp->left, S);
//    }
//  }
//  Push()
//}
//
//static void PostOrderByStack(const Trnode * root) {
//  Stack S = CreateStack();
//  if (root != NULL) {
//    Push(root, S);
//  }
//  ElementType temp;
//  while (S->TopOfStack != EMPTYTOS) {
//    temp = S->Data[S->TopOfStack];
//    Pop(S);
//    PrintItem(root->item);
//    if (temp->right) {
//      Push(temp->right, S);
//    }
//    if (temp->left) {
//      Push(temp->left, S);
//    }
//  }
//}

static Queue CreateQueue(void) {
  Queue Q = (Queue)malloc(sizeof(QNode));
  Q->Data = (ElementType *)malloc(sizeof(ElementType) * MAXCAP_Queue);
  Q->Front = Q->Rear = 0;
  Q->Capacity = MAXCAP_Queue;
  return Q;
}

static Status DisposeQueue(Queue Q) {
  if (Q != NULL) {
    free(Q->Data);
    free(Q);
    return SUCCESS;
  } else {
    return ERROR;
  }
}

static Status AddQ(ElementType x, Queue Q) {
  if ((Q->Rear + 1) % Q->Capacity == Q->Front) {
    fprintf(stderr, "Queue is full.\n");
    return ERROR;
  } else {
    Q->Rear = (Q->Rear + 1) % Q->Capacity;
    Q->Data[Q->Rear] = x;
    return SUCCESS;
  }
}

static Status DeleteQ(Queue Q) {
  if (Q->Front == Q->Rear) {
    puts("Queue is empty");
    fprintf(stderr, "Queue is empty.\n");
    return ERROR;
  } else {
    Q->Front = (Q->Front + 1) % Q->Capacity;
    return SUCCESS;
  }
}

static void LevelOrder(const Trnode * root) {
  Queue Q = CreateQueue();
  if (root != NULL) {
    AddQ(root, Q);
    ElementType temp;
    while (Q->Front != Q->Rear) {
      temp = Q->Data[Q->Front];
      DeleteQ(Q);
      PrintItem(temp->item);
      if (temp->left != NULL) {
        AddQ(temp->left, Q);
      }
      if (temp->right != NULL) {
        AddQ(temp->right, Q);
      }
    }
  }
}



