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
#include "Maze.h"
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

void FootPrint(Maze M, Position curpos);
// Operation-result: Identifies this block to show that it have passed

void MarkPrint(Maze M, Position curpos);
// Operation-result: Identifies this block to show that no way to go

Position NextPos(Position curpos, DirEnum dir);
// Operation-result: To know next block to go

bool Pass(const Maze M, Position curpos);
// Operation-result: To know can it pass

void NextDir(DirEnum & dir);
// Operation-result: To change the dir

bool MazePath(Maze M);
// Operation-result: To solve the maze

#endif // !MAZESOLUTIONSTACK_H


