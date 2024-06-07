#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

binary_tree_t *add_node(int *array, size_t size, avl_t *parent)
{
	binary_tree_t *node;

	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);

	node->n = array[(size - 1) / 2];
	node->right = NULL;
	node->left = NULL;
	node->parent = parent;
	
	if (size > 1)
	{
		node->right = add_node(array + (size + 1) / 2, size / 2, node);
		if (node->right == NULL)
			return (NULL);
	}
	if (size > 2)
	{
		node->left = add_node(array, (size - 1) / 2, node);
		if (node->right == NULL)
			return (NULL);
	}

	return (node);
}

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return NULL;

	if (!size)
		return NULL;
		
	return ((avl_t *) add_node(array, size, NULL));
}