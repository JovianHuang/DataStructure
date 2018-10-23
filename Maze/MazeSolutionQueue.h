#ifndef MAZESOLUTIONQUEUE_H
#define MAZESOLUTIONQUEUE_H

/* standard header files */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* stdanard header files */

/* Predefine */
#define MaxSize 100
//---------------------------------//
// Specialization for solving maze //
#include "Maze.h"
struct QPNode {
  int order;
  Position pos;
  int pre;
  DirEnum dir;
};
typedef QPNode QElementType;
//-------------------------//

typedef int Ptr;
struct QNode {
  QElementType *Data;  // Array of storage elements
  Ptr Front, Rear;    // Pointer to the front and the rear of the queue
  int Size;        // The maximum size of the queue
};
typedef QNode *Queue;
/* Predefine */

Queue CreateQueue(void);
// Operation-result: Create an empty queue

bool IsFull(Queue Q);
// Preconditions: Queue already exists.
// Operation-result£ºreturn a bool value to represent is full or not

bool IsEmpty(Queue Q);
// Preconditions: Queue already exists.
// Operation-result£ºreturn a bool value to represent is empty or not

bool AddQ(QElementType x, Queue &Q);
// Operation-result: Add a new element to the queue rear

bool DeleteQ(Queue Q);
// Operation-result: Delete an element from front

void DisposeQueue(Queue Q);
// Preconditions: Queue Q already exists.
// Operation-result: The memory allocated to this queue is free

QElementType Front(Queue Q);
// Operation-result: return the front element

bool MazePathQueue(Maze M);

#endif // !MAZESOLUTIONQUEUE_H
