#include <stdio.h>
#include "Sort.h"

/* local data type*/


/* prototype for local functions */

static void Swap(sortedItem_Type & a, sortedItem_Type & b);

/* functions definition */

void BubbleSort(sortedArray_Type arr, int size) {
  int i, j;
  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        Swap(arr[j + 1], arr[j]);
      }
    }
  }
}

void SelectionSort(sortedArray_Type arr, int size) {
  int i, j, min;
  for (i = 0; i < size - 1; i++) {
    min = i;
    for (j = i + 1; j < size; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    Swap(arr[i], arr[min]);
  }
}

void InsertionSort(sortedArray_Type arr, int size) {
  int i, j, temp;
  for (i = 1; i < size; i++) {
    if (arr[i] < arr[i - 1]) {
      temp = arr[i];
      for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
        arr[j + 1] = arr[j];
      }
      arr[j + 1] = temp;
    }
  }
}

void ShellSort(sortedArray_Type arr, int size) {
  int i, j, temp, increment;
  for (increment = size / 2; increment > 0; increment /= 2) {
    for (i = increment; i < size; i++) {
      temp = arr[i];
      for (j = i - increment; j >= 0 && temp < arr[j]; j -= increment) {
        arr[j + increment] = arr[j];
      }
      arr[j + increment] = temp;
    }
  }
}



/* local functions */

static void Swap(sortedItem_Type & a , sortedItem_Type  & b) {
  sortedItem_Type temp = a;
  a = b;
  b = temp;
}
