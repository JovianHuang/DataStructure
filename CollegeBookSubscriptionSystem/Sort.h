#ifndef SORT_H
#define SORT_H

typedef int sortedItem_Type;
typedef int* sortedArray_Type;

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
/* T(n) = O(n^2), S(n) = O(1) */
void BubbleSort(sortedArray_Type arr, int size);

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
/* T(n) = O(n^2), S(n) = O(1) */
void SelectionSort(sortedArray_Type arr, int size);

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
/* T(n) = O(n^2), S(n) = O(1) */
void InsertionSort(sortedArray_Type arr, int size);

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
/* T(n) = O(n^1.3), S(n) = O(1) */
void ShellSort(sortedArray_Type arr, int size);

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
/* T(n) = O(n * log2n), S(n) = O(n) */
void MergeSort(sortedArray_Type arr, int size);

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
/* T(n) = O(n * log2n), S(n) = O(nlog2n) */
void QuickSort(sortedArray_Type arr, int size);

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
/* T(n) = O(n * log2n), S(n) = O(1) */
void HeapSort(sortedArray_Type arr, int size);

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
/* T(n) = O(n + k), S(n) = O(n + k) */
void CountingSort(sortedArray_Type arr, int size);

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
/* T(n) = O(n + k), S(n) = O(n + k) */
void BucketSort(sortedArray_Type arr, int size);

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
/* T(n) = O(n * k), S(n) = O(n + k) */
void RadixSort(sortedArray_Type arr, int size);

#endif // !SORT_H
