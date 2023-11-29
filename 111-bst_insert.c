#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST)
 * @tree: Double pointer to the root node of the BST
 * @value: Value to insert in the BST
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node, *current;

    if (tree == NULL)
        return (NULL);

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    current = *tree;

    while (current)
    {
        if (value == current->n)
            return (NULL);

        if (value < current->n)
        {
            if (current->left == NULL)
            {
                new_node = binary_tree_node(current, value);
                current->left = new_node;
                return (new_node);
            }
            current = current->left;
        }
        else
        {
            if (current->right == NULL)
            {
                new_node = binary_tree_node(current, value);
                current->right = new_node;
                return (new_node);
            }
            current = current->right;
        }
    }

    return (NULL);
}
