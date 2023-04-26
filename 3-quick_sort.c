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
 * lomuto_partition - Partitions an array using the lomuto
 *                    partition scheme.
 * @array: The array to compute its pivot.
 * @size: The size of the array.
 * @l: The leftmost part of the array.
 * @r: The rightmost part of the array.
 * Return: The index of the pivot.
 */
int lomuto_partition(int *array, int size, int l, int r)
{
	int pivot = array[r], curr = r, i;

	for (i = r; i >= l; i--)
	{
		if (array[i] > pivot)
		{
			curr--;
			swap_values(&array[i], &array[curr]);
			print_array(array, size);
		}
	}
	swap_values(&array[r], &array[curr]);
	print_array(array, size);

	return (curr);
}


/**
 * lomuto_sort - Sorts an algorithm using Lomuto partition
 *               scheme.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @l: The leftmost part of the array.
 * @r: The rightmost part of the array.
 */
void lomuto_sort(int *array, int size, int l, int r)
{
	int idx;

	if (l >= r || l < 0)
		return;

	idx = lomuto_partition(array, size, l, r);

	lomuto_sort(array, size, l, idx - 1);

	lomuto_sort(array, size, idx + 1, r);
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using Quick sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array to be sorted.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
