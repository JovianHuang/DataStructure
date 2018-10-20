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

bool DeleteQ(Queue Q) {
  if (IsEmpty(Q)) {
    puts("Queue is empty");
    return false;
  } else {
    Q->Front = (Q->Front + 1) % Q->Size;
    return true;
  }
}

void DisposeQueue(Queue Q) {
  if (Q != NULL) {
    free(Q->Data);
    free(Q);
  }
}

ElementType Front(Queue Q) {
  return Q->Data[Q->Front];
}

bool MazePathQueue(Maze M) {
  Queue path = CreateQueue();
  Position start, end;
  FindGate(M, start, end);
  Position curpos = start;
  ElementType block;
  do {
    if (Pass(M, curpos)) {

      block.pos = curpos;
      block.dir = Up;
      if (curpos.row == end.row && curpos.column == end.column) {

        return true;
      }
      curpos = NextPos(block.pos, block.dir);
    } else {

      while (block.dir == Left && !IsEmpty(path)) {

      }
      if (block.dir != Left) {
        NextDir(block.dir);

      }
    }
  } while (!IsEmpty(path));
  DisposeQueue(path);
  return false;
}
