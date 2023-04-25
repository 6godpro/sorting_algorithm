#include "sort.h"


/**
 * swap_int - Swaps the values of two integers pointers.
 * @x: The first pointer.
 * @y: The second pointer.
 */
void swap_int(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}


/**
 * max_heapify - Creates a complete binary heap from a binary tree.
 * @array: The binary tree represented by an array of integers.
 * @size: The size of the binary tree.
 * @n: The number of nodes in the tree.
 * @idx: The index of a node in the tree.
 */
void max_heapify(int *array, int size, int n, int idx)
{
	int largest = idx, l = 2 * idx + 1, r = l + 1;

	if (l <= n && array[l] > array[largest])
		largest = l;
	if (r <= n && array[r] > array[largest])
		largest = r;

	if (largest > idx)
	{
		swap_int(&array[idx], &array[largest]);
		print_array(array, size);
		max_heapify(array, size, n, largest);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using Heap sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size - 1) / 2; i >= 0; i--)
		max_heapify(array, size, size - 1, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_int(&array[0], &array[i]);
		print_array(array, size);
		max_heapify(array, size, i - 1, 0);
	}
}
