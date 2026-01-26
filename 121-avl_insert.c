#include "binary_trees.h"

/**
 * avl_insert_recursive - Inserts a value into an AVL tree and rebalances
 * @tree: Double pointer to the current node in recursion
 * @parent: Parent of the current node
 * @new_node: Double pointer to store the newly created node
 * @value: Value to insert
 *
 * Return: Pointer to the new root of the subtree
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
			    avl_t **new_node, int value)
{
	int bf;

	if (*tree == NULL)
	{
		*new_node = binary_tree_node(parent, value);
		return (*new_node);
	}

	if (value < (*tree)->n)
		(*tree)->left = avl_insert_recursive(&((*tree)->left), 
				*tree, new_node, value);
	else if (value > (*tree)->n)
		(*tree)->right = avl_insert_recursive(&((*tree)->right), 
				*tree, new_node, value);
	else
		return (*tree);

	/* Update height/balance factor and rotate if necessary */
	bf = binary_tree_balance(*tree);

	if (bf > 1 && value < (*tree)->left->n) /* LL */
		return (binary_tree_rotate_right(*tree));

	if (bf < -1 && value > (*tree)->right->n) /* RR */
		return (binary_tree_rotate_left(*tree));

	if (bf > 1 && value > (*tree)->left->n) /* LR */
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree));
	}

	if (bf < -1 && value < (*tree)->right->n) /* RL */
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree));
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node
 * @value: Value to store
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (!tree)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	*tree = avl_insert_recursive(tree, NULL, &new_node, value);

	return (new_node);
}
