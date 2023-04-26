#include "sort.h"


/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order using
 *                       the insertion sort algorithm.
 * @list: A double pointer to the head of the list to sort.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *behind, *forward;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (forward = (*list)->next; forward != NULL; forward = forward->next)
	{
		behind = forward->prev;
		for (; behind && forward->n < behind->n; behind = forward->prev)
		{
			/* swap nodes */
			behind->next = forward->next;
			if (forward->next != NULL)
				forward->next->prev = behind;
			forward->next = behind;
			forward->prev = behind->prev;
			if (behind->prev != NULL)
				behind->prev->next = forward;
			else
				*list = forward;
			behind->prev = forward;
			/* display the list */
			print_list((const listint_t *)(*list));
		}
	}
}
