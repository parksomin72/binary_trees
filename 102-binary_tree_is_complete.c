#include "binary_trees.h"
#include "queues.h"
#include "queues.c"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
queue_t *front = NULL;
int flag = 0;

if (tree == NULL)
return (0);


enqueue(&front, (binary_tree_t *)tree);

while (front != NULL)
{
binary_tree_t *current = dequeue(&front);


if (current == NULL)
flag = 1;
else
{
if (flag)
return (0);

enqueue(&front, current->left);
enqueue(&front, current->right);
}
}

return (1);
}
