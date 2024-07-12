#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list
 * @list: Pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{

	listint_t *sorted = NULL;

	listint_t *current = *list;

	while (current != NULL)
	{
		listint_t *next = current->next;

		if (sorted == NULL || sorted->n >= current->n)
		{
			current->next = sorted;
			if (sorted != NULL)
				sorted->prev = current;
			sorted = current;
		}
		else
		{
			listint_t *tmp = sorted;
			while (tmp->next != NULL && tmp->next->n < current->n)
				tmp = tmp->next;

			current->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = current;
			tmp->next = current;
			current->prev = tmp;
		}

		current = next;
	}


	*list = sorted;
}

