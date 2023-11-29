#ifndef QUEUES_H
#define QUEUES_H

#include <stdlib.h>

/**
 * struct queue_s - Structure for a queue node
 * @node: Pointer to the binary tree node
 * @next: Pointer to the next element in the queue
 */
typedef struct queue_s
{
    struct binary_tree_s *node;
    struct queue_s *next;
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
