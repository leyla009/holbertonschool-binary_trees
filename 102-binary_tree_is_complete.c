#include "binary_trees.h"

/**
 * tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Size of the tree, 0 if NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * is_complete_recursive - Checks completeness using node indices
 * @tree: Pointer to the current node
 * @index: Index of the current node
 * @size: Total number of nodes in the tree
 *
 * Return: 1 if complete, 0 otherwise
 */
int is_complete_recursive(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
		return (1);

	/* If index assigned to current node is more than number of nodes */
	if (index >= size)
		return (0);

	/* Check left and right subtrees with their calculated indices */
	return (is_complete_recursive(tree->left, 2 * index + 1, size) &&
		is_complete_recursive(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node
 *
 * Return: 1 if complete, 0 if NULL or not complete
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);

	size = tree_size(tree);

	return (is_complete_recursive(tree, 0, size));
}
