#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: A pointer to the new root node after the rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    if (tree == NULL || tree->right == NULL)
        return (NULL);

    binary_tree_t *new_root = tree->right;
    tree->right = new_root->left;

    if (new_root->left != NULL)
        new_root->left->parent = tree;

    new_root->parent = tree->parent;

    if (tree->parent == NULL)
    {
        new_root->parent = NULL;
        tree->parent = new_root;
    }
    else
    {
        if (tree->parent->left == tree)
            tree->parent->left = new_root;
        else
            tree->parent->right = new_root;
    }

    new_root->left = tree;
    tree->parent = new_root;

    return (new_root);
}
