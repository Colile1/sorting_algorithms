#include "sort.h"

/**
 * swap - Swap two elements in an array
 * @a: First element
 * @b: Second element
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
 * lomuto_partition - Implementation of Lomuto partition scheme
 * @array: The array to partition
 * @low: Starting index 
 * @high: Ending index
 * @size: Size of the array
 *
 * Return: Index of the pivot after partition
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
  int pivot = array[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j], array);
    }
  }

  swap(&array[i + 1], &array[high], array);
  return (i + 1);
}

/**
 * quicksort_recursion - Recursive quicksort 
 * @array: The array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
void quicksort_recursion(int *array, int low, int high, size_t size)
{
  if (low < high) {
    int pi = lomuto_partition(array, low, high, size);

    quicksort_recursion(array, low, pi - 1, size);  
    quicksort_recursion(array, pi + 1, high, size);
  }
}

/**
 * quick_sort - Sorts an array of ints in ascending order
 *              using the quicksort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
  quicksort_recursion(array, 0, size - 1, size);
}
