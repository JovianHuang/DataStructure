#ifndef SORT_H
#define SORT_H

typedef char * sortedItem_Type;
typedef char ** sortedArray_Type;

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
void BubbleSort(sortedArray_Type arr, int num);

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
void SelectionSort(sortedArray_Type arr, int num);

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
void InsertionSort(sortedArray_Type arr, int num);

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
void ShellSort(sortedArray_Type arr, int num);

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
void MergeSort(sortedArray_Type arr, int num);

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
void QuickSort(sortedArray_Type arr, int num);

/* operation: Sort the array to be sorted in ascending order */
/* preconditions: The array exists and the size is not zero */
/* postconditions: Array is sorted in ascending order */
void HeapSort(sortedArray_Type arr, int num);

#endif // !SORT_H
