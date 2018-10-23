#include "MazeSolutionStack.h"

bool IsEmpty(Stack S) {
  bool isempty = false;
  if (S->TopOfStack == EmptyTOS) {
    isempty = true;
  }
  return isempty;
}

bool IsFull(Stack S) {
  bool isfull = false;
  if (S->TopOfStack == MaxCap) {
    isfull = true;
  }
  return isfull;
}

Stack CreateStack(void) {
  Stack S;
  S = (Stack)malloc(sizeof(SNode));
  S->Data= (SElementType *)malloc(sizeof(SNode) * MaxCap);
  S->Capacity = MaxCap;
  MakeEmpty(S);
  return S;
}

void MakeEmpty(Stack S) {
  S->TopOfStack = EmptyTOS;
}

void DisposeStack(Stack S) {
  if (S != NULL) {
    free(S->Data);
    free(S);
  }
}

bool Push(SElementType x, Stack &S) {
  if (IsFull(S)) {
    puts("ERROR: Fail to push! Cuz the stack is full.");
    return false;
  } else {
    S->Data[++S->TopOfStack] = x;
    return true;
  }
}

SElementType Top(Stack S) {
  return S->Data[S->TopOfStack];
}

bool Pop(Stack S) {
  if (IsEmpty(S)) {
    puts("ERROE: Empty stack");
    return false;
  } else {
    S->TopOfStack--;
    return true;
  }
}

bool MazePathStack(Maze M) {
  Stack path = CreateStack();
  Position start, end;
  FindGate(M, start, end);
  Position curpos = start;
  SElementType block;
  Maze tempM = CopyMaze(M);
  do {
    if (Pass(tempM, curpos)) {
      FootPrint(tempM, curpos);
      block.pos = curpos;
      block.dir = Up;
      Push(block, path);
      if (curpos.row == end.row && curpos.column == curpos.column) {
        while (!IsEmpty(path)) {
          FootPrint(M, curpos);
          Pop(path);
          curpos = Top(path).pos;
        }
        DisposeStack(path);
        return true;
      }
      curpos = NextPos(block.pos, block.dir);
    } else {
      if (!IsEmpty(path)) {
        Pop(path);
        while (block.dir == Left && !IsEmpty(path)) {
          MarkPrint(tempM, block.pos);
          block = Top(path);
          Pop(path);
        }
        if (block.dir != Left) {
          NextDir(block.dir);
          Push(block, path);
          curpos = NextPos(block.pos, block.dir);;
        }
      }
    }
  } while (!IsEmpty(path));
  DisposeStack(path);
  return false;
}