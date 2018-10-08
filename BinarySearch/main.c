#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
  ElementType Data[MAXSIZE];
  Position Last; /* 保存线性表中最后一个元素的位置*/
};

List ReadInput();
Position BinarySearch(List L, ElementType X);

int main(void) {
  List L;
  ElementType X;
  Position P;

  L = ReadInput();
  scanf("%d", &X);
  P = BinarySearch(L, X);
  printf("%d\n", P);

  return 0;
}

List ReadInput(void) {
  List L = (List)malloc(sizeof(struct LNode));
  int size;
  scanf("%d", &size);
  for (int i = 0; i < size; i++) {
    scanf("%d", &L->Data[i + 1]);
    L->Last = i + 1;
  }
  return L;
}

Position BinarySearch(List L, ElementType X) {
  int left = 1;
  int right = L->Last;
  int mid;
  while (right != left) {
    mid = (left + right) / 2;
    if (L->Data[mid] == X) {
      break;
    } else if (L->Data[mid] > X) {
      right = mid;
    } else {
      left = mid;
    }
    if ((left+right)/2 == mid) {
      return NotFound;
    }
  }
  return mid;
}
