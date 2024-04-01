#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int is_palindrome(listint_t **head) {
    listint_t *current;
    int n = 0, i = 0, j;
    int *array;

    if (*head == NULL) {
        return 1;
    }

    current = *head;

    while (current != NULL) {
        n++;
        current = current->next;
    }

    array = (int *)malloc(sizeof(int) * n);

    current = *head;
    while (current != NULL) {
        array[i++] = current->n;
        current = current->next;
    }

    for (i = 0, j = n - 1; i < j; i++, j--) {
        if (array[i] != array[j]) {
            free(array);
            return 0;
        }
    }

    free(array);
    return 1; 
}
