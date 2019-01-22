#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ExternalSorting.h"
#include "Sort.h"

/* local data type */

/* prototype for local functions */

static void InternalSort(int arr[], int size, int method);
static void Segement(FILE *fi, int wayNum, int capacity);
static int * ConstructLoser(int wayNum, ExNode *seges);
static void AdjustLoserTree(int * ls, ExNode * seges, int wayNum, int winner);
static void Merge(FILE *fo, int wayNum);

/* functions definition */

void SevenWayMergeSort(FILE *fi, FILE *fo, int size) {
  int capacity = size / WAYNUM + 1;
  // Prevent the last path from having no content
  int wayNum = size % capacity == 0 ? size / capacity : (size / (WAYNUM - 1)) == capacity ? WAYNUM : WAYNUM - 1;
  Segement(fi, wayNum, capacity);
  Merge(fo, wayNum);
}

/* local functions */

static void Segement(FILE *fi, int wayNum, int capacity) {
  int i, j;
  int *sege = (int *)malloc(sizeof(int) * capacity);
  for (i = 0; i < wayNum; i++) {
    memset(sege, 0, capacity * sizeof(int));
    j = 0;
    fscanf(fi, "%d", &sege[j]);
    while (!feof(fi)) {
      j++;
      if (j >= capacity) {
        break;
      }
      fscanf(fi, "%d", &sege[j]);
      if (feof(fi)) {
        j++;
        break;
      }
    }
    char filename[15];
    sprintf(filename, "temp%d.txt", i);
    FILE *fp = fopen(filename, "w");
    InternalSort(sege, j, i);
    for (int t = 0; t < j; t++) {
      fprintf(fp, "%d ", sege[t]);
    }
    fclose(fp);
  }
}

static void Merge(FILE *fo, int wayNum) {
  FILE **fp = (FILE **)malloc(sizeof(FILE *) * wayNum);
  char filename[15];
  int i;
  for (i = 0; i < wayNum; i++) {
    sprintf(filename, "temp%d.txt", i);
    fp[i] = fopen(filename, "a+");
  }
  ExNode *seges = (ExNode *)malloc(sizeof(ExNode) * wayNum + 1);
  for (i = 0; i < wayNum; i++) {
    fscanf(fp[i], "%d", &seges[i].key);
  }
  int *ls = ConstructLoser(wayNum, seges);
  int MAXKEY = 9999;
  while (seges[ls[0]].key != MAXKEY) {
    int pos;
    pos = ls[0];
    fprintf(fo, "%d ", seges[pos].key);
    printf("%d ", seges[pos].key);
    fscanf(fp[pos], "%d", &seges[pos].key);
    if (feof(fp[pos])) {
      seges[pos].key = MAXKEY;
    }
    AdjustLoserTree(ls, seges, wayNum, pos);
  }
}

static void InternalSort(int arr[], int size, int method) {
  switch (method) {
    case 0: {
      BubbleSort(arr, size);
      break;
    }
    case 1: {
      SelectionSort(arr, size);
      break;
    }
    case 2: {
      InsertionSort(arr, size);
      break;
    }
    case 3: {
      ShellSort(arr, size);
      break;
    }
    case 4: {
      HeapSort(arr, size);
      break;
    }
    case 5: {
      MergeSort(arr, size);
      break;
    }
    case 6: {
      QuickSort(arr, size);
      break;
    }
  }
}

static int * ConstructLoser(int wayNum, ExNode *seges) {
  seges[wayNum].key = 0;
  int i;
  int *ls = (int *)malloc(sizeof(int) * wayNum);
  for (i = 0; i < wayNum; i++) {
    ls[i] = wayNum;
  }
  for (i = wayNum - 1; i >= 0; i--) {
    AdjustLoserTree(ls, seges, wayNum, i);
  }
  return ls;
}

static void AdjustLoserTree(int * ls, ExNode * seges, int wayNum, int winner) {
  int t = (winner + wayNum) / 2;
  while (t > 0) {
    if (seges[winner].key > seges[ls[t]].key) {
      int tmp = ls[t];
      ls[t] = winner;
      winner = tmp;
    }
    t = t / 2;
  }
  ls[0] = winner;
}
