#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void merge_recursive(int *array, size_t size);
void merge_arrays(int *left, size_t left_size, int *right, size_t right_size);

/**
 * merge_sort - sorts an array of integers using the Merge Sort algorithm
 * @array: array of integers to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    merge_recursive(array, size);
}

/**
 * merge_recursive - recursively divides and merges the array
 * @array: array of integers to be sorted
 * @size: size of the array
 */
void merge_recursive(int *array, size_t size)
{
    size_t mid;
    int *left, *right;

    if (size < 2)
        return;

    mid = size / 2;
    left = array;
    right = array + mid;

    merge_recursive(left, mid);
    merge_recursive(right, size - mid);

    merge_arrays(left, mid, right, size - mid);

    printf("[Done]: ");
    print_array(array, size);
}



/**
 * merge_arrays - merges two arrays in sorted order
 * @left: left array
 * @left_size: size of the left array
 * @right: right array
 * @right_size: size of the right array
 */
void merge_arrays(int *left, size_t left_size, int *right, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;
    size_t merged_size = left_size + right_size;
    int *merged = malloc(sizeof(int) * merged_size);

    if (merged == NULL)
        return;

    printf("Merging...\n[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
            merged[k++] = left[i++];
        else
            merged[k++] = right[j++];
    }

    while (i < left_size)
        merged[k++] = left[i++];

    while (j < right_size)
        merged[k++] = right[j++];

    for (i = 0; i < merged_size; i++)
        left[i] = merged[i];

    printf("[Done]: ");
    print_array(left, merged_size);

    free(merged);
}
