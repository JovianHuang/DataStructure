#include "MazeSolutionStack.h"
#include "Maze.h"

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
  S->Data= (ElementType *)malloc(sizeof(SNode) * MaxCap);
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

void Push(ElementType x, Stack &S) {
  if (IsFull(S)) {
    puts("ERROR: Fail to push! Cuz the stack is full.");
  } else {
    S->Data[++S->TopOfStack] = x;
  }
}

ElementType Top(Stack S) {
  return S->Data[S->TopOfStack];
}

void Pop(Stack S) {
  if (IsEmpty(S)) {
    puts("ERROE: Empty stack");
  } else {
    S->TopOfStack--;
  }
}

void FootPrint(Maze M, Position curpos) {
  M->status[curpos.row][curpos.column] = '*';
}

void MarkPrint(Maze M, Position curpos) {
  M->status[curpos.row][curpos.column] = '@';
}

Position NextPos(Position curpos, DirEnum dir) {
  switch (dir) {
    case Up: 
    {
      curpos.row--;
      break;
    }
    case Right:
    {
      curpos.column++;
      break;
    }
    case Down:
    {
      curpos.row++;
      break;
    }
    case Left:
    {
      curpos.column--;
      break;
    }
  }
  return curpos;
}

bool Pass(const Maze M, Position curpos) {
  if (M->status[curpos.row][curpos.column] == '0' || M->status[curpos.row][curpos.column] == '2') {
    return true;
  } else {
    return false;
  }
}

void NextDir(DirEnum& dir) {
  switch (dir) {
    case Up:
    {
      dir = Right;
      break;
    }
    case Right:
    {
      dir = Down;
      break;
    }
    case Down:
    {
      dir = Left;
      break;
    }
  }
}

bool MazePath(Maze M) {
  Stack path = CreateStack();
  Position start, end;
  FindGate(M, start, end);
  Position curpos = start;
  ElementType block;
  block.pos = curpos;
  block.dir = Up;
  do {
    if (Pass(M, curpos)) {
      FootPrint(M, curpos);
      block.pos = curpos;
      block.dir = Up;
      Push(block, path);
      if (curpos.row == end.row && curpos.column == curpos.column) {
          return true;
      }
      curpos = NextPos(block.pos, block.dir);
    } else {
      if (!IsEmpty(path)) {
        Pop(path);
        while (block.dir == Left && !IsEmpty(path)) {
          MarkPrint(M, block.pos);
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
  return false;
}