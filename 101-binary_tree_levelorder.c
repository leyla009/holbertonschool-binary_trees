#include "binary_trees.h"

/**
 * tree_height_lvl - Measures the height of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Height of the tree
 */
size_t tree_height_lvl(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree == NULL)
		return (0);
	l = tree_height_lvl(tree->left);
	r = tree_height_lvl(tree->right);
	return ((l > r ? l : r) + 1);
}

/**
 * apply_at_level - Applies a function to all nodes at a specific level
 * @tree: Pointer to the root node
 * @level: Level to target
 * @func: Function to call
 */
void apply_at_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		apply_at_level(tree->left, level - 1, func);
		apply_at_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree == NULL || func == NULL)
		return;

	height = tree_height_lvl(tree);
	for (i = 1; i <= height; i++)
	{
		apply_at_level(tree, i, func);
	}
}
