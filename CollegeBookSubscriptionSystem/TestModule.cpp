#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Sort.h"
#include "CollegeInfo.h"

int main(void) {
  int test[] = {0, 37, 43, 20, 2, 18, 1, 16, 21};
  int size = sizeof(test) / sizeof(int);
  QuickSort(test, size);
  for (int i = 1; i < size; i++) {
    printf("%d ", test[i]);
  }
  return 0;
}