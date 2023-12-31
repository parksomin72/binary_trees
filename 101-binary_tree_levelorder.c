#include "binary_trees.h"
#include "queues.h"
#include "queues.c"


/**
 * binary_tree_levelorder - Performs a level-order traversal on a binary tree
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
queue_t *queue = NULL;
const binary_tree_t *current;

if (tree == NULL || func == NULL)
return;

enqueue(&queue, (binary_tree_t *)tree);

while (queue != NULL)
{
current = dequeue(&queue);

func(current->n);

if (current->left != NULL)
enqueue(&queue, current->left);

if (current->right != NULL)
enqueue(&queue, current->right);
}
}
