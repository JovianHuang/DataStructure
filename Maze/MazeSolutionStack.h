#ifndef MAZESOLUTIONSTACK_H
#define MAZESOLUTIONSTACK_H

/* standard header files */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* stdanard header files */

/* Predefine */
#define EmptyTOS -1
#define MaxCap 50

//---------------------------------//
// Specialization for solving maze //
struct Position {
  int row;
  int column;
};
enum DirEnum {
  Up = 0,
  Right,
  Down,
  Left
};
struct PNode {
  Position pos;
  DirEnum dir;
}; 
typedef PNode ElementType;
//-------------------------//

struct SNode {
  ElementType *Data;    // Array of storage elements
  int TopOfStack;  // Point to the top
  int Capacity;         // Maximum capacity of the stack
};
typedef struct SNode *Stack;
/* Predefine */

bool IsEmpty(Stack S);
// Preconditions: Stack S already exists
// Operation-result: Return a bool value to represent this stack is empty or not

bool IsFull(Stack S);
// Preconditions: Stack S already exists
// Operation-result: Return a bool value to represent this stack is full or not

Stack CreateStack(void);
// Operation-result: Construct an empty stack S

void MakeEmpty(Stack S);
// Preconditions: Stack S already exists
// Operation-result: Stack S seted to empty

void DisposeStack(Stack S);
// Preconditons: Stack S already exists
// Operation-result: The memory allocated to the stack have been free

void Push(ElementType x, Stack &S);
// Preconditions: Stack S already exists
// Operation-result: Push top of stack

ElementType Top(Stack S);
// Preconditions: Stack S already exists
// Operation-result: Return the top of stack

void Pop(Stack S);
// Preconditions: Stack S already exists
// Operation-result: Pop the top of stack


#endif // !MAZESOLUTIONSTACK_H


