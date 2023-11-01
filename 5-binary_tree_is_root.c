#include "binary_trees.h"
/**
 * binary_tree_is_root - Checks if a node is a root
 * @node: Pointer to the node to check
 *
 * Return: 1 if node is a root, otherwise 0
 */
int binary_tree_is_root(const struct binary_tree_s *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
