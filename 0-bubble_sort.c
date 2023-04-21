#include "sort.h"
#include <stdbool.h>

/**
 * bubble_sort - Sorts an array of integers in ascending order using the
 *               Bubble sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, tmp;
	bool swap = true;

	if (array == NULL || size < 2)
		return;

	while (swap == true)
	{
		swap = false;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;
				print_array(array, size);
				swap = true;
			}
		}
	}
}
