#include "Stack.h"

Status IsEmpty(Stack S) {
  if (S->TopOfStack == EmptyTOS) {
    return TRUE;
  }
  return FALSE;
}

Status IsFull(Stack S) {
  if (S->TopOfStack == MAXCAP) {
    return TRUE;
  }
  return FALSE;
}

void MakeEmpty(Stack S) {
  S->TopOfStack = EmptyTOS;
}

Stack CreateStack(void) {
  Stack S = (Stack)malloc(sizeof(SNode));
  S->Data = (ElementType *)malloc(sizeof(SNode));
  S->Capacity = MAXCAP;
  MakeEmpty(S);
  return S;
}

Status DisposeStack(Stack S) {
  if (S != NULL) {
    free(S->Data);
    free(S);
    return SUCCESS;
  } else {
    return ERROR;
  }
}

ElementType GetElement(void) {
  ElementType x;
  scanf("%d", &x);
  return x;
}

Status Push(ElementType x, Stack S) {
  if (IsFull(S)) {
    return OVERFLOW;
  } else {
    S->Data[++S->TopOfStack] = x;
    return SUCCESS;
  }
}

ElementType Top(Stack S) {
  if (!IsEmpty(S)) {
    return S->Data[S->TopOfStack];
  } else {
    puts("ERROR: Empty stack");
    ElementType x = GetElement();
    return x;
  }
}

Status Pop(Stack S) {
  if (IsEmpty(S)) {
    puts("ERROR: Empty stack");
    return ERROR;
  } else {
    S->TopOfStack--;
    return SUCCESS;
  }
}
