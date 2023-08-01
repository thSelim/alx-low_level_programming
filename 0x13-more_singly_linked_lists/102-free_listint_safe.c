#include "lists.h"

/**
 * free_listint_safe - Frees a linked list.
 *
 * @h: Pointer to the first node in the linked list.
 *
 * Return: The number of elements in the freed list.
 */
size_t free_listint_safe(listint_t **h)
{
    size_t len = 0;
    int diff;
    listint_t *temp;

    if (h == NULL || *h == NULL) {
        // The list is empty
        return 0;
    }

    while (*h != NULL) {
        // Calculate the difference between the current node and the next node in memory
        diff = *h - (*h)->next;

        if (diff > 0) {
            // The list is not circular, so we can safely free the current node and move to the next node.
            temp = (*h)->next;
            free(*h);
            *h = temp;
            len++;
        } else {
            // The list is circular, so we cannot safely free the current node without causing memory errors.
            free(*h);
            *h = NULL;
            len++;
            break;
        }
    }

    *h = NULL;

    return len;
}
