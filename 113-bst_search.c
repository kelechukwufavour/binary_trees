#include "binary_trees.h"

/**
 * bst_search - Search for a value in a Binary Search Tree (BST).
 * @tree: A pointer to the root node of the BST to search.
 * @value: The value to search for in the tree.
 *
 * Return: A pointer to the node containing a value equal to 'value'
 Otherwise - Null
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL || tree->n == value)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
}
