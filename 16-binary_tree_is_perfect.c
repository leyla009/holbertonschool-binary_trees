#include "binary_trees.h"

/**
 * tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Height of the tree
 */
size_t tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + tree_height(tree->left));
}

/**
 * is_perfect_recursive - Checks if tree is perfect recursively
 * @tree: Pointer to the root node
 * @depth: Current depth of the node
 * @level: The level of leaves in a perfect tree
 *
 * Return: 1 if perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (tree->left == NULL && tree->right == NULL)
		return (level == depth);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect_recursive(tree->left, depth + 1, level) &&
		is_perfect_recursive(tree->right, depth + 1, level));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree == NULL)
		return (0);

	level = tree_height(tree);
	return (is_perfect_recursive(tree, 1, level));
}
