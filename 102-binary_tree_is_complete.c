#include "binary_trees.h"
#include "queues.h"
#include "queues.c"

#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: The size of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    return 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    size_t index = 0;
    size_t size = binary_tree_size(tree);

    if (tree == NULL)
        return 0;

    return is_complete(tree, index, size);
}

/**
 * is_complete - Checks if a binary tree is complete recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @index: The index of the current node.
 * @size: The size of the entire tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
    if (tree == NULL)
        return 1;

    if (index >= size)
        return 0;

    return (is_complete(tree->left, 2 * index + 1, size) &&
            is_complete(tree->right, 2 * index + 2, size));
}
