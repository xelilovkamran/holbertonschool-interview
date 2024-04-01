#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int is_palindrome(listint_t **head) {
    listint_t *current;
    int n, i, j;
    int *array;

    if (*head == NULL) {
        return (1);
    }

    current = *head;

    n = 0;
    while (current != NULL) {
        current = current->next;
        n++;
    }

    array = (int *) malloc(sizeof(int) * (n / 2));

    if (array == NULL) {
        return (0);
    }
    
    current = *head;
    for (i = 0; i < n / 2; i++) {
        array[i] = current->n;
        current = current->next;
    }
    current = *head;

    int termination_point;

    if (n % 2 == 0) {
        termination_point = n / 2;
    } else {
        termination_point = n / 2 + 1;
    }

    for (int i = (n / 2) - 1; i >= termination_point; i--) {
        if (array[i] != current->n) {
            free(array);
            free(current);
            return (0);
        }
        current = current->next;
    }

    free(array);
    free(current);
    return (1);
}