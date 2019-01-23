#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sort.h"

/* local data type*/

static const int ITEMMAXLEN = 160;

/* prototype for local functions */

static void Swap(sortedItem_Type & a, sortedItem_Type & b);
static void PercDown(sortedArray_Type a, int p, int num);
static void Merge(sortedArray_Type A, sortedArray_Type TmpA, int L, int R, int RightEnd);
static void Merge_pass(sortedArray_Type A, sortedArray_Type TmpA, int N, int length);
static sortedItem_Type Median3(sortedArray_Type A, int Left, int Right);
static void Qsort(sortedArray_Type A, int Left, int Right);

/* functions definition */

void BubbleSort(sortedArray_Type arr, int num) {
  int i, j;
  for (i = 0; i < num - 1; i++) {
    for (j = 0; j < num - 1 - i; j++) {
      if (strcmp(arr[j], arr[j + 1]) > 0) {
        Swap(arr[j + 1], arr[j]);
      }
    }
  }
}

void SelectionSort(sortedArray_Type arr, int num) {
  int i, j, min;
  for (i = 0; i < num - 1; i++) {
    min = i;
    for (j = i + 1; j < num; j++) {
      if (strcmp(arr[j], arr[min]) < 0) {
        min = j;
      }
    }
    Swap(arr[i], arr[min]);
  }
}

void InsertionSort(sortedArray_Type arr, int num) {
  int i, j;
  sortedItem_Type temp = (sortedItem_Type)malloc(sizeof(char) * ITEMMAXLEN);
  for (i = 1; i < num; i++) {
    strcpy(temp, arr[i]);
    for (j = i; j > 0 && strcmp(arr[j - 1], temp) > 0; j--) {
      strcpy(arr[j], arr[j - 1]);
    }
    strcpy(arr[j], temp);
  }
}

void ShellSort(sortedArray_Type arr, int num) {
  int Si, increment, P, i;
  sortedItem_Type temp = (sortedItem_Type)malloc(sizeof(char) * ITEMMAXLEN);
  const int IncremenSqSedgewick[] = { 8929, 3905, 2161, 929, 505, 209, 109, 41, 19, 5, 1, 0 };
  for (Si = 0; IncremenSqSedgewick[Si] >= num; Si++) {
    ;
  }
  for (increment = IncremenSqSedgewick[Si]; increment > 0; increment = IncremenSqSedgewick[++Si]) {
    for (P = increment; P < num; P++) {
      strcpy(temp, arr[P]);
      for (i = P; i >= increment && strcmp(arr[i - increment], temp) > 0; i -= increment) {
        strcpy(arr[i], arr[i - increment]);
      }
      strcpy(arr[i], temp);
    }
  }
}

void HeapSort(sortedArray_Type a, int num) {
  int i;
  for (i = num / 2 - 1; i >= 0; i--) {
    PercDown(a, i, num);
  }
  for (i = num - 1; i > 0; i--) {
    Swap(a[0], a[i]);
    PercDown(a, 0, i);
  }
}

void MergeSort(sortedArray_Type A, int num) {
  int length;
  sortedArray_Type TmpA = (sortedArray_Type)malloc(num * sizeof(sortedItem_Type));
  for (int i = 0; i < num; i++) {
    TmpA[i] = (sortedItem_Type)malloc(sizeof(char) * ITEMMAXLEN);
  }
  length = 1; /* ��ʼ�������г���*/
  if (TmpA != NULL) {
    while (length < num) {
      Merge_pass(A, TmpA, num, length);
      length *= 2;
      Merge_pass(TmpA, A, num, length);
      length *= 2;
    }
    for (int i = 0; i < num; i++) {
      free(TmpA[i]);
    }
    free(TmpA);
  } else printf("�ռ䲻��");
}

void QuickSort(sortedArray_Type A, int num) { /* ͳһ�ӿ� */
  Qsort(A, 0, num - 1);
}

/* local functions */

static void Swap(sortedItem_Type & a, sortedItem_Type  & b) {
  sortedItem_Type temp = (sortedItem_Type)malloc(sizeof(char) * ITEMMAXLEN);
  strcpy(temp, a);
  strcpy(a, b);
  strcpy(temp, b);
}

static void PercDown(sortedArray_Type a, int p, int num) {
  int Parent, Child;
  sortedItem_Type x = (sortedItem_Type)malloc(sizeof(char) * ITEMMAXLEN);
  strcpy(x, a[p]);
  for (Parent = p; (Parent * 2 + 1) < num; Parent = Child) {
    Child = Parent * 2 + 1;
    if ((Child != num - 1) && strcmp(a[Child], a[Child + 1]) < 0) {
      Child++;
    }
    if (strcmp(x, a[Child]) >= 0) {
      break;
    } else {
      strcpy(a[Parent], a[Child]);
    }
  }
  strcpy(a[Parent], x);
}

static void Merge(sortedArray_Type A, sortedArray_Type TmpA, int L, int R, int RightEnd) {
  /* �������A[L]~A[R-1]��A[R]~A[RightEnd]�鲢��һ���������� */
  int LeftEnd, NumElements, Tmp;
  int i;
  LeftEnd = R - 1; /* ����յ�λ�� */
  Tmp = L;         /* �������е���ʼλ�� */
  NumElements = RightEnd - L + 1;
  while (L <= LeftEnd && R <= RightEnd) {
    if (strcmp(A[L], A[R]) <= 0)
      strcpy(TmpA[Tmp++], A[L++]);  /* �����Ԫ�ظ��Ƶ�TmpA */
    else
      strcpy(TmpA[Tmp++], A[R++]);  /* ���ұ�Ԫ�ظ��Ƶ�TmpA */
  }
  while (L <= LeftEnd)
    strcpy(TmpA[Tmp++], A[L++]); /* ֱ�Ӹ������ʣ�µ� */
  while (R <= RightEnd)
    strcpy(TmpA[Tmp++], A[R++]); /* ֱ�Ӹ����ұ�ʣ�µ� */
  for (i = 0; i < NumElements; i++, RightEnd--)
    strcpy(A[RightEnd], TmpA[RightEnd]);  /* �������TmpA[]���ƻ�A[] */
}

/* length = ��ǰ�������еĳ���*/
static void Merge_pass(sortedArray_Type A, sortedArray_Type TmpA, int N, int length) { /* �����鲢������������ */
  int i, j;
  for (i = 0; i <= N - 2 * length; i += 2 * length)
    Merge(A, TmpA, i, i + length, i + 2 * length - 1);
  if (i + length < N) /* �鲢���2������*/
    Merge(A, TmpA, i, i + length, N - 1);
  else /* ���ֻʣ1������*/
    for (j = i; j < N; j++) TmpA[j] = A[j];
}

static sortedItem_Type Median3(sortedArray_Type A, int Left, int Right) {
  int Center = (Left + Right) / 2;
  if (A[Left] > A[Center])
    Swap(A[Left], A[Center]);
  if (A[Left] > A[Right])
    Swap(A[Left], A[Right]); 
    Swap(A[Center], A[Right]);
  /* ��ʱA[Left] <= A[Center] <= A[Right] */
  Swap(A[Center], A[Right - 1]); /* ����׼Pivot�ص��ұ�*/
  /* ֻ��Ҫ����A[Left+1] �� A[Right-2] */
  return  A[Right - 1];  /* ���ػ�׼Pivot */
}

static void Qsort(sortedArray_Type A, int Left, int Right) { /* ���ĵݹ麯�� */
  sortedItem_Type Pivot = (sortedItem_Type)malloc(sizeof(char) * ITEMMAXLEN);
  int Low, High;
  int Cutoff = 50;  // ��ֵ�������г��Сʱ��ֱ��ʹ�ò�������Ч�ʸ���
  if (Cutoff <= Right - Left) { /* �������Ԫ�س�ֶ࣬������� */
    strcpy(Pivot, Median3(A, Left, Right)); /* ѡ��׼ */
    Low = Left; High = Right - 1;
    while (1) { /*�������бȻ�׼С���Ƶ���׼��ߣ�����Ƶ��ұ�*/
      
      while (strcmp(A[++Low], Pivot) < 0);
      while (strcmp(A[--High], Pivot) > 0);
      if (Low < High) Swap(A[Low], A[High]);
      else break;
    }
    Swap(A[Low], A[Right - 1]);   /* ����׼������ȷ��λ�� */
    Qsort(A, Left, Low - 1);    /* �ݹ������ */
    Qsort(A, Low + 1, Right);   /* �ݹ����ұ� */
  } else InsertionSort(A + Left, Right - Left + 1); /* Ԫ��̫�٣��ü����� */
}
