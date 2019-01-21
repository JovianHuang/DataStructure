#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"

/* local data type*/

/* prototype for local functions */

static void Swap(sortedItem_Type & a, sortedItem_Type & b);
static void PercDown(sortedArray_Type a, int p, int size);
static void Merge(sortedArray_Type A, sortedArray_Type TmpA, int L, int R, int RightEnd);
static void Merge_pass(sortedArray_Type A, sortedArray_Type TmpA, int N, int length);
static sortedItem_Type Median3(sortedArray_Type A, int Left, int Right);
static void Qsort(sortedArray_Type A, int Left, int Right);

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
  int i, j;
  sortedItem_Type temp;
  for (i = 1; i < size; i++) {
    temp = arr[i];
    for (j = i; j > 0 && arr[j - 1] > temp; j--) {
      arr[j] = arr[j - 1];
    }
    arr[j] = temp;
  }
}

void ShellSort(sortedArray_Type arr, int size) {
  int Si, increment, P, i;
  sortedItem_Type temp;
  const int IncremenSqSedgewick[] = { 8929, 3905, 2161, 929, 505, 209, 109, 41, 19, 5, 1, 0 };
  for (Si = 0; IncremenSqSedgewick[Si] >= size; Si++) {
    ;
  }
  for (increment = IncremenSqSedgewick[Si]; increment > 0; increment = IncremenSqSedgewick[++Si]) {
    for (P = increment; P < size; P++) {
      temp = arr[P];
      for (i = P; i >= increment && arr[i - increment] > temp; i -= increment) {
        arr[i] = arr[i - increment];
      }
      arr[i] = temp;
    }
  }
}

void HeapSort(sortedArray_Type a, int size) {
  int i;
  for (i = size / 2 - 1; i >= 0; i--) {
    PercDown(a, i, size);
  }
  for (i = size - 1; i > 0; i--) {
    Swap(a[0], a[i]);
    PercDown(a, 0, i);
  }
}

void MergeSort(sortedArray_Type A, int size) {
  int length;
  sortedArray_Type TmpA;
  length = 1; /* ��ʼ�������г���*/
  TmpA = (sortedArray_Type)malloc(size * sizeof(sortedArray_Type));
  if (TmpA != NULL) {
    while (length < size) {
      Merge_pass(A, TmpA, size, length);
      length *= 2;
      Merge_pass(TmpA, A, size, length);
      length *= 2;
    }
    free(TmpA);
  } else printf("�ռ䲻��");
}

void QuickSort(sortedArray_Type A, int size) { /* ͳһ�ӿ� */
  Qsort(A, 0, size - 1);
}

/* local functions */

static void Swap(sortedItem_Type & a, sortedItem_Type  & b) {
  sortedItem_Type temp = a;
  a = b;
  b = temp;
}

static void PercDown(sortedArray_Type a, int p, int size) {
  int Parent, Child;
  sortedItem_Type x;
  x = a[p];
  for (Parent = p; (Parent * 2 + 1) < size; Parent = Child) {
    Child = Parent * 2 + 1;
    if ((Child != size - 1) && (a[Child] < a[Child + 1])) {
      Child++;
    }
    if (x >= a[Child]) {
      break;
    } else {
      a[Parent] = a[Child];
    }
  }
  a[Parent] = x;
}

static void Merge(sortedArray_Type A, sortedArray_Type TmpA, int L, int R, int RightEnd) {
  /* �������A[L]~A[R-1]��A[R]~A[RightEnd]�鲢��һ���������� */
  int LeftEnd, NumElements, Tmp;
  int i;
  LeftEnd = R - 1; /* ����յ�λ�� */
  Tmp = L;         /* �������е���ʼλ�� */
  NumElements = RightEnd - L + 1;
  while (L <= LeftEnd && R <= RightEnd) {
    if (A[L] <= A[R])
      TmpA[Tmp++] = A[L++]; /* �����Ԫ�ظ��Ƶ�TmpA */
    else
      TmpA[Tmp++] = A[R++]; /* ���ұ�Ԫ�ظ��Ƶ�TmpA */
  }
  while (L <= LeftEnd)
    TmpA[Tmp++] = A[L++]; /* ֱ�Ӹ������ʣ�µ� */
  while (R <= RightEnd)
    TmpA[Tmp++] = A[R++]; /* ֱ�Ӹ����ұ�ʣ�µ� */
  for (i = 0; i < NumElements; i++, RightEnd--)
    A[RightEnd] = TmpA[RightEnd]; /* �������TmpA[]���ƻ�A[] */
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
  int Pivot, Low, High;
  int Cutoff = 50;  // ��ֵ�������г��Сʱ��ֱ��ʹ�ò�������Ч�ʸ���
  if (Cutoff <= Right - Left) { /* �������Ԫ�س�ֶ࣬������� */
    Pivot = Median3(A, Left, Right); /* ѡ��׼ */
    Low = Left; High = Right - 1;
    while (1) { /*�������бȻ�׼С���Ƶ���׼��ߣ�����Ƶ��ұ�*/
      while (A[++Low] < Pivot);
      while (A[--High] > Pivot);
      if (Low < High) Swap(A[Low], A[High]);
      else break;
    }
    Swap(A[Low], A[Right - 1]);   /* ����׼������ȷ��λ�� */
    Qsort(A, Left, Low - 1);    /* �ݹ������ */
    Qsort(A, Low + 1, Right);   /* �ݹ����ұ� */
  } else InsertionSort(A + Left, Right - Left + 1); /* Ԫ��̫�٣��ü����� */
}
