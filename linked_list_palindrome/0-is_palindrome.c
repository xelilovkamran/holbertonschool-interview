#include <stdio.h>
#include <stdlib.h>

int is_palindrome(listint_t **head) {
    if (*head == NULL) {
        return (1);
    }

    listint_t *current = *head;
    int n, i, j;
    int *array;

    n = 0;
    while (current != NULL) {
        current = current->next;
        n++;
    }

    array = (int *) malloc(sizeof(int) * n);
    current = *head;
    for (i = 0; i < n; i++) {
        array[i] = current->n;
        current = current->next;
    }

    for (i = 0, j = n - 1; i < n / 2; i++, j--) {
        if (array[i] != array[j]) {
            free(array);
            return (0);
        }
    }

    free(array);
    return (1);
}