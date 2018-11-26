#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "status.h"
#define EmptyTOS -1
#define MAXCAP 50
typedef int Position;
typedef int ElementType;
typedef int CapType;
typedef struct SNode {
  ElementType *Data;    // Array of storage elements
  Position TopOfStack;  // Point to the top
  CapType Capacity;     // Maximum capacity of the stack
} *Stack;

//typedef enum status {
//  OVERFLOW = -1,
//  FALSE = 0,
//  ERROR = 0,
//  TRUE = 1,
//  SUCCESS = 1
//} Status;

/* Operation: Judge if the stack is empty */
/* Preconditions: Stack 'S' already exists */
/* Postconditions: return the status: TRUE, if it's empty.*/
Status IsEmpty(Stack S);

/* Operation: Judge if the stack is full */
/* Preconditions: Stack 'S' already exists */
/* Postconditions: return the status: TRUE, if it's full.*/
Status IsFull(Stack S);

/* Operation: Empty the stack */
/* Preconditions: Stack 'S' already exists */
/* Postconditions: Stack became empty.*/
void MakeEmpty(Stack S);

/* Operation: Create a empty stack */
/* Preconditions: None */
/* Postconditions: Create a empty stack and the stack has been initialized. */
Stack CreateStack(void);

/* Operation: Dispose a stack */
/* Preconditions: Stack 'S' already exists */
/* Postconditions: return the status: SUCCESS, if dispose successed.*/
Status DisposeStack(Stack S);

/* Operation: Get a element from keyboard */
/* Preconditions: None */
/* Postconditions: return the element */
ElementType GetElement(void);

/* Operation: Push element x to the top of the stack */
/* Preconditions: Stack 'S' already exists and is not full*/
/* Postconditions: return the status: SUCCESS, if it's successed.*/
Status Push(ElementType x, Stack S);

/* Operation: Return the top element of the stack */
/* Preconditions: Stack 'S' already exists and is not empty */
/* Postconditions: Return the top element of the stack */
ElementType Top(Stack S);

/* Operation: Pop the top element of the stack */
/* Preconditions: Stack 'S' already exists and is not empty */
/* Postconditions: return the status: SUCCESS, if it's successed */
Status Pop(Stack S);

#endif // !STACK_H
