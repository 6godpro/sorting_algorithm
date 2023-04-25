#include "sort.h"
#include <stdio.h>


/**
 * get_max - Returns the max value from an array.
 * @array: The array to return its maximum value.
 * @size: The size of the array.
 * Return: The maximum value.
 */
int get_max(int *array, int size)
{
	int max, i = 0;

	max = array[i];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}

/**
 * radix_counting_sort - Implements the counting sort algorithm
 *                       for Radix sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @pos: Denotes the significance of the digit being computed.
 */
void radix_counting_sort(int *array, int size, int pos)
{
	int *count, *sorted, i;

	count = malloc(sizeof(int) * 10);
	if (count == NULL)
		return;

	for (i = 0; i < 10; i++)
		count[i] = 0;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
	{
		free(count);
		return;
	}
	/* save the frequency of the data in array */
	for (i = 0; i < size; i++)
		count[(array[i] / pos) % 10]++;

	/* update count to contain the actual position of input array values */
	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	/* find index using count and copy value to index of sorted array */
	for (i = (int)size - 1; i >= 0; i--)
		sorted[--count[(array[i] / pos) % 10]] = array[i];

	for (i = 0; i < size; i++)
		array[i] = sorted[i];

	free(count);
	free(sorted);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 *              using Radix sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, pos;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	for (pos = 1; max / pos > 0; pos *= 10)
	{
		radix_counting_sort(array, size, pos);
		print_array(array, size);
	}
}
