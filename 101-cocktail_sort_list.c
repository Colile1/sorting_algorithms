#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: A pointer to the head of a doubly linked list of integers
 *
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *current;
    int swapped = 1;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = *list;
    while (swapped)
    {
        swapped = 0;
        while (current->next != NULL)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(current, current->next);
                print_list(*list);
                swapped = 1;
            }
            current = current->next;
        }

        if (!swapped)
            break;
        swapped = 0;
        while (current->prev != NULL)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(current->prev, current);
                print_list(*list);
                swapped = 1;
            }
            current = current->prev;
        }
    }
}
