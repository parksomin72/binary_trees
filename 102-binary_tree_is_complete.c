#include "binary_trees.h"
#include "queues.h"

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

    /* Use level-order traversal to check completeness */

    enqueue(&front, (binary_tree_t *)tree);

    while (front != NULL)
    {
        binary_tree_t *current = dequeue(&front);

        /* Check if a non-full node is encountered */
        if (current == NULL)
            flag = 1;
        else
        {
            /* If a non-full node was encountered before, and a non-NULL node is found, the tree is not complete */
            if (flag)
                return (0);

            enqueue(&front, current->left);
            enqueue(&front, current->right);
        }
    }

    return (1);
}
