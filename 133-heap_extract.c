#include "binary_trees.h"

/**
 * tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root
 * Return: Size of the tree
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * get_last_node - Gets the last node in level-order traversal
 * @root: Pointer to the root
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
	heap_t *queue[1024];
	int head = 0, tail = 0;
	heap_t *curr = NULL;

	queue[tail++] = root;
	while (head < tail)
	{
		curr = queue[head++];
		if (curr->left)
			queue[tail++] = curr->left;
		if (curr->right)
			queue[tail++] = curr->right;
	}
	return (curr);
}

/**
 * sift_down - Restores the max heap property from root downwards
 * @root: Pointer to the root of the heap
 */
void sift_down(heap_t *root)
{
	heap_t *largest = NULL;
	int temp;

	while (root)
	{
		largest = root;
		if (root->left && root->left->n > largest->n)
			largest = root->left;
		if (root->right && root->right->n > largest->n)
			largest = root->right;

		if (largest == root)
			break;

		temp = root->n;
		root->n = largest->n;
		largest->n = temp;
		root = largest;
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last_node, *root_node;

	if (!root || !*root)
		return (0);

	root_node = *root;
	value = root_node->n;

	if (!root_node->left && !root_node->right)
	{
		free(root_node);
		*root = NULL;
		return (value);
	}

	last_node = get_last_node(root_node);
	root_node->n = last_node->n;

	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	free(last_node);
	sift_down(root_node);

	return (value);
}
