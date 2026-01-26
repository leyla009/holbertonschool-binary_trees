#include "binary_trees.h"

/**
 * bst_min_value - Finds the node with the minimum value in a tree
 * @node: Pointer to the root of the tree
 * Return: Pointer to the node with the min value
 */
bst_t *bst_min_value(bst_t *node)
{
	while (node && node->left)
		node = node->left;
	return (node);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree
 * @value: The value to remove
 * Return: Pointer to the new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *successor;

	if (!root)
		return (NULL);

	/* 1. Locate the node */
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		/* 2. Found the node - Handle children cases */
		if (!root->left) /* No left child or no children */
		{
			temp = root->right;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else if (!root->right) /* Only left child */
		{
			temp = root->left;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}

		/* 3. Two children: Get successor (smallest in right subtree) */
		successor = bst_min_value(root->right);
		root->n = successor->n;
		/* Delete the successor */
		root->right = bst_remove(root->right, successor->n);
	}
	return (root);
}

