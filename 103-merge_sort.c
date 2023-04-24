#include "sort.h"
#include <stdio.h>


/**
 * merge_array - Sort a subarray of integers.
 * @array: This is a subarray of an array of integers to be sorted.
 * @sorted: A buffer to store the sorted array.
 * @lb: The lower bound of the array.
 * @mid: The middle index of the array.
 * @ub: The upper bound of the array.
 */
void merge_array(int *array, int *sorted, int lb, int mid, int ub)
{
	int i = lb, j = mid + 1, k = lb;

	printf("Merging...\n[left]: ");
	print_array(array + lb, mid - lb + 1);
	printf("[right]: ");
	print_array(array + mid + 1, ub - mid);

	while (i <= mid && j <= ub)
		sorted[k++] = (array[i] < array[j]) ? array[i++] : array[j++];

	if (i > mid)
	{
		while (j <= ub)
			sorted[k++] = array[j++];
	}
	else
	{
		while (i <= mid)
			sorted[k++] = array[i++];
	}
	for (k = lb; k <= ub; k++)
		array[k] = sorted[k];

	printf("[Done]: ");
	print_array(array + lb, ub - lb + 1);
}

/**
 * merge - The Mergesort algorithm.
 * @array: The array to be sorted.
 * @sorted: A buffer to store the sorted values.
 * @lb: The lower bound of the array.
 * @ub: The upper bound of the array.
 */
void merge(int *array, int *sorted, int lb, int ub)
{
	size_t mid;

	if (lb < ub)
	{
		mid = ((ub - 1) + lb) / 2;

		merge(array, sorted, lb, mid);
		merge(array, sorted, mid + 1, ub);

		merge_array(array, sorted, lb, mid, ub);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array to be sorted.
 */
void merge_sort(int *array, size_t size)
{
	int *sorted;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;

	merge(array, sorted, 0, size - 1);

	free(sorted);
}
