#include "sort.h"

/**
 * shell_sort - Sorting an arr with shell sort alg
 * @array: The arr
 * @size: len of arr
 * Return: Nothing always
 */

void shell_sort(int *array, size_t size)
{
	unsigned int outer, inner, gap;
	int curr;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (outer = gap; outer < size; outer++)
		{
			curr = array[outer];
			for (inner = outer; inner >= gap && array[inner - gap] > curr; inner -= gap)
				array[inner] = array[inner - gap];
			array[inner] = curr;
		}
		print_array(array, size);
	}
}
