#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

#define UP 0
#define DOWN 1

/**
 * enum bool - Defines true and false Boolean values
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
    false = 0,
    true
} bool;

/**
 * struct listint_s - Node for a doubly linked list
 *
 * @n: Integer stored in the node
 * @prev: Pointer to previous node in the list
 * @next: Pointer to next node in the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Functions to print arrays and linked lists */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting algorithms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);

void quick_sort(int *array, size_t size);
void swap(int *a, int *b, int *array);
int lomuto_partition(int *array, int low, int high, size_t size);
void quicksort_recursion(int *array, int low, int high, size_t size);


void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif /* SORT_H */
