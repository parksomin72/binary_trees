#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/**
 * struct binary_tree_s - Basic binary tree structure
 * @n: Integer value stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
int n;
struct binary_tree_s *parent;
struct binary_tree_s *left;
struct binary_tree_s *right;
} binary_tree_t;

/* Binary search tree structure */
typedef struct binary_tree_s bst_t;

/* AVL tree structure */
typedef struct binary_tree_s avl_t;

/* Max Binary Heap structure */
typedef struct binary_tree_s heap_t;

/* Function prototypes */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *tree);

/* Binary Search Tree (BST) function prototypes */
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);

/* AVL Tree function prototypes */
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *avl_remove(avl_t *root, int value);

/* Max Binary Heap function prototypes */
heap_t *heap_insert(heap_t **root, int value);
heap_t *array_to_heap(int *array, size_t size);
int heap_extract(heap_t **root);
int *heap_to_sorted_array(heap_t *heap, size_t *size);

/* Additional binary tree function prototypes */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

#endif /* BINARY_TREES_H */

