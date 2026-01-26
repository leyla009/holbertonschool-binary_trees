#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the LCA node, or NULL if no common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	const binary_tree_t *temp_f, *temp_s;

	if (!first || !second)
		return (NULL);

	temp_f = first;
	while (temp_f)
	{
		temp_s = second;
		while (temp_s)
		{
			if (temp_f == temp_s)
				return ((binary_tree_t *)temp_f);
			temp_s = temp_s->parent;
		}
		temp_f = temp_f->parent;
	}

	return (NULL);
}
