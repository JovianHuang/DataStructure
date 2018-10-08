#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
  ElementType Data;
  PtrToNode   Next;
};
typedef PtrToNode List;

List Read();
void Print(List L);

List Merge(List L1, List L2);

int main() {
  List L1, L2, L;
  L1 = Read();
  L2 = Read();
  L = Merge(L1, L2);
  Print(L);
  Print(L1);
  Print(L2);
  return 0;
}

List Read(void) {
  int size;
  scanf("%d", &size);
  List head = (List)malloc(sizeof(struct Node));
  head->Next = NULL;
  if (!size) {
    return head;
  }
  List prev = head;
  for (int i = 0; i < size; i++) {
    List current = (List)malloc(sizeof(struct Node));
    scanf("%d", &current->Data);
    current->Next = NULL;
    prev->Next = current;
    prev = current;
  }
  return head;
}

void Print(List L) {
  List current;
  if (L->Next) {
    current = L->Next;
  } else {
    printf("NULL");
    exit(0);
  }
  while (current) {
    printf("%d ", current->Data);
    current = current->Next;
  }
}

List Merge(List L1, List L2) {
  List head = (List)malloc(sizeof(struct Node));
  head->Next = NULL;
  List current = head;
  List checked_1 = L1->Next;
  List checked_2 = L2->Next;
  while (checked_1 && checked_2) {
    if (checked_1->Data <= checked_2->Data) {
      L1->Next = checked_1->Next;
      current->Next = checked_1;
      current = current->Next;
      checked_1 = L1->Next;
    } else {
      L2->Next = checked_2->Next;
      current->Next = checked_2;
      current = current->Next;
      checked_2 = L2->Next;
    }
    if (!checked_1) {
      current->Next = checked_2;
      L2->Next = NULL;
      break;
    } else if (!checked_2) {
      current->Next = checked_1;
      L1->Next = NULL;
      break;
    }
  }
  return head;
}