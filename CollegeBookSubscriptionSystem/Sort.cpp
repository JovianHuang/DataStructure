#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sort.h"

/* local data type*/

static const int ITEMMAXLEN = 160;

/* prototype for local functions */

static void Copy(sortedItem_Type &a, sortedItem_Type &b);
static sortedItem_Type InitializeItem(void);
static void Swap(sortedItem_Type &a, sortedItem_Type &b);
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
      if (strcmp(arr[j].key, arr[j + 1].key) > 0) {
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
      if (strcmp(arr[j].key, arr[min].key) < 0) {
        min = j;
      }
    }
    Swap(arr[i], arr[min]);
  }
}

void InsertionSort(sortedArray_Type arr, int num) {
  int i, j;
  sortedItem_Type temp = InitializeItem();
  for (i = 1; i < num; i++) {
    if (strcmp(arr[i].key, arr[i - 1].key) < 0) {
      Copy(temp, arr[i]);
      Copy(arr[i], arr[i - 1]);
      for (j = i - 1; strcmp(arr[j].key, temp.key) > 0; j--) {
        Copy(arr[j + 1], arr[j]);
      }
      Copy(arr[j + 1], temp);
    }
  }
}

void ShellSort(sortedArray_Type arr, int num) {
  int Si, increment, P, i;
  sortedItem_Type temp = InitializeItem();
  const int IncremenSqSedgewick[] = { 8929, 3905, 2161, 929, 505, 209, 109, 41, 19, 5, 1, 0 };
  for (Si = 0; IncremenSqSedgewick[Si] >= num; Si++) {
    ;
  }
  for (increment = IncremenSqSedgewick[Si]; increment > 0; increment = IncremenSqSedgewick[++Si]) {
    for (P = increment; P < num; P++) {
      Copy(temp, arr[P]);
      for (i = P; i >= increment && strcmp(arr[i - increment].key, temp.key) > 0; i -= increment) {
        Copy(arr[i], arr[i - increment]);
      }
      Copy(arr[i], temp);
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
  sortedArray_Type TmpA = (ExNode *)malloc(sizeof(ExNode) * num);
  memset(TmpA, 0, num * sizeof(char) * KEYMAXLEN);
  length = 1; /* 初始化子序列长度*/
  if (TmpA != NULL) {
    while (length < num) {
      Merge_pass(A, TmpA, num, length);
      length *= 2;
      Merge_pass(TmpA, A, num, length);
      length *= 2;
    }
    free(TmpA);
  } else printf("空间不足");
}

void QuickSort(sortedArray_Type A, int num) { /* 统一接口 */
  Qsort(A, 0, num - 1);
}

/* local functions */

static void Copy(sortedItem_Type &a, sortedItem_Type &b) {
  strcpy(a.key, b.key);
  a.serialNum = b.serialNum;
}

static sortedItem_Type InitializeItem(void) {
  sortedItem_Type temp;
  memset(&temp, 0, sizeof(ExNode));
  return temp;
}

static void Swap(sortedItem_Type &a, sortedItem_Type &b) {
  sortedItem_Type temp = InitializeItem();
  Copy(temp, a);
  Copy(a, b);
  Copy(b, temp);
}

static void PercDown(sortedArray_Type a, int p, int num) {
  int Parent, Child;
  sortedItem_Type x = InitializeItem();
  Copy(x, a[p]);
  for (Parent = p; (Parent * 2 + 1) < num; Parent = Child) {
    Child = Parent * 2 + 1;
    if ((Child != num - 1) && strcmp(a[Child].key, a[Child + 1].key) < 0) {
      Child++;
    }
    if (strcmp(x.key, a[Child].key) >= 0) {
      break;
    } else {
      Copy(a[Parent], a[Child]);
    }
  }
  Copy(a[Parent], x);
}

static void Merge(sortedArray_Type A, sortedArray_Type TmpA, int L, int R, int RightEnd) {
  /* 将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列 */
  int LeftEnd, NumElements, Tmp;
  int i;
  LeftEnd = R - 1; /* 左边终点位置 */
  Tmp = L;         /* 有序序列的起始位置 */
  NumElements = RightEnd - L + 1;
  while (L <= LeftEnd && R <= RightEnd) {
    if (strcmp(A[L].key, A[R].key) <= 0) {
      Copy(TmpA[Tmp++], A[L++]);  /* 将左边元素复制到TmpA */
    } else {
      Copy(TmpA[Tmp++], A[R++]);  /* 将右边元素复制到TmpA */
    }
  }
  while (L <= LeftEnd) {
    Copy(TmpA[Tmp++], A[L++]);   /* 直接复制左边剩下的 */
  }
  while (R <= RightEnd) {
    Copy(TmpA[Tmp++], A[R++]);
  }
  for (i = 0; i < NumElements; i++, RightEnd--) {
    Copy(A[RightEnd], TmpA[RightEnd]);  /* 将有序的TmpA[]复制回A[] */
  }
}

/* length = 当前有序子列的长度*/
static void Merge_pass(sortedArray_Type A, sortedArray_Type TmpA, int N, int length) { /* 两两归并相邻有序子列 */
  int i, j;
  for (i = 0; i <= N - 2 * length; i += 2 * length)
    Merge(A, TmpA, i, i + length, i + 2 * length - 1);
  if (i + length < N) /* 归并最后2个子列*/
    Merge(A, TmpA, i, i + length, N - 1);
  else /* 最后只剩1个子列*/
    for (j = i; j < N; j++) TmpA[j] = A[j];
}

static sortedItem_Type Median3(sortedArray_Type A, int Left, int Right) {
  int Center = (Left + Right) / 2;
  if (strcmp(A[Left].key, A[Center].key) > 0) {
    Swap(A[Left], A[Center]);
  }
  if (strcmp(A[Left].key, A[Right].key) > 0) {
    Swap(A[Left], A[Right]);
  }
  if (strcmp(A[Center].key, A[Right].key) > 0) {
    Swap(A[Center], A[Right]);
  }
  /* 此时A[Left] <= A[Center] <= A[Right] */
  Swap(A[Center], A[Right - 1]); /* 将基准Pivot藏到右边*/
  /* 只需要考虑A[Left+1] … A[Right-2] */
  return  A[Right - 1];  /* 返回基准Pivot */
}

static void Qsort(sortedArray_Type A, int Left, int Right) { /* 核心递归函数 */
  sortedItem_Type Pivot = InitializeItem();
  int Low, High;
  int Cutoff = 50;  // 阈值，当数列充分小时，直接使用插入排序效率更高
  if (Cutoff <= Right - Left) { /* 如果序列元素充分多，进入快排 */
    sortedItem_Type temp = InitializeItem();
    temp = Median3(A, Left, Right);
    Copy(Pivot, temp); /* 选基准 */
    Low = Left; High = Right - 1;
    while (1) { /*将序列中比基准小的移到基准左边，大的移到右边*/

      while (strcmp(A[++Low].key, Pivot.key) < 0);
      while (strcmp(A[--High].key, Pivot.key) > 0);
      if (Low < High) Swap(A[Low], A[High]);
      else break;
    }
    Swap(A[Low], A[Right - 1]);   /* 将基准换到正确的位置 */
    Qsort(A, Left, Low - 1);    /* 递归解决左边 */
    Qsort(A, Low + 1, Right);   /* 递归解决右边 */
  } else InsertionSort(A + Left, Right - Left + 1); /* 元素太少，用简单排序 */
}
