#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in a linked list at a certain index
 * @head: pointer to the first element in the list
 * @index: index of the node to delete
 *
 * Return: 1 (Success), or -1 (Fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    if (*head == NULL) {
        // The list is empty
        return -1;
    }

    listint_t *current = *head;
    if (index == 0) {
        // Delete the first node
        *head = (*head)->next;
        free(current);
        return 1;
    }

    // Find the node before the one to be deleted
    unsigned int i = 0;
    while (i < index - 1 && current->next != NULL) {
        current = current->next;
        i++;
    }

    if (i < index - 1) {
        // The index is out of range
        return -1;
    }

    // Delete the node
    listint_t *node_to_delete = current->next;
    current->next = node_to_delete->next;
    free(node_to_delete);

    return 1;
}
