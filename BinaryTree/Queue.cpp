#include "Queue.h"

Queue CreateQueue(void) {
  Queue Q = (Queue)malloc(sizeof(QNode));
  Q->Data = (ElementType *)malloc(sizeof(ElementType) * Q_MAXSIZE);
  Q->Front = Q->Rear = 0;
  Q->Size = Q_MAXSIZE;
  return Q;
}

Status IsFull(Queue Q) {
  if ((Q->Rear +1) % Q->Size == Q->Front) {
    return TRUE;
  }
  return FALSE;
}

Status IsEmpty(Queue Q) {
  if (Q->Front == Q->Rear) {
    return TRUE;
  }
  return FALSE;
}

Status AddQ(ElementType x, Queue Q) {
  if (IsFull(Q)) {
    puts("Queue is full.");
    return ERROR;
  } else {
    Q->Rear = (Q->Rear + 1) % Q->Size;
    Q->Data[Q->Rear] = x;
    return SUCCESS;
  }
}

Status DeleteQ(Queue Q) {
  if (IsEmpty(Q)) {
    puts("Queue is empty");
    return ERROR;
  } else {
    Q->Front = (Q->Front + 1) % Q->Size;
    return SUCCESS;
  }
}

Status DisposeQueue(Queue Q) {
  if (Q != NULL) {
    free(Q->Data);
    free(Q);
    return SUCCESS;
  } else {
    return ERROR;
  }
}

ElementType Front(Queue Q) {
  return Q->Data[Q->Front];
}

