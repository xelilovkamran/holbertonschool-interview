#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value) {
    binary_tree_t *new;
    new = malloc(sizeof(binary_tree_t));
    new->n = value;

    return (new);
}