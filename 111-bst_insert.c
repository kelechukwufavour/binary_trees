#include "binary_trees.h"

/**
 * bst_insert - Insert a value into a Binary Search Tree (BST).
 * @tree: A double pointer to the root node of the BST where the value is to be inserted.
 * @value: The value to be inserted into the tree.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value) {
	if (*tree == NULL) {
		*tree = malloc(sizeof(bst_t));
		if (*tree == NULL)
			return NULL;

		(*tree)->value = value;
		(*tree)->left = NULL;
		(*tree)->right = NULL;

		return *tree;
	}

	if (value < (*tree)->value) {
		return bst_insert(&(*tree)->left, value);
	} else if (value > (*tree)->value) {
		return bst_insert(&(*tree)->right, value);
	}

	// Value already exists, ignore and return NULL
	return NULL;
}
