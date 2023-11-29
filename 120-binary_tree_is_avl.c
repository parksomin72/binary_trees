#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst - Helper function to check if a binary tree is a BST
 * @tree: Pointer to the root of the tree
 * @min: Minimum allowed value for a node
 * @max: Maximum allowed value for a node
 * Return: 1 if it's a BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1);

    if (tree->n <= min || tree->n >= max)
        return (0);

    return (is_bst(tree->left, min, tree->n) && is_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root of the tree
 * Return: 1 if it's a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int height_diff;

    if (tree == NULL)
        return (0);

    if (!is_bst(tree, INT_MIN, INT_MAX))
        return (0);

    height_diff = binary_tree_balance(tree);

    if (height_diff > 1 || height_diff < -1)
        return (0);

    if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
        return (0);

    return (1);
}
