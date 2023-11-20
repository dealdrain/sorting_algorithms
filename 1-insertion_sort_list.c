#include "sort.h"

/**
 * insertion_sort_list - Sorting a dl list (int)
 * @list: The DL list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *next_node, *aux;

    if (!list || !(*list) || !(*list)->next)
        return;

    current = *list;
    while (current->next)
    {
        next_node = current->next;
        if (current->n > next_node->n)
        {
            next_node->prev = current->prev;
            if (next_node->prev)
                next_node->prev->next = next_node;
            else
                *list = next_node;

            current->prev = next_node;
            current->next = next_node->next;
            next_node->next = current;
            if (current->next)
                current->next->prev = current;

            current = next_node->prev;
            print_list(*list);

            while (current->prev && current->prev->n > current->n)
            {
                aux = current->next;
                current->next = current->prev;
                current->prev = current->next->prev;
                current->next->prev = current;
                current->next->next = aux;

                if (current->prev)
                    current->prev->next = current;
                else
                    *list = current;

                print_list(*list);
            }
        }
        current = current->next;
    }
}

