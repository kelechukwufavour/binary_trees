#include "binary_trees.h"

/**
 * bst_insert - Insert a value into a Binary Search Tree (BST).
 * @tree: A double pointer to the root node of the BST where the value is to be inserted.
 * @value: The value to be inserted into the tree.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
binary_tree_t *bst_insert(binary_tree_t **tree, int value) {
	if (*tree == NULL) {
		*tree = binary_tree_node(NULL, value);
		if (*tree == NULL)
			return NULL;
		return *tree;
	}

	if (value < (*tree)->n) {
		return bst_insert(&(*tree)->left, value);
	} else if (value > (*tree)->n) {
		return bst_insert(&(*tree)->right, value);
	}

	return NULL;
}
