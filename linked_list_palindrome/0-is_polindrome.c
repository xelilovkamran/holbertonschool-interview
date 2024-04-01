#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int is_palindrome(listint_t **head) {
    listint_t *current;
    int n = 0, i = 0, j;
    int *array;

    if (*head == NULL) {
        return 1; // Empty list is palindrome
    }

    current = *head;

    // Count the number of unique elements
    while (current != NULL) {
        n++;
        current = current->next;
    }

    array = (int *)malloc(sizeof(int) * n);

    // Fill the array with unique elements
    current = *head;
    while (current != NULL) {
        array[i++] = current->n;
        current = current->next;
    }

    // Check for palindrome
    for (i = 0, j = n - 1; i < j; i++, j--) {
        if (array[i] != array[j]) {
            free(array);
            return 0; // Not a palindrome
        }
    }

    free(array);
    return 1; // Palindrome
}
