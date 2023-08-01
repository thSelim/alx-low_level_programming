#include "lists.h"

/**
 * find_listint_loop - Finds the node where a loop starts in a linked list.
 *
 * @head: Pointer to the head of the linked list to search.
 *
 * Return: The address of the node where the loop starts, or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *slow_ptr = head;
    listint_t *fast_ptr = head;

    if (head == NULL) {
        // The list is empty
        return NULL;
    }

    while (slow_ptr && fast_ptr && fast_ptr->next) {
        // Move the slow_ptr one step and the fast_ptr two steps
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        if (slow_ptr == fast_ptr) {
            // We have found a loop in the list
            slow_ptr = head;
            while (slow_ptr != fast_ptr) {
                // Move both pointers one step at a time until they meet
                slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next;
            }
            return fast_ptr;
        }
    }

    // There is no loop in the list
    return NULL;
}
