#include <stdio.h>
#include "sort.h"


/**
 * swap_nodes - Swaps two nodes of a doubly linked list.
 * @h: A double pointer to the head of the list whose nodes we want to swap.
 * @t: A double pointer to the end of the list whose nodes we want to swap.
 * @n1: The first node.
 * @n2: The second node.
 */
void swap_nodes(listint_t **h, listint_t **t, listint_t *n1, listint_t *n2)
{
	n1->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = n1;
	else
		*t = n1;

	n2->next = n1;
	n2->prev = n1->prev;

	if (n1->prev != NULL)
		n1->prev->next = n2;
	else
		*h = n2;

	n1->prev = n2;
}

/**
 * cocktail_sort_list - Sort a doubly linked list in ascending order
 *                      using the Cocktail shaker sort algorithm.
 * @list: A double pointer to the head of the list to be sorted.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp, *tail;
	int swap;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	tail = *list;
	while (tail->next)
		tail = tail->next;

	do {
		swap = 0;
		/* Run loop forward, swap if necesary */
		for (tmp = *list; tmp->next; tmp = tmp->next)
		{
			if (tmp->n > tmp->next->n)
			{
				swap_nodes(list, &tail, tmp, tmp->next);
				tmp = tmp->prev;
				swap = 1;
				print_list((const listint_t *)(*list));
			}
		}
		if (swap == 0)
			break;

		swap = 0;
		/* Run loop backward, swap if necessary */
		for (tmp = tail; tmp->prev; tmp = tmp->prev)
		{
			if (tmp->prev->n > tmp->n)
			{
				swap_nodes(list, &tail, tmp->prev, tmp);
				tmp = tmp->next;
				swap = 1;
				print_list((const listint_t *)(*list));
			}
		}
	} while (swap == 1);
}
