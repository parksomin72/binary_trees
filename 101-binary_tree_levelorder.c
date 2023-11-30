#include "binary_trees.h"
#include "queues.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{

    queue_t *queue = NULL;
    const binary_tree_t *current;

    enqueue(&queue, (binary_tree_t *)tree);

    if (tree == NULL || func == NULL)
        return;

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
