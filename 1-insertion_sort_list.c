#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @first_node: first node to be swapped
 * @second_node: second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *first_node, listint_t *second_node);

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *forward, *temporary;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    for (forward = (*list)->next; forward && forward->prev; forward = forward->next)
    {
        for (; forward && forward->prev && forward->n < forward->prev->n; forward = forward->prev)
        {
            temporary = forward->prev;
            swap_nodes(list, temporary, forward);
            print_list(*list);
            forward = forward->next;
        }
    }
}

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @first_node: first node to be swapped
 * @second_node: second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *first_node, listint_t *second_node)
{
    listint_t *previous, *next_node;

    previous = first_node->prev;
    next_node = second_node->next;

    if (previous != NULL)
        previous->next = second_node;
    else
        *list = second_node;

    first_node->prev = second_node;
    first_node->next = next_node;
    second_node->prev = previous;
    second_node->next = first_node;

    if (next_node)
        next_node->prev = first_node;
}
