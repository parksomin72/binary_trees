#include "binary_trees.h"

/**
 * heap_insert - Inserts a value in a Max Binary Heap.
 * @root: A double pointer to the root node of the heap.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node;

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return NULL;

    if (!*root)
    {
        *root = new_node;
        return new_node;
    }

    insert_last_node(*root, new_node);
    heapify_up(new_node);

    return new_node;
}

/**
 * insert_last_node - Inserts a new node as the last node in the heap.
 * @root: A pointer to the root node of the heap.
 * @node: The new node to insert.
 */
void insert_last_node(heap_t *root, heap_t *node)
{
    int height = binary_tree_height(root) - 1;
    int index = 1 << height;

    while (index > 0)
    {
        if (index & height)
            root = root->right;
        else
            root = root->left;

        index >>= 1;
    }

    if (height & 1)
        root->right = node;
    else
        root->left = node;

    node->parent = root;
}

/**
 * heapify_up - Ensures the Max Heap property is maintained by moving
 *               the new node up the tree if necessary.
 * @node: A pointer to the newly inserted node.
 */
void heapify_up(heap_t *node)
{
    while (node && node->parent && node->n > node->parent->n)
    {
        swap_values(node, node->parent);
        node = node->parent;
    }
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: The height of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (!tree)
        return 0;

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}

/**
 * swap_values - Swaps the values of two nodes.
 * @a: A pointer to the first node.
 * @b: A pointer to the second node.
 */
void swap_values(heap_t *a, heap_t *b)
{
    int temp;

    temp = a->n;
    a->n = b->n;
    b->n = temp;
}
