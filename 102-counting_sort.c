#include "sort.h"
#include <stdio.h>

/**
 * get_key - Returns the max value from an array.
 * @array: The array to return its maximum value.
 * @size: The size of the array.
 * Return: The maximum value.
 */
int get_key(int *array, int size)
{
	int key, i = 0;

	key = array[i];
	for (i = 1; i < size; i++)
		if (array[i] > key)
			key = array[i];

	return (key);
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array to be sorted.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted_array, key, i = 0;

	if (array == NULL || size < 2)
		return;

	key = get_key(array, size);
	count = malloc(sizeof(int) * (key + 1));
	if (count == NULL)
		return;

	for (i = 0; i <= key; i++)
		count[i] = 0;

	/* Populate count with the frequency of occurence input array values. */
	for (i = 0; i <= (int)size - 1; i++)
		count[array[i]]++;

	for (i = 0; i <= key; i++)
		count[i] += count[i - 1];

	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
	{
		free(count);
		return;
	}

	print_array(count, key + 1);
	/* Starting from the end to maintain stability. */
	for (i = (int)size - 1; i >= 0; i--)
		sorted_array[--count[array[i]]] = array[i];

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];

	free(count);
	free(sorted_array);
}
