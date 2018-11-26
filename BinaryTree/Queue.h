#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "status.h"

#define Q_MAXSIZE 50

typedef int ElementType;
typedef int Ptr;
typedef int SizeType;
typedef struct QNode {
  ElementType *Data;  // Array of storage elements
  Ptr Front, Rear;  // Pointer to the front and the rear of the queue
  SizeType Size;  // The maximum size of the queue
} *Queue;

//typedef enum status {
//  OVERFLOW = -1,
//  FALSE = 0,
//  ERROR = 0,
//  TRUE = 1,
//  SUCCESS = 1
//} Status;

/* Operation: Create a empty queue */
/* Preconditions: None */
/* Postconditions: Create a empty queue and the queue has been initialized. */
Queue CreateQueue(void);

/* Operation: Judge if the queue is full */
/* Preconditions: Queue 'Q' already exists */
/* Postconditions: return the status: TRUE, if it's full.*/
Status IsFull(Queue Q);

/* Operation: Judge if the queue is empty */
/* Preconditions: Queue 'Q' already exists */
/* Postconditions: return the status: TRUE, if it's empty.*/
Status IsEmpty(Queue Q);

/* Operation: Add element x to the rear of the queue */
/* Preconditions: Queue 'Q' already exists and is not full */
/* Postconditions: return the status: SUCCESS, if it's successed */
Status AddQ(ElementType x, Queue Q);

/* Operation: Delete element from the front of the queue */
/* Preconditions: Queue 'Q' already exists and is not empty */
/* Postconditions: return the status: SUCCESS, if it's successed */
Status DeleteQ(Queue Q);

/* Operation: Dispose the queue 'Q' */
/* Preconditions: Queue 'Q' already exists */
/* Postconditions: return the status: SUCCESS, if it's successed */
Status DisposeQueue(Queue Q);

/* Operation: return the element of the front of the queue */
/* Preconditions: Queue 'Q' already exists and is not empty */
/* Postconditions: return the status: SUCCESS, if it's successed */
ElementType Front(Queue Q);

#endif // !QUEUE_H

