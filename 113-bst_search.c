#include "binary_trees.h"

typedef struct bst_s {
	struct bst_s *left;
	struct bst_s *right;
	int value;
} bst_t;

/**
 * bst_search - Search for a value in a Binary Search Tree (BST).
 * @tree: A pointer to the root node of the BST to search.
 * @value: The value to search for in the tree.
 *
 * Return: A pointer to the node containing a value equal to `value`, or NULL if not found.
 */
bst_t *bst_search(const bst_t *tree, int value) {
	if (tree == NULL || tree->value == value)
		return (bst_t *)tree;

	if (value < tree->value)
		return bst_search(tree->left, value);
	else
		return bst_search(tree->right, value);
}
