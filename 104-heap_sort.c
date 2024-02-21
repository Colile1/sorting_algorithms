#include "sort.h"

void swap(int *a, int *b, int *array)
void siftDown(int *array, int size, int i)


/**
 * swap - Swap two elements in an array
 * @a: Index of first element
 * @b: Index of second element
 * @array: The array
 */
void swap(int *a, int *b, int *array)
{
  int tmp = *a;
  *a = *b;  
  *b = tmp;
  print_array(array, 10); 
}

/**
 * siftDown - Repair the heap 
 * @array: The array
 * @size: Size of heap 
 * @i: Index of element to sift down
*/  
void siftDown(int *array, int size, int i)
{
  int max = i; 
  int left = 2*i + 1;
  int right = 2*i + 2;

  if (left < size && array[left] > array[max])
      max = left;

  if (right < size && array[right] > array[max])
      max = right;

  if (max != i) {
    swap(&array[i], &array[max], array);
    siftDown(array, size, max);
  }
}

/**
 * heap_sort - Sorts an array of integers using heap sort
 * @array: The array to sort
 * @size: Size of the array
*/
void heap_sort(int *array, size_t size)
{
  for (int i = size / 2 - 1; i >= 0; i--)
    siftDown(array, size, i);

  for (int i = size - 1; i > 0; i--) {
    swap(&array[0], &array[i], array);
    siftDown(array, i, 0); 
  }
}
