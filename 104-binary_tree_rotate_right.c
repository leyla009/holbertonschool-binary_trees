#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *parent;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	pivot = tree->left;
	parent = tree->parent;

	/* 1. Pivot's right child becomes tree's left child */
	tree->left = pivot->right;
	if (pivot->right != NULL)
		pivot->right->parent = tree;

	/* 2. Tree becomes pivot's right child */
	pivot->right = tree;

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
