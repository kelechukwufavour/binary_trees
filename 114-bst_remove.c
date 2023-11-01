#include "binary_trees.h"

typedef struct bst_s {
	struct bst_s *left;
	struct bst_s *right;
	int value;
} bst_t;

/**
 * bst_remove - Remove a node from a Binary Search Tree (BST).
 * @root: A pointer to the root node of the tree.
 * @value: The value to remove from the tree.
 *
 * Return: A pointer to the new root node of the tree after removing the desired value.
 */
bst_t *bst_remove(bst_t *root, int value) {
	if (root == NULL)
		return root;

	if (value < root->value) {
		root->left = bst_remove(root->left, value);
	} else if (value > root->value) {
		root->right = bst_remove(root->right, value);
	} else {
		// Node with the value to be removed found

		if (root->left == NULL) {
			bst_t *temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL) {
			bst_t *temp = root->left;
			free(root);
			return temp;
		}

		// Node has two children, find in-order successor
		bst_t *temp = root->right;
		while (temp->left != NULL) {
			temp = temp->left;
		}

		// Copy the in-order successor's value to this node
		root->value = temp->value;

		// Remove the in-order successor
		root->right = bst_remove(root->right, temp->value);
	}

	return root;
}
