#include <stdio.h>
#include <stdlib.h>

int * Read(int);

int main(void) {
  int size;
  scanf("%d", &size);
  int *sequence = Read(size);
  int ThisSum, MaxSum;
  ThisSum = MaxSum = 0;
  for (int i = 0; i < size; i++) {
    ThisSum += sequence[i];
    if (ThisSum > MaxSum) {
      MaxSum = ThisSum;
    } else if (ThisSum < 0) {
      ThisSum = 0;
    }
  }
  printf("%d", MaxSum);
  return 0;
}

int * Read(int size) {
  int  *sequence = (int *)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    scanf("%d", &sequence[i]);
  }
  return sequence;
}
