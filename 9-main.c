#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t height;

    root = binary_tree_node(NULL, 98);
    binary_tree_insert_right(root, 128);
    binary_tree_insert_right(root->right, 256);
    binary_tree_insert_right(root->right->right, 512);

    binary_tree_print(root);

    height = binary_tree_height(root);
    printf("Height of tree with root node (%d): %lu\n", root->n, height);

    height = binary_tree_height(root->right);
    printf("Height from %d: %lu\n", root->right->n, height);

    height = binary_tree_height(root->right->right);
    printf("Height from %d: %lu\n", root->right->right->n, height);

    return (0);
}
