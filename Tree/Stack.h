#ifndef STACK_H
#define STACK_H

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

#endif // !STACK_H
