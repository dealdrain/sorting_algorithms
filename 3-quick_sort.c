#include "sort.h"

/**
 * partition - partition of the array
 * @array: the array to sort
 * @low: low position
 * @high: high position
 * @size: array size
 * Return: int index
 */
int partition(int *array, int low, int high, size_t size)
{
	int i = low - 1, temp;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < array[high])
		{
			i++;
			if (i < j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * qs - sorting int in recursion
 * @array: the arr
 * @low: low position
 * @high: high position
 * @size: size of arr
 */
void qs(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = partition(array, low, high, size);

		qs(array, low, pivot - 1, size);
		qs(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorting arr with Quick sort alg
 * @array: the arr
 * @size: arr size
 */
void quick_sort(int *array, size_t size)
{
	qs(array, 0, size - 1, size);
}
