#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree for removing a node
 * @value: Value to remove in the tree
 * Return: Pointer to the new root node of the tree after removing the desired value, and after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
    if (root == NULL)
        return NULL;

    /* Perform standard BST delete */
    if (value < root->n)
        root->left = avl_remove(root->left, value);
    else if (value > root->n)
        root->right = avl_remove(root->right, value);
    else
    {
        /* Node with only one child or no child */
        if (root->left == NULL)
        {
            avl_t *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            avl_t *temp = root->left;
            free(root);
            return temp;
        }

        /* Node with two children, get the in-order successor */
        avl_t *temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        /* Copy the in-order successor's data to this node */
        root->n = temp->n;

        /* Delete the in-order successor */
        root->right = avl_remove(root->right, temp->n);
    }

    /* If the tree had only one node, then return */
    if (root == NULL)
        return root;

    /* Update height of the current node */
    root->height = 1 + MAX(avl_height(root->left), avl_height(root->right));

    /* Get the balance factor */
    int balance = avl_get_balance(root);

    /* Left Left Case */
    if (balance > 1 && avl_get_balance(root->left) >= 0)
        return avl_rotate_right(root);

    /* Left Right Case */
    if (balance > 1 && avl_get_balance(root->left) < 0)
    {
        root->left = avl_rotate_left(root->left);
        return avl_rotate_right(root);
    }

    /* Right Right Case */
    if (balance < -1 && avl_get_balance(root->right) <= 0)
        return avl_rotate_left(root);

    /* Right Left Case */
    if (balance < -1 && avl_get_balance(root->right) > 0)
    {
        root->right = avl_rotate_right(root->right);
        return avl_rotate_left(root);
    }

    return root;
}
