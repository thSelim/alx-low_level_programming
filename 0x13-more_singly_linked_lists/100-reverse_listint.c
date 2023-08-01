#include "lists.h"

/**
 * reverse_listint - Reverses a linked list.
 * @head: A pointer to the first node in the list.
 *
 * Return: A pointer to the first node in the new list.
 */
listint_t *reverse_listint(listint_t **head)
{
    listint_t *previous_node = NULL;
    listint_t *current_node = *head;
    listint_t *next_node = NULL;

    while (current_node != NULL)
    {
        // Store the next node, so we don't lose the rest of the list.
        next_node = current_node->next;

        // Reverse the current node's pointer.
        current_node->next = previous_node;

        // Move the previous node and current node pointers one step forward.
        previous_node = current_node;
        current_node = next_node;
    }

    // At this point, the previous_node pointer points to the last node in the original list,
    // which is now the first node in the reversed list. Set the head pointer to this node.
    *head = previous_node;

    return *head;
}
