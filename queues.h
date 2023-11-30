#ifndef QUEUES_H
#define QUEUES_H
#include "binary_trees.h"
#include <stdlib.h>

typedef struct queue_node {
    binary_tree_t *tree;
    struct queue_node *next;
} queue_t;

/**
 * enqueue - Enqueues a binary tree node in the queue
 * @front: Pointer to the front of the queue
 * @node: Pointer to the binary tree node to enqueue
 */
void enqueue(queue_t **front, binary_tree_t *node);

/**
 * dequeue - Dequeues a binary tree node from the queue
 * @front: Pointer to the front of the queue
 * Return: Pointer to the dequeued binary tree node
 */
binary_tree_t *dequeue(queue_t **front);

#endif /* QUEUES_H */
