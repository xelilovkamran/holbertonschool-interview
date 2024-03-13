#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - function that inserts a value in Max Binary Heap
 * @value: value to be inserted
 * @root: tree root
 * Return: pointer to the created node, or NULL on failure.
 */

void correct_heap(heap_t **root) {
    if ((*root)->left != NULL && (*root)->right != NULL) {
        correct_heap(&(*root)->left);
        correct_heap(&(*root)->right);
    } else if ((*root)->left != NULL && (*root)->right == NULL && (*root)->left->left != NULL) {
        heap_t *new = (*root)->left;
        if (new->n > new->left->n) {
            (*root)->right = new;
            (*root)->right->parent = *root;
            (*root)->left = new->left;
            (*root)->left->parent = *root;
            new->left = NULL;
        } else {
            (*root)->right = new->left;
            (*root)->right->parent = *root;
            new->left = NULL;
        }
    } else if ((*root)->right != NULL && (*root)->left == NULL && (*root)->right->left != NULL) {
        heap_t *new = (*root)->right;
        if (new->n < new->left->n) {
            (*root)->left = new;
            (*root)->left->parent = *root;
            (*root)->right = new->left;
            (*root)->right->parent = *root;
            new->left = NULL;
        } else {
            (*root)->left = new->left;
            (*root)->left->parent = *root;
            new->left = NULL;
        }
    }
}

int height(heap_t *root) {
    int left, right;

    if (root == NULL) {
        return (0);
    }

    left = height(root->left);
    right = height(root->right);

    if (left > right) {
        return (left + 1);
    } else {
        return (right + 1);
    }
}

int left_is_full(heap_t *root, int h) {
    int count = 0;
    heap_t *temp = root;

    if (temp == NULL) {
        temp = temp->left;
    }

    while (temp->left != NULL && temp->right != NULL) {
        count++;
        temp = temp->left;
    }

    if (count == h - 1) {
        return (1);
    } else {
        return (0);
    }
}

int right_is_full(heap_t *root, int h) {
    int count = 0;
    heap_t *temp = root;

    if (temp == NULL) {
        temp = temp->right;
    }

    while (temp->left != NULL && temp->right != NULL) {
        count++;
        temp = temp->right;
    }

    if (count == h - 1) {
        return (1);
    } else {
        return (0);
    }
}

heap_t *heap_insert(heap_t **root, int value) {
    heap_t *new;
    int left_is_ful, right_is_ful;

    if (*root == NULL) {
        *root = malloc(sizeof(heap_t));
        if (*root == NULL) {
            return NULL;
        }
        (*root)->n = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->parent = NULL;
        return *root;
    }

    new = malloc(sizeof(heap_t));

    if (new == NULL) {
        return (NULL);
    }

    new->n = value;
    new->left = NULL;
    new->right = NULL;
    new->parent = NULL;

    if ((*root)->n > value && (*root)->left == NULL)
    {
        new->parent = *root;
        (*root)->left = new;
        return (new);
    }
    else if ((*root)->n > value && (*root)->right == NULL)
    {
        new->parent = *root;
        (*root)->right = new;
        return (new);
    }
    else if (((*root)->n < value)) {
        int left_is_ful = left_is_full(*root, height(*root));
        int right_is_ful = right_is_full(*root, height(*root));


        if ((left_is_ful == 1 && right_is_ful == 1) || (left_is_ful == 0 && right_is_ful == 1) || (left_is_ful == 0 && right_is_ful == 0)) {
            if ((*root)->parent == NULL && (*root)->left != NULL) {
                new->parent = (*root)->parent;
                new->right = (*root)->right;
                new->left = (*root);
                (*root)->right = NULL;
                *root = new;
            } else {
                new->parent = (*root)->parent;
                new->left = *root;
                (*root)->parent = new;
                *root = new;
            }
        }
        else if (left_is_ful == 1 && right_is_ful == 0) {
            if ((*root)->parent == NULL && (*root)->right != NULL) {
                new->parent = (*root)->parent;
                new->left = (*root)->left;
                new->right = (*root);
                (*root)->left = NULL;
                *root = new;
            } else {
                new->parent = (*root)->parent;
                new->right = *root;
                (*root)->parent = new;
                *root = new;
            }
        }

        correct_heap(root);

        return (new);
    }

    left_is_ful = left_is_full(*root, height(*root));
    right_is_ful = right_is_full(*root, height(*root));

    if ((left_is_ful == 1 && right_is_ful == 1) || (left_is_ful == 0 && right_is_ful == 1) || (left_is_ful == 0 && right_is_ful == 0)) {
        heap_insert(&(*root)->left, value);
    } else {
        heap_insert(&(*root)->right, value);
    }

    return (new);
}