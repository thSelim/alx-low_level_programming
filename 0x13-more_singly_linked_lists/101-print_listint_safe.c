#include "lists.h"
#include <stdio.h>

/**
 * looped_listint_len - Counts the number of unique nodes in a looped listint_t linked list.
 *
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0. Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
    const listint_t *slow_ptr, *fast_ptr;
    size_t nodes = 1;

    if (head == NULL || head->next == NULL) {
        // The list is empty or has only one node
        return 0;
    }

    // Initialize the slow_ptr and the fast_ptr
    slow_ptr = head->next;
    fast_ptr = (head->next)->next;

    while (fast_ptr != NULL) {
        if (slow_ptr == fast_ptr) {
            // The list has a loop
            slow_ptr = head;
            while (slow_ptr != fast_ptr) {
                nodes++;
                slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next;
            }
            slow_ptr = slow_ptr->next;
            while (slow_ptr != fast_ptr) {
                nodes++;
                slow_ptr = slow_ptr->next;
            }
            return nodes;
        }
        slow_ptr = slow_ptr->next;
        fast_ptr = (fast_ptr->next)->next;
    }

    // The list is not looped
    return 0;
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 *
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t nodes, index = 0;

    nodes = looped_listint_len(head);

    if (nodes == 0) {
        // The list is not looped
        for (; head != NULL; nodes++) {
            printf("[%p] %d\n", (void *)head, head->n);
            head = head->next;
        }
    } else {
        // The list is looped
        for (index = 0; index < nodes; index++) {
            printf("[%p] %d\n", (void *)head, head->n);
            head = head->next;
        }
        printf("-> [%p] %d\n", (void *)head, head->n);
    }

    return nodes;
}
