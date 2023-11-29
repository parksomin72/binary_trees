#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        if (*tree == NULL)
            return (NULL);
        return (*tree);
    }

    if (value < (*tree)->n)
    {
        (*tree)->left = avl_insert(&((*tree)->left), value);
    }
    else if (value > (*tree)->n)
    {
        (*tree)->right = avl_insert(&((*tree)->right), value);
    }
    else
    {
        // Ignore duplicate values
        return (*tree);
    }

    // Update height of the current node
    (*tree)->height = 1 + MAX(binary_tree_height((*tree)->left), binary_tree_height((*tree)->right));

    // Get the balance factor
    int balance = binary_tree_balance(*tree);

    // Perform rotations if needed
    if (balance > 1 && value < (*tree)->left->n)
        return binary_tree_rotate_right(*tree);
    if (balance < -1 && value > (*tree)->right->n)
        return binary_tree_rotate_left(*tree);
    if (balance > 1 && value > (*tree)->left->n)
    {
        (*tree)->left = binary_tree_rotate_left((*tree)->left);
        return binary_tree_rotate_right(*tree);
    }
    if (balance < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = binary_tree_rotate_right((*tree)->right);
        return binary_tree_rotate_left(*tree);
    }

    return (*tree);
}
