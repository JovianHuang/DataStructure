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

Status IsFull(Stack S);

void MakeEmpty(Stack S);

Stack CreateStack(void);

Status DisposeStack(Stack S);

ElementType GetElement(void);

Status Push(ElementType x, Stack S);

ElementType Top(Stack S);

Status Pop(Stack S);

#endif // !STACK_H
