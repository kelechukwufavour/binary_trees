#include "binary_trees.h"
/**
 * binary_tree_rotate_right - Perform a right-rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree) {
	if (tree == NULL || tree->left == NULL)
		return tree;

	binary_tree_t *temp = tree->left;
	tree->left = temp->right;
	temp->right = tree;

	return temp;
}
