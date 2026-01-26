#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: A pointer to the node to find the uncle
 *
 * Return: A pointer to the uncle node, or NULL if node is NULL,
 * has no parent, or has no uncle.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	/* Check if the parent is the left child of the grandparent */
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	/* If parent is the right child, uncle is the left child */
	return (node->parent->parent->left);
}
