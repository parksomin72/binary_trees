#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (!tree)
        return 0;

    if (!binary_tree_is_complete(tree))
        return 0;

    return is_heap_util(tree);
}

/**
 * is_heap_util - Helper function to recursively check if a tree is a valid
 *                Max Binary Heap.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise.
 */
int is_heap_util(const binary_tree_t *tree)
{
    if (!tree)
        return 1;

    if (tree->left && tree->left->n > tree->n)
        return 0;

    if (tree->right && tree->right->n > tree->n)
        return 0;

    return is_heap_util(tree->left) && is_heap_util(tree->right);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (!tree)
        return 1;

    return (binary_tree_size(tree) == binary_tree_count(tree, 0));
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: The size of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return 0;

    return 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);
}

/**
 * binary_tree_count - Counts the number of nodes with a specific depth
 * @tree: A pointer to the root node of the tree to count.
 * @depth: The depth to count nodes at.
 *
 * Return: The number of nodes at the specified depth.
 */
size_t binary_tree_count(const binary_tree_t *tree, size_t depth)
{
    if (!tree)
        return 0;

    if (depth == 0)
        return 1;

    return binary_tree_count(tree->left, depth - 1) + binary_tree_count(tree->right, depth - 1);
}
