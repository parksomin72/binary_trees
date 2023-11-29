#include "binary_trees.h"

/**
 * bst_find_min - Finds the minimum value node in a BST
 * @root: Pointer to the root node of the BST
 *
 * Return: Pointer to the node with the minimum value
 */
bst_t *bst_find_min(bst_t *root)
{
    if (root == NULL)
        return (NULL);

    while (root->left != NULL)
        root = root->left;

    return (root);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST)
 * @root: Pointer to the root node of the BST
 * @value: Value to remove from the BST
 *
 * Return: Pointer to the new root node of the tree after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
    if (root == NULL)
        return (NULL);

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else {
        if (root->left == NULL) {
            bst_t *temp = root->right;
            free(root);
            return (temp);
        } else if (root->right == NULL) {
            bst_t *temp = root->left;
            free(root);
            return (temp);
        }

        bst_t *min = bst_find_min(root->right);
        root->n = min->n;
        root->right = bst_remove(root->right, min->n);
    }

    return (root);
}
