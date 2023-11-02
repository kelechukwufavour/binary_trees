#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree.
 * Return: Size of the binary tree, 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree) {
	if (tree == NULL) {
		return 0; //Base case: empty tree has size 0
	} else {
		//Recursively calculate size: size of left subtree + size of right subtree + (for current node)
		return binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1;
	}
}
