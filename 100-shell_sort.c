#include "sort.h"
#include <stdio.h>


/**
 * swap_values - Swaps two values.
 * @x: The first value.
 * @y: The second value.
 */
void swap_values(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}


/**
 * shell_sort - Sort a dataset using the Shell sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array to be sorted.
 */
void shell_sort(int *array, size_t size)
{
	int i, j, n = size, gap;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (n / 3); gap = gap * 3 + 1)
		;

	for (; gap >= 1; gap /= 3)
	{
		for (j = gap; j < n; j++)
		{
			for (i = j - gap; i >= 0; i -= gap)
			{
				if (array[i] < array[i + gap])
					break;
				swap_values(&array[i], &array[i + gap]);
			}
		}
		print_array(array, size);
	}
}
