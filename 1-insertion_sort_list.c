#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the insertion sort algorithm
 * @list: A pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
  listint_t *current;
  listint_t *tmp;

  if (list == NULL || *list == NULL || (*list)->next == NULL)
    return;

  current = (*list)->next; 
  while (current != NULL) {
    tmp = current->prev;
    while (tmp != NULL && current->n < tmp->n) {
      tmp->next = current->next;
      if (current->next != NULL) {
        current->next->prev = tmp; 
      }
      current->next = tmp;
      current->prev = tmp->prev;
      if (tmp->prev != NULL) {
        tmp->prev->next = current;
      }
      tmp->prev = current;
      if (tmp == *list) {
        *list = current;
      }
      print_list(*list);
      tmp = current->prev;
    }
    current = current->next;
  }
}
