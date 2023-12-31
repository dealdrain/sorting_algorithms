#include "sort.h"

/**
 * swap_node - Swapng two nodes in a DL list.
 * @node_a: First node
 * @node_b: Second node
 * @list: DL list.
 */
void swap_node(listint_t *node_a, listint_t *node_b, listint_t **list)
{
	listint_t *temp_next_a = node_a->next;
	listint_t *temp_prev_b = node_b->prev;

	if (temp_next_a)
		temp_next_a->prev = node_b;
	if (temp_prev_b)
		temp_prev_b->next = node_a;

	node_a->prev = temp_prev_b;
	node_b->next = temp_next_a;
	node_a->next = node_b;
	node_b->prev = node_a;

	if (*list == node_b)
		*list = node_a;

	print_list(*list);
}

/**
 * cocktail_sort_list - Sorting dL list using Cocktail kind of sort.
 * @list: DL list.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *first = NULL, *last = NULL;

	if (!list || !(*list) || !((*list)->next))
		return;

	do {
		current = *list;

		while (current->next)
		{
			if (current->n > current->next->n)
				swap_node(current->next, current, list);
			else
				current = current->next;
		}
		last = current;

		while (current->prev != first)
		{
			if (current->n < current->prev->n)
				swap_node(current, current->prev, list);
			else
				current = current->prev;
		}

		first = current;

	} while (first != last);
}
