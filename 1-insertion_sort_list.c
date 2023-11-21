#include "sort.h"

/**
 * insertion_sort_list - sorting a DL list of int
 * @list: DL list
 * Return: void always
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list, *temp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current)
	{
		while (current->prev && current->n < current->prev->n)
		{
			temp = current;
			if (current->next)
				current->next->prev = temp->prev;
			if (temp->prev)
				temp->prev->next = temp->next;
			current = current->prev;
			temp->prev = current->prev;
			temp->next = current;
			if (current->prev)
				current->prev->next = temp;
			current->prev = temp;
			if (temp->prev == NULL)
				*list = temp;
			print_list(*list);
			current = current->prev;
		}
		current = current->next;
	}
}
