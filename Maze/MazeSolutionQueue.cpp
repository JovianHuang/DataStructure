#include "MazeSolutionQueue.h"

  Queue CreateQueue(void) {
    Queue Q = (Queue)malloc(sizeof(QNode));
    Q->Data = (ElementType *)malloc(sizeof(ElementType) * MaxSize);
    Q->Front = Q->Rear = 0;
    Q->Size = MaxSize;
    return Q;
  }

  bool IsFull(Queue Q) {
    return ((Q->Rear + 1) % Q->Size == Q->Front);
  }

  bool IsEmpty(Queue Q) {
    return (Q->Front == Q->Rear);
  }

  bool AddQ(ElementType x, Queue Q) {
    if (IsFull(Q)) {
      puts("Queue is full.");
      return false;
    } else {
      Q->Rear = (Q->Rear + 1) % Q->Size;
      Q->Data[Q->Rear] = x;
      return true;
    }
  }

  ElementType DeleteQ(Queue Q) {
    if (IsEmpty(Q)) {
      puts("Queue is empty");
      return;
    } else {
      Q->Front = (Q->Front + 1) % Q->Size;
      return Q->Data[Q->Front];
    }
  }


