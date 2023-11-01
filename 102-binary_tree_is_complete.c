#include "binary_trees.h"
/**
 * binary_tree_is_complete - Check if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree) {
    if (tree == NULL)
        return 0;

    int is_complete = 1; // Assume it's complete by default
    int level = 0;
    int node_count = 0;

    if (tree != NULL)
        node_count++;

    while (tree) {
        if (!tree->left && tree->right) {
            is_complete = 0;
            break;
        }

        if (tree->left && !tree->right) {
            is_complete = 0;
            break;
        }

        if (tree->left) {
            node_count++;
            tree = tree->left;
            level++;
        } else {
            is_complete = 0;
            break;
        }
    }

    if (is_complete) {
        if (node_count != (1 << (level + 1)) - 1)
            is_complete = 0;
    }

    return is_complete;
}
