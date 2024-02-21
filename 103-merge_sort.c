#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two subarrays 
 * @array: Array to sort
 * @left: Left subarray index
 * @mid: Mid point 
 * @right: Right subarray index
 * @size: Size of original array
 */
void merge(int *array, int left, int mid, int right, size_t size)
{
  int *tmp = malloc(sizeof(int) * size);
  int i = left, j = mid + 1, k = left;

  printf("Merging...\n[left]: ");
  print_array(array + left, mid - left + 1);

  printf("[right]: ");
  print_array(array + mid + 1, right - mid);

  while(i <= mid && j <= right) {
    if(array[i] <= array[j]) {
      tmp[k] = array[i];
      i++;
    } else {
      tmp[k] = array[j];
      j++;
    }
    k++;
  }

  while(i <= mid) {
    tmp[k] = array[i];
    i++;
    k++;
  }

  while(j <= right) {
    tmp[k] = array[j];
    j++;
    k++; 
  }

  printf("[Done]: ");
  print_array(tmp + left, right - left + 1);
  printf("\n");

  for(i = left; i <= right; i++) {
    array[i] = tmp[i];
  }

  free(tmp);
}

/**
 * top_down_split - Splits array recursively
 * @array: Array to sort 
 * @left: Left index
 * @right: Right index
 * @size: Size of original array
 */
void top_down_split(int *array, int left, int right, size_t size) 
{
  if (right - left <= 0)
    return;

  int mid = (left + right) / 2;

  top_down_split(array, left, mid, size);
  top_down_split(array, mid + 1, right, size);

  merge(array, left, mid, right, size);
}

/**
 * merge_sort - Sorts an array of integers in ascending
 *              order using the merge sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
  top_down_split(array, 0, size - 1, size);
}
