#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sort an array using the Counting sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
    int max = array[0];
    int min = array[0];
    int i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    int k = max - min + 1;
    int *count = malloc(sizeof(int) * k);
    if (count == NULL)
    {
        return;
    }

    for (i = 0; i < k; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < size; i++)
    {
        count[array[i] - min]++;
    }

    printf("%s", "Counting array: ");
    for (i = 0; i < k; i++)
    {
        printf("%d, ", count[i]);
    }
    printf("\n");

    int j = 0;
    for (i = 0; i < k; i++)
    {
        while (count[i] > 0)
        {
            array[j++] = i + min;
            count[i]--;
        }
    }

    free(count);
}
