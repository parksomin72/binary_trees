#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if no ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{

const binary_tree_t *temp1 = first;
const binary_tree_t *temp2;
if (first == NULL || second == NULL)
return (NULL);

while (temp1)
{
temp2 = second;

while (temp2)
{
if (temp1 == temp2)
return ((binary_tree_t *)temp1);
temp2 = temp2->parent;
}

temp1 = temp1->parent;
}

return (NULL);
}
