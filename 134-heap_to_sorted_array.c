#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array of integers.
 * @heap: A pointer to the root node of the heap to convert.
 * @size: An address to store the size of the array.
 *
 * Return: A pointer to the sorted array of integers.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *sorted_array;
    size_t i;

    if (!heap || !size)
        return (NULL);

    *size = heap->size;
    sorted_array = malloc(sizeof(int) * *size);
    if (!sorted_array)
        return (NULL);

    for (i = 0; i < *size; ++i)
        sorted_array[i] = heap_extract(&heap);

    return (sorted_array);
}
