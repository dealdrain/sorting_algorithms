#include "sort.h"

/**
 * selection_sort - Sorts an array using the selection sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in @array.
 */
void selection_sort(int *array, size_t size)
{
	size_t cur_idx, comp_idx, min_idx, temp, swap_flag;

	if (array == NULL)
		return;

	for (cur_idx = 0; cur_idx < size; cur_idx++)
	{
		for (min_idx = cur_idx, comp_idx = cur_idx; comp_idx < size; comp_idx++)
		{
		if (array[comp_idx] < array[min_idx])
		{
			min_idx = comp_idx;
			swap_flag = 1;
		}
	}
		if (swap_flag == 1)
		{
			temp = array[min_idx];
			array[min_idx] = array[cur_idx];
			array[cur_idx] = temp;
			print_array(array, size);
			swap_flag = 0;
		}
	}
}
