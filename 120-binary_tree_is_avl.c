#include <limits.h>
#include "binary_trees.h"

/* Forward declaration of is_avl function */
int is_avl(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_avl - Check if a binary tree is a valid AVL Tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (is_avl(tree, INT_MIN, INT_MAX))
		return (1);

	return (0);
}

/**
 * is_avl - Recursively check if a binary tree is a valid AVL Tree.
 * @tree: A pointer to the current node.
 * @min: The minimum value for the current node.
 * @max: The maximum value for the current node.
 *
 * Return: 1 if the tree is a valid AVL Tree, 0 otherwise.
 */
int is_avl(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	if (abs(binary_tree_balance(tree)) > 1)
		return (0);

	return (is_avl(tree->left, min, tree->n) &&			is_avl(tree->right, tree->n, max));
}

/**
 * binary_tree_balance - Calculate the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The balance factor of the tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}

/**
 * binary_tree_height - Calculate the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}
