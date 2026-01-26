#include "binary_trees.h"

/**
 * min_value_node - Finds the node with the smallest value in a tree
 * @node: Pointer to the root of the tree
 * Return: Pointer to the min node
 */
avl_t *min_value_node(avl_t *node)
{
	avl_t *current = node;

	while (current->left != NULL)
		current = current->left;
	return (current);
}

/**
 * balance_avl - Rebalances an AVL tree node
 * @root: Pointer to the node to rebalance
 * Return: Pointer to the new root after rotations
 */
avl_t *balance_avl(avl_t *root)
{
	int bf;

	bf = binary_tree_balance(root);

	/* Left Heavy */
	if (bf > 1)
	{
		if (binary_tree_balance(root->left) < 0)
			root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	/* Right Heavy */
	if (bf < -1)
	{
		if (binary_tree_balance(root->right) > 0)
			root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree
 * @value: Value to remove
 * Return: Pointer to the new root node
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp = NULL;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (root->left == NULL || root->right == NULL)
		{
			temp = root->left ? root->left : root->right;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		temp = min_value_node(root->right);
		root->n = temp->n;
		root->right = avl_remove(root->right, temp->n);
	}

	/* Rebalancing is done as we come back up the recursive stack */
	return (balance_avl(root));
}
