#include "binary_trees.h"
#include <limits.h>

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Height of the tree, 0 if NULL
 */
size_t height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = height(tree->left);
	right_h = height(tree->right);

	return ((left_h > right_h ? left_h : right_h) + 1);
}

/**
 * is_bst_helper - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node
 * @min: Minimum value
 * @max: Maximum value
 *
 * Return: 1 if valid BST, 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst_helper(tree->left, min, tree->n) &&
		is_bst_helper(tree->right, tree->n, max));
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL
 * @tree: Pointer to the root node
 *
 * Return: 1 if valid AVL, 0 otherwise
 */
int is_avl_helper(const binary_tree_t *tree)
{
	int left_h, right_h, diff;

	if (tree == NULL)
		return (1);

	left_h = (int)height(tree->left);
	right_h = (int)height(tree->right);
	diff = left_h - right_h;

	if (diff < -1 || diff > 1)
		return (0);

	return (is_avl_helper(tree->left) && is_avl_helper(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node
 *
 * Return: 1 if tree is a valid AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!is_bst_helper(tree, INT_MIN, INT_MAX))
		return (0);

	return (is_avl_helper(tree));
}
