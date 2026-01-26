#include "binary_trees.h"

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (!root)
		return (NULL);

	if (!(*root))
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	parent = get_insert_parent(*root);
	new_node = binary_tree_node(parent, value);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (bubble_up(new_node));
}

/**
 * get_insert_parent - Finds the parent for the next insertion point
 * @root: Pointer to the root
 *
 * Return: Pointer to the parent node
 */
heap_t *get_insert_parent(heap_t *root)
{
	heap_t *queue[1024];
	int head = 0, tail = 0;

	queue[tail++] = root;
	while (head < tail)
	{
		heap_t *curr = queue[head++];

		if (!curr->left || !curr->right)
			return (curr);

		queue[tail++] = curr->left;
		queue[tail++] = curr->right;
	}
	return (NULL);
}

/**
 * bubble_up - Fixes the max heap property by swapping values
 * @node: Pointer to the new node
 *
 * Return: Pointer to the node in its final position
 */
heap_t *bubble_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
	return (node);
}
