#include "Stack.h"

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
  S->Data = (ElementType *)malloc(sizeof(SNode) * MaxCap);
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

void Push(ElementType x, Stack S) {
  if (IsFull(S)) {
    puts("ERROR: Fail to push! Cuz the stack is full.");
  } else {
    S->Data[++S->TopOfStack] = x;
  }
}

ElementType Top(Stack S) {
  if (!IsEmpty(S)) {
    return S->Data[S->TopOfStack];
  } else {
    puts("ERROR: Empty stack");
    return 0;
  }
}

void Pop(Stack S) {
  if (IsEmpty(S)) {
    puts("ERROE: Empty stack");
  } else {
    S->TopOfStack--;
  }
}
