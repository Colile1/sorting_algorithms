#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the shell sort algorithm, Knuth sequence
 * @array: The array to sort
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
    int interval = 1;
    int i, j, valueToInsert;

    while (interval < size)
    {
        interval = interval * 3 + 1;
    }

    while (interval > 0)
    {
        for (i = interval; i < size; i++)
        {
            valueToInsert = array[i];
            j = i;

            while (j > interval - 1 && array[j - interval] >= valueToInsert)
            {
                array[j] = array[j - interval];
                j = j - interval;
            }

            array[j] = valueToInsert;
        }

        print_array(array, size);

        interval = (interval - 1) / 3;
    }
}
