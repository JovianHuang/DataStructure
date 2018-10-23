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
#include "Maze.h"
struct SPNode {
  Position pos;
  DirEnum dir;
}; 
typedef SPNode SElementType;
//-------------------------//

struct SNode {
  SElementType *Data;    // Array of storage elements
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

bool Push(SElementType x, Stack &S);
// Preconditions: Stack S already exists
// Operation-result: Push top of stack

SElementType Top(Stack S);
// Preconditions: Stack S already exists
// Operation-result: Return the top of stack

bool Pop(Stack S);
// Preconditions: Stack S already exists
// Operation-result: Pop the top of stack

bool MazePathStack(Maze M);
// Operation-result: To solve the maze

#endif // !MAZESOLUTIONSTACK_H


