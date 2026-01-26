#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: A pointer to the node to find the sibling
 *
 * Return: A pointer to the sibling node, or NULL if node is NULL,
 * parent is NULL, or node has no sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* If node is the left child, sibling is the right child */
	if (node->parent->left == node)
		return (node->parent->right);

	/* If node is the right child, sibling is the left child */
	return (node->parent->left);
}
