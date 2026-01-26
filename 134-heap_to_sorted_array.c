#include "binary_trees.h"

/**
 * tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Size of the tree, 0 if NULL
 */
static size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array (descending order), or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t i, t_size;

	if (!heap || !size)
		return (NULL);

	/* 1. Calculate the total size needed */
	t_size = tree_size(heap);
	*size = t_size;

	/* 2. Allocate memory for the array */
	array = malloc(t_size * sizeof(int));
	if (!array)
		return (NULL);

	/* 3. Extract root repeatedly to fill array in descending order */
	for (i = 0; i < t_size; i++)
	{
		/* heap_extract handles the re-heaping and freeing of nodes */
		array[i] = heap_extract(&heap);
	}

	return (array);
}
