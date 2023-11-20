#include "sort.h"

/**
 * bubble_sort - sorting an array of ints
 * @array: the array
 * @size: array size
 * int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	for (i = 1; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}

