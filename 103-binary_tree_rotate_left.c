#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *parent;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	pivot = tree->right;
	parent = tree->parent;

	/* 1. Pivot's left child becomes tree's right child */
	tree->right = pivot->left;
	if (pivot->left != NULL)
		pivot->left->parent = tree;

	/* 2. Tree becomes pivot's left child */
	pivot->left = tree;

	/* 3. Update parents */
	pivot->parent = parent;
	tree->parent = pivot;

	/* 4. Update the original parent's child pointer if it exists */
	if (parent != NULL)
	{
		if (parent->left == tree)
			parent->left = pivot;
		else
			parent->right = pivot;
	}

	return (pivot);
}
