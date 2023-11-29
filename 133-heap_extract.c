#include "binary_trees.h"

/**
 * heapify_down - Fix the heap property by moving down the tree.
 * @root: A pointer to the root node.
 */
void heapify_down(heap_t *root)
{
    heap_t *child;
    int temp;

    while (root->left || root->right)
    {
        child = (!root->right || root->left->n > root->right->n) ? root->left : root->right;
        if (root->n > child->n)
            break;

        temp = root->n;
        root->n = child->n;
        child->n = temp;

        root = child;
    }
}

/**
 * get_last_node - Get the last node in level order.
 * @root: A pointer to the root node.
 *
 * Return: A pointer to the last node.
 */
heap_t *get_last_node(heap_t *root)
{
    heap_t *last_node = NULL;

    while (root)
    {
        last_node = root;
        root = root->left;
    }

    return last_node;
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: A double pointer to the root node of heap.
 *
 * Return: The value stored in the root node.
 */
int heap_extract(heap_t **root)
{
    heap_t *last_node, *temp;
    int value;

    if (!root || !*root)
        return 0;

    value = (*root)->n;
    last_node = get_last_node(*root);

    if (last_node->parent)
    {
        if (last_node->parent->left == last_node)
            last_node->parent->left = NULL;
        else
            last_node->parent->right = NULL;
    }
    else
    {
        *root = NULL;
    }

    last_node->parent = NULL;
    last_node->left = (*root)->left;
    last_node->right = (*root)->right;

    if ((*root)->left)
        (*root)->left->parent = last_node;
    if ((*root)->right)
        (*root)->right->parent = last_node;

    temp = *root;
    *root = last_node;
    free(temp);

    heapify_down(*root);

    return value;
}
