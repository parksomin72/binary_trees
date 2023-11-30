#include "queues.h"
#include "binary_trees.h"
#include <stdio.h>


void enqueue(queue_t **front, binary_tree_t *node)
{
    queue_t *new_node = malloc(sizeof(queue_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Failed to enqueue: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->tree = node;
    new_node->next = NULL;

    if (*front == NULL)
    {
        *front = new_node;
    }
    else
    {
        queue_t *temp = *front;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

binary_tree_t *dequeue(queue_t **front)
{
    binary_tree_t *dequeued;
    queue_t *temp;

    if (*front == NULL)
    {
        return NULL;
    }


    dequeued = (*front)->tree;
    temp = *front;
    *front = (*front)->next;

    free(temp);
    return dequeued;
}
