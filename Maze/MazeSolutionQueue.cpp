#include "MazeSolutionQueue.h"

Queue CreateQueue(void) {
  Queue Q = (Queue)malloc(sizeof(QNode));
  Q->Data = (QElementType *)malloc(sizeof(QElementType) * MaxSize);
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

bool AddQ(QElementType x, Queue &Q) {
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

QElementType Front(Queue Q) {
  return Q->Data[Q->Front];
}

bool MazePathQueue(Maze M) {
  Queue path = CreateQueue();
  Position start, end;
  FindGate(M, start, end);
  Position curpos;
  QElementType block;
  block.order = 1;
  block.pos = start;
  block.pre = -1;
  block.dir = Up;
  AddQ(block, path);
  Maze tempM = CopyMaze(M);
  FootPrint(tempM, start);
  while (!IsEmpty(path)) {
    do {
      curpos = NextPos(block.pos, block.dir);
      if (Pass(tempM, curpos)) {
        FootPrint(tempM, curpos);
        QElementType temp;
        temp.pos = curpos;
        temp.pre = block.order;
        temp.dir = Up;
        temp.order = path->Rear + 1;
        AddQ(temp, path);
      } else {
        if (!OutOfBound(curpos)) {
          MarkPrint(tempM, curpos);
        }
      }
      NextDir(block.dir);
    } while (block.dir != Up);
    if (block.order + 1 <= path->Rear) {
      block = path->Data[block.order + 1];
    } else {
      DisposeQueue(path);
      return false;
    }
    if (block.pos.row == end.row && block.pos.column == end.column) {
      QElementType mark = path->Data[path->Rear];
      while (mark.pre != -1) {
        FootPrint(M, mark.pos);
        mark = path->Data[mark.pre];
      }
      FootPrint(M, start);
      DisposeQueue(path);
      return true;
    }
  }
}
