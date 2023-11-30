#include "queues.h"
#include <stdio.h>
#include <stdlib.h>

void enqueue(queue_t **rear, binary_tree_t *tree)
{
    queue_t *new_node = malloc(sizeof(queue_t));
    if (!new_node)
    {
        perror("Failed to enqueue");
        exit(EXIT_FAILURE);
    }

    new_node->tree = tree;
    new_node->next = NULL;

    if (*rear == NULL)
    {
        *rear = new_node;
    }
    else
    {
        (*rear)->next = new_node;
        *rear = new_node;
    }
}

binary_tree_t *dequeue(queue_t **front)
{
    binary_tree_t *tree = (*front)->tree;
    queue_t *temp = *front;
    if (*front == NULL)
    {
        return NULL;
    }

    *front = (*front)->next;
    free(temp);

    return tree;
}
