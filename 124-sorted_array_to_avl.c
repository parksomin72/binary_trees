#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (size == 0)
        return NULL;

    return sorted_array_to_avl_helper(array, 0, size - 1);
}

/**
 * sorted_array_to_avl_helper - Recursive helper function to build AVL tree
 * @array: Pointer to the first element of the array to be converted
 * @start: Starting index of the current subarray
 * @end: Ending index of the current subarray
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl_helper(int *array, size_t start, size_t end)
{
    if (start > end)
        return NULL;

    size_t mid = (start + end) / 2;

    avl_t *root = binary_tree_node(NULL, array[mid]);
    if (root == NULL)
        return NULL;

    root->left = sorted_array_to_avl_helper(array, start, mid - 1);
    root->right = sorted_array_to_avl_helper(array, mid + 1, end);

    return root;
}
