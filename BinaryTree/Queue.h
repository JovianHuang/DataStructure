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

Queue CreateQueue(void);

Status IsFull(Queue Q);

Status IsEmpty(Queue Q);

Status AddQ(ElementType x, Queue Q);

Status DeleteQ(Queue Q);

Status DisposeQueue(Queue Q);

ElementType Front(Queue Q);




#endif // !QUEUE_H

