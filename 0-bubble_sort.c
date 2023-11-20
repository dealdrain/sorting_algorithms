#include "sort.h"

/**
 * bubble_sort - sorting an array of ints
 * @array: the array
 * @size: array size
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int x;

	for (i = 1; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				x = array[j];
				array[j] = array[j + 1];
				array[j + 1] = x;
				print_array(array, size);
			}
		}
	}
}

