#ifndef SORT_H
#define SORT_H

typedef int sortedItem_Type;
typedef int* sortedArray_Type;

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
void BubbleSort(sortedArray_Type arr, int size);

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
void SelectionSort(sortedArray_Type arr, int size);

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
void InsertionSort(sortedArray_Type arr, int size);

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
void ShellSort(sortedArray_Type arr, int size);

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
void MergeSort(sortedArray_Type arr, int size);

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
void QuickSort(sortedArray_Type arr, int size);

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
void HeapSort(sortedArray_Type arr, int size);

#endif // !SORT_H
